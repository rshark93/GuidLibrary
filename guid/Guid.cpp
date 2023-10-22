#include "Guid.h"

#include <chrono>
#include <iostream>
#include <string>

customShark::Guid customShark::Guid::new_guid() {
    auto guid = Guid();

    const auto time_now = std::chrono::system_clock::now();
    guid._data1 = time_point_cast<std::chrono::milliseconds>(time_now).time_since_epoch().count();
    guid._data2 = time_point_cast<std::chrono::seconds>(time_now).time_since_epoch().count();
    guid._data3 = time_point_cast<std::chrono::minutes>(time_now).time_since_epoch().count();
    return guid;
}

std::string customShark::Guid::to_string(Guid guid) {
    return value_to_hex(guid._data1) + "-"
    + value_to_hex(guid._data2) + "-"
    + value_to_hex(guid._data3);
}

template<typename T>
std::string customShark::Guid::value_to_hex(T value) {
    std::stringstream ss;
    ss << std::hex << value;
    return ss.str();
}
