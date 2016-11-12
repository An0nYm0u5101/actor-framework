/******************************************************************************
 *                       ____    _    _____                                   *
 *                      / ___|  / \  |  ___|    C++                           *
 *                     | |     / _ \ | |_       Actor                         *
 *                     | |___ / ___ \|  _|      Framework                     *
 *                      \____/_/   \_|_|                                      *
 *                                                                            *
 * Copyright (C) 2011 - 2016                                                  *
 * Dominik Charousset <dominik.charousset (at) haw-hamburg.de>                *
 *                                                                            *
 * Distributed under the terms and conditions of the BSD 3-Clause License or  *
 * (at your option) under the terms and conditions of the Boost Software      *
 * License 1.0. See accompanying files LICENSE and LICENSE_ALTERNATIVE.       *
 *                                                                            *
 * If you did not receive a copy of the license files, see                    *
 * http://opensource.org/licenses/BSD-3-Clause and                            *
 * http://www.boost.org/LICENSE_1_0.txt.                                      *
 ******************************************************************************/

#ifndef CAF_IO_NETWORK_DATAGRAM_HEADER_HPP
#define CAF_IO_NETWORK_DATAGRAM_HEADER_HPP

#include <cstdint>

#include "caf/meta/type_name.hpp"

namespace caf {
namespace io {
namespace network {

/// This header adds a sequence number and response port to 
/// datagram messages carrying BASP messages.
struct datagram_header {
  uint32_t sequence_number;
  uint16_t response_port;

  inline datagram_header(uint32_t seq, uint16_t port)
      : sequence_number(seq),
        response_port(port) {
    // nop
  }

  datagram_header() = default;
};

/// @relates datagram_header
template <class Inspector>
typename Inspector::result_type inspect(Inspector& f, datagram_header& hdr) {
  return f(meta::type_name("datagram_header"), hdr.sequence_number,
           hdr.response_port);
}

/// @relates datagram_header
bool operator==(const datagram_header& lhs, const datagram_header& rhs);

/// @relates datagram_header
inline bool operator!=(const datagram_header& lhs, const datagram_header& rhs) {
  return !(lhs == rhs);
}

/// Size of the datagram header in serialized form
constexpr size_t datagram_header_size = sizeof(uint32_t) + sizeof(uint16_t);

} // namespace network
} // namespace io
} // namespace caf

#endif // CAF_IO_NETWORK_DATAGRAM_HEADER_HPP