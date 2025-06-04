/*
  Filename: 01_introToQueue.cpp
  Purpose : Introduction to Queue Data Structure (DSA Overview)

  -------------------------------------------------------------------------------
  QUEUE DATA STRUCTURE
  -------------------------------------------------------------------------------

  A **Queue** is a **linear data structure** that follows the **FIFO** principle,
  i.e., **First In, First Out**. This means that the element added first to the
  queue will be the one to be removed first, just like a real-life queue.

  ------------------------------------------------------------------------------
  BASIC CHARACTERISTICS
  ------------------------------------------------------------------------------

  - **FIFO Order**: The first element inserted is the first one removed.
  - **Linear Structure**: Elements are organized sequentially.
  - **Two Key Indices**:
      * Front: Points to the first element (for deletion).
      * Rear : Points to the last element (for insertion).

  ------------------------------------------------------------------------------
  QUEUE OPERATIONS
  ------------------------------------------------------------------------------

  1. **enqueue(x)** → Inserts an element `x` at the rear of the queue.
  2. **dequeue()**  → Removes the front element from the queue.
  3. **front()**    → Returns (but does not remove) the element at the front.
  4. **isEmpty()**  → Checks whether the queue is empty.
  5. **isFull()**   → (For fixed-size queue) Checks whether the queue is full.
  6. **size()**     → Returns the current number of elements in the queue.

  ------------------------------------------------------------------------------
  QUEUE IMPLEMENTATIONS
  ------------------------------------------------------------------------------

  Queues can be implemented using:
  - Arrays
  - Linked Lists
  - Stacks (for some special types like queue using two stacks)
  - Circular Arrays (for circular queues)
  - Libraries/Standard Template Libraries (STL)

  ------------------------------------------------------------------------------
  TYPES OF QUEUES
  ------------------------------------------------------------------------------

  1. **Simple Queue**:
      - Standard FIFO behavior.

  2. **Circular Queue**:
      - The last position is connected back to the first to make a circle.
      - Helps in utilizing space more efficiently.

  3. **Priority Queue**:
      - Elements are dequeued based on priority, not FIFO.
      - Higher priority elements are served first.

  4. **Deque (Double-Ended Queue)**:
      - Insertion and deletion can be done from both ends.
      - Can act as both a queue and a stack.

  ------------------------------------------------------------------------------
  USE CASES / APPLICATIONS
  ------------------------------------------------------------------------------

  - **CPU Scheduling**: Processes are scheduled in FIFO order.
  - **Disk Scheduling**: Managing read/write requests to disks.
  - **Breadth-First Search (BFS)** in graphs/trees.
  - **Handling Requests**: Like printer queues or call center queues.
  - **Buffering**: Data streaming, IO Buffers, etc.
  - **Resource Sharing**: Managing access to limited resources.
  - **Messaging Queues**: For inter-process communication (e.g., RabbitMQ, Kafka).

  ------------------------------------------------------------------------------
  REAL-LIFE ANALOGIES
  ------------------------------------------------------------------------------

  - People standing in line at a ticket counter.
  - Print jobs waiting in a printer’s queue.
  - Orders waiting to be processed in a restaurant.

  ------------------------------------------------------------------------------
  SUMMARY
  ------------------------------------------------------------------------------

  - Queue is a fundamental data structure in computer science.
  - Ideal for situations where processing order must be preserved.
  - Can be implemented in multiple ways and extended to suit various scenarios.

  ------------------------------------------------------------------------------
  NEXT STEPS
  ------------------------------------------------------------------------------

  -> In the next files, we will explore:
     - Array-based implementation of queues.
     - Queue using STL (Standard Template Library).
     - Circular queue.
     - Queue using linked list.
     - Priority queues and deques.
*/
