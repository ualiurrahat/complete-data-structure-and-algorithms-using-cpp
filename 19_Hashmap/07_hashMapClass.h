// We will create our own hashmap here
// there will be an array Buckets which we will be using for our Map
// each index of Buckets array will contain a linked list
// in the link list we will insert elements as key-value pair
// index will be based upon keys and values will be inserted on the linked list as nodes
// so each linked list node will have 3 elements. key, value, next node address
// we will take string data type(default) for keys and template(generic data type) for values
// so, each node of linked list will look like this :
// Node<v>*    here, v is template for values
// since Buckets is an array of containing those linked list
// buckets will be pointer of node pointers....... : Node<v>**

#include <bits/stdc++.h>

using namespace std;

// class for node of Linked List
template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;
    // constructor
    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

    // destructor
    // deleting whole linked list of an index in the buckets array
    ~MapNode()
    {
        // will recursively delete all node's next node when called
        // untill it reaches to null
        // then will delete the list for which it was called.
        // hence, entire list will be deleted
        delete next;
    }
};

// Map class
template <typename V>
class ourmap
{
    // map is an  array of linked list nodes
    // nodes are MapNode<V>*
    // array of nodes will be MapNode<V>**
    MapNode<V> **buckets;
    int count;      // counts total elements == total size of map
    int bucketSize; // size of the buckets array

public:
    // constructor
    ourmap()
    {
        count = 0;
        // initial array size let's take 5
        bucketSize = 5;
        // creating array
        buckets = new MapNode<V> *[bucketSize];
        // each index of buckets array are filled with garbage value
        // inserting NULL as value in them
        for (int i = 0; i < bucketSize; i++)
        {
            buckets[i] = nullptr;
        }
    }

    // destructor
    // deleting the whole map
    // deleting map we need to delete all linked list first
    // then the array itself has to be deleted
    ~ourmap()
    {
        // deleting all linkedlist
        for (int i = 0; i < bucketSize; i++)
        {
            delete buckets[i];
        }
        // now deleting the array
        delete[] buckets;
        // whole map is deleted now.
    }

    // function to get total size of the map
    int size()
    {
        return count;
    }

private:
    // function to get index of key in the buckets array
    // keep it private as user need not concern about hashing
    // 2 things has to be done
    // 1. converty key stringinto hashCode,
    // 2. compress hashCode value within size of buckets.
    int getBucketIndex(string key)
    {
        // converting key into hashCode
        int hashCode = 0;
        int currentCoEfficient = 1;

        // changing string key into int value
        // calculating integer value of key from the last index
        // using base p method, here p = 37
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoEfficient;
            hashCode = hashCode % bucketSize;
            currentCoEfficient *= 37;
            currentCoEfficient = currentCoEfficient % bucketSize;
        }

        // returning compression code
        return hashCode % bucketSize;
    }

public:
    // function to insert a key-value pair
    void insert(string key, V value)
    {
        // first we need to get the index within the array
        // where we will store the elements(key-value)
        // using private function to get the bucketIndex
        int bucketIndex = getBucketIndex(key);

        // creating a head node to access the node in the bucketIndex.
        MapNode<V> *head = buckets[bucketIndex];

        // traverseing the linked list
        // check if the key already exists in the node
        // if it exists, then update its value
        while (head != nullptr)
        {

            if (head->key == key)
            {
                // key already exists in the node
                // update its value and return
                head->value = value;
                return;
            }
            head = head->next;
        }
        // key is not found in the list
        // creating a new node to contain the key in the linked list
        // first getting back the head
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        // this node will be the new head for the linked list located in bucketIndex in buckets array
        // attaching head to the next of this new node
        node->next = head;
        // assigning node as the head of the linked list
        // in the bucketIndex index
        buckets[bucketIndex] = node;
        // size has increased
        count++;

        // checking load factor
        // load factor = total entries / total size
        // if load factor > 0.7
        // we will perform rehashing
        // rehasing is done to make sure load factor
        // is < 0.7, so that T:O(1), for insertion,deletion,get value functions.
        double loadFactor = (1.0 * count) / bucketSize;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    // function to search a value
    V getValue(string key)
    {
        // convert key into integer which is the index
        // in the the bucket array
        // in which the linked list is located
        // inside that LL the key is present
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        // traversing the LL to find the key
        while (head != nullptr)
        {
            // check for the desired key
            if (head->key == key)
            {
                // we got the key
                // return the value and we are done
                return head->value;
            }
            head = head->next;
        }
        // key is not found
        // return 0 as value as a sign of key not found
        return 0;
    }

    // function to remove a key-value pair
    // also returns the value corresponding to the key that is deleted
    V remove(string key)
    {
        // first find the index in the bucket array
        // in which the key is in inside a linked list
        int bucketIndex = getBucketIndex(key);
        // node for head and previous node of the key node in the LL
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = nullptr;

        // traversing the LL to find the key node
        while (head != nullptr)
        {

            if (head->key == key)
            { // if key is inside the first node of the LL
                // then prev is NULL
                // so we will have to update the index of the bucket array
                if (prev == nullptr)
                {
                    // need to delete the head node
                    // new head will be head->next
                    // assgning head->next in the bucketIndex
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    // attaching prev node with head's next
                    // as head node will be removed
                    prev->next = head->next;
                }
                // we found the node with our desired key
                // preserve the value of key node
                V value = head->value;
                // head node needs to be deleted
                // but we change the delete operator in the destructor
                // so calling "delete head" will delete the entire LL recursivelyfrom head to end
                // so assigning head->next as null
                // then deleting the head
                head->next = nullptr;
                delete head;
                // one node is deleted. so count decreases.
                count--;
                // returning the value
                return value;
            }
            //  updating head and prev
            prev = head;
            head = head->next;
        }
        // we came out of the while loop
        // means we did not find the key node
        // so returning 0 as value. as a sign that key is not present inside the map
        return 0;
    }

    // function to perform rehash
    // will do it when load factor surpasses 0.7

    void rehash()
    {
        // temp array for containing the old hashmap i.e . bucket array.
        MapNode<V> **temp = buckets;
        // resizing the buckets array for rehashing
        buckets = new MapNode<V> *[2 * bucketSize];

        // to store size of old buckets
        int oldBucketSize = bucketSize;
        // new bucketSize is double than its previous size
        bucketSize *= 2;
        // hashMap is empty now. so count should be 0
        count = 0;
        // assigning null to each index in buckets array
        // as they have garbage values now
        for (int i = 0; i < bucketSize; i++)
        {
            buckets[i] = nullptr;
        }
        for (int i = 0; i < oldBucketSize; i++)
        {
            MapNode<V> *head = temp[i];
            // traversing the LL in ith index of temp
            //  and inserting each element in the new buckets array
            while (head != nullptr)
            {
                string key = head->key;
                V value = head->value;
                // inserting element into buckets array
                insert(key, value);
                head = head->next;
            }
        }

        // deleting the old hashmap i.e. temp array
        // first deleting each LL in the temp array
        for (int i = 0; i < oldBucketSize; i++)
        {
            MapNode<V> *head = temp[i];
            // recursively deleting each node of the LL
            delete head;
        }
        // now deleting temp array
        delete[] temp;
    }

    // function to get load factor
    double getLoadFactor()
    {
        return (1.0 * count) / bucketSize;
    }
};
