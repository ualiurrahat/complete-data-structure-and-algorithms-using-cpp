// find the length of a chracter string using recursion.
// ex: input->  bangladesh
// output = 10;
#include <iostream>
#include <string>

using namespace std;

int length(char str[])
{
    // base case
    if (str[0] == '\0')
    {
        return 0;
    }
    // recursive call
    int smallLength = length(str + 1);
    // calculation
    return smallLength + 1;
}

int main()
{
    // taking a 100 characters input string
    char str[100];
    cout << "Enter your string: ";
    cin.getline(str, 100);

    int l = length(str);
    cout << l << endl;
    return 0;
}