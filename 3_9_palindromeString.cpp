/*
check if a string is palindrome using recursion
ex: input: madam,rahat
output: true,false
*/

#include <iostream>
using namespace std;

bool isPalindrome(string str, int firstIndex, int lastIndex)
{
    // base case
    if(firstIndex == lastIndex)
    {
        return true;
    }
    // small calculaion: check character
    if(str[firstIndex] != str[lastIndex])
    {
        return false;
    }
    // recursive call
    bool smallOutput = isPalindrome(str, firstIndex+1, lastIndex-1);
    return smallOutput;
}
int main()
{
    
    cout << isPalindrome("rahat", 0,4) << endl;
    cout << isPalindrome("madam",0,4) << endl;
    return 0;
}