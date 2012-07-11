
#ifndef _STR_ALGO_PART_1_H_
#define _STR_ALGO_PART_1_H_

#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>

#include <iostream>
#include <string>

using namespace boost;
using namespace std;

namespace string_algo {

    void test_format() {

        // in place
        cout << format("%| 5s|:%|05d|+%X=%d\n") % "sum" % 1 % 30 % (1+2);

        // positioning number %n%, like C#
        format fmt("(%1%+%2%)*%2%=%3%\n");
        fmt % 2 % 5;
        fmt % ((2+5)*5);
        cout << fmt.str();
        cout << "---------------------- test end ----------------------"<<endl;
    }

    void test_string_algo() {
        string str("readme.txt");
        if(ends_with(str, "txt")) {
            cout << to_upper_copy(str) + " UPPER" <<endl;
            cout <<"ends with txt"<<endl;
        }

        replace_first(str, "readme", "followme");
        cout <<"replace_first: " << str<<endl;

        vector<char> v1(str.begin(), str.end());
        // return : same type as input
        vector<char> v2 = to_upper_copy(erase_first_copy(v1, "follow"));
        for(int i = 0; i < v2.size(); i++) { cout << v2[i];}
        cout <<endl;
        cout << "---------------------- test end ----------------------"<<endl;
    }
}

#endif

