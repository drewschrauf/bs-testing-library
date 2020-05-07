open Jest;
open Expect;
open ReactHooksTestingLibrary;

let rh = [%bs.raw {| require("@testing-library/react-hooks") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/react-hooks", () => {
      const rerender = jest.fn();
      const unmount = jest.fn();
      const waitForNextUpdate = jest.fn().mockReturnValue(Promise.resolve());
      const wait = jest.fn().mockReturnValue(Promise.resolve());
      const waitForValueToChange = jest.fn().mockReturnValue(Promise.resolve());

      return {
        mocks: {
          rerender,
          unmount,
          waitForNextUpdate,
          wait,
          waitForValueToChange
        },
        act: jest.fn(),
        renderHook: jest.fn().mockReturnValue({
          result: {
            current: "value",
            error: new Error("Error")
          },
          rerender,
          unmount,
          waitForNextUpdate,
          wait,
          waitForValueToChange
        })
      }
    })
  |}
];

module Wrapper = {
  [@react.component]
  let make = (~children) => children;
};

beforeEach(() => [%bs.raw {| jest.clearAllMocks() |}]->ignore);

test("render hook without options", () => {
  renderHook(() => "value")->ignore;
  [%bs.raw
    {|
      expect(rh.renderHook).toHaveBeenCalledWith(expect.any(Function), {
        initialProps: undefined,
        wrapper: undefined
      })
  |}
  ]
  ->ignore;
  pass;
});

test("render hook with options", () => {
  renderHook(s => s, ~initialProps="initialProps", ~wrapper=Wrapper.make)
  ->ignore;
  [%bs.raw
    {|
      expect(rh.renderHook).toHaveBeenCalledWith(expect.any(Function), {
        initialProps: "initialProps",
        wrapper: Wrapper.make
      })
  |}
  ]
  ->ignore;
  pass;
});

test("current", () => {
  let result = renderHook(() => "value");
  result |> current |> expect |> toBe("value");
});

test("error", () => {
  let result = renderHook(() => "value");
  result |> error |> Js.Exn.message |> expect |> toBe(Some("Error"));
});

test("act", () => {
  act(() => ());
  [%bs.raw {| expect(rh.act).toHaveBeenCalledWith(expect.any(Function)) |}]
  ->ignore;
  pass;
});

test("rerender", () => {
  let result = renderHook(s => s);
  result |> rerender("value");
  [%bs.raw {| expect(rh.mocks.rerender).toHaveBeenCalledWith("value") |}]
  ->ignore;
  pass;
});

test("unmount", () => {
  let result = renderHook(s => s);
  result |> unmount;
  [%bs.raw {| expect(rh.mocks.unmount).toHaveBeenCalledWith() |}]->ignore;
  pass;
});

test("waitForNextUpdate without options", () => {
  let result = renderHook(s => s);
  let p = result |> waitForNextUpdate;
  [%bs.raw
    {|
      expect(rh.mocks.waitForNextUpdate).toHaveBeenCalledWith({
        timeout: undefined,
        suppressErrors: undefined
      })
    |}
  ]
  ->ignore;
  expect(p) |> toEqual(Js.Promise.resolve());
});

test("waitForNextUpdate with options", () => {
  let result = renderHook(s => s);
  let p = result |> waitForNextUpdate(~timeout=1000, ~suppressErrors=true);
  [%bs.raw
    {|
      expect(rh.mocks.waitForNextUpdate).toHaveBeenCalledWith({
        timeout: 1000,
        suppressErrors: true
      })
    |}
  ]
  ->ignore;
  expect(p) |> toEqual(Js.Promise.resolve());
});

test("wait without options", () => {
  let result = renderHook(s => s);
  let p = result |> wait(() => ());
  [%bs.raw
    {|
      expect(rh.mocks.wait).toHaveBeenCalledWith(expect.any(Function), {
        timeout: undefined,
        suppressErrors: undefined
      })
    |}
  ]
  ->ignore;
  expect(p) |> toEqual(Js.Promise.resolve());
});

test("wait with options", () => {
  let result = renderHook(s => s);
  let p = result |> wait(() => (), ~timeout=1000, ~suppressErrors=true);
  [%bs.raw
    {|
      expect(rh.mocks.wait).toHaveBeenCalledWith(expect.any(Function), {
        timeout: 1000,
        suppressErrors: true
      })
    |}
  ]
  ->ignore;
  expect(p) |> toEqual(Js.Promise.resolve());
});

test("waitForValueToChange without options", () => {
  let result = renderHook(s => s);
  let p = result |> waitForValueToChange(() => ());
  [%bs.raw
    {|
      expect(rh.mocks.waitForValueToChange).toHaveBeenCalledWith(expect.any(Function), {
        timeout: undefined,
        suppressErrors: undefined
      })
    |}
  ]
  ->ignore;
  expect(p) |> toEqual(Js.Promise.resolve());
});

test("waitForValueToChange with options", () => {
  let result = renderHook(s => s);
  let p =
    result
    |> waitForValueToChange(() => (), ~timeout=1000, ~suppressErrors=true);
  [%bs.raw
    {|
      expect(rh.mocks.waitForValueToChange).toHaveBeenCalledWith(expect.any(Function), {
        timeout: 1000,
        suppressErrors: true
      })
    |}
  ]
  ->ignore;
  expect(p) |> toEqual(Js.Promise.resolve());
});
