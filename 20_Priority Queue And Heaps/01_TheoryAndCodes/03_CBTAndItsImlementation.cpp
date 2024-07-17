// To use complete binary tree(CBT) to create priority queue,
// we need to resolve the two issues we faced when balanced BST was used

// 1. height:
// height for any CBT is always O(logn)
// for height h,
// the minimum no. of nodes needed to create CBT is= 2^(h-1)
// the maximum no. of nodes needed to create CBT is = (2^h) - 1
// if h = 4, min no. of nodes = 2^(4-1) = 2^3 = 8
// if h = 4, max no. of nodes = (2^4) - 1 = 15

// 2. storing elements:
// we will store elements in an array for a CBT
// for any ith index(0 based indexing)
// parent --> i    child--> 2*i + 1, 2 * i + 2
// for child--> 2*i +1      parent--> (2*i+1 - 1 )/ 2 = i
// for child --> 2*i + 2    parent--> (2*i + 2 -1 ) / 2 = i