# Contributing to Softloq-WHATWG-Infra

## Library Structure

This library provides two forms of support that must always be kept in sync:

- **Header-Only** — implemented in the `inline/` folder. Does not require compilation into a library.
- **Library (Static/Shared)** — headers implemented in the `include/` folder, with corresponding implementation files in the `src/` folder.

Both forms must produce the same observable output. They may differ in performance characteristics based on C++ features used (e.g. `constexpr`, inlining, visibility attributes).

---

## Development Cycle (Test-Driven Development)

All new features must follow this four-step cycle:

### Step 1 — Skeleton

Add a skeleton of the feature across both `include/`+`src/` and `inline/`. The skeleton must expose all intended functionality (classes, methods, operators) but must not yet contain working implementations. All functionality must be testable and must fail at this stage.

### Step 2 — Test Cases

Add test cases under `tests/Test-Units/` that cover the full intended behavior of the skeleton, including edge cases. All new tests must fail at this stage since the implementations are not yet complete.

### Step 3 — Implementation

Implement the working code in both `include/`+`src/` and `inline/` until all tests pass.

### Step 4 — Documentation

Document all changes. Every file must have a `@file`, `@author`, and `@brief` Doxygen tag. Every class, method, and non-trivial construct must have a Doxygen comment. Update the relevant `README.md` file trees in `include/`, `inline/`, and `src/` to reflect any added files.
