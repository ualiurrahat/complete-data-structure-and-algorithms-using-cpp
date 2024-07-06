//  bucket Array: we use an array to keep the value of keys
//  we change the data type of keys into integers
//  then stores them in the bucket array

// how to change data type of keys from original to int type?
// solutin: using hash function
// hashfunction--------- two parts.
//   1. hash Code----. change keys into int
//   2. compression function.... compressed the int value of key within array size.

// bucket size can be = % bucket size

// keys......hash function.......()int) keys

// how to use hash function
// for example, to change string keys into int, we can take sum of ascii values.
// or sum of first 3 digits
// but these are not good hash code
// better hash code is like considering a string as a number of base p
// p is a prime number. as per research, prime gives very good distribution.
// ex: "abcd" is a number of base p
// so abcd = 'a' *(p^3) + 'b' * (p^2) + 'c' * p + d

// for any object, we can use address of it, then convert the address into int
// thus hashing code can be generated
