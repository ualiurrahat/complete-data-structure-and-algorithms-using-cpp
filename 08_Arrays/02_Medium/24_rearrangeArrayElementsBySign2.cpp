/*
in previous quesiton, equal number of
+ve and -ve numbers were there.But here,
they are not. so after alteranating the
equal no. of +ve and -ve numbers, you have
to print the remaining numbers without
changing their relative order
ex: a[] = {-1,25,3,4,-3};
output[] = {25,-1,3,-3,4};
*/

#include <bits/stdc++.h>
using namespace std;

// approach: take two arrays for storing -ve,+ve nums
// then, first alternate equal no. of -,+ve numbers.
// fill the ans array with remaining same signed numbers
vector<int> rearrangeElements(vector<int> &a)
{
    int n = a.size();
    // to store rearranged numbers
    vector<int> ans(n, 0);
    // to store +ve,-ve numbers
    vector<int> pos, neg;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            pos.push_back(a[i]);
        }
        else
        {
            neg.push_back(a[i]);
        }
    }
    // in case given array has greater +ve numbers
    if (pos.size() > neg.size())
    {
        // so pos,neg both have neg.size() number of alternating +ve,-ve numbers.
        // alternate elements upto the index of neg array size
        for (int i = 0; i < neg.size(); i++)
        {
            // storing +ve in even indexes,-ve in odd indexes.
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }
        // now need to store remaining +ve numbers
        // from index of 2*neg.size()
        int index = 2 * neg.size();
        for (int i = neg.size(); i < pos.size(); i++)
        {
            ans[index] = pos[i];
            index++;
        }
    }
    // in case given array has greater -ve numbers
    // if given array has equal no. of +ve,-ve array
    // this else block code will run
    else
    {
        // so pos,neg both have pos.size() number of alternating +ve,-ve numbers.
        // alternate elements upto the index of pos array size
        for (int i = 0; i < pos.size(); i++)
        {
            // storing +ve in even indexes,-ve in odd indexes.
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }
        // now need to store remaining -ve numbers
        // from index of 2*pos.size()
        int index = 2 * pos.size();
        for (int i = pos.size(); i < neg.size(); i++)
        {
            ans[index] = neg[i];
            index++;
        }
    }
    return ans;
}
// S:O(2N), for pos,ans,neg
// if we used given array instead of ans, it would be O(N).
// T:O(N) + O(min(pos,neg)) + O(leftovers) == O(2N)
// as O(min(pos,neg)) + O(leftovrs) always equal to O(N)
// in all differenct cases.
int main()
{ // size of array
    int n;
    cout << "Enter array size: ";
    cin >> n;
    // creating n size vector
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = rearrangeElements(arr);
    cout << "Array after rearranging: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}