#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;
    cout << "Given String: ";
    cin >> s;

    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    string ans = "";
    while (!st.empty())
    {
        char a = st.top();
        ans.push_back(a);
        st.pop();
    }
    cout << "reverse word: " << ans << endl;
    return 0;
}