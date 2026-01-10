#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findSecondLargest(vector<int> &arr, int n)
{
    int secondLargest = INT_MIN;
    int largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] < largest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
int main()
{
    vector<int> nums = {20, 1, 13, 15, 14, 24, 18, 25, 28};
    cout << findSecondLargest(nums, nums.size());

    return 0;
}