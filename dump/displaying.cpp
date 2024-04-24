#include <iostream>

// ANSI escape codes for text formatting
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void displayMenu() {
    // Clear screen
    std::cout << "\033[2J\033[1;1H";

    // Title
    std::cout << ANSI_COLOR_YELLOW << "Welcome to Social Media Management System\n\n" << ANSI_COLOR_RESET;

    // Menu options
    std::cout << "1. Login\n";
    std::cout << "2. Signup\n";
    std::cout << "3. Help\n";
    std::cout << "4. About\n";
}

int main() {
    int choice;

    do {
        displayMenu();

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        // Handle user choice
        switch(choice) {
            case 1:
                std::cout << "You selected Login.\n";
                // Add login functionality here
                break;
            case 2:
                std::cout << "You selected Signup.\n";
                // Add signup functionality here
                break;
            case 3:
                std::cout << "You selected Help.\n";
                // Add help functionality here
                break;
            case 4:
                std::cout << "You selected About.\n";
                // Add about functionality here
                break;
            default:
                std::cout << ANSI_COLOR_RED << "Invalid choice. Please enter a number from 1 to 4.\n\n" << ANSI_COLOR_RESET;
        }
    } while (choice < 1 || choice > 4);

    return 0;
}
