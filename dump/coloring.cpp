// C++ program for the coloring the 
// background and text with 
// different color 
#include <iostream> 

// Header file to change color of 
// text and background 
#include <windows.h> 
using namespace std; 

// Driver Code 
int main() 
{ 
	// Color of the console 
	HANDLE console_color; 
	console_color = GetStdHandle( 
		STD_OUTPUT_HANDLE); 

	// Print different colors from 1 
	// to 50 on the output screen 
	for (int P = 1; P < 50; P++) { 

		// P is color code of the 
		// corresponding color 
		SetConsoleTextAttribute( 
			console_color, P); 

		// Print Statement 
		cout << P << " Hello Geeks, "
			<< "good night!!!"<<endl; 
	} 

	return 0; 
} 
