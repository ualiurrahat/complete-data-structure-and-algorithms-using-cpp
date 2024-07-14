#include <iostream>
#include <vector>

using namespace std;

// min heap priority class
class PriorityQueue
{
    // vector to store elements as a heap
    vector<int> pq;

public:
    // constructor
    PriorityQueue()
    {
        //  no neet do anything here
        // wrote this empty constructor
        // just to initialize priority queue when created
    }
    // function to get the no. of elements present in the priority queue
    int size()
    {
        return pq.size();
    }
    // function to check if priority queue
    // is empty or not.
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    // function to get minimum data from the min priority queue
    int getMin()
    {
        // returning 0 as a sign that
        // priority queue is empty
        if (isEmpty())
        {
            cout << "returning 0 as queue is empty ";
            return 0;
        }
        // otherwise returning the min element
        return pq[0]; // in min heap.
    }
    // function to insert an element in the min priority queue
    void insert(int element)
    {
        // insert the element at the last position in the queue
        pq.push_back(element);
        // get index of the child to perform up-heapify
        int childIndex = pq.size() - 1;
        // loop to maintain min heap property.

        while (childIndex > 0)
        {
            // figure out the parent's index
            int parentIndex = (childIndex - 1) / 2;
            // compare parent and child data
            if (pq[childIndex] < pq[parentIndex])
            {
                // child's data lesser than parent's.
                // swap their data.
                swap(pq[childIndex], pq[parentIndex]);
            }
            else
            // means the element which we inserted has
            // got to its right position
            // so, breaking the loop.
            {
                break;
            }
            // update the child index.
            childIndex = parentIndex;
        }
        // T:O(logn)
    }

    // function to remove minimum element from min heap priority queue
    // int removeMin()
    // {
    //     // if priority queue is empty
    //     // then returning 0 as a sign of being empty
    //     if (isEmpty())
    //     {
    //         return 0;
    //     }
    //     int ans = pq[0]; // for min heap
    //     // exchanging position of oth and last index element
    //     pq[0] = pq[pq.size() - 1];
    //     // removing min element which is now at last index
    //     pq.pop_back();

    //     // down heapify
    //     int parentIndex = 0;
    //     int leftChildIndex = 2 * parentIndex + 1;
    //     int rightChildIndex = 2 * parentIndex + 2;

    //     // condition for the loop to be within the boundary
    //     while (leftChildIndex < pq.size())
    //     {
    //         int minIndex = parentIndex;
    //         if (pq[minIndex] > pq[leftChildIndex])
    //         {
    //             minIndex = leftChildIndex;
    //         }
    //         if (rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex])
    //         {
    //             minIndex = rightChildIndex;
    //         }
    //         if (minIndex == parentIndex)
    //         {
    //             break;
    //         }

    //         int temp = pq[minIndex];
    //         pq[minIndex] = pq[parentIndex];
    //         pq[parentIndex] = temp;

    //         parentIndex = minIndex;
    //         leftChildIndex = 2 * parentIndex + 1;
    //         rightChildIndex = 2 * parentIndex + 2;
    //     }
    //     return ans;
    // }

    int removeMin()
    {
        // in case of empty queue, return 0
        // as a sing that queue is empty
        if (isEmpty())
        {
            cout << "Can't remove element as queue is empty ";
            return 0;
        }
        // store the min heap root
        int ans = pq[0];
        // replace root value with last element's value
        pq[0] = pq[pq.size() - 1];
        // remove the last element
        pq.pop_back();
        // performing down-heapfiy
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        // loop to maintain the heap property
        while (leftChildIndex < pq.size())
        {
            // get index of the lowest data among children
            int lowIndex = (pq[leftChildIndex] < pq[rightChildIndex]) ? leftChildIndex : rightChildIndex;
            // check if parent's data is greater than lower index data
            if (pq[parentIndex] > pq[lowIndex])
            {
                // swapping to maintain heap property
                swap(pq[parentIndex], pq[lowIndex]);
            }
            // all elements are positioned maintaing min heap property
            else
            {
                // break the loop
                break;
            }
            // update the parent and children indexes.
            parentIndex = lowIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        // return the removed element.
        return ans;
        // T:O(logN)
    }
    // function to implement heapify algo
    // this is for min heap
    // takes index i as parameter
    // function performs so that index i maintians the heap condition
    // within the array
    void heapify(int i)
    {
        int n = pq.size(); // size of heap. total no. of elements.
        // as we are gonna built min heap, so take i as smallest index
        int smallest = i;
        // index of left and right child
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        // check min heap condition and update smallest index.
        if (leftIndex < n && pq[smallest] > pq[leftIndex])
        {
            smallest = leftIndex;
        }
        if (rightIndex < n && pq[smallest] > pq[rightIndex])
        {
            smallest = rightIndex;
        }

        // if smallest index is changed, means heapify has been done
        if (smallest != i)
        {
            // swap the numbers
            swap(pq[smallest], pq[i]);
            // perform heapify at smallest index
            heapify(smallest);
        }
        // T:O(logN)
    }
};
