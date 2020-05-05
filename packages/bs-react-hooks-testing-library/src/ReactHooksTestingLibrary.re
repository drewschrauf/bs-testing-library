type waitOptions = {
  timeout: option(int),
  suppressErrors: option(bool),
};
type renderHookOptions('props) = {
  initialProps: option('props),
  wrapper: option({. "children": React.element} => React.element),
};
type renderResult('result);
type hookUtils('props, 'result);

[@bs.module "@testing-library/react-hooks"]
external _renderHook:
  ('props => 'result, renderHookOptions('props)) =>
  hookUtils('props, 'result) =
  "renderHook";
[@bs.module "@testing-library/react-hooks"]
external act: (unit => unit) => unit = "act";
[@bs.get]
external result: hookUtils('props, 'result) => renderResult('result) =
  "result";
[@bs.send.pipe: hookUtils('props, 'result)]
external rerender: 'props => unit = "rerender";
[@bs.send] external unmount: hookUtils('props, 'result) => unit = "unmount";
[@bs.send.pipe: hookUtils('props, 'result)]
external _waitForNextUpdate: waitOptions => Js.Promise.t(unit) =
  "waitForNextUpdate";
[@bs.send.pipe: hookUtils('props, 'result)]
external _wait: (unit => 'x, waitOptions) => Js.Promise.t(unit) = "wait";
[@bs.send.pipe: hookUtils('props, 'result)]
external _waitForValueToChange:
  (unit => 'x, waitOptions) => Js.Promise.t(unit) =
  "waitForValueToChange";
[@bs.get] external _current: renderResult('result) => 'result = "current";
[@bs.get] external _error: renderResult('result) => Js.Exn.t = "error";

let renderHook =
    (
      ~initialProps: option('props)=?,
      ~wrapper: option({. "children": React.element} => React.element)=?,
      cb: 'props => 'result,
    )
    : hookUtils('props, 'result) =>
  _renderHook(cb, {initialProps, wrapper});

let current = (r: hookUtils('props, 'result)): 'result =>
  r |> result |> _current;

let error = (r: hookUtils('props, 'result)): Js.Exn.t =>
  r |> result |> _error;

let waitForNextUpdate =
    (
      ~timeout: option(int)=?,
      ~suppressErrors: option(bool)=?,
      r: hookUtils('props, 'result),
    )
    : Js.Promise.t(unit) =>
  r |> _waitForNextUpdate({timeout, suppressErrors});

let wait =
    (
      ~timeout: option(int)=?,
      ~suppressErrors: option(bool)=?,
      cb: unit => 'any,
      r: hookUtils('props, 'result),
    )
    : Js.Promise.t(unit) =>
  r |> _wait(cb, {timeout, suppressErrors});

let waitForValueToChange =
    (
      ~timeout: option(int)=?,
      ~suppressErrors: option(bool)=?,
      cb: unit => 'any,
      r: hookUtils('props, 'result),
    )
    : Js.Promise.t(unit) =>
  r |> _waitForValueToChange(cb, {timeout, suppressErrors});
