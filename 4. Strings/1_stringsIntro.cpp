#include <iostream>
#include <string> // header file for using string class
#include <algorithm>

using namespace std;

int main()
{

    // different ways to declare a string
    string str;
    cin >> str; // takes only the first word....means untill the first space character.
    cout << str << endl;

    string str1(5, 'r'); // str1 = rrrrr
    cout << str1 << endl;

    string str2 = "UaliurRahat";
    cout << str2 << endl;

    // string str3;
    // getline(cin, str3); // used to take sentence as sentence.
    // cout << str3 << endl;

    string ami[15]; // string with 15 characters.
    string b(str2); // b is equal to str2.
    cout << b << endl;

    // string concetanation:
    //  way 1 : using append()
    string str4 = "fam";
    string str5 = "ily";
    // str4.append(str5);
    // cout << str4 << endl;
    // way 2: direct concetanation
    str4 = str4 + str5;
    cout << str4 << endl;

    // accessing character.
    cout << str4[0] << endl;

    // erase string.
    str4.clear();

    // string comparison.
    string s1 = "abc";
    string s2 = "zkl";
    string s3 = "abc";

    cout << s2.compare(s1) << endl;
    // string compare() function
    // returns 0 it strings are equal
    // return 1 otherwise
    if (!s1.compare(s3)) // if(s1.compare(s2) == 0)
    {
        cout << "strings are equal" << endl;
    }

    // string empty.
    s1.clear();
    if (s1.empty())
    {
        cout << "s1 is empty" << endl;
    }

    // string erase.
    string s4 = "ualiur rahat";
    s4.erase(7, 5); // erase(starting index of the removing word, total characters that has to be removed )
    cout << s4 << endl;

    // string find.
    string s5 = "ahnaf";
    cout << s5.find("naf") << endl; // returns index of the first character of the substring.

    // string insert.
    string s6 = "ualiur rahat";
    s6.insert(7, "lol"); // insert(inseting index, inserting string)
    s6.insert(10, " ");
    cout << s6 << endl;

    // string length.
    cout << s6.size() << endl; // s6.length()

    for (int i = 0; i < s6.length(); i++)
    {
        cout << s6[i] << " ";
    }
    cout << endl;

    // substring.
    cout << s6.substr(7, 8) << endl; // substr(starting index, total char)

    // string to integer.
    string s7 = "825";
    int x = stoi(s7);
    cout << x << endl;

    // integer to string.

    string s8 = to_string(x);
    cout << s8 + "0" << endl;

    // string sort.
    string s9 = "rahatmoholasdfjkkl";
    sort(s9.begin(), s9.end());
    cout << s9 << endl;

    // resize in string.
    string name = "manikerChipa";
    name.resize(5); // string is now first 5 digit only.
    cout << name << endl;

    return 0;
}