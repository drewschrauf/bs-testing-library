let render:
  (
    ~container: Dom.element=?,
    ~baseElement: Dom.element=?,
    ~hydrate: bool=?,
    ReasonReact.reactElement
  ) =>
  Dom.element;

let act: (unit => unit) => unit;
