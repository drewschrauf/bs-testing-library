let click: Dom.element => unit;

let dblClick: Dom.element => unit;

let type_:
  (~allAtOnce: bool=?, ~delay: int=?, string, Dom.element) =>
  Js.Promise.t(unit);

let clear: Dom.element => unit;

let selectOption: (string, Dom.element) => unit;

let selectOptions: (list(string), Dom.element) => unit;

let tab: (~shift: bool=?, ~focusTrap: Dom.element=?, unit) => unit;
