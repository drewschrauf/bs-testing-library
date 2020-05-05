type waitOptions = {
  timeout: option(int),
  suppressErrors: option(bool),
};
type renderHookOptions('p) = {
  initialProps: option('p),
  wrapper: option({. "children": React.element} => React.element),
};
type renderResult('a);
type hookUtils('p, 'a);

[@bs.module "@testing-library/react-hooks"]
external _renderHook: ('p => 'a, renderHookOptions('p)) => hookUtils('p, 'a) =
  "renderHook";
[@bs.module "@testing-library/react-hooks"]
external act: (unit => unit) => unit = "act";
[@bs.get] external result: hookUtils('p, 'a) => renderResult('a) = "result";
[@bs.send.pipe: hookUtils('p, 'a)] external rerender: 'p => unit = "rerender";
[@bs.send] external unmount: hookUtils('p, 'a) => unit = "unmount";
[@bs.send.pipe: hookUtils('p, 'a)]
external _waitForNextUpdate: waitOptions => Js.Promise.t(unit) =
  "waitForNextUpdate";
[@bs.send.pipe: hookUtils('p, 'a)]
external _wait: (unit => 'x, waitOptions) => Js.Promise.t(unit) = "wait";
[@bs.send.pipe: hookUtils('p, 'a)]
external _waitForValueToChange:
  (unit => 'x, waitOptions) => Js.Promise.t(unit) =
  "waitForValueToChange";
[@bs.get] external _current: renderResult('a) => 'a = "current";
[@bs.get] external _error: renderResult('a) => Js.Exn.t = "error";

let renderHook =
    (
      ~initialProps: option('p)=?,
      ~wrapper: option({. "children": React.element} => React.element)=?,
      cb: 'p => 'a,
    )
    : hookUtils('p, 'a) =>
  _renderHook(cb, {initialProps, wrapper});

let current = (r: hookUtils('p, 'a)): 'a => r |> result |> _current;

let error = (r: hookUtils('p, 'a)): Js.Exn.t => r |> result |> _error;

let waitForNextUpdate =
    (
      ~timeout: option(int)=?,
      ~suppressErrors: option(bool)=?,
      r: hookUtils('p, 'a),
    )
    : Js.Promise.t(unit) =>
  r |> _waitForNextUpdate({timeout, suppressErrors});

let wait =
    (
      ~timeout: option(int)=?,
      ~suppressErrors: option(bool)=?,
      cb: unit => 'x,
      r: hookUtils('p, 'a),
    )
    : Js.Promise.t(unit) =>
  r |> _wait(cb, {timeout, suppressErrors});

let waitForValueToChange =
    (
      ~timeout: option(int)=?,
      ~suppressErrors: option(bool)=?,
      cb: unit => 'x,
      r: hookUtils('p, 'a),
    )
    : Js.Promise.t(unit) =>
  r |> _waitForValueToChange(cb, {timeout, suppressErrors});
