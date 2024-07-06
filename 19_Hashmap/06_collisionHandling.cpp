
// collision: when a hash function genertates same index even though having
// different hash code for objects
// ex: bucket size = 20
// hash code for ob1 = 105 and ob2 = 205
// so index of ob1 = 105 % 20 = 5
// so index of ob2 = 205 % 20 5
// this situation is called collision.

// collision: two or more keys got same index after hashing
// solution: collision handling

// collision handling:
// 1. closed hashing/ closed addressing /separate chaining
// 2. open addressing.

// closed hashing:
// we will create an array in the index and will keep all the key with their value
// at that index
// in that linked list following their apperance
// that is why it is called separate chaining

// open addressing:
// each key will be kept to separate index
// if index is empty, fill the first appeared key into it
// if index is full, search an alternative place to keep the key

// hash function = hf(a)
// function i = f(i)

// formaula for open addressing:
// ith attempt = original hash function + function of i
// hi(a) = hf(a) + f(i)
// requirements: f(i)->f(0) = 0  [means first attempt would be in the index where collision happened]

// types of open addressing:
// i) linear probing: f(i)->i
// linear probing may generate indexes covering a common index.
// means linear probing generates a popular index
// this is solved by quadratic probing
// ii) quadratic probing: f(i) -> i*i
// quadratic function is used when hash function is generating indexes nearing a common index.
// so quadratic function finds index maintaining a good distance from that common index
// iii) double hasing: f(i)-> i*h2(a)........h2(a) = another hashing function

// note: separate chaining works as well as any open addressing technique
// we will use separate chaining to create our hash function
