#include <iostream>
#include <cstring> // Include for string functions like strcpy

class StringHolder {
private:
    static const int MAX_LENGTH = 100; // Maximum length for the character array
    char data[MAX_LENGTH]; // Character array to hold the string

public:
    // Getter for the string data
    const char* getData() const {
        return data;
    }

    // Setter for the string data
    void setData(const char* newData) {
        // Use strncpy to safely copy the string into data array
        strncpy(data, newData, MAX_LENGTH - 1);
        data[MAX_LENGTH - 1] = '\0'; // Ensure null termination
    }
};

int main() {
    StringHolder sh;

    // Set data using setter function
    sh.setData("Hello, World! is nice thing");

    // Get and display data using getter function
    std::cout << "Data: " << sh.getData() << std::endl;

    return 0;
}
