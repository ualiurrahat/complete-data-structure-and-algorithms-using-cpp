// intro to typecasting
// implicit typecasting: compiler automatically typecasts.
// explicit typecasting: user tells compiler to typecast.

// always practice explicit typecasting

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int i = 65;
    char c = i; // implicit typecasting;
    cout << c << endl;

    int *p = &i;
    // char *pc = p; // compiler does not allow this
    // but allows, when you explictly do this
    char *pc = (char *)p;

    cout << *p << endl;
    cout << *pc << endl;
    // *pc prints A. but *(pc+3) should have done that
    // num 65 should be stored in the 4th byte of total 4 bytes of integer
    // looks like it was stored in the first byte
    // why?
    // process to store integer: 1) Little Endian 2 ) Big Endian
    // mostly machine follows little Endian
    // little Endian : integer is stored in the first bit, last bit is sign bit
    // big Endian: reverse of little Endian
    // here, int stores from first byte.
    cout << *(pc + 1) << endl;
    cout << *(pc + 2) << endl;
    cout << *(pc + 3) << endl;

    cout << p << endl;
    cout << pc << endl;
    return 0;
}