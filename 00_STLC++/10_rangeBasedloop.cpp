#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {10, 20, 30, 40, 50};
    // printing normally
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    // printing using range based for loop
    cout << "printing using range based loop: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    // here, the elements in nums vector is just copied as value inside num
    // first num value is 10, then 20,30,,,,,goes on.
    // means range based loop does shallow copy of elements

    for (int number : nums)
    {
        number = number + 100;
        // means we are adding 100 with first number 10
        // so nums[0] should be 110
        // but it does not happen as range based loop justy copy the values from container
    }
    cout << "values after range based loop did shallow copy: ";
    for (int a : nums)
    {
        cout << a << " "; // 10 20 30 40 50; no change of values as range based loop did shallow copy before.
    }
    cout << endl;
    // NOTE: to change elements of the container, use reference of elements in the range based loop
    // for example below:
    for (int &value : nums)
    {
        value = value + 100; // for ex: 10 + 100 = 110,.....120,130,..other elements.
        // now, nums each element will be changed
        // since value is taken as reference
    }
    cout << "values after range based loop did deep copy: ";
    for (int a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}