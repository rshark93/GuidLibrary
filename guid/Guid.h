#pragma once

#include <chrono>
#include <format>
#include <iostream>
#include <string>
#include <sstream>

// guid Format : {XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX}
// f.e.        :  6B29FC40-CA47-1067-B31D-00DD010662DA

namespace customShark
{
    class Guid {
    private:
        int _data1;
        short int _data2;
        short int _data3;
        short int _data4;
        char _data5[12];

        template<typename T>
        static std::string value_to_hex_str(T value);
    public:
        Guid() {};
        ~Guid() {};

        static Guid new_guid();
        const std::string to_string();

        bool operator == (const Guid& guid) const {
            return this->_data1 == guid._data1 && this->_data2 == guid._data2 && this->_data3 == guid._data3
                && this->_data4 == guid._data4 && (std::strcmp(this->_data5, guid._data5) == 0);
        }

        bool operator != (const Guid& guid) const {
            return this->_data1 != guid._data1 && this->_data2 != guid._data2 && this->_data3 != guid._data4
                && this->_data4 != guid._data4 && (std::strcmp(this->_data5, guid._data5) != 0);
        }

        bool operator < (const Guid& guid) const {
            return this->_data1 < guid._data1;
        }
    };
}