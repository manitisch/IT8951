//
// Copyright (c) 2023 Manuel Tischhauser
//
// Distributed under the MIT Software License
// See accompanying file LICENSE or copy at
// https://opensource.org/licenses/MIT
//
// See the documentation for more information
//

#ifndef MATI_IT8951_H
#define MATI_IT8951_H

#include <string>
#include <cstdint>
#include <span>
#include <atomic>

#include "ISpi.h"
#include "IGpio.h"

namespace mati {

template<uint32_t BufferSize>
class IT8951 {
  public:
    enum class Status {
        ok = 0,
        busy,
        error
    };

    struct DeviceInfo {
        DeviceInfo(uint16_t width, uint16_t height, uint32_t imageBufferAddress, std::string firmwareVersion, std::string lutVersion) : 
                   width_{width}, height_{height}, imageBufferAddress_{imageBufferAddress}, firmwareVersion_{firmwareVersion}, lutVersion_{lutVersion} {};

        const uint16_t width_;
        const uint16_t height_;
        const uint16_t imageBufferAddress_;
        const std::string firmwareVersion_;
        const std::string lutVersion_;
    };

    IT8951(hardware_abstraction::ISpi& spi, hardware_abstraction::IGpio& resetPin, hardware_abstraction::IGpio& busyPin);
    IT8951(const IT8951&) = delete;
    IT8951(IT8951&&) = delete;
    IT8951& operator=(const IT8951&) = delete;
    IT8951& operator=(IT8951&&) = delete;

    Status wakeUp();
    Status standby();
    void reset();
    DeviceInfo getDeviceInfo();   
    Status setVcom(const float vcom);
    // TODO: document the following
    Status writeImage(const std::span<uint16_t> image, const uint16_t xCoordinate, const uint16_t yCoordinate, const uint16_t width, const uint16_t height);
    Status display(const uint16_t xCoordinate, const uint16_t yCoordinate, const uint16_t width, const uint16_t height);
    Status clear(const uint16_t xCoordinate, const uint16_t yCoordinate, const uint16_t width, const uint16_t height);

  private:
    float getVcom(); // TODO: is this needed?
    Status enablePackedMode();
    Status disablePackedMode(); // TODO: is this needed?

    std::atomic_flag busyFlag_;
    hardware_abstraction::ISpi& spi_;
    hardware_abstraction::IGpio& resetPin_;
    hardware_abstraction::IGpio& busyPin_;
};

template<uint32_t BufferSize>
IT8951<BufferSize>::IT8951(hardware_abstraction::ISpi& spi, hardware_abstraction::IGpio& resetPin, hardware_abstraction::IGpio& busyPin) : 
    spi_{spi}, resetPin_{resetPin}, busyPin_{busyPin} {}

template<uint32_t BufferSize>
IT8951<BufferSize>::Status IT8951<BufferSize>::wakeUp() {
    // TODO   
}

template<uint32_t BufferSize>
IT8951<BufferSize>::Status IT8951<BufferSize>::standby() {
    // TODO
}

template<uint32_t BufferSize>
void IT8951<BufferSize>::reset() {
    // TODO
}

template<uint32_t BufferSize>
IT8951<BufferSize>::DeviceInfo IT8951<BufferSize>::getDeviceInfo() {
    // TODO
}

template<uint32_t BufferSize>
IT8951<BufferSize>::Status IT8951<BufferSize>::setVcom(const float vcom) {
    // TODO
}

template<uint32_t BufferSize>
IT8951<BufferSize>::Status IT8951<BufferSize>::writeImage(const std::span<uint16_t> image, const uint16_t xCoordinate, const uint16_t yCoordinate, const uint16_t width, const uint16_t height) {
    // TODO
}

template<uint32_t BufferSize>
IT8951<BufferSize>::Status IT8951<BufferSize>::display(const uint16_t xCoordinate, const uint16_t yCoordinate, const uint16_t width, const uint16_t height) {
    // TODO
}

template<uint32_t BufferSize>
IT8951<BufferSize>::Status IT8951<BufferSize>::clear(const uint16_t xCoordinate, const uint16_t yCoordinate, const uint16_t width, const uint16_t height) {
    // TODO
}

} // mati

#endif // MATI_IT8951_H