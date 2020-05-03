open Jest;
open Expect;

let ue = [%bs.raw {| require("@testing-library/user-event") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/user-event", () => ({
      default: {
        click: jest.fn(),
        dblClick: jest.fn(),
        type: jest.fn().mockReturnValue(Promise.resolve()),
        clear: jest.fn(),
        selectOptions: jest.fn(),
        tab: jest.fn()
      }
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

test("click", () => {
  let result = UserEvent.click(el);
  [%bs.raw {| expect(ue.default.click).toHaveBeenCalledWith(el) |}]->ignore;
  expect(result) |> toBe();
});

test("dblClick", () => {
  let result = UserEvent.dblClick(el);
  [%bs.raw {| expect(ue.default.dblClick).toHaveBeenCalledWith(el) |}]->ignore;
  expect(result) |> toBe();
});

testPromise("type without options", () => {
  let result = UserEvent.type_("text", el);
  [%bs.raw
    {|
    expect(ue.default.type).toHaveBeenCalledWith(el, "text", {
      allAtOnce: undefined,
      delay: undefined
    })
  |}
  ]
  ->ignore;
  result |> Js.Promise.then_(r => expect(r) |> toBe() |> Js.Promise.resolve);
});

testPromise("type with options", () => {
  let result = UserEvent.type_("text", el, ~allAtOnce=true, ~delay=1000);
  [%bs.raw
    {|
    expect(ue.default.type).toHaveBeenCalledWith(el, "text", {
      allAtOnce: true,
      delay: 1000
    })
  |}
  ]
  ->ignore;
  result |> Js.Promise.then_(r => expect(r) |> toBe() |> Js.Promise.resolve);
});

test("clear", () => {
  let result = UserEvent.clear(el);
  [%bs.raw {| expect(ue.default.clear).toHaveBeenCalledWith(el) |}]->ignore;
  expect(result) |> toBe();
});

test("selectOption", () => {
  let result = UserEvent.selectOption("value", el);
  [%bs.raw
    {| expect(ue.default.selectOptions).toHaveBeenCalledWith(el, "value") |}
  ]
  ->ignore;
  expect(result) |> toBe();
});

test("selectOptions", () => {
  let result = UserEvent.selectOptions(["value1", "value2"], el);
  [%bs.raw
    {| expect(ue.default.selectOptions).toHaveBeenCalledWith(el, ["value1", "value2"]) |}
  ]
  ->ignore;
  expect(result) |> toBe();
});

test("tab without options", () => {
  let result = UserEvent.tab();
  [%bs.raw
    {| expect(ue.default.tab).toHaveBeenCalledWith({ shift: undefined, focusTrap: undefined }) |}
  ]
  ->ignore;
  expect(result) |> toBe();
});

test("tab with options", () => {
  let result = UserEvent.tab(~shift=true, ~focusTrap=el, ());
  [%bs.raw
    {| expect(ue.default.tab).toHaveBeenCalledWith({ shift: true, focusTrap: el }) |}
  ]
  ->ignore;
  expect(result) |> toBe();
});
