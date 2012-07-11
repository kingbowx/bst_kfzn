/*
 * =====================================================================================
 *
 *       Filename:  example2.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/06/2012 03:09:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kfeng (), kenneth.feng@sirca.org.au
 *        Company:  Sirca
 *
 * =====================================================================================
 */
#include <boost/make_shared.hpp>
#include <string>
#include <vector>

class shared {
private:
	shared_ptr<int> p;
public:
	shared(shared_ptr<int> p_) : p(p_) {}
	void print() {
		cout << "count: " << p.use_count() << ", v = " << *p << endl;
	}
};

void print_func(shared_ptr<int> p) {
	cout << "count: " << p.use_count() << ", v = " << *p << endl;
}

void shared_ptr_as_class_member() {
	cout << "===== " << __FUNCTION__ << " ====="<<endl;
		shared_ptr<int> p(new int(100));
		shared sh1(p), sh2(p);

		sh1.print();
		sh2.print();

		*p = 20;
		print_func(p);

		sh1.print();
}

void test_make_shared() {
	cout << "===== " << __FUNCTION__ << " ====="<<endl;
	shared_ptr<string> sps = make_shared<string>("make_shared");
	shared_ptr<vector<int> > spv = make_shared<vector<int> >(10, 2);
	assert(spv->size() == 10);
	spv->push_back(123);
	assert(spv->size() == 11);
}



void example2() {
	shared_ptr_as_class_member();
	test_make_shared();
}

bool isnum(const char* str)
try{
   str;
   return true;
}
catch (std::bad_cast& e)
{
   return false;
};
