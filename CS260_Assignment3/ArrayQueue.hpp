// ArrayQueue.hpp
#ifndef ARRAYQUEUE_HPP
#define ARRAYQUEUE_HPP

// ArrayQueue class for the queue implementation using dynamic array
class ArrayQueue {
private:
    int* queue; // Pointer to the array holding the queue elements
    int front; // Index of the front element in the queue
    int rear; // Index of the rear element in the queue
    int capacity;

    // Method to resize the array when it's full
    void resize();

public:
    ArrayQueue(); // Constructor
    ~ArrayQueue(); // Destructor
    void enqueue(int value); // Method to enqueue (add) an element to the rear of the queue
    int dequeue(); // Method to dequeue (remove) an element from the front of the queue
    int peek(); // Method to peek at the front element of the queue without removing it
};

#endif // ARRAYQUEUE_HPP
