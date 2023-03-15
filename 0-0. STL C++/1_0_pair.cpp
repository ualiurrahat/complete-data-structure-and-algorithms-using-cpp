// introduction to pair.
#include <iostream>
#include <string>
#include <utility> // header file for pair.

using namespace std;

int main()
{
    // pair syntax 
    // pair<dataType1, dataType2>pairName;
    // pair<container1,container2>pairName;
    // pair declaration.
    pair<int, int> p1;
    p1 = {25, 8};

    // pair declaration with initialization.
    pair<int, int> p2 = {3, 9};

    pair<float, float> p3 = {1.8, 2.7};

    // pair can be assigned as copy of another.
    pair<int, int> p = p1; // p(p1);

    // pair initialization with make_pair() function.
    pair<float, float> p4 = make_pair(25.7, 8.25);

    // displaying pair.

    cout << "pair p1: " << p1.first << " " << p1.second << endl;
    cout << "pair p: " << p.first << " " << p.second << endl;
    cout << "pair p2: " << p2.first << " " << p2.second << endl;
    cout << "pair p3: " << p3.first << " " << p3.second << endl;
    cout << "pair p4: " << p4.first << " " << p4.second << endl;

    // pair array.
    pair<int, int> p5[4];

    // pair array insertion
    for (int i = 0; i < 4; i++)
    {
        cout << "Insert pair " << i + 1 << " elements: ";
        cin >> p5[i].first >> p5[i].second;
    }

    // displaying pair array.
    for (int i = 0; i < 4; i++)
    {
        cout << "Pair " << i + 1 << ": " << p5[i].first << " " << p5[i].second << endl;
    }

    // operation in pair.
    // comparison:
    // for pair p1,p2 : p1 > p2 if p1.first > p2.first
    cout << endl;
    cout << "Comapring p and p1: " << endl;
    if (p == p1)
    {
        cout << "p and p1 are equal.\n";
    }
    else
    {
        cout << "p and p1 are not equal.\n";
    }

    cout << endl;
    cout << "Comparing p1 and p2: " << endl;
    if (p1 == p2)
    {
        cout << "p1 and p2 are equal.\n";
    }
    else
    {
        cout << "p1 and p2 are not equal.\n";
    }
    cout << endl;

    // comparison operator between p1 and p2.
    cout << "Comparing p1 and p2 again: " << endl;
    if (p1 > p2)
    {
        cout << "p1 is greater than p2.\n";
    }
    else
    {
        cout << "p2 is greater than p1.\n";
    }

    cout << endl;
    // comparison operator between p3 and p4.
    cout << "Comparing p3 and p4 again: " << endl;
    if (p3 > p4)
    {
        cout << "p3 is greater than p4.\n";
    }
    else
    {
        cout << "p4 is greater than p3.\n";
    }
    return 0;
}