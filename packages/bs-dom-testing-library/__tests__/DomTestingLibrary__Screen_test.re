open Jest;
open ExpectJs;

open DomTestingLibrary__Screen;

[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      screen: { container: "container" },
    }))
  |}
];

test("screen", () => {
  expect(screen) |> toBeTruthy
});
