// seems like Balanced BST is the better choice to make priority queue
// but we face two issues using Balanced BST:
// 1. balancing BST: with every insert, we will have to check for maintaining balance in the BST
// 2. storing: storing element is difficult. since we use pointers for each element in BST.

// That's why we use Heap Data Structure in making priority_queue
// heap is a data structure maintaing 2 properties:
// 1. complete binary tree
// 2. follows heap order property

// complete binary tree(CBT):
// A CBT is a binary tree where
// each level is completely filled except the last one.
// each level of a binary tree is filled except the last level
// each level in tree must be filled from left to right side

// heap order
// in max heap each element will be less than root
// in min heap each element will be greater than root