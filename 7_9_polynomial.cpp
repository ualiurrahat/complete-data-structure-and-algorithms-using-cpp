// incomplete

#include <bits/stdc++.h>

using namespace std;

class Polynomial
{
public:
    int *degreeCoEfficient;
    // each index of this degreeCoEfficient array represents the power
    // of the polynomial array
    // each value represents the co-efficient corresponding to the power(index) part
    int capacity;

    // constructor
    Polynomial()
    {
        degreeCoEfficient = new int[5];
        capacity = 10;
        for (int i = 0; i < 10; i++)
        {
            degreeCoEfficient[i] = 0;
        }
    }

    // copy constructor
    Polynomial(Polynomial const &p)
    {
        this->degreeCoEfficient = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            degreeCoEfficient[i] = p.degreeCoEfficient[i];
        }
        capacity = p.capacity;
    }

    // copy assignment operator
    void operator=(Polynomial const &p)
    {
        this->degreeCoEfficient = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            degreeCoEfficient[i] = p.degreeCoEfficient[i];
        }
        capacity = p.capacity;
    }

    // function to display polynomials
    // polynomials with 0 as co-efficient won't be displayed
    // ex: 3x^2 + 5x^4 - x^7 ........will be printed like this
    // 3x2 + 5x4 -1x7
    void display()
    {
        for (int i = 0; i < capacity - 1; i++)
        {
            if (degreeCoEfficient[i] != 0 && degreeCoEfficient[i] > 0)
            {

                cout << degreeCoEfficient[i] << "x" << i << "+";
            }

            else if (degreeCoEfficient[i] != 0 && degreeCoEfficient[i] < 0)
            {
                cout << degreeCoEfficient[i] << "x" << i << "+";
            }
        }
        if (degreeCoEfficient[capacity - 1] != 0)
        {
            cout << degreeCoEfficient[capacity - 1] << "x" << capacity - 1 << endl;
        }
    }
};

int main()
{
    Polynomial a;
    int degree[] = {0, 0, 3, 0, 0, 4, 0, -1, 0, 0};
    for (int i = 0; i < a.capacity; i++)
    {
        a.degreeCoEfficient[i] = degree[i];
    }
    a.display();

    return 0;
}