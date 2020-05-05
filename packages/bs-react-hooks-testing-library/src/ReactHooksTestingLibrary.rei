type renderResult('a);
type hookUtils('p, 'a);

let renderHook:
  (
    ~initialProps: 'p=?,
    ~wrapper: {. "children": React.element} => React.element=?,
    'p => 'a
  ) =>
  hookUtils('p, 'a);

let act: (unit => unit) => unit;

let current: hookUtils('p, 'a) => 'a;
let error: hookUtils('p, 'a) => Js.Exn.t;
let rerender: ('p, hookUtils('p, 'a)) => unit;
let unmount: hookUtils('p, 'a) => unit;

let waitForNextUpdate:
  (~timeout: int=?, ~suppressErrors: bool=?, hookUtils('p, 'a)) =>
  Js.Promise.t(unit);
let wait:
  (~timeout: int=?, ~suppressErrors: bool=?, unit => 'x, hookUtils('p, 'a)) =>
  Js.Promise.t(unit);
let waitForValueToChange:
  (~timeout: int=?, ~suppressErrors: bool=?, unit => 'x, hookUtils('p, 'a)) =>
  Js.Promise.t(unit);
