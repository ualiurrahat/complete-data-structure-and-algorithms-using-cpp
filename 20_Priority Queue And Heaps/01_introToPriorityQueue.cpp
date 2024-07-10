// priority queue is a queue with important factors
/*example:
Suppose we have a flight reservation system. Now we need to implement tickets booking based on
the priority factors:
i) aged passenger gets highest priority. The older the age, the higher the chance of ticket booking.
ii) VIP factor
etc...
to implement this kind of logic, we use priority queues as data structure.
*/
// types:
// 1. max priority queue
// 2. min priority queue

// operations:
// insert
// remove max/min
// get max/min

// whcih data structure will be best for creating priority queue?

// data structure        insert()         getMin/getMax          removeMin()/Max()      Overall

// array(unsorted)          O(1)             O(n)                     O(n)                O(n*n)

// array(sorted)            O(n)             O(1)                     O(n)                O(n*n)

// LL (unsorted)            O(1)             O(n)                     O(n)                O(n*n)

// LL (sorted)              O(n)             O(1)                     O(1)                O(nIn)

// BST                      O(height)        O(height)                O(height)           O(height*n)

// Balanced BST             O(logN)          O(logN)                  O(logN)             O(nlogN)

// hashMap                 O(1)              O(n)                     O(n)                O(n*n)

// seems like Balanced BST is the better choice to make priority queue

// but we face two issues using Balanced BST:
// 1. balancing BST: with every insert, we will have to check for maintaining balance in the BST
// 2. storing: storing element is difficult. since we use pointers for each element in BST.

// That's why we use Heap Data Structure in making priority_queue
