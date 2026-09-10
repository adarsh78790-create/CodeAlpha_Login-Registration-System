#include <iostream>
#include <fstream>
#include <string>
#include <functional>

using namespace std;

const string USER_FILE = "users.txt";

// Create a hash of the password
string hashPassword(const string& password) {
    hash<string> hasher;
    return to_string(hasher(password + "CodeAlphaSalt"));
}

// Check whether username already exists
bool usernameExists(const string& username) {

    ifstream file(USER_FILE);

    string savedUsername;
    string savedPassword;

    while (file >> savedUsername >> savedPassword) {

        if (savedUsername == username) {
            return true;
        }
    }

    return false;
}

// Register a new user
void registerUser() {

    string username;
    string password;

    cout << "\n========== REGISTRATION ==========\n";

    cout << "Enter username: ";
    cin >> username;

    // Validate username
    if (username.length() < 3) {
        cout << "Username must contain at least 3 characters.\n";
        return;
    }

    // Check duplicate username
    if (usernameExists(username)) {
        cout << "Username already exists. Please choose another username.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Validate password
    if (password.length() < 6) {
        cout << "Password must contain at least 6 characters.\n";
        return;
    }

    string hashedPassword = hashPassword(password);

    // Store username and hashed password
    ofstream file(USER_FILE, ios::app);

    if (!file) {
        cout << "Error: Unable to save user details.\n";
        return;
    }

    file << username << " " << hashedPassword << endl;

    file.close();

    cout << "Registration successful!\n";
}

// Login existing user
void loginUser() {

    string username;
    string password;

    cout << "\n============== LOGIN ==============\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    string enteredHash = hashPassword(password);

    ifstream file(USER_FILE);

    if (!file) {
        cout << "No registered users found. Please register first.\n";
        return;
    }

    string savedUsername;
    string savedPassword;

    bool loginSuccessful = false;

    while (file >> savedUsername >> savedPassword) {

        if (savedUsername == username &&
            savedPassword == enteredHash) {

            loginSuccessful = true;
            break;
        }
    }

    file.close();

    if (loginSuccessful) {
        cout << "Login successful!\n";
        cout << "Welcome, " << username << "!\n";
    }
    else {
        cout << "Invalid username or password.\n";
    }
}

int main() {

    int choice;

    cout << "========================================\n";
    cout << "      LOGIN & REGISTRATION SYSTEM\n";
    cout << "========================================\n";

    do {

        cout << "\n1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice. Please select 1, 2 or 3.\n";
        }

    } while (choice != 3);

    return 0;
}
