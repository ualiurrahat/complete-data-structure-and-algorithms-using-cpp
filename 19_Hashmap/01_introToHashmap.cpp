// introduction to HashMap
// why we need hashMap?
// in array, the index has to be int and value must have to be same data type throughout the array
// means a[int] = {int/double/float/char/string....}
// but we can not store data in correspond to string or char or any other data type
// using string as an index in array
// a["abc"] is not allowed
// hashMap allows us to do this. In Hashmap   Map[key]-> value
// key can be any type...similarly value

// HashMap can be created usning:
// 1) linked List: search(), delete(), insert() -----> O(n)
// 2) BST: search(), delete(), insert() ------>O(logN)
// assuming BST is balanced. so height will be logN
// 3) Using Hash Table: search(), delete(), insert() -------> O(1)

// the in-built map is made up of both linked list and BST.
// built-in Map in C++....use BST---> O(logN)
// unordered_map......use HashMap---->O(1)

/*
ADVANTAGES OF HASHMAP
1. Fast random memory access through hash functions
2. Can use negative and non-integral values to access the values.
3. Keys can be stored in sorted order hence can iterate over the maps easily.

DISADVANTAGES:

1. Collisions can cause large penalties and can blow up the time complexity to linear.
2. When the number of keys is large, a single hash function often causes collisions.

APPLICATIONS:

1. These have applications in implementations of Cache where memory locations are mapped to small sets.
2. They are used to index tuples in Database management systems.
3. They are also used in algorithms like the Rabin Karp pattern matching algorithm.*/