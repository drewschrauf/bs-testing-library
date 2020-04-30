open Jest;
open Expect;
open ReactTestingLibrary;
open JestDom;

module Counter = {
  [@react.component]
  let make = () => {
    let (count, setCount) = React.useState(_ => 0);

    <div>
      <h1> {j|Count $count|j}->React.string </h1>
      <button onClick={_ => setCount(c => c + 1)}>
        "Increment"->React.string
      </button>
    </div>;
  };
};

test("render", () => {
  let root = render(<Counter />);
  expect(root) |> toBeInTheDocument;
});

test("queries", () => {
  let root = render(<Counter />);
  root |> getByText("Count 0") |> expect |> toBeInTheDocument;
});

test("firing events", () => {
  let root = render(<Counter />);
  root |> getByText("Increment") |> FireEvent.click;
  root |> getByText("Count 1") |> expect |> toBeInTheDocument;
});
