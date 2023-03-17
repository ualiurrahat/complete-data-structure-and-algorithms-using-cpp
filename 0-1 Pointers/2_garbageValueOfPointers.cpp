#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    cout <<"value of uninitialized i :" << i << endl;
    // we did not initialize any value in i
    // so will print any garbage value
    i++;
    cout <<"after increment of i " << endl << "value of uninitialized i :" << i << endl;

    // now let's see a garbage pointer
    int *p;
    // p points to any garbage value
    cout << p << endl;
    // let's see what garbage value *p obtains
    cout << *p << endl;
    // this is dangerous. we are trying to get a value from a garbage location
    // so any garbage value can be obtained
    (*p)++;
    // this is dangerous. we are changing garbage value from garbage memory
    // we don't know from which memory program will fetch the value.
    // it can take read-only memory which can damage our memory system
    // bad practice
    cout << *p << endl;
    // this is also dangerous and bad practice

    // insetaed of not initializing pointer
    // we can initialize them with 0 or NULL pointer
    // this will fetch no memory from prohibited area
    // and code will also be good

    // like int *p = NULL;
    // since p is pointing NULL, now this will give error:
    // cout << *p << endl;
    // p is pointing null means nothing.
    // so there is no point to ask for *p.
    // that's why code will show error
    // (*p)++;

    return 0;
}