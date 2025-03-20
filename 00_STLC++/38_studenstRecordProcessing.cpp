/*You are given a list of student records, where each record consists of the student's name, age, and score in a particular subject. Your task is to process these records and perform some operations based on certain criteria.


Average Age: Calculate the average age of all students in the records, rounded down to nearest integer.
Highest Score: Find the highest score among all students in the records.
Input Format
The first line of input will contain a single integer
N, denoting the number of student records.

Output Format
Print on a single line, two space separated values: average age of students(rounded down to nearest integer) and highest score among them.

Input:
3
Alice 20 85.5
Bob 22 90.0
Charlie 21 75.5

Output:
21 90.0

*/
#include <bits/stdc++.h>

using namespace std;

// Function to process student records and compute required statistics
tuple<int, double> processStudentRecords(const vector<tuple<string, int, double>> &records)
{
    int totalAge = 0;       // Sum of all students' ages
    double highestMark = 0; // Highest score among students
    int n = records.size(); // Total number of students

    // Iterate through each student record
    for (int i = 0; i < n; i++)
    {
        totalAge += get<1>(records[i]);                     // Accumulate total age
        highestMark = max(highestMark, get<2>(records[i])); // Update highest score
    }

    int avgAge = totalAge / n; // Compute average age (rounded down)

    return make_tuple(avgAge, highestMark); // Return results as a tuple
}

int main()
{
    int n;
    cin >> n; // Read the number of student records

    vector<tuple<string, int, double>> records; // Vector to store student records

    // Read student records and populate the vector
    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        double score;
        cin >> name >> age >> score;
        records.emplace_back(name, age, score); // Add record to the vector
    }

    // Process student records to compute required statistics
    tuple<int, double> result = processStudentRecords(records);

    // Print the computed average age and highest score
    cout << get<0>(result) << " " << get<1>(result) << endl;

    return 0;
}
