open Jest;
open Expect;

open DomTestingLibrary__Helpers;

let tl = [%bs.raw {| require("@testing-library/dom") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      prettyDOM: jest.fn().mockImplementation(function(el, number, opts) { return "prettyDOM" })
    }))
  |}
];
[%bs.raw {|
  console.log = jest.fn()
|}];

let root: Dom.element = [%bs.raw {| document.createElement("div") |}];

beforeEach(() => {
  %bs.raw
  {|
    jest.clearAllMocks()
  |}
});

test("prettyDOM without options", () => {
  let result = prettyDOM(root);
  [%bs.raw
    {|
      expect(tl.prettyDOM).toHaveBeenCalledWith(root, undefined)
    |}
  ]
  ->ignore;
  result |> expect |> toBe("prettyDOM");
});

test("prettyDOM with options", () => {
  let result = prettyDOM(root, ~maxLength=1000);
  [%bs.raw
    {|
      expect(tl.prettyDOM).toHaveBeenCalledWith(root, 1000)
    |}
  ]
  ->ignore;
  result |> expect |> toBe("prettyDOM");
});

test("debug without options", () => {
  debug(root);
  [%bs.raw
    {|
      expect(console.log).toHaveBeenCalledWith("prettyDOM")
    |}
  ]
  ->ignore;
  expect(true) |> toBe(true);
});

test("debug with options", () => {
  debug(root, ~maxLength=1000);
  [%bs.raw
    {|
      expect(console.log).toHaveBeenCalledWith("prettyDOM")
    |}
  ]
  ->ignore;
  expect(true) |> toBe(true);
});
