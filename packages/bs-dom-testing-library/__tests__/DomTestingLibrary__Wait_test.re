open Jest;
open Expect;

open DomTestingLibrary__Wait;

let tl = [%bs.raw {| require("@testing-library/dom") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      waitFor: jest.fn().mockImplementation((cb) => Promise.resolve(cb())),
      waitForElementToBeRemoved: jest.fn().mockImplementation((cb) => Promise.resolve(typeof cb === "function" ? cb() : cb))
    }))
  |}
];
let el: Dom.element = [%bs.raw {| document.createElement("div") |}];

beforeEach(() => {
  %bs.raw
  {|
    jest.clearAllMocks()
  |}
});

describe("waitFor", () => {
  testPromise("without options", () => {
    let p = waitFor(() => "done");
    [%bs.raw
      {|
        expect(tl.waitFor).toHaveBeenCalledWith(expect.any(Function), {
          container: undefined,
          timeout: undefined,
          interval: undefined
        })
      |}
    ]
    ->ignore;
    p
    |> Js.Promise.then_(result =>
         expect(result) |> toBe("done") |> Js.Promise.resolve
       );
  });

  testPromise("with options", () => {
    let p =
      waitFor(() => "done", ~container=el, ~timeout=2000, ~interval=1000);
    [%bs.raw
      {|
        expect(tl.waitFor).toHaveBeenCalledWith(expect.any(Function), {
          container: el,
          timeout: 2000,
          interval: 1000
        })
      |}
    ]
    ->ignore;
    p
    |> Js.Promise.then_(result =>
         expect(result) |> toBe("done") |> Js.Promise.resolve
       );
  });
});

describe("waitForElementToBeRemoved", () => {
  testPromise("element without options", () => {
    let p = waitForElementToBeRemoved("done");
    [%bs.raw
      {|
        expect(tl.waitForElementToBeRemoved).toHaveBeenCalledWith("done", {
          container: undefined,
          timeout: undefined,
          interval: undefined
        })
      |}
    ]
    ->ignore;
    p
    |> Js.Promise.then_(result =>
         expect(result) |> toBe("done") |> Js.Promise.resolve
       );
  });

  testPromise("element with options", () => {
    let p =
      waitForElementToBeRemoved(
        "done",
        ~container=el,
        ~timeout=2000,
        ~interval=1000,
      );
    [%bs.raw
      {|
        expect(tl.waitForElementToBeRemoved).toHaveBeenCalledWith("done", {
          container: el,
          timeout: 2000,
          interval: 1000
        })
      |}
    ]
    ->ignore;
    p
    |> Js.Promise.then_(result =>
         expect(result) |> toBe("done") |> Js.Promise.resolve
       );
  });

  testPromise("callback without options", () => {
    let p = waitForElementToBeRemovedFn(() => "done");
    [%bs.raw
      {|
        expect(tl.waitForElementToBeRemoved).toHaveBeenCalledWith(expect.any(Function), {
          container: undefined,
          timeout: undefined,
          interval: undefined
        })
      |}
    ]
    ->ignore;
    p
    |> Js.Promise.then_(result =>
         expect(result) |> toBe("done") |> Js.Promise.resolve
       );
  });

  testPromise("callback with options", () => {
    let p =
      waitForElementToBeRemovedFn(
        () => "done",
        ~container=el,
        ~timeout=2000,
        ~interval=1000,
      );
    [%bs.raw
      {|
        expect(tl.waitForElementToBeRemoved).toHaveBeenCalledWith(expect.any(Function), {
          container: el,
          timeout: 2000,
          interval: 1000
        })
      |}
    ]
    ->ignore;
    p
    |> Js.Promise.then_(result =>
         expect(result) |> toBe("done") |> Js.Promise.resolve
       );
  });
});
