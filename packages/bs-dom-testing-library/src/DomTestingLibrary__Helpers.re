[@bs.module "@testing-library/dom"]
external _prettyDOM: (Dom.element, Js.Undefined.t(int)) => string =
  "prettyDOM";

let prettyDOM = (~maxLength: option(int)=?, node: Dom.element): string =>
  _prettyDOM(node, maxLength->Js.Undefined.fromOption);

let debug = (~maxLength: option(int)=?, node: Dom.element): unit =>
  _prettyDOM(node, maxLength->Js.Undefined.fromOption)->Js.log;
