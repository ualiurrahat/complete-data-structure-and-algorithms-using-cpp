/* for n = 3,
    1
    2 2
    3 3 3

    binary triangle would look like
    1
    0 0
    1 1 1

    alphabetic triangle would look like
    A
    B B
    C C C

    asterisk triangle would look like
    *
    * *
    * * *


    */
#include <iostream>
using namespace std;

int main()
{
   int n, row, col;
   cout << ("Enter n = ");
   cin >> n;

   // code for number triangle.
   for (row = 1; row <= n; row++)
   {
      for (col = 1; col <= row; col++)
      {
         cout << row;
      }
      cout << endl;
   }

   cout << endl;
   cout << ("now we will do the same for binary right triangle\n");

   // code for binary triangle.
   for (row = 1; row <= n; row++)
   {
      for (col = 1; col <= row; col++)
      {
         cout << row % 2;
      }
      cout << endl;
   }
   cout << endl;
   cout << ("now will do the same for alphabetic triangle\n");
      char ch = char('A'-1);
   // code for alphabetic triangle.
   for (row = 1; row <= n; row++)
   {
      for (col = 1; col <= row; col++)
      {
         cout << char(ch + col); 
      }
      cout << endl;
   }

   cout << endl;
   cout << ("now will do the same for asterisk triangle\n");

   // code for asterisk triangle.
   for (row = 1; row <= n; row++)
   {
      for (col = 1; col <= row; col++)
      {
         cout << ("* ");
      }
      cout << endl;
   }

   return 0;
}
