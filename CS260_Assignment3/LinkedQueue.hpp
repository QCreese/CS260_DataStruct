// LinkedQueue.hpp
#ifndef LINKEDQUEUE_HPP
#define LINKEDQUEUE_HPP

// Node class for individual elements in the queue
class Node {
public:
    int value;
    Node* next;
    Node(int val);
};

// LinkedQueue class for the queue implementation using linked list
class LinkedQueue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear; // Pointer to the rear of the queue

public:
    LinkedQueue(); // Constructor
    ~LinkedQueue(); // Destructor
    void enqueue(int value); // Method to enqueue (add) an element to the rear of the queue
    int dequeue(); // Method to dequeue (remove) an element from the front of the queue
    int peek(); // Method to peek at the front element of the queue without removing it
};

#endif // LINKEDQUEUE_HPP
