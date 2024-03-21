#include <iostream>
#include <vector>
using namespace std;

template <class T>
// function to print vector of vector
void printVector(vector<vector<T>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "displaying vector " << i+1 << ": ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter how many vetor you want to take: ";
    cin >> n;

    // vector of vectors
    vector<vector<int>> v;

    for (int i = 0; i < n; i++)
    {
        cout << "enter size of vector number " << i + 1 << " : ";
        int size;
        cin >> size;
        // using a temporary vector to take vector input
        vector<int> a;
        // another way to do it:
        //push ith vector to the v
        // v.push_back(vector<int>());
        for (int j = 0; j < size; j++)
        {
            int x;
            cin >> x;
            a.push_back(x);
            // another way to do it:
            // v[i].push_back(x);
        }
        v.push_back(a);
    }

   printVector(v);
//    cout << v.size() << endl;
//    cout << v[0].size() << endl;
//    cout << v[1].size() << endl;
//    cout << v[2].size() << endl;


    return 0;
}