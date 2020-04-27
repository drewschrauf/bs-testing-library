open Jest;
open Expect;

let fe = [%bs.raw {| require("@testing-library/dom").fireEvent |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      fireEvent: {
        click: jest.fn(),
        change: jest.fn()
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

describe("click", () => {
  test("without options", () => {
    let result = DomTestingLibrary.FireEvent.click(el);
    [%bs.raw {| expect(fe.click).toHaveBeenCalledWith(el, undefined) |}]
    ->ignore;
    expect(result) |> toBe();
  });

  test("with options", () => {
    let result =
      DomTestingLibrary.FireEvent.click(el, ~eventInit={"test": true});
    [%bs.raw {| expect(fe.click).toHaveBeenCalledWith(el, { test: true }) |}]
    ->ignore;
    expect(result) |> toBe();
  });
});

describe("change", () => {
  test("without options", () => {
    let result = DomTestingLibrary.FireEvent.change(el);
    [%bs.raw {| expect(fe.change).toHaveBeenCalledWith(el, undefined) |}]
    ->ignore;
    expect(result) |> toBe();
  });

  test("with options", () => {
    let result =
      DomTestingLibrary.FireEvent.change(el, ~eventInit={"test": true});
    [%bs.raw {| expect(fe.change).toHaveBeenCalledWith(el, { test: true }) |}]
    ->ignore;
    expect(result) |> toBe();
  });
});
