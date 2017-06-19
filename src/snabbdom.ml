
type snabb_data
type snabb_node

external _h : string -> snabb_data -> snabb_node array -> snabb_node = "h" [@@bs.module "snabbdom"]
external _h_text : string -> snabb_data -> string -> snabb_node = "h" [@@bs.module "snabbdom"]

type prop = string * string
type style = string * string
type 'a event_cb = ('a -> unit)

type node_info = Text of string
               | Style of style
               | StyleDelay of style
               | StyleRemove of style
               | Props of prop list
               | Prop of string * string
               | Children of snabb_node list
               | EventListener of (string * Dom.event event_cb)
               | Key of string
               | Ignore

(*
external a : Dom.dragEvent = ""
let x = EventListener ("abc", a)
*)

exception Not_supported
exception Children_not_allowed_with_text

(* Helper functions for manipulating Snabbdom data plain JS object *)
[%%bs.raw{|
var bs_snabbdom = {
    empty_data: function() { return {}; },
    set_in_path: function(data, path, value){
        var base = data || {};
        var ref = base;
        while(path.length > 1){
            var next = path.shift();
            ref[next] = ref[next] || {};
            ref = ref[next];
        }
        if(path.length == 1) {
            var next = path.shift();
            ref[next] = value;
        }
        return base;
    }
};
|}]

external empty_data : unit -> snabb_data = "empty_data" [@@bs.val] [@@bs.scope "bs_snabbdom"]
external set_in_path : snabb_data -> string array -> 'a -> snabb_data = "set_in_path" [@@bs.val] [@@bs.scope "bs_snabbdom"]

let h selector (props: node_info list) =
let snabb_props = (empty_data (), [||], None) in
    let set_prop data (k, v) = set_in_path data [|"props"; k|] v in

    let reducer (data, children, text) (prop: node_info) = match prop with
        | Text v -> (data, children, Some v)
        | Children l -> (data, Array.append children (Array.of_list l), text)
        | Style (k, v) -> (set_in_path data [|"style"; k|] v, children, text)
        | StyleDelay (k, v) -> (set_in_path data [|"style"; "delayed"; k|] v, children, text)
        | StyleRemove (k, v) -> (set_in_path data [|"style"; "remove"; k|] v, children, text)
        | Props l -> (List.fold_left set_prop data l, children, text)
        | Prop (k, v) -> (set_prop data (k,v), children, text)
        | EventListener (key, cb) -> (set_in_path data [|"on"; key|] cb, children, text)
        | Key v -> (set_in_path data [|"key"|] v, children, text)
        | Ignore -> (data, children, text)
    in

    let snabb_props = List.fold_left reducer snabb_props props in
    match snabb_props with
        | (data, children, None) -> _h selector data children
        | (data, [||], Some t) -> _h_text selector data t
        | (_, _, Some _) -> raise Children_not_allowed_with_text

type submodule
type patchfn = snabb_node -> snabb_node -> unit

external document : Dom.document = "" [@@bs.val]
external get_element_by_id : Dom.document -> string -> Dom.element option = "getElementById" [@@bs.send] [@@bs.return null_to_opt]
external dom_as_vnode : Dom.element -> snabb_node = "%identity"
external init : submodule array -> patchfn = "init" [@@bs.module "snabbdom"]

external module_props : submodule = "default" [@@bs.module "snabbdom/modules/props"]
external module_eventlisteners : submodule = "default" [@@bs.module "snabbdom/modules/eventlisteners"]
external module_style : submodule = "default" [@@bs.module "snabbdom/modules/style"]

let prop key value = Prop (key, value)
let style key value = Style (key, value)
