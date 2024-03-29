/*You are given an array ‘NUMS’ of length ‘N’. You are also given an integer ‘TARGET’.
Return an array of all the unique quadruplets [ ‘NUMS[ a ]’, ‘NUMS[ b ]’, ‘NUMS[ c ]’, ‘NUMS[ d ]’ ] with the following conditions:
i. 0 <= a, b, c, d < ‘N’ and a, b, c, and d are distinct.

ii. NUMS[ a ] + NUMS[ b ] + NUMS[ c ] +NUMS[ d ] = TARGET

Return the array in any order.

*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// brute force solution
vector<vector<int>> fourSumBrute(vector<int> &nums, int target)
{
    // to store unique quadruplets
    set<vector<int>> st;
    // array size
    int n = nums.size();

    // checking all possible quadruplets
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    // taking bigger data type
                    // to avoid integer overflow
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        // storing quadruplets in a vector
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        // sort them
                        sort(temp.begin(), temp.end());
                        // push them in the set
                        st.insert(temp);
                    }
                }
            }
        }
    }
    // to store and return output
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

    /*
    T:O(n^4)
    S:O(no. of quads * 2) [one for set quads, one for answer output]
    */
}

// better solution
vector<vector<int>> fourSumBetter(vector<int> &nums, int target)
{
    // to store unique quadruplets
    set<vector<int>> st;
    // array size
    int n = nums.size();

    // checking all possible quadruplets
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // to store the possible 4th value
            // it will be all the numbers
            // between index j and k
            set<long long> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                // check if the fourth exists in the hashset
                if (hashset.find(fourth) != hashset.end())
                {
                    // found quadruplets
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    // sort them
                    sort(temp.begin(), temp.end());
                    // push the quadruplets in the set
                    st.insert(temp);
                }
                // insert the number in the hashset
                hashset.insert(nums[k]);
            }
        }
    }
    // to store and return output
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    /*
    T:O(n^3 * log(size of hashset))
    S:O(n)[hashset] + O(no. of quadruplets * 2) [one for set + one for output answer]
    */
}

// optimal solution
vector<vector<int>> fourSumOptimal(vector<int> &nums, int target)
{

    vector<vector<int>> ans; // to store ouput
    // sort the array
    sort(nums.begin(), nums.end());
    int n = nums.size(); // array size

    for (int i = 0; i < n; i++)
    {
        // skip for duplicate numbers
        // and rerun the loop from start
        // skipping starts from index 1
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            // skip duplicate number for index j
            // starts skipping from the 2nd element from
            // j's starting index
            if (j != i + 1 && nums[j] == nums[j - 1])
                continue;

            // take two pointers
            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    // update two pointers
                    k++;
                    l--;
                    // skip duplicate number
                    // for these pointers
                    while (k < l && nums[k] == nums[k + 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    k++;
                }
            }
        }
    }
    return ans;
    // T:O(n^3)
    // S:O(no. of quads)
}
int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    // vector<vector<int>> ans = fourSumBrute(nums, target);
    // vector<vector<int>> ans = fourSumBetter(nums, target);
    vector<vector<int>> ans = fourSumOptimal(nums, target);

    cout << "The quadruplets are: \n";
    for (auto it : ans)
    {
        cout << "[";
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}