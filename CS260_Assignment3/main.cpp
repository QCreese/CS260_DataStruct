/*Command line code to run program:
g++ -o main main.cpp LinkedQueue.cpp ArrayQueue.cpp
*/
#include <iostream>
#include <stdexcept>
#include "LinkedQueue.hpp"
#include "ArrayQueue.hpp"

using namespace std;

// Function to display menu options
void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice, value;
    LinkedQueue linkedQueue; // Create an instance of LinkedQueue
    ArrayQueue arrayQueue; // Create an instance of ArrayQueue

    // Main loop to interact with the user
    while (true) {
        displayMenu(); // Display the menu options
        cin >> choice; // Read user's choice

        switch (choice) {
            case 1: // Enqueue operation
                cout << "Enter value to enqueue: ";
                cin >> value;
                linkedQueue.enqueue(value); // Enqueue value in LinkedQueue
                arrayQueue.enqueue(value); // Enqueue value in ArrayQueue
                break;
            case 2: // Dequeue operation
                try {
                    cout << "Dequeued value from LinkedQueue: " << linkedQueue.dequeue() << endl;
                    cout << "Dequeued value from ArrayQueue: " << arrayQueue.dequeue() << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl; // Handle out-of-range exception
                }
                break;
            case 3: // Peek operation
                try {
                    cout << "Front element of LinkedQueue: " << linkedQueue.peek() << endl;
                    cout << "Front element of ArrayQueue: " << arrayQueue.peek() << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl; // Handle out-of-range exception
                }
                break;
            case 4: // Exit program
                cout << "Exiting program." << endl;
                return 0;
            default: // Invalid choice
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }

    return 0;
}
