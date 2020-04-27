open Jest;
open ExpectJs;

open ReactTestingLibrary__Render;

let tl = [%bs.raw {| require("@testing-library/react") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/react", () => ({
      render: jest.fn().mockImplementation(function() { return { container: "container" } })
    }))
  |}
];

let el: Dom.element = [%bs.raw {| document.createElement("div") |}];

module SimpleComponent = {
  [@react.component]
  let make = () => {
    <div />;
  };
};

module WrapperComponent = {
  [@react.component]
  let make = (~children) => {
    <div> children </div>;
  };
};

beforeEach(() => {
  %bs.raw
  {|
    jest.clearAllMocks()
  |}
});

test("render without options", () => {
  let result = render(<SimpleComponent />);
  [%bs.raw
    {|
      expect(tl.render).toHaveBeenCalledWith(expect.any(Object),  {
        container: undefined,
        baseElement: undefined,
        hydrate: undefined,
        wrapper: undefined
      })
    |}
  ]
  ->ignore;
  expect(result) |> toBeTruthy;
});

test("render with options", () => {
  let result =
    render(
      <SimpleComponent />,
      ~container=el,
      ~baseElement=el,
      ~hydrate=true,
      ~wrapper=WrapperComponent.make,
    );
  [%bs.raw
    {|
      expect(tl.render).toHaveBeenCalledWith(expect.any(Object),  {
        container: expect.any(Object),
        baseElement: expect.any(Object),
        hydrate: true,
        wrapper: expect.any(Function)
      })
    |}
  ]
  ->ignore;
  expect(result) |> toBeTruthy;
});
