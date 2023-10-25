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
        int _data1 = 0;
        short int _data2 = 0;
        short int _data3 = 0;
        short int _data4 = 0;
        char _data5[12] = "00000000000";

        template<typename T>
        static std::string value_to_hex_str(T value);
        template<typename T>
        static T hex_string_to_value(std::string str);
        void uuid_to_guid(std::string str);

        void remove_symbol(std::string str, const char symbol);
        void remove_redundant_symbols(std::string str);
    public:
        Guid();
        Guid(std::string uid);
        ~Guid();

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