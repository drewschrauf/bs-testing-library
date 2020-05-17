open Jest;
open Expect;
open ReactTestingLibrary;
open JestDom;

/* Async wrappers for bs-let */
module Async = {
  let let_ = (prom, cb) => Js.Promise.then_(cb, prom);

  module Wrap = {
    let let_ = (prom, cb) =>
      Js.Promise.then_(result => cb(result)->Js.Promise.resolve, prom);
  };
};

/* Counter that waits a bit before incrementing */
module SlowCounter = {
  type timerToken;
  [@bs.val]
  external setTimeout: (unit => unit, int) => timerToken = "setTimeout";

  type counterState = {
    count: int,
    pending: bool,
  };
  type counterActions =
    | StartIncrement
    | EndIncrement;

  [@react.component]
  let make = () => {
    let ({count, pending}, dispatch) =
      React.useReducer(
        (state, action) =>
          switch (action) {
          | StartIncrement => {...state, pending: true}
          | EndIncrement => {count: state.count + 1, pending: false}
          },
        {count: 0, pending: false},
      );

    let increment = _ => {
      dispatch(StartIncrement);
      setTimeout(() => dispatch(EndIncrement), 100)->ignore;
    };

    <div>
      <h1> {j|Count $count|j}->React.string </h1>
      <button disabled=pending onClick=increment>
        "Increment"->React.string
      </button>
    </div>;
  };
};

testPromise("async assertion", () => {
  render(<SlowCounter />) |> ignore;
  screen |> getByText("Increment") |> UserEvent.click;
  screen
  |> findByText("Count 1")
  |> Js.Promise.then_(count =>
       expect(count) |> toBeInTheDocument |> Js.Promise.resolve
     );
});

testPromise("async assertion with bs-let", () => {
  render(<SlowCounter />) |> ignore;
  screen |> getByText("Increment") |> UserEvent.click;
  let%Async.Wrap count = screen |> findByText("Count 1");
  expect(count) |> toBeInTheDocument;
});

testPromise("async chaining", () => {
  render(<SlowCounter />) |> ignore;
  let button = screen |> getByText("Increment");
  button |> UserEvent.click;
  screen
  |> findByText("Count 1")
  |> Js.Promise.then_(_ => {
       button |> UserEvent.click;
       screen |> findByText("Count 2");
     })
  |> Js.Promise.then_(count =>
       expect(count) |> toBeInTheDocument |> Js.Promise.resolve
     );
});

testPromise("async chaining with bs-let", () => {
  render(<SlowCounter />) |> ignore;
  let button = screen |> getByText("Increment");

  button |> UserEvent.click;
  let%Async _ = screen |> findByText("Count 1");

  button |> UserEvent.click;
  let%Async.Wrap count = screen |> findByText("Count 2");

  expect(count) |> toBeInTheDocument;
});

testPromise("waitFor", () => {
  render(<SlowCounter />) |> ignore;

  screen |> getByText("Increment") |> UserEvent.click;

  waitFor(() => screen |> getByText("Count 1"))
  |> Js.Promise.then_(count =>
       expect(count) |> toBeInTheDocument |> Js.Promise.resolve
     );
});

testPromise("waitFor with bs-let", () => {
  render(<SlowCounter />) |> ignore;

  screen |> getByText("Increment") |> UserEvent.click;

  let%Async.Wrap count = waitFor(() => screen |> getByText("Count 1"));
  expect(count) |> toBeInTheDocument;
});
