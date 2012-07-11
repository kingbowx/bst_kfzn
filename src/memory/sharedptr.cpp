/*
 * =====================================================================================
 *
 *       Filename:  sharedptr.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/23/2012 09:56:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kfeng (), kenneth.feng@sirca.org.au
 *
 * =====================================================================================
 */

#include <boost/shared_ptr.hpp>
#include <iostream>
using namespace std;
using namespace boost;

#include "example2.h"
#include "example3.h"

int main(int argc, char *argv[]) {
    shared_ptr<int> spi(new int);
    assert(spi);
    *spi = 123;

    shared_ptr<string> sps(new string("hello"));
    cout << "length of " << *sps << " is " << sps->size()<<endl;
    assert(sps->size() == 5);
    cout << "shared_ptr test" <<endl;

    shared_ptr<int> sp(new int(10));
    assert(sp.unique());             // verify the only holder

    shared_ptr<int> sp2 = sp;
    assert(sp == sp2 && sp.use_count() == 2); // two sp are equal, use count is 2

    *sp2 = 100;
    assert(*sp == 100);

    sp.reset();                      // sp released, not hold anything
    assert(!sp);

    example2();
    example3();
    return 0;
}
