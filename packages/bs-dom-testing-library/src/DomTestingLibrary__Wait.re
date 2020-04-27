module WaitForOptions = {
  type t = {
    container: option(Dom.element),
    timeout: option(int),
    interval: option(int),
  };

  let make = (~container, ~timeout, ~interval) => {
    container,
    timeout,
    interval,
  };
};

[@bs.module "@testing-library/dom"]
external _waitFor:
  (unit => 'result, WaitForOptions.t) => Js.Promise.t('result) =
  "waitFor";

[@bs.module "@testing-library/dom"]
external _waitForElementToBeRemoved:
  (
    [@bs.unwrap] [ | `El('result) | `Fn(unit => 'result)],
    WaitForOptions.t
  ) =>
  Js.Promise.t('result) =
  "waitForElementToBeRemoved";

let waitFor =
    (
      ~container: option(Dom.element)=?,
      ~timeout: option(int)=?,
      ~interval: option(int)=?,
      callback: unit => 'result,
    )
    : Js.Promise.t('result) =>
  _waitFor(callback, WaitForOptions.make(~container, ~timeout, ~interval));

let waitForElementToBeRemoved =
    (
      ~container: option(Dom.element)=?,
      ~timeout: option(int)=?,
      ~interval: option(int)=?,
      element: 'result,
    )
    : Js.Promise.t('result) =>
  _waitForElementToBeRemoved(
    `El(element),
    WaitForOptions.make(~container, ~timeout, ~interval),
  );

let waitForElementToBeRemovedFn =
    (
      ~container: option(Dom.element)=?,
      ~timeout: option(int)=?,
      ~interval: option(int)=?,
      callback: unit => 'result,
    )
    : Js.Promise.t('result) =>
  _waitForElementToBeRemoved(
    `Fn(callback),
    WaitForOptions.make(~container, ~timeout, ~interval),
  );
