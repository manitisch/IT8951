//
// Copyright (c) 2023 Manuel Tischhauser
//
// Distributed under the GNU GENERAL PUBLIC LICENSE Version 3
// See accompanying file LICENSE-example or copy at
// https://www.gnu.org/licenses/gpl-3.0.html
//
// A class which provides GPIO access.
//

#ifndef MATI_HARDWARE_ABSTRACTION_GPIO_H
#define MATI_HARDWARE_ABSTRACTION_GPIO_H

#include <atomic>
#include <cstdint>
#include <functional>
#include <thread>

#include "IGpio.h"

namespace mati::hardware_abstraction {

class Gpio : public IGpio {
  public:
    enum class Functionality {
        input = 0,
        output   
    };

    Gpio(const uint32_t pin, const Functionality functionality);
    ~Gpio();

    void write(const bool level) noexcept override;
    bool read() noexcept override;
    void setRisingEdgeCallback(std::function<void(void)>&& callback) noexcept override;

  private:
    void detectRisingEdge();

    const uint32_t pin_;
    std::function<void(void)> callback_;
    std::thread edgeDetector_;
    std::atomic_bool isRunning_;
};

} // namespace mati::hardware_abstraction

#endif // MATI_HARDWARE_ABSTRACTION_GPIO_H