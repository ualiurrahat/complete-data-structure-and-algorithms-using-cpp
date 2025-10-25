#include <iostream>

using namespace std;

// Notes:
// 1. storage is not constant. Path is.
// 2. If you have a read-only path, you can not make a write-able path using read-only path.

int main()
{

    // const must be initialized with the declaration.
    // ex: const a = 20;
    // can't write:
    // int const a;
    // a = 20. XXXXX this is not allowed.

    // 1. const int
    const int i = 10;
    // since, i is a constant variable,i++  this is not allowed.
    // const int i or int const i is same thing.

    // 2. const reference from a non const int
    int j = 25;
    const int &k = j; // now k is const reference of j
    cout << j << endl;
    cout << k << endl;
    j++;
    cout << j << endl;
    cout << k << endl;
    // j++ is possible as it is a regular variable
    // but k++ is not possible. it is a const reference
    // remember: path is or can be constant
    // actual storage can not be constant
    // here, path k is blocked to reach to j.

    // 3. const reference for a const int
    int const x = 30;
    int const &y = x;
    // x++, y++ ...both not possible

    // 4. reference from a const int
    int const a = 20;
    // int & p = a;
    //  this is not possible. so p++ is not possible.
    //  why: cause p is an reference for an int
    //  here, a is a int which is const
    // we can't change a by 'a' itself
    // so how will we be able to change a throug 'p'?
    // this is not allowed
    //  a const int can not have a regular int reference.
    // int const & p = a; this is permitted

    // const pointer for const value
    // a const can have only const pointer
    // can not change its address neither its value
    int const rahat = 0;

    // int const *r = &rahat;
    //  means r is a pointer to a const int
    //  but r is not constant
    //  so r = &kbkt is possible
    //  but (*r)++ is not possible.since rahat is an int const

    // a const pointer for a var is possible
    // line: int const * p; means p is a pointer to a const integer
    int rasel = 1;
    int const *rupa = &rasel;
    // rasel++ is possible
    // but (*rupa)++ is not.

    // const int  == int const == same thing
    const int t = 18;
    int const *T = &t; // T is a pointer to a const int

    // now take a look at this
    const int kbkt = 180;
    T = &kbkt;
    // this is correct. cause kbkt is also a const int.
    // So T can store kbkt or any other const int. no issue here.

    // if you want pointer to be const...then
    // int * const T = &t; here T is a const pointer to an int.
    // i can do (*T)++;
    // but can not do T = &kbkt as T is const pointer.

    // we can do this too
    const int ma = 100;
    int const *const p3 = &ma;
    // p3 is a constant pointer to a constant integer
    // p3 = &(anything except ma) is not possible
    // *p3++ not possible

    return 0;
}