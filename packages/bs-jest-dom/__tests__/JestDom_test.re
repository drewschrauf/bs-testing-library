open Jest;
open Expect;

open JestDom;

let el: Dom.element = [%bs.raw {| () => document.createElement("div") |}];
let el2: Dom.element = [%bs.raw {| document.createElement("span") |}];

let jd = [%bs.raw {| require("@testing-library/jest-dom/dist/matchers") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/jest-dom/dist/matchers", () => {

      return {
        toBeDisabled: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toBeEnabled: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toBeEmpty: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toBeInTheDocument: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toBeInvalid: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toBeRequired: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toBeValid: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toBeVisible: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toContainElement: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toContainHTML: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toHaveAttribute: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toHaveClass: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toHaveFocus: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toHaveFormValues: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toHaveStyle: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toHaveTextContent: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toHaveValue: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toHaveDisplayValue: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
        toBeChecked: jest.fn().mockImplementation(() => ({ pass: true, message: () => "m" })),
      };
    })
  |}
];

beforeEach(() => {
  %bs.raw
  {|
    jest.clearAllMocks()
  |}
});

test("toBeDisabled", () => {
  el |> expect |> toBeDisabled |> ignore;
  [%bs.raw {| expect(jd.toBeDisabled).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeEnabled", () => {
  el |> expect |> toBeEnabled |> ignore;
  [%bs.raw {| expect(jd.toBeEnabled).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeEmpty", () => {
  el |> expect |> toBeEmpty |> ignore;
  [%bs.raw {| expect(jd.toBeEmpty).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeInTheDocument", () => {
  el |> expect |> toBeInTheDocument |> ignore;
  [%bs.raw {| expect(jd.toBeInTheDocument).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeInvalid", () => {
  el |> expect |> toBeInvalid |> ignore;
  [%bs.raw {| expect(jd.toBeInvalid).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeRequired", () => {
  el |> expect |> toBeRequired |> ignore;
  [%bs.raw {| expect(jd.toBeRequired).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeValid", () => {
  el |> expect |> toBeValid |> ignore;
  [%bs.raw {| expect(jd.toBeValid).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeVisible", () => {
  el |> expect |> toBeVisible |> ignore;
  [%bs.raw {| expect(jd.toBeVisible).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeVisible", () => {
  el |> expect |> toBeVisible |> ignore;
  [%bs.raw {| expect(jd.toBeVisible).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toContainElement", () => {
  el |> expect |> toContainElement(el2) |> ignore;
  [%bs.raw {| expect(jd.toContainElement).toHaveBeenCalledWith(el, el2)|}]
  ->ignore;
  pass;
});

test("toContainHTML", () => {
  el |> expect |> toContainHTML("html") |> ignore;
  [%bs.raw {| expect(jd.toContainHTML).toHaveBeenCalledWith(el, "html")|}]
  ->ignore;
  pass;
});

test("toHaveAttribute without options", () => {
  el |> expect |> toHaveAttribute("attr") |> ignore;
  [%bs.raw
    {| expect(jd.toHaveAttribute).toHaveBeenCalledWith(el, "attr", undefined)|}
  ]
  ->ignore;
  pass;
});

test("toHaveAttribute with options", () => {
  el |> expect |> toHaveAttribute("attr", ~value="value") |> ignore;
  [%bs.raw
    {| expect(jd.toHaveAttribute).toHaveBeenCalledWith(el, "attr", "value")|}
  ]
  ->ignore;
  pass;
});

test("toHaveClass without options", () => {
  el |> expect |> toHaveClass("class") |> ignore;
  [%bs.raw
    {| expect(jd.toHaveClass).toHaveBeenCalledWith(el, "class", {exact: undefined})|}
  ]
  ->ignore;
  pass;
});

test("toHaveAttribute with options", () => {
  el |> expect |> toHaveClass("class", ~exact=true) |> ignore;
  [%bs.raw
    {| expect(jd.toHaveClass).toHaveBeenCalledWith(el, "class", {exact: true})|}
  ]
  ->ignore;
  pass;
});

test("toHaveFocus", () => {
  el |> expect |> toHaveFocus |> ignore;
  [%bs.raw {| expect(jd.toHaveFocus).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toHaveFormValues", () => {
  el |> expect |> toHaveFormValues({"key": "value"}) |> ignore;
  [%bs.raw
    {| expect(jd.toHaveFormValues).toHaveBeenCalledWith(el, {"key": "value"})|}
  ]
  ->ignore;
  pass;
});

test("toHaveStyle", () => {
  el |> expect |> toHaveStyle("style") |> ignore;
  [%bs.raw {| expect(jd.toHaveStyle).toHaveBeenCalledWith(el, "style")|}]
  ->ignore;
  pass;
});

test("toHaveTextContent without options", () => {
  el |> expect |> toHaveTextContent("text") |> ignore;
  [%bs.raw
    {| expect(jd.toHaveTextContent).toHaveBeenCalledWith(el, "text", {normalizeWhitespace: undefined})|}
  ]
  ->ignore;
  pass;
});

test("toHaveTextContent with options", () => {
  el
  |> expect
  |> toHaveTextContent("text", ~normalizeWhitespace=true)
  |> ignore;
  [%bs.raw
    {| expect(jd.toHaveTextContent).toHaveBeenCalledWith(el, "text", {normalizeWhitespace: true})|}
  ]
  ->ignore;
  pass;
});

test("toHaveTextContentRe without options", () => {
  el |> expect |> toHaveTextContentRe([%re "/text/"]) |> ignore;
  [%bs.raw
    {| expect(jd.toHaveTextContent).toHaveBeenCalledWith(el, /text/, {normalizeWhitespace: undefined})|}
  ]
  ->ignore;
  pass;
});

test("toHaveTextContentRe with options", () => {
  el
  |> expect
  |> toHaveTextContentRe([%re "/text/"], ~normalizeWhitespace=true)
  |> ignore;
  [%bs.raw
    {| expect(jd.toHaveTextContent).toHaveBeenCalledWith(el, /text/, {normalizeWhitespace: true})|}
  ]
  ->ignore;
  pass;
});

test("toHaveValue", () => {
  el |> expect |> toHaveValue("value") |> ignore;
  [%bs.raw {| expect(jd.toHaveValue).toHaveBeenCalledWith(el, "value")|}]
  ->ignore;
  pass;
});

test("toHaveDisplayValue", () => {
  el |> expect |> toHaveDisplayValue("value") |> ignore;
  [%bs.raw
    {| expect(jd.toHaveDisplayValue).toHaveBeenCalledWith(el, "value")|}
  ]
  ->ignore;
  pass;
});

test("toBeChecked", () => {
  el |> expect |> toBeChecked |> ignore;
  [%bs.raw {| expect(jd.toBeChecked).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});
