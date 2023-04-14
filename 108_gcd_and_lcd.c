//euclidean's division algorithm is best for gcd lcd.

// gcd for any x and 0 is x.ex: gcd(15,0) = 0
// gcd (a,b) =  gcd(b, a % b).

//ex: gcd(15,40) = 5 and gcd(15, 25) = 5.

#include <stdio.h>

int main()
{
    int num1, num2; // 2 input.
    int rem; // for processing.
    int n1,n2;
    int gcd, lcd;
    printf("enter two numbers: ");
    scanf("%d %d", &num1, &num2); // 15, 40

    n1 = num1;
    n2 = num2;

    if(num1 == 0)
    {
        gcd = num2;
    }
    else if(num2 == 0)
    {
        gcd = num1;
    }
    else
    {
        while(n2 !=  0)
        {
            rem = n1 % n2; // 40 % 15 = 10 | 15 % 10 = 5 | 10 % 5 = 0
            n1 = n2; // 15 | 10 | 5
            n2 = rem; // 10 | 5 | 0
        }

    }


    gcd = n1;
    lcd = (num1*num2)/ gcd;

    printf("gcd = %d\n", gcd);
    printf("lcd = %d\n", lcd);


}

