// STL stands for Standard Template Library
// STL has 4 parts.......
// 1. Containers:
//    - sequential containers
//    i. vector
//    ii. stack
//    iii. queue
//    iv. pair(not a container,basically a c++ class, but keeps data sequentially)
//    - non-ordered containers
//    keeps data in an orderly manner
//    i. set
//    ii. map
//    iii. multiset
//    iv. multimap;
//     - unorderd
//     i. unordered map 
//     ii. unordered set 

// - nested containers
// containers within containers
// vector<vector<int>>
// map<int,vector<int>>
// set<pair<int,string>>
// vector<map<int,set<int>>>
// 2. iterators:
// point to memory address of containers
// begin(), end()
// vector<int>:: iterator it;
// important: continuity and discontinuity for iterators

// 3. Algorithms:
// upperbound,lowerbound
// max_element, min_element
// sort(comparator)
// reverse,count,find,accumulate
// next_permutations, prev_permutations
// 4. functors:
// classes which can act as functions