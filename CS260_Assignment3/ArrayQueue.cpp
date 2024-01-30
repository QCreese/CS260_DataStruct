#include "ArrayQueue.hpp"
#include <stdexcept>

using namespace std;

// Constructor initializes the queue with default capacity and sets front and rear to -1
ArrayQueue::ArrayQueue() : queue(new int[1]), front(-1), rear(-1), capacity(1) {}

// Destructor deallocates memory used by the queue
ArrayQueue::~ArrayQueue() {
    delete[] queue;
}

// Enqueue operation adds an element to the rear of the queue
void ArrayQueue::enqueue(int value) {
    // Resize the queue if it's full
    if ((rear + 1) % capacity == front)
        resize();
    // If the queue is empty, set front to 0
    if (front == -1)
        front = 0;
    // Increment rear and add the value to the queue
    rear = (rear + 1) % capacity;
    queue[rear] = value;
}

// Dequeue operation removes and returns the element from the front of the queue
int ArrayQueue::dequeue() {
    // Throw an exception if the queue is empty
    if (front == -1)
        throw out_of_range("Queue is empty");
    // Get the value of the front element
    int value = queue[front];
    // If the queue has only one element, reset front and rear
    if (front == rear)
        front = rear = -1;
    else // Otherwise, move front to the next element
        front = (front + 1) % capacity;
    // Return the dequeued value
    return value;
}

// Peek operation returns the value of the front element without removing it
int ArrayQueue::peek() {
    // Throw an exception if the queue is empty
    if (front == -1)
        throw out_of_range("Queue is empty");
    // Return the value of the front element
    return queue[front];
}

// Resize operation doubles the capacity of the queue when it's full
void ArrayQueue::resize() {
    // Create a new queue with double the capacity
    int newCapacity = capacity * 2;
    int* newQueue = new int[newCapacity];
    int i = 0;
    int j = front;
    // Copy elements from the old queue to the new one
    while (j != rear) {
        newQueue[i++] = queue[j];
        j = (j + 1) % capacity;
    }
    newQueue[i] = queue[rear];
    // Reset front, rear, and capacity
    front = 0;
    rear = capacity - 1;
    capacity = newCapacity;
    // Deallocate memory used by the old queue and update the queue pointer
    delete[] queue;
    queue = newQueue;
}
