open Jest;
open Expect;
open ReactTestingLibrary;
open JestDom;

/*
 * reason-react doesn't support data attributes.
 * This component can be wrapped around another to add a data-testid.
 */
module WithTestId = {
  [@react.component]
  let make = (~testid, ~children) =>
    ReasonReact.cloneElement(children, ~props={"data-testid": testid}, [||]);
};

/* note that WithTestId has been wrapped **around** the heading */
module TestIdExample = {
  [@react.component]
  let make = () =>
    <div>
      <WithTestId testid="my-test-id">
        <h1> "Heading"->React.string </h1>
      </WithTestId>
    </div>;
};

test("getByTestId", () => {
  let root = render(<TestIdExample />);
  root |> getByTestId("my-test-id") |> expect |> toHaveTextContent("Heading");
});
