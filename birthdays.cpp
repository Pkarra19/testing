/**
 * birthdays.cpp
 * 37/60 oneeeee
 * Pranav Karra
 * pkarra
 *
 * EECS 183: Project 2
 *
 * This program asks the user for your birthday along with various other options to
 * choose from. It returns the day you were born, the next 10 leap years or finishes
 * the program.
 */

#include <iostream>
#include <string>

using namespace std;


/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  prints out the initial heading for the program
 */
void printHeading();


/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  prints out the final greeting for the program
 */
void printCloser();


/**
 * Requires: nothing
 * Modifies: cout 
 * Effects:  prints the menu
 */
void printMenu();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  prints the menu
 *           reads the input from the user
 *           checks to make sure the input is within range for the menu
 *           If not prints "Invalid menu choice"
 *           continues to print the menu and read an input until 
 *           a valid one is entered
 *           returns the users choice of menu options
 */
int getMenuChoice();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects:  returns 'true' if the date is in the limits
 *           of the Gregorian calendar otherwise returns 'false'
 */
bool isGregorianDate(int month, int day, int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: year is a Gregorian year
 * Modifies: nothing
 * Effects:  returns 'true' if the year is a leap year
 *           otherwise returns 'false'
 */
bool isLeapYear(int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects:  returns 'true' if the date is valid
 *           otherwise returns 'false'
 *           see the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * Modifies: nothing
 * Effects:  returns the value that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: day (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * Modifies: cout
 * Effects:  prints the day you were born on
 *           Sunday, Monday, ..., Saturday
 */
void printDayOfBirth(int day);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  asks for the Month/day/year of their birth
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt
 */
void determineDayOfBirth();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Base Project
 * Requires: nothing
 * Modifies: cout
 * Effects: prints "Under Construction"
 *
 * S'more version of this function
 * Requires: nothing
 * Modifies: cout, cin 
 * Effects:  reads the month and day of birthday
 *           loops through 10 years printing the day of the week
 *           the birthday falls on
 *           If the month/day is not valid, it prints nothing
 */
void print10Birthdays();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: nothing
 * Modifies: cin, cout
 * Effects:  asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 */
void print10LeapYears();


int main() {

    printHeading();
    // get menu choice from the function getMenuChoice() and assign to choice
    int choice;
    choice = getMenuChoice();
    
    while (choice != 4){
        if (choice == 1) {
            determineDayOfBirth();
           choice = getMenuChoice();
        }
        else if (choice == 2 ){
            print10LeapYears();
           choice = getMenuChoice();
        }
        else if (choice == 3 ){
            print10Birthdays();
           choice = getMenuChoice();
        }
    }
    printCloser();
    return 0;
}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Determine birthdays for the next 10 years" << endl;
    cout << "4) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}

int getMenuChoice() {
    printMenu();
    
    // check for invalidity and then return input
    int input;
    cin >> input;
    while (input > 4 || input < 1){
        cout << "Invalid menu choice";
        printMenu();
        cin >> input;
    }
       return input;
}

bool isGregorianDate(int month, int day, int year) {

   // if else conditions to check if the argument isGregorian
    if (year > 1752){
        return true;
    }
    if (year < 1752){
        return false;
    }
    if (year == 1752){
        if (month == 9 && day <= 13){
            return false;
        }
        else if (day > 13){
            return true;
        }
    }
    if (month > 9 && year > 1752){
        return true;
    }
    else{
        return false;
    }
    // returning false to avoid compile error
    return false;
}

bool isLeapYear(int year) {
    
    // if else conditions to check if year is leap year or not and return bool value
    if (year % 4 == 0 ){
        return true;
    }
    else if (year % 100 != 0 && year % 400 == 0){
        return true;
    }
    // returning false to avoid compile error
    else return false;
}


bool isValidDate(int month, int day, int year) {
    
    // if else conditions to check if valid is inputted and return bool value
    if (month > 12){
        return false;
    }
    if (!isGregorianDate(month, day, year)){
        return false;
    }
    if (isLeapYear(year) && month == 2){
        if (day >=1 && day <= 29){
            return true;
        }
        else if (day >=1 && day <=28){
            return false;
        }
    }
    if (!isLeapYear(year) && month == 2){
        if (day >=1 && day <=28){
            return true;
        }
        else return false;
    }
    
    // different cases for different months error checking
    if ((month == 4 || month == 6 || month == 9 || month == 11)
            && (day >= 1 && day <= 30)){
        return true;
    }
    
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
              month == 10 || month == 12) && (day >=1 && day <=31)){
        return true;
    }
    else return false;
    
    
}


int determineDay(int month, int day, int year) {
    
   // if else conditions to determine day an input recieved is using zellers
    if (isValidDate(month, day, year)){
        if (month == 1){
            month = 13;
            year--;
        }
        if (month == 2){
            month = 14;
            year--;
        }
        int firstPartOfYear, lastPartOfYear, zeller;
        firstPartOfYear =  year/100;
        lastPartOfYear = year % 100;
        
        zeller = (day + 13*(month+1)/5 + lastPartOfYear + lastPartOfYear/4 + firstPartOfYear/4 + 5*firstPartOfYear);
        zeller = zeller % 7;
        return zeller;
    }
    // returning 0 to avoid compile error
    else return false;
    

}


void printDayOfBirth(int day) {
    
    // comparing the numeric output from determineDay() and assigning the following day
    if (day == 0 ){
        cout << "Saturday" << endl;
    }
    if (day == 1 ){
        cout << "Sunday" << endl;
    }
    if (day == 2 ){
        cout << "Monday" << endl;
    }
    if (day == 3 ){
        cout << "Tuesday" << endl;
    }
    if (day == 4 ){
        cout << "Wednesday" << endl;
    }
    if (day == 5 ){
        cout << "Thursday" << endl;
    }
    if (day == 6 ){
        cout << "Friday" << endl;
    }
    
}


void determineDayOfBirth() {
    
   // function to determine the day of birth by receiving input and then using
   // above functions to determine it
    int day, month, year;
    char x, y;
    
    cout << "Enter your date of birth" << endl;
    cout << "format: month / day / year  -->" << endl;
    
    cin >> month;
    cin >> x;
    cin >> day;
    cin >> y;
    cin >> year;
    
    if (!isValidDate(month,day,year)){
        cout << "Invalid date" << endl;
    }
    else if (isValidDate(month,day,year)){
        int answer;
        answer = determineDay(month,day,year);
        cout << "You were born on a: ";
        printDayOfBirth(answer);
        cout << "Have a great birthday!!!" << endl;
    }
    return;
}

void print10Birthdays() {

    // print statement for when this function is called
    cout << "Under Construction" << endl;
    return;
}

void print10LeapYears() {
    
    // print the next 10 leap years for the given input by using for loop
    int year;
    cout << "Enter year -->";
    cin >> year;
    if (isLeapYear(year)){
        for (int i = 0; i <=10; i++){
            year += 4;
            cout << "Leap year is " << year << endl;
        }
    }
    // if not a leap year then increment and check if it's leap year again
    // keep doing that until it's leap year and then print out the list
    else if (!isLeapYear(year)){
        while (!isLeapYear(year)){
            year += 1;
        }
        for (int i = 0; i <=11; i++){
            cout << "Leap year is " << year << endl;
            year += 4;
        }
    }
}
