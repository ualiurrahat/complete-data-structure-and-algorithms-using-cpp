// There are two types of data structures
// 1) whcich changes how data is stored in the memeory.
// ex: array, LL.
// 2) a layer above a basic DS which defines how data is accessible to the user.
// ex: stacks, queues

// Tree: tree is also like first type DS like array,LL.
// it changes how data is stored in the memory.
// ex: computer directory.
// This PC--> local disk,programming,others,me etc.

/*Tree Structure:         root
                /           /           /
               a            b           c
                         / | \         | \
                        d  e  f         g h


 */

// elements in tree DS:
// root node
// child node: a,b,c are children of root node
// parent node: root is parent of a,b,c. b is parent of d,e,f
// descendants: all nodes under root node are descendants of root.(a to h)
// leaf node : node with no child (a node here)
// siblings: children of same parent(a,b,c) (d,e,f)(g,h)