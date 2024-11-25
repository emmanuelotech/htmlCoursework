#include <iostream>
using namespace std;

// Constants for account storage
const int MAX_ACCOUNTS = 100;
int user_ids[MAX_ACCOUNTS];
int user_passwords[MAX_ACCOUNTS];
int account_count = 0;


// Function to only display the main menu and get user choice
//Or obtain what the user enters as their option on the console of the program.

string DisplayMainMenu() {
    cout << "Hi! Welcome to the ATM Machine \n" << endl;
    cout << "Please select an option from the menu below:\n";
    // Showing Menu Options to the user
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit \n" << endl;

    // Request User input
    string user_menu_choice;
    // Requests user to enter something either l for login etc.
    cout << ">";
    cin >> user_menu_choice;

    return user_menu_choice;
}

// Show for all logged-in successfully users:
void DisplayTransactionMenu(){
    cout << "\n ***ACCESS GRANTED*** \n" << endl;
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
}

// Asking user to supply their user ID
int AskForUserId() {
    cout << "Please enter your user id: ";
    int user_id;
    cin >> user_id;
    return user_id;
}

// Asks for user password that is registered with the system
int AskForUserPassword() {
    cout << "Please enter your password: ";
    int password;
    cin >> password;
    return password;
}

// Function to create a new account
void CreateAccount() {
    if (account_count >= MAX_ACCOUNTS) {
        cout << "Account creation limit reached." << endl;
        return;
    }
    int user_id, password;
    cout << "Please enter your user id: ";
    cin >> user_id;
    cout << "Please enter your password: ";
    cin >> password;

    // Store the new account information
    user_ids[account_count] = user_id;
    user_passwords[account_count] = password;
    account_count++;

    cout << "Thank You! Your account has been created!" << endl;
}

// Function to check if the login is successful for the users
bool Login(int &logged_in_user_id) {
    int user_id, password;
    cout << "Please enter your user id: ";
    cin >> user_id;
    cout << "Please enter your password: ";
    cin >> password;

    // Check user credentials if it exists in the system.
    for (int i = 0; i < account_count; i++) {
        if (user_ids[i] == user_id && user_passwords[i] == password) {
            logged_in_user_id = user_id;
            return true;
        }
    }
    cout << "*** LOGIN FAILED! ***" << endl;
    return false;
    string MainMenuOption;
}

// Function to handle transactions
void HandleTransactions() {
    string choice;
    double balance = 0.0;

    do {
        choice = DisplayTransactionMenu();
        switch (choice) {
            case 'd': {
                double deposit;
                cout << "Amount of deposit: $";
                cin >> deposit;
                balance += deposit;
                break;
            }
            case 'w': {
                double withdrawal;
                cout << "Amount of withdrawal: $";
                cin >> withdrawal;
                if (withdrawal <= balance) {
                    balance -= withdrawal;
                } else {
                    cout << "Insufficient funds." << endl;
                }
                break;
            }
            case 'r': {
                cout << "Your balance is $" << balance << "." << endl;
                break;
            }
            case 'q':
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'q');
}

int main() {
    string MainMenuOption;
    int logged_in_user_id;

    do {
        MainMenuOption = DisplayMainMenu();

        if (MainMenuOption == "c"){
            CreateAccount();
        } else if (MainMenuOption == "l") {
            if (Login(logged_in_user_id)) {
                HandleTransactions();
            }
        } else if (MainMenuOption == "q") {
            cout << "Exiting the program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (MainMenuOption != "q");

    return 0;
}
