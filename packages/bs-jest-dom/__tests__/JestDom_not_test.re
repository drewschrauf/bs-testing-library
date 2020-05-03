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
        toBeDisabled: jest.fn().mockImplementation(() => ({ pass: false })),
        toBeEnabled: jest.fn().mockImplementation(() => ({ pass: false })),
        toBeEmpty: jest.fn().mockImplementation(() => ({ pass: false })),
        toBeInTheDocument: jest.fn().mockImplementation(() => ({ pass: false })),
        toBeInvalid: jest.fn().mockImplementation(() => ({ pass: false })),
        toBeRequired: jest.fn().mockImplementation(() => ({ pass: false })),
        toBeValid: jest.fn().mockImplementation(() => ({ pass: false })),
        toBeVisible: jest.fn().mockImplementation(() => ({ pass: false })),
        toContainElement: jest.fn().mockImplementation(() => ({ pass: false })),
        toContainHTML: jest.fn().mockImplementation(() => ({ pass: false })),
        toHaveAttribute: jest.fn().mockImplementation(() => ({ pass: false })),
        toHaveClass: jest.fn().mockImplementation(() => ({ pass: false })),
        toHaveFocus: jest.fn().mockImplementation(() => ({ pass: false })),
        toHaveFormValues: jest.fn().mockImplementation(() => ({ pass: false })),
        toHaveStyle: jest.fn().mockImplementation(() => ({ pass: false })),
        toHaveTextContent: jest.fn().mockImplementation(() => ({ pass: false })),
        toHaveValue: jest.fn().mockImplementation(() => ({ pass: false })),
        toHaveDisplayValue: jest.fn().mockImplementation(() => ({ pass: false })),
        toBeChecked: jest.fn().mockImplementation(() => ({ pass: false })),
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
  el |> expect |> not |> toBeDisabled |> ignore;
  [%bs.raw {| expect(jd.toBeDisabled).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeEnabled", () => {
  el |> expect |> not |> toBeEnabled |> ignore;
  [%bs.raw {| expect(jd.toBeEnabled).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeEmpty", () => {
  el |> expect |> not |> toBeEmpty |> ignore;
  [%bs.raw {| expect(jd.toBeEmpty).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeInTheDocument", () => {
  el |> expect |> not |> toBeInTheDocument |> ignore;
  [%bs.raw {| expect(jd.toBeInTheDocument).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeInvalid", () => {
  el |> expect |> not |> toBeInvalid |> ignore;
  [%bs.raw {| expect(jd.toBeInvalid).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeRequired", () => {
  el |> expect |> not |> toBeRequired |> ignore;
  [%bs.raw {| expect(jd.toBeRequired).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeValid", () => {
  el |> expect |> not |> toBeValid |> ignore;
  [%bs.raw {| expect(jd.toBeValid).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeVisible", () => {
  el |> expect |> not |> toBeVisible |> ignore;
  [%bs.raw {| expect(jd.toBeVisible).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toBeVisible", () => {
  el |> expect |> not |> toBeVisible |> ignore;
  [%bs.raw {| expect(jd.toBeVisible).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toContainElement", () => {
  el |> expect |> not |> toContainElement(el2) |> ignore;
  [%bs.raw {| expect(jd.toContainElement).toHaveBeenCalledWith(el, el2)|}]
  ->ignore;
  pass;
});

test("toContainHTML", () => {
  el |> expect |> not |> toContainHTML("html") |> ignore;
  [%bs.raw {| expect(jd.toContainHTML).toHaveBeenCalledWith(el, "html")|}]
  ->ignore;
  pass;
});

test("toHaveAttribute without options", () => {
  el |> expect |> not |> toHaveAttribute("attr") |> ignore;
  [%bs.raw
    {| expect(jd.toHaveAttribute).toHaveBeenCalledWith(el, "attr", undefined)|}
  ]
  ->ignore;
  pass;
});

test("toHaveAttribute with options", () => {
  el |> expect |> not |> toHaveAttribute("attr", ~value="value") |> ignore;
  [%bs.raw
    {| expect(jd.toHaveAttribute).toHaveBeenCalledWith(el, "attr", "value")|}
  ]
  ->ignore;
  pass;
});

test("toHaveClass without options", () => {
  el |> expect |> not |> toHaveClass("class") |> ignore;
  [%bs.raw
    {| expect(jd.toHaveClass).toHaveBeenCalledWith(el, "class", {exact: undefined})|}
  ]
  ->ignore;
  pass;
});

test("toHaveClass with options", () => {
  el |> expect |> not |> toHaveClass("class", ~exact=true) |> ignore;
  [%bs.raw
    {| expect(jd.toHaveClass).toHaveBeenCalledWith(el, "class", {exact: true})|}
  ]
  ->ignore;
  pass;
});

test("toHaveClasses without options", () => {
  el |> expect |> not |> toHaveClasses(["class1", "class2"]) |> ignore;
  [%bs.raw
    {| expect(jd.toHaveClass).toHaveBeenCalledWith(el, ["class1", "class2"], {exact: undefined})|}
  ]
  ->ignore;
  pass;
});

test("toHaveClasses with options", () => {
  el
  |> expect
  |> not
  |> toHaveClasses(["class1", "class2"], ~exact=true)
  |> ignore;
  [%bs.raw
    {| expect(jd.toHaveClass).toHaveBeenCalledWith(el, ["class1", "class2"], {exact: true})|}
  ]
  ->ignore;
  pass;
});

test("toHaveFocus", () => {
  el |> expect |> not |> toHaveFocus |> ignore;
  [%bs.raw {| expect(jd.toHaveFocus).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});

test("toHaveFormValues", () => {
  el |> expect |> not |> toHaveFormValues({"key": "value"}) |> ignore;
  [%bs.raw
    {| expect(jd.toHaveFormValues).toHaveBeenCalledWith(el, {"key": "value"})|}
  ]
  ->ignore;
  pass;
});

test("toHaveStyle", () => {
  el |> expect |> not |> toHaveStyle("style") |> ignore;
  [%bs.raw {| expect(jd.toHaveStyle).toHaveBeenCalledWith(el, "style")|}]
  ->ignore;
  pass;
});

test("toHaveStyles", () => {
  el
  |> expect
  |> not
  |> toHaveStyles({"style1": "value1", "style2": "value2"})
  |> ignore;
  [%bs.raw
    {| expect(jd.toHaveStyle).toHaveBeenCalledWith(el, {
      style1: "value1",
      style2: "value2"
    })|}
  ]
  ->ignore;
  pass;
});

test("toHaveTextContent without options", () => {
  el |> expect |> not |> toHaveTextContent("text") |> ignore;
  [%bs.raw
    {| expect(jd.toHaveTextContent).toHaveBeenCalledWith(el, "text", {normalizeWhitespace: undefined})|}
  ]
  ->ignore;
  pass;
});

test("toHaveTextContent with options", () => {
  el
  |> expect
  |> not
  |> toHaveTextContent("text", ~normalizeWhitespace=true)
  |> ignore;
  [%bs.raw
    {| expect(jd.toHaveTextContent).toHaveBeenCalledWith(el, "text", {normalizeWhitespace: true})|}
  ]
  ->ignore;
  pass;
});

test("toHaveTextContentRe without options", () => {
  el |> expect |> not |> toHaveTextContentRe([%re "/text/"]) |> ignore;
  [%bs.raw
    {| expect(jd.toHaveTextContent).toHaveBeenCalledWith(el, /text/, {normalizeWhitespace: undefined})|}
  ]
  ->ignore;
  pass;
});

test("toHaveTextContentRe with options", () => {
  el
  |> expect
  |> not
  |> toHaveTextContentRe([%re "/text/"], ~normalizeWhitespace=true)
  |> ignore;
  [%bs.raw
    {| expect(jd.toHaveTextContent).toHaveBeenCalledWith(el, /text/, {normalizeWhitespace: true})|}
  ]
  ->ignore;
  pass;
});

test("toHaveValue", () => {
  el |> expect |> not |> toHaveValue("value") |> ignore;
  [%bs.raw {| expect(jd.toHaveValue).toHaveBeenCalledWith(el, "value")|}]
  ->ignore;
  pass;
});

test("toHaveValueOfType string", () => {
  el |> expect |> not |> toHaveValueOfType(`str("value")) |> ignore;
  [%bs.raw {| expect(jd.toHaveValue).toHaveBeenCalledWith(el, "value")|}]
  ->ignore;
  pass;
});

test("toHaveValueOfType string array", () => {
  el |> expect |> not |> toHaveValueOfType(`array([|"value"|])) |> ignore;
  [%bs.raw {| expect(jd.toHaveValue).toHaveBeenCalledWith(el, ["value"])|}]
  ->ignore;
  pass;
});

test("toHaveValueOfType int", () => {
  el |> expect |> not |> toHaveValueOfType(`int(1)) |> ignore;
  [%bs.raw {| expect(jd.toHaveValue).toHaveBeenCalledWith(el, 1)|}]->ignore;
  pass;
});

test("toHaveValueOfType float", () => {
  el |> expect |> not |> toHaveValueOfType(`float(1.5)) |> ignore;
  [%bs.raw {| expect(jd.toHaveValue).toHaveBeenCalledWith(el, 1.5)|}]->ignore;
  pass;
});

test("toHaveDisplayValue", () => {
  el |> expect |> not |> toHaveDisplayValue("value") |> ignore;
  [%bs.raw
    {| expect(jd.toHaveDisplayValue).toHaveBeenCalledWith(el, "value")|}
  ]
  ->ignore;
  pass;
});

test("toHaveDisplayValues", () => {
  el |> expect |> not |> toHaveDisplayValues(["value1", "value2"]) |> ignore;
  [%bs.raw
    {| expect(jd.toHaveDisplayValue).toHaveBeenCalledWith(el, ["value1", "value2"])|}
  ]
  ->ignore;
  pass;
});

test("toBeChecked", () => {
  el |> expect |> not |> toBeChecked |> ignore;
  [%bs.raw {| expect(jd.toBeChecked).toHaveBeenCalledWith(el)|}]->ignore;
  pass;
});
