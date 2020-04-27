let waitFor:
  (
    ~container: Dom.element=?,
    ~timeout: int=?,
    ~interval: int=?,
    unit => 'result
  ) =>
  Js.Promise.t('result);

let waitForElementToBeRemoved:
  (~container: Dom.element=?, ~timeout: int=?, ~interval: int=?, 'result) =>
  Js.Promise.t('result);

let waitForElementToBeRemovedFn:
  (
    ~container: Dom.element=?,
    ~timeout: int=?,
    ~interval: int=?,
    unit => 'result
  ) =>
  Js.Promise.t('result);
