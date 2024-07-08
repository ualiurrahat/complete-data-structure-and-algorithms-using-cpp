#include <bits/stdc++.h>
using namespace std;

// class for linked list nodes
template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode<V> *next;
    // constructor
    MapNode(string key, V value)
    {
        this->key = key;
        this->value value;
        this->next = nullptr;
    }
    // destructor
    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class Ourmap
{
public:
    MapNode<V> **buckets;
    int count;
    int bucketSize;
    // constructor
    Ourmap()
    {

        bucketSize = 5;
        count = 0;
        buckets = new MapNode<V> *[bucketSize];
        for (int i = 0; i < bucketSize; i++)
        {
            buckets[i] = nullptr;
        }
    }
    // ~destructor
    ~Ourmap()
    {
        // delete each index's linked list
        for (int i = 0; i < bucketSize; i++)
        {
            delete buckets[i];
        }
        // delete map i.e. array of the linked list
        delete[] buckets;
    }
    int size()
    {
        return count;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currentCoEfficient = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoEfficient;
            hashCode = hashCode % bucketSize;
            currentCoEfficient *= 37;
            currentCoEfficient = currentCoEfficient % bucketSize;

            return hashCode % bucketSize;
        }
    }

public:
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != nullptr)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0 * count) / bucketSize;
        if (loadFactor > 0.7)
        {
            rehash();
        }
        return;
    }
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = nullptr;
        while (head != nullptr)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = nullptr;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != nullptr)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * bucketSize];
        int oldBucketSize = bucketSize;
        bucketSize *= 2;
        count = 0;
        for (int i = 0; i < bucketSize; i++)
        {
            buckets[i] = nullptr;
        }
        for (int i = 0; i < oldBucketSize; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != nullptr)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketSize; i++)
        {
            delete temp[i];
        }
        delete[] temp;
    }
};
int main()
{

    return 0;
}