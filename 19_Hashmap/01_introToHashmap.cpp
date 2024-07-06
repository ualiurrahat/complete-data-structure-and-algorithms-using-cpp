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