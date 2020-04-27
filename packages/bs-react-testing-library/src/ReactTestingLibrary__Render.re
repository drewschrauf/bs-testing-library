type renderResult = {container: Dom.element};

[@bs.module "@testing-library/react"]
external _render: ReasonReact.reactElement => renderResult = "render";

[@bs.module "@testing-library/react"]
external _act: (unit => Js.Undefined.t('a)) => unit = "act";

let render = (component: ReasonReact.reactElement): Dom.element =>
  _render(component).container;

let act = (callback: unit => unit): unit =>
  _act(() => {
    callback();
    Js.Undefined.empty;
  });
