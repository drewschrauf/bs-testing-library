open Jest;
open Expect;
open ReactHooksTestingLibrary;

[@bs.val] external setTimeout: (unit => unit, int) => unit = "setTimeout";

let useWait = () => {
  let (complete, setComplete) = React.useState(_ => false);
  React.useEffect1(
    () => {
      setTimeout(() => setComplete(_ => true), 200);
      None;
    },
    [||],
  );
  complete;
};

test("current value", () => {
  let result = renderHook(() => React.useState(_ => 1));
  let (count, _) = result |> current;
  expect(count) |> toBe(1);
});

test("update with act", () => {
  let result = renderHook(() => React.useState(_ => 1));

  let (_, setCount) = result |> current;
  act(() => setCount(_ => 2));

  let (count, _) = result |> current;

  expect(count) |> toBe(2);
});

testPromise("wait", () => {
  let result = renderHook(() => useWait());

  result
  |> wait(() => result |> current != false)
  |> Js.Promise.then_(_ =>
       result |> current |> expect |> toBe(true) |> Js.Promise.resolve
     );
});

testPromise("waitForNextUpdate", () => {
  let result = renderHook(() => useWait());

  result
  |> waitForNextUpdate
  |> Js.Promise.then_(_ =>
       result |> current |> expect |> toBe(true) |> Js.Promise.resolve
     );
});

testPromise("waitForValueToChange", () => {
  let result = renderHook(() => useWait());

  result
  |> waitForValueToChange(() => result |> current)
  |> Js.Promise.then_(_ =>
       result |> current |> expect |> toBe(true) |> Js.Promise.resolve
     );
});

