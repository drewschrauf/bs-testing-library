module RenderOptions = {
  type t = {
    container: option(Dom.element),
    baseElement: option(Dom.element),
    hydrate: option(bool),
    wrapper: option({. "children": React.element} => React.element),
  };

  let make = (~container, ~baseElement, ~hydrate, ~wrapper) => {
    container,
    baseElement,
    hydrate,
    wrapper,
  };
};

type renderResult = {container: Dom.element};

[@bs.module "@testing-library/react"]
external _render: (ReasonReact.reactElement, RenderOptions.t) => renderResult =
  "render";

[@bs.module "@testing-library/react"]
external _act: (unit => Js.Undefined.t('a)) => unit = "act";

let render =
    (
      ~container: option(Dom.element)=?,
      ~baseElement: option(Dom.element)=?,
      ~hydrate: option(bool)=?,
      ~wrapper: option({. "children": React.element} => React.element)=?,
      component: ReasonReact.reactElement,
    )
    : Dom.element =>
  _render(
    component,
    RenderOptions.make(~container, ~baseElement, ~hydrate, ~wrapper),
  ).
    container;

let act = (callback: unit => unit): unit =>
  _act(() => {
    callback();
    Js.Undefined.empty;
  });
