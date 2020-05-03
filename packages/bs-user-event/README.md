# @drewschrauf/bs-user-event

[@testing-library/user-event](https://github.com/testing-library/user-event) Reason/BuckleScript bindings.

## Installation

Install as a dev dependency:

```sh
npm install --save-dev @drewschrauf/bs-user-event
```

Add it to your bsconfig.json as a dev dependency.

```json
{
  ...
  "bs-dev-dependencies": [
    ...
    "@drewschrauf/bs-user-event"
  ]
}
```

## API

This documentation covers the specifics of these bindings. To learn about the principles and approach behind Testing Library, refer to the [official documentation](https://testing-library.com/).

All methods from @testing-library/user-event are implemented. Generally you'd pipe an element into the event function like below.

```reason
el |> UserEvent.click
```

If the event can take an argument, pass positional and named optional arguments like below:

```reason
el |> UserEvent.type_("text", ~delay=1000)
```

Methods that can take multiple argument types have been split into multiple assertions. For example, `selectOption` and `selectOptions` take a `string` and `list(string)` respectively. Refer to the [interface file](https://github.com/drewschrauf/bs-testing-library/blob/master/packages/bs-user-event/src/UserEvent.rei) for a full list of events.