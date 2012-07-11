/*
 * =====================================================================================
 *
 *       Filename:  pool_example1.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/08/2012 05:13:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kfeng (), kenneth.feng@sirca.org.au
 *        Company:  Sirca
 *
 * =====================================================================================
 */

#include <boost/pool/object_pool.hpp>
#include <string>

using namespace boost;

struct test_struct {
	int _i;
	double _d;
	std::string _s;
	test_struct(int i = 1, double d=0.1, std::string s = "hello") : _i(i), _d(d), _s(s) {}
};

void test_object_pool() {

	object_pool<test_struct> pl;
	test_struct * pts = pl.malloc();

}

void pool_example() {

}
