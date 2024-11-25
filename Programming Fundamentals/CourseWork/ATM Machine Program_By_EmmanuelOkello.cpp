#include <iostream>
#include <string>
using namespace std;
// Global variables to hold the current user's ID, password, and balance
int stored_user_id; /*Store user entered user*/
int stored_user_password; //Handle user entered password
double stored_user_balance = 0.0; // Handle user balance

// Function to display the main menu and get user User_entered_choice
string DisplayMainMenu() {
    cout << "Hi! Welcome to the ATM Machine\n" << endl;
    cout << "Please select an option from the menu below:\n";
    cout << "l -> "<<"🗝️ "<<"Login" << endl;
    cout << "c -> "<<"🏦 "<<"Create New Account" << endl;
    cout << "q -> "<<"🏃‍♀️ "<<"Quit" << endl;

    // Request user input so the program can continue
    string user_menu_User_entered_choice;
    cout << ">";
    cin >> user_menu_User_entered_choice;

    return user_menu_User_entered_choice;
}

// Function to display the transaction menu
char DisplayTransactionMenu() {
    cout << "\n***ACCESS GRANTED***\n" << endl;
    cout << "d ->"<< "➕ "<<"Deposit Money" << endl;
    cout << "w ->"<< "➖ "<<"Withdraw Money" << endl;
    cout << "r ->"<< "⚖️ "<<" Request Balance" << endl;
    cout << "q ->"<<"🏃‍♂️ "<<"Quit"<<endl;

    char User_entered_choice;
    cout << ">";
    cin >> User_entered_choice;
    return User_entered_choice;
}

// Function to create a new account
void CreateAccount() {
    cout << "Please enter your user id: ";
    cin >> stored_user_id;
    cout << "Please enter your password: ";
    cin >> stored_user_password;

    // Initialize balance for the new account
    stored_user_balance = 0.0;

    cout << "Thank You! Your account has been created!" << endl;
}

// Function to handle user login
bool Login() {
    int user_id, password;
    cout << "Please enter your user id: ";
    cin >> user_id;
    cout << "Please enter your password: ";
    cin >> password;

    // Check if the provided credentials match the existing account
    if (user_id == stored_user_id && password == stored_user_password) {
        return true;
    } else {
        cout << "*** LOGIN FAILED! ***" << endl;
        return false;
    }
}

// Function to handle transactions
void HandleTransactions() {
    char User_entered_choice;

    do {
        User_entered_choice = DisplayTransactionMenu();
        switch (User_entered_choice) {
            case 'd': {
                double deposit;
                cout << "Amount of deposit: $";
                cin >> deposit;
                stored_user_balance += deposit;
                cout << "Deposit successful." << endl;
                break;
            }
            case 'w': {
                double withdrawal;
                cout << "Amount of withdrawal: $";
                cin >> withdrawal;
                if (withdrawal <= stored_user_balance) {
                    stored_user_balance -= withdrawal;
                    cout << "Withdrawal successful." << endl;
                } else {
                    cout << "Insufficient funds." << endl;
                }
                break;
            }
            case 'r': {
                cout << "Your balance is $" << stored_user_balance << "." << endl;
                break;
            }
            case 'q':
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid User_entered_choice. Please try again." << endl;
        }
    } while (User_entered_choice != 'q');
}

int main() {
    string MainMenuOption;

    do {
        MainMenuOption = DisplayMainMenu();

        if (MainMenuOption == "c") {
            CreateAccount();
        } else if (MainMenuOption == "l") {
            if (Login()) {
                HandleTransactions();
            }
        } else if (MainMenuOption == "q") {
            cout << "Now exiting the program. Goodbye!" << endl;
        } else {
            cout << "Invalid User_entered_choice. Please try again." << endl;
        }

    } while (MainMenuOption != "q");

    return 0;
}
