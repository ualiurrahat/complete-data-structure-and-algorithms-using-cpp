// STL stands for Standard Template Library
// STL has 4 parts.......

// 1. Containers:
//    - Sequential containers:
//      i. vector
//      ii. stack
//      iii. queue
//      iv. deque
//      v. list (doubly linked list)
//      vi. forward_list (singly linked list)
//      vii. pair (not a container, but a C++ class for storing two values together)

//    - Associative containers (ordered, sorted by keys):
//      i. set
//      ii. map
//      iii. multiset
//      iv. multimap

//    - Unordered containers (hashed, unsorted):
//      i. unordered_map
//      ii. unordered_set
//      iii. unordered_multimap
//      iv. unordered_multiset

//    - Nested containers (containers within containers):
//      i. vector<vector<int>>
//      ii. map<int,vector<int>>
//      iii. set<pair<int,string>>
//      iv. vector<map<int,set<int>>>

// 2. Iterators:
//    - Point to memory addresses of container elements.
//    - Common types: begin(), end(), rbegin(), rend(), cbegin(), cend()
//    - Important: Continuity and discontinuity for iterators
//    - Categories: Input, Output, Forward, Bidirectional, Random Access
//    - Discussed in detail in iterator-specific files.

// 3. Algorithms:
//    - Common algorithms:
//      i. upper_bound(), lower_bound()
//      ii. max_element(), min_element()
//      iii. sort() (custom comparator)
//      iv. reverse(), count(), find(), accumulate()
//      v. next_permutation(), prev_permutation()
//      vi. binary_search(), merge(), partition(), shuffle(), rotate(), swap_ranges()
//    - More details and implementations are covered in algorithm-related files.

// 4. Functors:
//    - Classes that behave like functions by overloading the operator ()
//    - Used in STL algorithms for custom operations
//    - More examples provided in functor-related files.
