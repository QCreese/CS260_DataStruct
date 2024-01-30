/*Command line code for testing:
clang++ -o test LinkedQueue.cpp ArrayQueue.cpp test.cpp && ./test
*/

#include <iostream>
#include <cassert>
#include "LinkedQueue.hpp"
#include "ArrayQueue.hpp"

using namespace std;

// Test cases for LinkedQueue class
void testLinkedListQueue() {
    LinkedQueue linkedQueue;

    // Test enqueue and peek operations
    linkedQueue.enqueue(1);
    assert(linkedQueue.peek() == 1); // Check if the front element is 1

    linkedQueue.enqueue(2);
    linkedQueue.enqueue(3);
    assert(linkedQueue.peek() == 1); // Check if the front element is still 1

    // Test dequeue operation
    assert(linkedQueue.dequeue() == 1); // Check if the dequeued element is 1
    assert(linkedQueue.dequeue() == 2); // Check if the dequeued element is 2
    assert(linkedQueue.dequeue() == 3); // Check if the dequeued element is 3

    // Test dequeue operation on an empty queue
    try {
        linkedQueue.dequeue();
    } catch (const out_of_range& e) {
        // Check if the expected exception is thrown when dequeueing from an empty queue
        assert(string(e.what()) == "Queue is empty");
    }
}

// Test cases for ArrayQueue class
void testArrayQueue() {
    ArrayQueue arrayQueue;

    // Test enqueue and peek operations
    arrayQueue.enqueue(1);
    assert(arrayQueue.peek() == 1); // Check if the front element is 1

    arrayQueue.enqueue(2);
    arrayQueue.enqueue(3);
    assert(arrayQueue.peek() == 1); // Check if the front element is still 1

    // Test dequeue operation
    assert(arrayQueue.dequeue() == 1); // Check if the dequeued element is 1
    assert(arrayQueue.dequeue() == 2); // Check if the dequeued element is 2
    assert(arrayQueue.dequeue() == 3); // Check if the dequeued element is 3

    // Test dequeue operation on an empty queue
    try {
        arrayQueue.dequeue();
    } catch (const out_of_range& e) {
        // Check if the expected exception is thrown when dequeueing from an empty queue
        assert(string(e.what()) == "Queue is empty");
    }
}

int main() {
    // Run tests for LinkedQueue
    cout << "Running tests for LinkedQueue..." << endl;
    testLinkedListQueue();
    cout << "All tests for LinkedQueue passed!" << endl;

    // Run tests for ArrayQueue
    cout << "Running tests for ArrayQueue..." << endl;
    testArrayQueue();
    cout << "All tests for ArrayQueue passed!" << endl;

    return 0;
}
