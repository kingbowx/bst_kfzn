#include <boost/enable_shared_from_this.hpp>
#define print_me() \
	cout << "===== " << __FUNCTION__ << " ====="<<endl;

// shared_ptr in bridge mode
////////////////////////////////////////////////////////////////////////////
class sample {
private:
	class impl;
	shared_ptr<impl> p;
public:
	sample();
	void print();
};

class sample::impl {
public:
	void print() {
		cout << "This is sample::impl::print"<<endl;
	}
};

sample::sample(): p(new impl) {}

void sample::print() {
	p->print();
	cout<< "use count: " << p.use_count() << endl;
}

void shared_ptr_in_bridge_mode() {
	cout << "===== " << __FUNCTION__ << " ====="<<endl;
	sample s;
	s.print();
}
/////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////
class self_shared : public enable_shared_from_this<self_shared> {
private:
	int x;
public:
	self_shared(int n): x(n) {}
	void print() {
		cout << "self_shared: " << x << endl;
	}
};

void test_enable_shared_from_this() {
	print_me();
	shared_ptr<self_shared> sp = make_shared<self_shared>(314);
	sp->print();
	cout << "use_count1: " << sp.use_count()<<endl;
	shared_ptr<self_shared> p = sp->shared_from_this();
	cout << "use_count2: " << sp.use_count()<<endl;
}

void example3() {
	shared_ptr_in_bridge_mode();
	test_enable_shared_from_this();
}
