//
// Created by Raman Sharkovich on 22.10.23.
//

#include <iostream>
#include "Guid.h"
#include <vector>
#include <map>

using namespace customShark;

int main(int argc, char** argv)
{
    auto g = new Guid("6B29FC40-CA47-1067-B31D-00DD010662DA");
    std::cout << g->to_string() << std::endl;

    auto mp = std::map<Guid, int>();
    auto vc = std::vector<std::pair<Guid, int>>();

    for (auto i = 0; i < 10; ++i) {
        auto guid = Guid::new_guid();

        std::cout << guid.to_string() << std::endl;

        mp[guid] = i; //mp.insert(std::pair<Guid, int>(guid, i));
        vc.push_back(std::pair<Guid, int>(guid, i));
    }

    auto is_find = mp[vc[5].first] == vc[5].second;
    auto state = is_find ? "found" : "not found";

    std::cout << state << std::endl;

    is_find = vc[0].first == Guid::new_guid();
    state = is_find ? "equal" : "not equal";
    std::cout << state << std::endl;

    auto old_guid = vc[0].first;
    is_find = vc[0].first == old_guid;
    state = is_find ? "equal" : "not equal";
    std::cout << state << std::endl;

    return 0;
}
