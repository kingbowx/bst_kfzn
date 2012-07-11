
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <iostream>
#include <vector>

using namespace std;

#define FNAME cout << "==============" << __FUNCTION__ << "==============" <<endl
#define auto_t BOOST_AUTO
///////////////////////////////////////////////////////////
// 4.2
///////////////////////////////////////////////////////////

// resolve type from function
vector<string> func() {
    vector<string> v(10);
    v[0] = "123";
    v[1] = "456";
    return v;
}

// register self-defined class
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
namespace ex {
    struct demo_class{ int a, b; };
}
BOOST_TYPEOF_REGISTER_TYPE(ex::demo_class)

void register_own_class() {
    FNAME;

    auto_t(p, make_pair("test", ex::demo_class()));
    cout << typeid(p).name() << endl;
    p.second.a = 10;
    p.second.b = 20;
    cout << p.second.a << ","<< p.second.b << endl;
}

///////////////////////////////////////////////////////////
// 4.4
///////////////////////////////////////////////////////////
void test_assign() {
    FNAME;

    using namespace boost::assign;
    vector<int> v;
    // operator +=
    v += 1,2,3,4,5,6*6;
    // operator ()
    push_back(v)(7)(8)(9);
    for(auto_t(it, v.begin()); it != v.end(); ++it)
        cout << *it <<endl;

    vector<string> vs;
    vs += "c", "c++", "java", "python";
    for(auto_t(it, vs.begin()); it != vs.end(); ++it)
        cout << *it <<endl;

    // initialize STL container with list_of()
    vector<int> vi = list_of(1)(2)(3)(4)(5);
    deque<string> ds = (list_of("one")("two"), "three", "four");
    map<int, string> mis = list_of(make_pair(1, "one"))(make_pair(2, "one"));

    // map_list_of(), pair_list_of()
    map<int, int> mii = map_list_of(1,1)(2,2)(3,3);

    // repeat()
    vector<int> vir = list_of(1).repeat(3,2)(3)(4)(5);
    // vir = (1,2,2,2,3,4,5)
}


///////////////////////////////////////////////////////////
// 4.9 exception
///////////////////////////////////////////////////////////
//#inlcude <exception>
#include <boost/exception/all.hpp>
struct my_exception:
    virtual std::exception,
    virtual boost::exception {};

typedef boost::error_info< struct err_info_no, int> err_no;
typedef boost::error_info< struct err_info_str, string> err_str;

void test_exception()
try {
    FNAME;

    using namespace boost;
    try {
        throw my_exception() << err_no(10);
    }
    catch (my_exception& e) {
        cout << *get_error_info<err_no>(e) << endl;
        cout << e.what() <<endl;
        e << err_str("A error string");
        throw;
    }
}
catch (my_exception& e) {
    cout<< *boost::get_error_info<err_str>(e) << endl;
}


int main(int argc, char* *argv[]) {
    using namespace boost;

    auto_t(y, 2*3.1);
    cout<<"boost auto, y, 2*3.1: "<<y<<endl;

    auto_t(v, func());
    cout<<"boost auto, vector:" << v[0] << "," << v[1] << ","<< v[2] << endl;

    register_own_class();

    // 4.4
    test_assign();

    // 4.9
    test_exception();
}
