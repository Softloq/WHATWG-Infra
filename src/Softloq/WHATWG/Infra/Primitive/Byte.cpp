#include <Softloq/WHATWG/Infra/Primitive/Byte.hpp>

namespace Softloq::WHATWG::Infra::Primitive {

bool is_ascii_byte(byte b) noexcept {
  // ASCII bytes are in the range 0x00 (NUL) to 0x7F (DEL), inclusive
  return b <= 0x7F;
}

} // namespace Softloq::WHATWG::Infra::Primitive
