//
// Created by Raman Sharkovich on 22.10.23.
//

#include "Guid.h"

#include <chrono>
#include <iostream>
#include <string>
#include <type_traits>

 customShark::Guid customShark::Guid::new_guid() {
    auto guid = Guid();

    const auto time_now = std::chrono::system_clock::now();
    guid._data1 = time_point_cast<std::chrono::microseconds>(time_now).time_since_epoch().count();
    guid._data2 = time_point_cast<std::chrono::milliseconds>(time_now).time_since_epoch().count() + rand();
    guid._data3 = time_point_cast<std::chrono::seconds>(time_now).time_since_epoch().count() + rand();
    guid._data4 = time_point_cast<std::chrono::minutes>(time_now).time_since_epoch().count() + rand();
    auto data5 = value_to_hex_str(time_point_cast<std::chrono::nanoseconds>(time_now).time_since_epoch().count());
    data5.erase(0, 4); // should be 16
    std::strcpy(guid._data5, value_to_hex_str(data5).c_str());

    return guid;
}

const std::string customShark::Guid::to_string() {
    return value_to_hex_str(this->_data1) + "-"
    + value_to_hex_str(this->_data2) + "-"
    + value_to_hex_str(this->_data3) + "-"
    + value_to_hex_str(this->_data4) + "-"
    + this->_data5;
}

template<typename T>
std::string customShark::Guid::value_to_hex_str(T value) {
    std::stringstream ss;
    ss << std::hex << value;
    auto str = ss.str();

    if (std::is_same<T, int>::value) {
        if (str.size() < 8) {
            while (str.size() < 8) {
                str.insert(0, "0");
            }
        }
    } else if (std::is_same<T, short int>::value) {
        if (str.size() < 4) {
            while (str.size() < 4) {
                str.insert(0, "0");
            }
        }
    }

    return str;
}
