#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a[] = {25, 8};
    char c[] = "rahat";

    cout << a << endl; // print address
    cout << c << endl; // print content , not address

    // to print address of char
    // use void pointer
    cout << (void *)&c << endl;

    // why they are acting differntly ?
    // because of implementation of cout differs between int and char array.

    char *b = &c[0];   // should contain address of c array i.e. address of c[0]
    cout << b << endl; // print whole array content instead of address. but why?
    // the differencs are showing  cause of cout implementation difference

    char e = 'l';
    char *f = &e;
    cout << e << endl; // print content
    cout << f << endl; // printing starts from content and stops after finding null character.

    free(f);
    free(b);

    // char str[] = "rahat"; good practice
    // why?: here computer creates a copy of string "rahat" and
    // then send it as an array in str[] array
    // so computer is sending a copy of "rahat" from temporary memory to str[].

    // char * str = "rahat"; very bad practice.
    // here, str is storing an address of temporary memory
    // which has the string "rahat".
    // so if we want to change the string or to access
    // the string using the address
    // it might show error results.
    // the address is a read-only space
    // so we can't change or update the string.

    return 0;
}