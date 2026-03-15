Unit tests for the Softloq-WHATWG-Infra library live in this folder.

Tests are built alongside the library when `SOFTLOQ_WHATWG_INFRA_BUILD_TESTS=ON` (the default). After building, run:

```bash
cd build
ctest --output-on-failure
```
