# Softloq-WHATWG-Infra Roadmap

This document tracks the development progression of the library, following the [WHATWG Infra specification](https://infra.spec.whatwg.org/).

---

## Phase 1 — Primitive Data Types

Each primitive requires both an implementation and test case coverage.

| Primitive | Skeleton | Test Cases | Implementation | Pass Tests |
|-----------|:--------:|:----------:|:--------------:|:----------:|
| Null | ✅ | ✅ | ✅ | ✅ |
| Boolean | ✅ | ✅ | ✅ | ✅ |
| Byte | ✅ | ✅ | ✅ | ✅ |
| Byte Sequence | ✅ | ✅ | ☐ | ☐ |
| Code Point | ✅ | ✅ | ✅ | ✅ |
| String | ☐ | ☐ | ☐ | ☐ |
| Number (Integer types) | ✅ | ✅ | ✅ | ✅ |

---

## Phase 1.5 — Primitive Interop

Operations that depend on multiple primitives being available. Each operation requires both an implementation and test case coverage.

| Operation | Skeleton | Test Cases | Implementation | Pass Tests |
|-----------|:--------:|:----------:|:--------------:|:----------:|
| Isomorphic Decode (ByteSequence → String) | ☐ | ☐ | ☐ | ☐ |

> **Note:** Isomorphic decode is defined by the WHATWG Infra specification as converting a byte sequence to a string by mapping each byte to the corresponding Unicode code point. It requires the String primitive (Phase 1) to be implemented first.

---

## Phase 2 — Data Structures

Each data structure requires both an implementation and test case coverage.

| Data Structure | Skeleton | Test Cases | Implementation | Pass Tests |
|----------------|:--------:|:----------:|:--------------:|:----------:|
| List | ☐ | ☐ | ☐ | ☐ |
| Stack | ☐ | ☐ | ☐ | ☐ |
| Queue | ☐ | ☐ | ☐ | ☐ |
| Set | ☐ | ☐ | ☐ | ☐ |
| Map | ☐ | ☐ | ☐ | ☐ |
| Tuple | ☐ | ☐ | ☐ | ☐ |
