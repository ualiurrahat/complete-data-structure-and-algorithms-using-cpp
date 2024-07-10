#include <bits/stdc++.h>

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
    int size()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getMin()
    {
        // if priority queue is empty, returning 0 as a sign
        // that priority queue is zero;
        if (isEmpty())
        {
            return 0;
        }
        // otherwise returning the min element
        return pq[0]; // in min heap.
    }
    // function to insert an element in the min priority queue
    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
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
    //     int rightChildIndex = 2 * parentIndex + 1;

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
        if (isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < pq.size() || rightChildIndex < pq.size())
        {

            int lowIndex = (pq[leftChildIndex] < pq[rightChildIndex]) ? leftChildIndex : rightChildIndex;
            if (pq[parentIndex] > pq[lowIndex])
            {
                swap(pq[parentIndex], pq[lowIndex]);
            }
            else
            {
                break;
            }
            parentIndex = lowIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return ans;
    }
};
