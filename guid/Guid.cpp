//
// Created by Raman Sharkovich on 22.10.23.
//

#include "Guid.h"

#include <chrono>
#include <iostream>
#include <string>
#include <type_traits>

customShark::Guid::Guid() {}

customShark::Guid::Guid(std::string uid) {
    uuid_to_guid(uid);
}

customShark::Guid::~Guid() {}

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

template<typename T>
T customShark::Guid::hex_string_to_value(std::string str) {
    unsigned int x;
    std::stringstream ss;
    ss << std::hex << str;
    ss >> x;

    return static_cast<T>(x);
}

void customShark::Guid::uuid_to_guid(std::string str) {
    remove_redundant_symbols(str);

    auto n = str.find('-');
    if ( n != std::string::npos ) {
        _data1 = hex_string_to_value<int>(str.substr(0, n));
        str.erase(str.begin() + 0, str.begin() + n + 1);

        n = str.find('-');
        if ( n != std::string::npos ) {
            _data2 = hex_string_to_value<short int>(str.substr(0, n));
            str.erase(str.begin() + 0, str.begin() + n + 1);

            n = str.find('-');
            if ( n != std::string::npos ) {
                _data3 = hex_string_to_value<short int>(str.substr(0, n));
                str.erase(str.begin() + 0, str.begin() + n + 1);

                n = str.find('-');
                if ( n != std::string::npos ) {
                    _data4 = hex_string_to_value<short int>(str.substr(0, n));
                    str.erase(str.begin() + 0, str.begin() + n + 1);

                    std::strcpy(_data5, str.c_str());
                }
            }
        }
    }
}

void customShark::Guid::remove_redundant_symbols(std::string str) {
    remove_symbol(str, '\n');
    remove_symbol(str, '\t');
    remove_symbol(str, '{');
    remove_symbol(str, '}');
    remove_symbol(str, ' ');
}

void customShark::Guid::remove_symbol(std::string str, const char symbol) {
    if (str.find(symbol))
        str.erase(std::remove(str.begin(), str.end(), symbol), str.end());
}