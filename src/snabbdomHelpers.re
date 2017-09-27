module Base = SnabbdomBase;

let tag = Base.h; /* a (List.append b [Base.children c]); */
let childlessTag = Base.h;

let a = tag "a";
let abbr = tag "abbr";
let address = tag "address";
let article = tag "article";
let aside = tag "aside";
let audio = tag "audio";
let b = tag "b";
let bdi = tag "bdi";
let bdo = tag "bdo";
let big = tag "big";
let blockquote = tag "blockquote";
let body = tag "body";
let button b => childlessTag "button" b;
let canvas = tag "canvas";
let caption = tag "caption";
let cite = tag "cite";
let code = tag "code";
let colgroup = tag "colgroup";
let data = tag "data";
let datalist = tag "datalist";
let dd = tag "dd";
let dtag = tag "del";
let details = tag "details";
let dfn = tag "dfn";
let dialog = tag "dialog";
let div = tag "div";
let dl = tag "dl";
let dt = tag "dt";
let em = tag "em";
let fieldset = tag "fieldset";
let figcaption = tag "figcaption";
let figure = tag "figure";
let footer = tag "footer";
let form = tag "form";
let h1 b => childlessTag "h1" b;
let h2 b => childlessTag "h2" b;
let h3 b => childlessTag "h3" b;
let h4 b => childlessTag "h4" b;
let h5 b => childlessTag "h5" b;
let h6 b => childlessTag "h6" b;
let head = tag "head";
let header = tag "header";
let hgroup = tag "hgroup";
let html = tag "html";
let i = tag "i";
let iframe = tag "iframe";
let ins = tag "ins";
let kbd = tag "kbd";
let labtag = tag "label";
let legend = tag "legend";
let li = tag "li";
let main = tag "main";
let map = tag "map";
let mark = tag "mark";
let menu = tag "menu";
let meter = tag "meter";
let nav = tag "nav";
let noscript = tag "noscript";
let ol = tag "ol";
let optgroup = tag "optgroup";
let option = tag "option";
let output = tag "output";
let p = tag "p";
let picture = tag "picture";
let pre = tag "pre";
let progress = tag "progress";
let q = tag "q";
let rp = tag "rp";
let rt = tag "rt";
let ruby = tag "ruby";
let s = tag "s";
let samp = tag "samp";
let script = tag "script";
let section = tag "section";
let select = tag "select";
let small = tag "small";
let span = tag "span";
let strong = tag "strong";
/* let style = tag "style"; */
let sub = tag "sub";
let summary = tag "summary";
let sup = tag "sup";
let table = tag "table";
let tbody = tag "tbody";
let td = tag "td";
let textarea = tag "textarea";
let tfoot = tag "tfoot";
let ttag = tag "th";
let thead = tag "thead";
let time = tag "time";
let title = tag "title";
let tr = tag "tr";
let u = tag "u";
let ul = tag "ul";
let var = tag "var";
let video = tag "video";

/* Void Elements */
let area b => childlessTag "area" b;
let base b => childlessTag "base" b;
let br b => childlessTag "br" b;
let col b => childlessTag "col" b;
let embed b => childlessTag "embed" b;
let hr b => childlessTag "hr" b;
let img b => childlessTag "img" b;
let input b => childlessTag "input" b;
let keygen b => childlessTag "keygen" b;
let link b => childlessTag "link" b;
let menuitem b => childlessTag "menuitem" b;
let meta b => childlessTag "meta" b;
let param b => childlessTag "param" b;
let source b => childlessTag "source" b;
let track b => childlessTag "track" b;
let wbr b => childlessTag "wbr" b;

/* SVG api */
let svg = tag "svg";
let circle = tag "circle";
let clipPattag = tag "clipPath";
let defs = tag "defs";
let ellipse = tag "ellipse";
let g = tag "g";
let image = tag "image";
let line = tag "line";
let linearGradient = tag "linearGradient";
let mask = tag "mask";
let pattag = tag "path";
let pattern = tag "pattern";
let polygon = tag "polygon";
let polyline = tag "polyline";
let radialGradient = tag "radialGradient";
let rect = tag "rect";
let stop = tag "stop";
/* let text = tag "text"; */
let tspan = tag "tspan";
