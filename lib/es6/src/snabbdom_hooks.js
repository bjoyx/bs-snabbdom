// Generated by BUCKLESCRIPT VERSION 1.8.1, PLEASE EDIT WITH CARE
'use strict';

import * as Block from "bs-platform/lib/es6/block.js";

function insert(cb) {
  return /* Hook */Block.__(9, [/* tuple */[
              "insert",
              /* One */Block.__(1, [cb])
            ]]);
}

var autofocus = insert((function (n) {
        n.elm.focus();
        return /* () */0;
      }));

export {
  insert    ,
  autofocus ,
  
}
/* autofocus Not a pure module */