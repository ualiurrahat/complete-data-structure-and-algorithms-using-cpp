/*Given N strings, and Q queries.
in each query, you are given a string.
print frequency of that string
N = 10^6 and string size <= 100
Q <= 10^6

ex: string input 8 : abc,def,abc,ghj,jkl,ghj,ghj,abc
queries 2: abc,ghj
output: frequency of abc = 3, frequency of ghj = 3;
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string,int>m;
    int n;
    cout << "Enter total no. of strings you want to insert: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;;
        m[s]++;
    }
    int q;
    cout << "Enter total queries: ";
    cin >> q;
    while(q--)
    {
        string s;
        cout << "enter string to see frequency: ";
        cin >> s;
        cout << s << " : " << m[s] << endl;
    }
    
    return 0;
}