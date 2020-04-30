open Jest;
open Expect;
open ReactTestingLibrary;
open JestDom;

/* Simple component that increments a counter when a button is clicked */
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

/*
 * reason-react doesn't support data attributes.
 * This component can be wrapped around another to add a data-testid.
 */
module WithTestId = {
  [@react.component]
  let make = (~testid, ~children) =>
    ReasonReact.cloneElement(children, ~props={"data-testid": testid}, [||]);
};

/* Simple component that shows entered text as a message */
module Message = {
  [@react.component]
  let make = () => {
    let (message, setMessage) = React.useState(_ => "");

    <div>
      <WithTestId testid="message">
        <h1> message->React.string </h1>
      </WithTestId>
      <label htmlFor="input"> "Message"->React.string </label>
      <input
        id="input"
        value=message
        onChange={e => {
          let value = e->ReactEvent.Form.target##value;
          setMessage(_ => value);
        }}
      />
    </div>;
  };
};

/* Simple component that displays a message after a short delay */
module Delay = {
  type timeoutToken;

  [@bs.val]
  external setTimeout: (unit => unit, int) => timeoutToken = "setTimeout";

  [@react.component]
  let make = () => {
    let (show, setShow) = React.useState(_ => false);
    React.useEffect1(
      () => {
        setTimeout(() => setShow(_ => true), 200)->ignore;

        None;
      },
      [||],
    );
    <div> {show ? "Done" : ""}->React.string </div>;
  };
};

module Wrapper = {
  [@react.component]
  let make = (~children) => {
    <WithTestId testid="wrapper"> <div> children </div> </WithTestId>;
  };
};

/* Async wrappers for bs-let */
module Async = {
  let let_ = (prom, cb) => Js.Promise.then_(cb, prom);

  module Wrap = {
    let let_ = (prom, cb) =>
      Js.Promise.then_(result => cb(result)->Js.Promise.resolve, prom);
  };
};

test("basic render", () => {
  render(<Counter />) |> getByText("Count 0") |> expect |> toBeInTheDocument
});

test("click event", () => {
  let root = render(<Counter />);

  root |> getByText("Increment") |> FireEvent.click;
  root |> getByText("Count 1") |> expect |> toBeInTheDocument;
});

test("change event", () => {
  let root = render(<Message />);

  root
  |> getByLabelText("Message")
  |> FireEvent.change(~eventInit={
                        "target": {
                          value: "Hello",
                        },
                      });

  root |> getByTestId("message") |> expect |> toHaveTextContent("Hello");
});

testPromise("asynchronous assertion", () => {
  let root = render(<Delay />);

  Js.Promise.(
    root
    |> findByText("Done")
    |> then_(result => result |> expect |> toBeInTheDocument |> resolve)
  );
});

testPromise("asynchronous assertion with bs-let", () => {
  let root = render(<Delay />);

  let%Async.Wrap element = root |> findByText("Done");
  element |> expect |> toBeInTheDocument;
});

test("wrapper with testid", () => {
  let root = render(<Counter />, ~wrapper=Wrapper.make);

  root |> getByTestId("wrapper") |> expect |> toBeInTheDocument;
});
