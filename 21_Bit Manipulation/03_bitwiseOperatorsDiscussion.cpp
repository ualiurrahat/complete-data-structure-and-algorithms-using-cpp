/*
1's Complement: flip bits of a given binary number
2's complement = 1's complement + add 1 to it
ex:      13 = 1101
(flip bits) = 0010 ---> 1's complement of 13
add 1           +1
-----------------------------
            = 0011 ---> 2's complement of 13

Bitwise Operators
NOTE: True returns 1, False returns 0.
AND (&) Operator
-if all conditions true --> true
-if any 1 condition false --> false

OR (|) Operator
- if 1 condition true --> true
- if all conditions false --> false

XOR(^) Operator
-  odd no. of 1 --> true(1)
-  even no. of 1 --> false(0)

Bitwise Right (>>) Shift:
---------------------------------------
i) 13 >> 1 = ?
        13 = 0 0 0 0 1 1 0 1    (though int is 32 bits, let's see within 8 bits)
               0 0 0 0 1 1 0  = 6  (right shift by 1 bit, fill the left empty by 0)

                          X(right shift by 1 means 1 bit is elimintae)
       13 = 0 0 0 0 1 1 0 1
  13 >> 1 = 0 0 0 0 1 1 0 = 6

ii) 13 << 2 = ?
                       x x (right shift by 2 == elimintate 2 bits from right side)
      13 = 0 0 0 0 1 1 0 1
 13 >> 2 = 0 0 0 0 0 0 1 1 = 3

 So, 13 << 1 = 13 / 2 = 6 and 13 << 2 = 6 / 2 = 3

 Right Shift formula = n << k = (n / 2^k)

Bitwise Left (<<) Shift:
----------------------------------
i) 13 << 1 = ?
       13 = 0 0 0 0 1 1 0 1    (though int is 32 bits, let's see within 8 bits)
              0 0 0 1 1 0 1 0 = 26  (left shift by 1 bit, fill the right empty by 0)

                         X(left shift by 1 means 1 bit is added on the right side)
      13 = 0 0 0 0 1 1 0 1
 13 << 1 = 0 0 0 1 1 0 1 0 = 26

ii) 13 << 2 = ?
                       0 0 (left shift by 2 == add 2 bits on the right side)
     13 = 0 0 0 0 1 1 0 1
13 << 2 = 0 0 1 1 0 1 0 0 = 52

So, 13 << 1 = 13 * 2 = 26 and 13 << 2 = 26 * 2 = 52

Left Shift formula = n << k = (n * 2^k)

** How does left shift or right shift work
sol:
      13 = 1 1 0 1 = (1 . 2 ^3 + 1 . 2 ^ 2 + 0 . 2 ^ 1) + 1 . 2 ^ 0 [ last part is off the clip in the right shift]
13 >> 1  = 0 1 1 0 = (1 . 2 ^ 2 + 1. 2 ^ 1 + 0 . 2 ^ 0)
you see, in each element within the bracket part, the power of 2 has been reduced by 1
so, right shift by 1, eliminates one 2 from each element = divided by 2 the original number
that's how it works.
Similarly, 13 >> 2, ........ all other things work

** How does computer store Numbers (-ve, +ve)
sol: int numbers are 32 bits.
The 31st bit (starting from right) is signed bit
31st bit 0 --> positive number
31st bit 1 --> negative number

for number 13,
     13 = |0| 0 0 ........................ 1 1 0 1
     31st bit is 0. so 13 is a positive number. all the ........... are zeros here

for number -13, computer does 2's complement of the positive 13 number.

               13 = |0| 0 0 ........................ 1 1 0 1
   1's complement = |1| 1 1 ........................ 0 0 1 0 (flip bits)
                                                         + 1 (add 1 to it)
----------------------------------------------------------------------------
2'complement (-13)= [1] 1 1 ........................ 0 0 1 1
the 31st bit is 1. so it is a negative number = -13.
That's how computer saves -ve numbers.

** What is the largest int value?
sol: int has 32 bits. the 31st bit is for sign.
for the largest number, the other 30 bits have to be 1

largest = |0| 1 1 1 1 1 1 1 1 1 .......................1

= 2^30(2nd bit) + 2^29 + 2^28 + .......................2^0

= (2^31) -1 -----> equivalent to INT_MAX

** What is the largest value of a negative numbers?
sol:
Computer saves the negative numbers by performing the 2's complement.
int has 32 bits, first bit is for sign. but for now, let's don't think about the sign bit.
what will 2^31 look like if there is no sign bits.
it will look like this = 1 0 0 0 0 0 0........0 0 0 0 0
 (31st->1, all 30s are 0. do not bother about sign bit now.)

So, now how will computer save -2^31. It will do 2's complement. Also we did not bother about sign bit.
but computer does.

for a 32 bit smallest number, it would look like this
                         now, number = 1 0 0 0 0 0 0........0 0 0 0 0
                      1's complement = 0 1 1 1 1 1 1........1 1 1 1 1
                                                                  + 1
-------------------------------------------------------------------------
                      2's complement = |1| 0 0 0 0 0 0 .......0 0 0 0 0 = - 2^31 = INT_MIN

So, largest  = (2^31) - 1
    smallest = - 2^31
    it is because there is no -0 in computer. only positive 0


Bitwise Not (~) Operator
- flip the bits
- check if number is neagtive.
      if yes, then do 2's complement of the flipped number(without the signed bit).
      if not, then stop.

ex: number 13 = |0| 0 0................ 0 1 1 0 1
     flip bit =  1  1 1................ 1 0 0 1 0
it is negative. now do its 2's complement
     flip bit = |1|  1 1 1 0 0 1 0
     1's com. =      0 0 0 1 1 0 1
     add 1    =             + 1
---------------------------------
      (~13)   = |1| 0 0 0 1 1 1 0 = -14


Always Remeber:
If you are performing opeartions on negative number,
always convert the number into its 2's complement before operation.
*/
