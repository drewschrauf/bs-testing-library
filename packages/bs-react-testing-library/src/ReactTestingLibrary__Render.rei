let render:
  (
    ~container: Dom.element=?,
    ~baseElement: Dom.element=?,
    ~hydrate: bool=?,
    ~wrapper: {. "children": React.element} => React.element=?,
    ReasonReact.reactElement
  ) =>
  Dom.element;

let act: (unit => unit) => unit;
