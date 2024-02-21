/*Aakash is a member of Ninja club. He has a weird family structure.
Every male member (M) gives birth to a male child first and then a female child,
 whereas every female (F) member gives birth to a female child first and then to a male child.
  Aakash analyses this pattern and wants to know
   what will be the Kth child in his Nth generation.*/

#include <bits/stdc++.h>
using namespace std;

// This function calculates the gender of the Kth child in the Nth generation
string kthChildNthGeneration(int n, long long int k)
{
    // Base case: If we are at the first generation or the first child position, the gender is always male
    if (n == 1 or k == 1)
    {
        return "Male";
    }
    // Calculate the index of the parent of the Kth child in the Nth generation
    long long int par = (k + 1) / 2;

    // Recursively find the gender of the parent (in the previous generation)
    string parGender = kthChildNthGeneration(n - 1, par);

    // Check if the Kth child of Nth generation is the first child of its parent
    if (k == 2 * par - 1)
    {
        // If yes, return the gender of the parent
        return parGender;
    }
    // If the Kth child of Nth generation is the second child of its parent
    else
    {
        // Determine the gender of the child based on the gender of its parent
        if (parGender == "Male")
        {
            return "Female"; // If parent is male, the child is female
        }
        else
        {
            return "Male"; // If parent is female, the child is male
        }
    }
    // T:O(2^n - 1);
}
int main()
{
    int generation;
    long long int childPosition;

    // Input generation number and child position
    cout << "Enter the generation number: ";
    cin >> generation;
    cout << "Enter the position of the child: ";
    cin >> childPosition;

    // Call the function to determine the gender of the child
    string gender = kthChildNthGeneration(generation, childPosition);

    // Output the result
    cout << "The gender of the child at position " << childPosition << " in generation " << generation << " is: " << gender << endl;

    return 0;
}