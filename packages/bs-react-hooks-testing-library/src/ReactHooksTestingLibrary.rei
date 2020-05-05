type renderResult('result);
type hookUtils('props, 'result);

let renderHook:
  (
    ~initialProps: 'props=?,
    ~wrapper: {. "children": React.element} => React.element=?,
    'props => 'result
  ) =>
  hookUtils('props, 'result);

let act: (unit => unit) => unit;

let current: hookUtils('props, 'result) => 'result;
let error: hookUtils('props, 'result) => Js.Exn.t;
let rerender: ('props, hookUtils('props, 'result)) => unit;
let unmount: hookUtils('props, 'result) => unit;

let waitForNextUpdate:
  (~timeout: int=?, ~suppressErrors: bool=?, hookUtils('props, 'result)) =>
  Js.Promise.t(unit);
let wait:
  (
    ~timeout: int=?,
    ~suppressErrors: bool=?,
    unit => 'x,
    hookUtils('props, 'result)
  ) =>
  Js.Promise.t(unit);
let waitForValueToChange:
  (
    ~timeout: int=?,
    ~suppressErrors: bool=?,
    unit => 'x,
    hookUtils('props, 'result)
  ) =>
  Js.Promise.t(unit);
