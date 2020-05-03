open Jest;
open Expect;
open ReactTestingLibrary;
open JestDom;

/* Super simple counter that increments on click */
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

/* Component with a text field to show how FireEvent.change works */
module Message = {
  [@react.component]
  let make = () => {
    let (message, setMessage) = React.useState(_ => "");

    <div>
      <h1> message->React.string </h1>
      <label htmlFor="message"> "Message"->React.string </label>
      <input
        id="message"
        value=message
        onChange={e => {
          let value = ReactEvent.Form.target(e)##value;
          setMessage(_ => value);
        }}
      />
    </div>;
  };
};

test("render", () =>
  render(<Counter />) |> expect |> toBeInTheDocument
);

test("query with string matcher", () =>
  render(<Counter />) |> getByText("Count 0") |> expect |> toBeInTheDocument
);

test("query with regex matcher", () =>
  render(<Counter />)
  |> getByTextRe([%re "/^Count \\d+$/"])
  |> expect
  |> toBeInTheDocument
);

test("query with function matcher", () =>
  render(<Counter />)
  |> getByTextFn((content, _) => content == "Count 0")
  |> expect
  |> toBeInTheDocument
);

test("query with options", () =>
  render(<Counter />)
  |> getByText("Count", ~exact=false, ~selector="h1")
  |> expect
  |> toBeInTheDocument
);

test("firing events", () => {
  let root = render(<Counter />);
  root |> getByText("Increment") |> FireEvent.click;
  root |> getByText("Count 1") |> expect |> toBeInTheDocument;
});

/*
 * If you're passing an object to an event, make sure you wrap the keys in double quotes. This
 * makes Reason interpret the value as a JavaScript object (Js.t) instead of a Reason record.
 */
test("firing events with options", () => {
  let root = render(<Message />);

  root
  |> getByLabelText("Message")
  |> FireEvent.change(~eventInit={
                        "target": {
                          "value": "My message",
                        },
                      });

  root |> getByText("My message") |> expect |> toBeInTheDocument;
});

/*
 * bs-jest only wants one assertion per test, right at the end. If you want multiple assertions,
 * pipe everything but the last assertion to ignore. This still runs the assertion, it just clears
 * up the type warning.
 * Reason assumes that if a function returns a value (like a Jest.assertion) and you don't do
 * anything with it, you probably made a mistake.
 */
test("multiple assertions", () => {
  let root = render(<Message />);

  let input = root |> getByLabelText("Message");

  /* here's that ignore */
  expect(input) |> toHaveValue("") |> ignore;

  input |> FireEvent.change(~eventInit={
                              "target": {
                                "value": "My message",
                              },
                            });

  expect(input) |> toHaveValue("My message");
});
