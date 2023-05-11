// Given N strings, print strings in lexographical order
// with their frequency
// N = 10^5
// string size <= 100
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{

    int n;
    cout << "Enter how many strings you want to insert: ";
    cin >> n;
    // to store strings and their frequencies
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cout << "enter string: ";
        cin >> s;
        // insert string in the map and update frequency
        m[s]++;
        // m[s] = m[s] + 1
    }

    // printing string in lexographical order
    for (auto word : m)
    {
        cout << word.first << " : " << word.second << endl;
    }
    return 0;
}