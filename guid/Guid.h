#pragma once

#include <chrono>
#include <format>
#include <iostream>
#include <string>
#include <sstream>

// guid Format : {XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX}
// f.e.        :  6B29FC40-CA47-1067-B31D-00DD010662DA
//                18b57b88a81-d1d1-326e-12910
//                18b57b88-a81d-1d13-26e1-2910

namespace customShark
{
    class Guid {
    private:
        long  _data1;
        short _data2;
        short _data3;
        char _data4[8];

        template<typename T>
        static std::string value_to_hex(T value);
    public:
        Guid() {};
        ~Guid() {};

        static Guid new_guid();
        static std::string to_string(Guid guid);
    };
}