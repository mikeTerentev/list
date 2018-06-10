//
// Created by Михаил Терентьев on 10/06/2018.
//

#include <iostream>
#include "List.h"

int main() {
    List<int> list__;

    for (int i = 0; i < 18; i++)
        list__.push_back(i);
    List<int>::const_iterator i(list__.begin());
    List<int> dst_l, src_list = list__;
    //list__.clear();
    for (auto i = list__.begin(); i != list__.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    std::cerr
            << "*******\npush_back -> pb\npush_fron -> pf\npop_back->popb\npop_front->popf\ninsert -> i\nerase -> e\nerase_segm -> es\n*******\n";
    while (true) {
        std::cout << "LAST ELEMENT:" << *(--list__.end()) << std::endl;
        std::cout << "FIRST ELEMENT:" << *(list__.begin()) << std::endl;
        std::string line;
        std::cin >> line;
        if (line == "pb") {
            int VAL;
            std::cin >> VAL;
            list__.push_back(VAL);
        } else if (line == "pf") {
            int x;
            std::cin >> x;
            list__.push_front(x);
        } else if (line == "popb") {
            list__.pop_back();
        } else if (line == "popf") {
            list__.pop_front();
        } else if (line == "i") {
            int POS, VAL;
            std::cin >> POS >> VAL;
            List<int>::iterator it = list__.begin();
            for (int i = 0; i < POS; i++, it++);
            auto res = list__.insert(it, VAL);
            std::cout << "FROM RES IT:";
            for (; res != list__.end(); ++res)
                std::cout << *(res) << " ";
            std::cout << std::endl;
        } else if (line == "e") {
            int x;
            std::cin >> x;

            List<int>::iterator it = list__.begin();
            for (int z = 0; z < x; z++) ++it;

            auto res = list__.erase(it);
            for (; res != list__.end(); ++res) std::cout << *res << " ";
            std::cout << std::endl;

        } else if (line == "c") {
            list__.clear();
        } else if (line == "es") {
            int x, y;
            std::cin >> x >> y;

            List<int>::iterator it = list__.begin();
            for (int z = 0; z < x; z++) ++it;
            List<int>::iterator it2 = list__.begin();
            for (int z = 0; z < y; z++) ++it2;

            auto res = list__.erase(it, it2);
            std::cout << "FROM RES IT:";
            for (; res != list__.end(); ++res)
                std::cout << *(res) << " ";
            std::cout << std::endl;

        } else if (line == "break")
            break;
        std::cout << "NORM_LIST: ";
        for (auto i = list__.begin(); i != list__.end(); ++i) std::cout << *i << " ";
        std::cout << std::endl;
        std::cout << "REV_LIST : ";
        //std::cout <<*(my_list.rbegin())<<*( --my_list.rend()) <<std::endl;
        for (auto x = list__.rbegin(); x != list__.rend(); x++) {
            auto tmp = *x;
            std::cout << tmp << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}