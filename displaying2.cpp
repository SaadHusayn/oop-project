#include <iostream>
#include <conio.h> // for _getch()

void displayMenu(int currentOption) {
    system("cls"); // Clear screen

    // Header
    std::cout << "==============================\n";
    std::cout << "  Welcome to Social Media Management System\n";
    std::cout << "==============================\n\n";

    // Menu options
    const char* options[] = {"Login", "Signup", "Help", "About"};
    for (int i = 0; i < 4; ++i) {
        if (currentOption == i) {
            std::cout << "  \x1b[97m\x1b[44m> " << options[i] << " <\x1b[0m\n"; // Selected option
        } else {
            std::cout << "    " << options[i] << "\n";
        }
    }
}

int main() {
    int choice = 0;
    int currentOption = 0;
    char key;

    do {
        displayMenu(currentOption);

        key = _getch();

        switch (key) {
            case '1':
            case '2':
            case '3':
            case '4':
                choice = key - '0';
                break;
            case -32: // Arrow key
                key = _getch();
                switch (key) {
                    case 72: // Up arrow
                        currentOption = (currentOption - 1 + 4) % 4;
                        break;
                    case 80: // Down arrow
                        currentOption = (currentOption + 1) % 4;
                        break;
                }
                break;
            case 13: // Enter key
                choice = currentOption + 1;
                break;
        }

    } while (choice == 0);

    // Handle user choice
    switch (choice) {
        case 1:
            std::cout << "\nYou selected Login.\n";
            // Add login functionality here
            break;
        case 2:
            std::cout << "\nYou selected Signup.\n";
            // Add signup functionality here
            break;
        case 3:
            std::cout << "\nYou selected Help.\n";
            // Add help functionality here
            break;
        case 4:
            std::cout << "\nYou selected About.\n";
            // Add about functionality here
            break;
    }

    return 0;
}
