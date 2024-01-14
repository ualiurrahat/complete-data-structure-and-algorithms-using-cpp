/*You are given an array. Each element represents the prices of stock
of a day. You have to buy and sell stock so that the profit is maximum
NOTE: You can't sell before you buy.
You can't buy two times at a stretch.
You have to buy then sell,then again buy and sell and go on.
ex: a[] = {1,2,3,4}
output = 3
(buy at 1, sell at 4...profit = 4-1 = 3)
*/

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int arr[], int n)
{
    // taking inital profit as 0.
    int maxProfit = 0;
    // assuming arr[0] as least cost price
    int minCost = arr[0];
    // traverse array
    for (int i = 1; i < n; i++)
    {
        int currProfit = arr[i] - minCost;
        // update maxProfit
        maxProfit = max(maxProfit, currProfit);
        // update cost
        minCost = min(minCost, arr[i]);
    }
    return maxProfit;
}
int main()
{
    // size of array
    int n;
    cout << "Enter array size: ";
    cin >> n;
    // creating n size array
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "maximum profit: " << maximumProfit(arr, n) << endl;
    return 0;
}