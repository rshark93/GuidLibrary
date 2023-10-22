//
// Created by Raman Sharkovich on 22.10.23.
//

#include <iostream>
#include "Guid.h"

using namespace customShark;

int main(int argc, char** argv)
{
    auto guid = Guid::new_guid();
    auto id = Guid::to_string(guid);

    std::cout << id << std::endl;

    return 0;
};
