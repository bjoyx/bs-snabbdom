open SnabbdomBase;
module VNode = SnabbdomVnode;

external module_eventlisteners : snabbdom_module =
  "default" [@@bs.module "snabbdom/modules/eventlisteners"];

/* Helper for waiting until post-render before calling a callback */
let next_tick cb => {
  let _ = SnabbdomDom.set_timeout cb 0;
  ()
};

type event_cb 'a = 'a => unit;
let event_listener key cb => VNode.set_in_data [|"on", key|] cb;

let event event (cb: event_cb Dom.event) => event_listener event cb;
let change = event "change";
let oninput = event "input";

let mouse event (cb: event_cb Dom.mouseEvent) => event_listener event cb;

let click = mouse "click";
let mousedown = mouse "mousedown";
let mouseup = mouse "mouseup";
let mousemove = mouse "mousemove";

let keyboard event (cb: event_cb Dom.keyboardEvent) => event_listener event cb;
let keydown = keyboard "keydown";
let keyup = keyboard "keyup";
let keypress = keyboard "keypress";

let drag event (cb: event_cb Dom.dragEvent) => event_listener event cb;
let dragenter = drag "dragenter";
let dragover = drag "dragover";
let dragleave = drag "dragleave";
let drop = drag "drop";