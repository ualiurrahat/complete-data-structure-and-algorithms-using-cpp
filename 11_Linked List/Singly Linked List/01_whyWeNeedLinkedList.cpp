/*
the problem with array: once it is declared, we can not add more elements.
as array is a contiguous part of the memeory.Even deletion is also tiresome.
So we needed a data structure where we can add data as per our wish.
That's where Linked List comes in.

Linked List: a data structure that is collection of nodes, where each node
has two property: 1) data, 2) address of the next node
Head: the first node of LL
Tail: the last node of LL

Array VS Vector VS Linked List:
1) for array, size is fixed. but in vector size gets doubled if we try to insert
a new element when vector is full. So this space usage needs to be optmized.
LL does optimize this space usage.
2) deletion, insertion is tiresome in array as we need to do shifting.
it is easy in vector compared to array.
LL does deletion,insertion in the easiest way.


types of LL:
1) singley LL:
each node contains data and address of next node
2) doubley LL:
each node contains data, address of previous node, address of next node.
3) circular singly LL
4) circular doubley LL

*/