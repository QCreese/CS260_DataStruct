#include "LinkedQueue.hpp"
#include <stdexcept>

using namespace std;

// Node constructor
Node::Node(int val) : value(val), next(nullptr) {}

// LinkedQueue constructor
LinkedQueue::LinkedQueue() : front(nullptr), rear(nullptr) {}

// LinkedQueue destructor
LinkedQueue::~LinkedQueue() {
    // Delete all nodes in the queue
    while (front) {
        Node* temp = front; // Store the current front node
        front = front->next; // Move front pointer to the next node
        delete temp; // Delete the current front node
    }
}

// Enqueue operation
void LinkedQueue::enqueue(int value) {
    Node* newNode = new Node(value); // Create a new node with the provided value
    if (!front) { // If the queue is empty
        front = newNode; // Set both front and rear pointers to the new node
        rear = newNode;
    } else { // If the queue is not empty
        rear->next = newNode; // Set the next pointer of the current rear node to the new node
        rear = newNode; // Update the rear pointer to the new node
    }
}

// Dequeue operation
int LinkedQueue::dequeue() {
    if (!front) // If the queue is empty
        throw out_of_range("Queue is empty"); // Throw an exception
    int value = front->value; // Get the value of the front node
    Node* temp = front; // Store the current front node
    front = front->next; // Move front pointer to the next node
    delete temp; // Delete the previous front node
    if (!front) // If the queue becomes empty after dequeue
        rear = nullptr; // Update the rear pointer to nullptr
    return value; // Return the dequeued value
}

// Peek operation
int LinkedQueue::peek() {
    if (!front) // If the queue is empty
        throw out_of_range("Queue is empty"); // Throw an exception
    return front->value; // Return the value of the front node
}

