//
// Copyright (c) 2023 Manuel Tischhauser
//
// Distributed under the MIT Software License
// See accompanying file LICENSE or copy at
// https://opensource.org/licenses/MIT
//
// See the documentation for more information
//

#ifndef MATI_HARDWARE_ABSTRACTION_ISPI_H
#define MATI_HARDWARE_ABSTRACTION_ISPI_H

#include <span>
#include <cstint>

namespace mati::hardware_abstraction {

class ISpi {
  public:
    virtual bool transfer(std::span<uint16_t> txBuffer, const std::span<uint16_t> rxBuffer) noexcept = 0;
};

} // mati::hardware_abstraction

#endif // MATI_HARDWARE_ABSTRACTION_ISPI_H