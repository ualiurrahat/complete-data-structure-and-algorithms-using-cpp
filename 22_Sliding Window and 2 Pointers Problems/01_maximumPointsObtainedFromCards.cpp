/*There are several cards arranged in a row, and each card has an associated number of points.
 The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row.
 You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1.
 However, choosing the rightmost card first will maximize your total score.
 The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

*/

#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
    int lsum = 0, rsum = 0, sum = 0, maxSum = 0;
    int n = cardPoints.size();

    // Step 1: Calculate the sum of the first 'k' cards from the left (lsum)
    for (int i = 0; i < k; i++)
    {
        lsum += cardPoints[i];
    }

    // Step 2: Initialize maxSum with lsum, assuming we take all 'k' cards from the left
    maxSum = lsum;

    // Step 3: Now, gradually replace cards from the left with cards from the right
    //         i iterates backwards from the last included left card
    //         j iterates backwards from the last card in the array
    for (int i = k - 1, j = n - 1; i >= 0; i--, j--)
    {
        lsum = lsum - cardPoints[i];       // Remove one leftmost card from lsum
        rsum = rsum + cardPoints[j];       // Add one rightmost card to rsum
        maxSum = max(maxSum, lsum + rsum); // Update maxSum if the new sum is greater
    }

    return maxSum;
    /*
Time Complexity: O(2K)  -> O(K) for lsum calculation + O(K) for the sliding process.
Space Complexity: O(1)  -> Only a few integer variables are used; no extra space is required.
*/
}

int main()
{
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    int ans = maxScore(cardPoints, k);
    cout << ans << endl;

    return 0;
}