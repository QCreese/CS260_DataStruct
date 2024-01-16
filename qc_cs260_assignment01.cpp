/* Assignment 01 Bag of Marbles
Quentin Creese
Jess
Class: CS260 Datta Structures
Date due: 01/15/24
Description: This program depicts a bag of marbles which the user can interact with.
It also includes a user friendly menu which allows the user to add a marble by color,
draw a random marble, and shows the marbles within the user's bag. 
*/
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class MarbleBag {
private:
    std::vector<std::string> marbles;

public:
    // Function to add a marble to the bag
    void addMarble(const std::string& color) {
        marbles.push_back(color);
    }

    // Function to draw a random marble from the bag
    std::string drawMarble() {
        if (marbles.empty()) {
            return "The bag is empty!";
        }

        // Seed the random number generator with the current time
        std::srand(static_cast<unsigned int>(std::time(0)));

        // Generate a random index within the range of marbles vector
        int randomIndex = rand() % marbles.size();

        // Retrieve the marble at the random index
        std::string drawnMarble = marbles[randomIndex];

        // Remove the drawn marble from the bag
        marbles.erase(marbles.begin() + randomIndex);

        return drawnMarble;
    }

    // Function to display the marbles in the bag
    void displayMarbles() const {
        if (marbles.empty()) {
            std::cout << "The bag is empty." << std::endl;
        } else {
            std::cout << "Marbles in the bag: ";
            for (const auto& marble : marbles) {
                std::cout << marble << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    MarbleBag bag;

    // Interactive menu for the user
    int choice;
    do {
        std::cout << "\nMarble Bag Menu:\n";
        std::cout << "1. Add Marble\n";
        std::cout << "2. Draw Marble\n";
        std::cout << "3. Display Marbles\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string color;
                std::cout << "Enter the color of the marble: ";
                std::cin >> color;
                bag.addMarble(color);
                std::cout << "Marble added to the bag.\n";
                break;
            }
            case 2: {
                std::string drawnMarble = bag.drawMarble();
                std::cout << "Drawn marble: " << drawnMarble << std::endl;
                break;
            }
            case 3:
                bag.displayMarbles();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}

