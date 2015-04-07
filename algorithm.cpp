/*
  Author: Joshua Lee
  Date: 4/6/2015
  Description: Program that will display a menu and allow the user to choose which 
               search or sort algorithm to use until the user quits.
  Algorithm:
    1) Display a menu of the choices the user can choose
    2) From the selection perform the search or sort that they chose
    3) If it is a search function display the book in table format
      a) take in the Book ID and the # of books bought
      b) output the total cost
    4) If it is a sorting function
      a) display the unsorted array of 1,000 random numbers and then sort them
      b) display the sorted array
    5) Continue to loop through the menu until the user chooses to quit
    6) Bonus: add a execution time calculation to both the searching and sorthing 
              and display it to the user
*/
#include<iostream>
#include<string>

using namespace std;

int displayMenu(){ // Function to display and return the user choice
  int choice;
  cout << "**** SEARCHING & SORTING MENU ****\n\n";
  cout << "\t1. Linear Search\n";
  cout << "\t2. Binary Search\n";
  cout << "\t3. Bubble Sort\n";
  cout << "\t4. Selection Sort\n";
  cout << "\t5. Quit\n\n";
  cout << "PLease enter your choice: ";
  cin >> choice;
  return choice;
}

int main(){
  int choice = 0;
  while (choice != 5){ // Continue to display the menu until they choose the quit option
    choice = displayMenu();
  }

  return 0;
}
