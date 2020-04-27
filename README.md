# @testing-library BuckleScript bindings

This project provide BuckleScript bindings for the [@testing-library](https://testing-library.com/) ecosystem.

- [@drewschrauf/bs-dom-testing-library](./packages/bs-dom-testing-library/README.md) - BuckleScript bindings for [@testing-library/dom](https://github.com/testing-library/dom-testing-library).
- [@drewschrauf/bs-react-testing-library](./packages/bs-react-testing-library/README.md) - BuckleScript bindings for [@testing-library/react](https://github.com/testing-library/react-testing-library)

## Motivation

This is not the only set of bindings available to use Testing Library with BuckleScript. [@wyze](https://github.com/wyze) has existing projects for [bs-dom-testing-library](https://github.com/wyze/bs-dom-testing-library), [bs-react-testing-library](https://github.com/wyze/bs-react-testing-library) and [bs-jest-dom](https://github.com/wyze/bs-jest-dom) which are linked to from the official Testing Library documentation.

These projects provide a more "literal" mapping to the underlying framework. However, the dynamic nature of JavaScript can lead to awkward ergonomics when attempting to port to BuckleScript.

This project attempts to reimagine the ecosystem to feel more natural to Reason programmers. See the individual libraries in this project for the specifics.

## Acknowledgments

@wyze - The original bindings were a great reference for marshalling techniques between the Reason and JavaScript worlds.