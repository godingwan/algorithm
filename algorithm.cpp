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
#include<iomanip>

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

void display(string *bookTitle, int *bookID, double *bookPrice){
  cout << "**** LINEAR SEARCH ****\n";
  cout << "Book ID\t\t\tTitle\t\t\t\tCost\n";
  for (int i=0; i<10; i++){
    cout << bookID[i] << "\t " << setw(40) << left << bookTitle[i] << "\t$" << bookPrice[i] << "\n";
  }
  cout << endl;
}

int linearSearch(int *bookID, int id){
  for (int i; i<10; i++){
    if (bookID[i] == id){
      return i;
    }
  }
  return 0;
}

double calcTotalCost(double *bookPrice, int index, int qty){
  double price = bookPrice[index];
  return price *= qty;
}

void navigateMenu(int choice){
  // Creating the arrays for the searching algorithm
  string bookTitle[] = {"Starting out with C++", "Java Programming", "Software Structures", "Design and Analysis of Algorithms", "Computer Graphics", "Artificial Intelligence: A Modern Approach", "Probability and Statistics", "Cognitive Science", "Modern Information Retrieval", "Speech and Language Processing"};
  int bookID[] = {1101, 1211, 1333, 1456, 1567, 1642, 1699, 1755, 1800, 1999};
  double bookPrice[] = {112.32, 73.25, 54.00, 67.32, 135.00, 173.22, 120.00, 42.25, 32.11, 123.75};
  // Create variables to be used in below functions
  int id = 0, copies = 0, index;
  double totalPrice;


  switch(choice)
  {
    case 1:{
      // Function call to Linear Search
      display(bookTitle, bookID, bookPrice);
      cout << "Please enter the book ID you wish to purchase: ";
      cin >> id;
      cout << "How many copies you wish to purchase: ";
      cin >> copies;
      index = linearSearch(bookID, id);
      while (index == 0){
        cout << "That is not an existing book ID. Please enter the book ID you wish to purchase: ";
        cin >> id;
        index = linearSearch(bookID, id);
      }
      totalPrice = calcTotalCost(bookPrice, index, copies);
      cout << "Book ID: " << id << endl;
      cout << "Book Title: " << bookTitle[index] << endl;
      cout << "Number of books bought: " << copies << endl;
      cout << "Total Cost: $" << setprecision(2) << fixed << totalPrice << endl;
      break;
    }
    case 2:{
      // Function call to Binary Search
      break; 
    }
    case 3:{
      // Function call to Bubble Sort
      break;
    }
    case 4:{
      // Function call to Selection Sort
      break;
    }
  }
}

int main(){
  int choice = 0;
  while (choice != 5){ // Continue to display the menu until they choose the quit option
    choice = displayMenu();
    navigateMenu(choice);
  }

  return 0;
}
