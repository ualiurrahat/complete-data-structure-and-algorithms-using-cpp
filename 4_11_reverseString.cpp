#include <bits/stdc++.h>

using namespace std;

string reverse(string s)
{
    if(s.size() == 0)
    {
        string ans = "";
        return ans;
    }
    string smallString = s.substr(1);
    string smallAns = reverse(smallString);
    return   smallAns + s[0];

}
int main()
{
    string input;
    getline(cin, input);

    string output = reverse(input);
    cout << output << endl;
    

    return 0;
}