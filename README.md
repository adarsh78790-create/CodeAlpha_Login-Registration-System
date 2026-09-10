# Login and Registration System

A simple C++ console-based Login and Registration System that allows users to create an account and securely verify their credentials during login.

## Features

- User registration
- Username validation
- Password validation
- Duplicate username checking
- Password hashing before storing credentials
- File-based user data storage
- User login and credential verification
- Success and error messages

## How It Works

### Registration

1. User enters a username.
2. The system checks whether the username already exists.
3. User enters a password.
4. The password is hashed before being stored.
5. Username and hashed password are saved in a file.

### Login

1. User enters their username and password.
2. The entered password is hashed.
3. The system compares the username and hashed password with the stored credentials.
4. The user is logged in if the credentials match.

## Validation

- Username must contain at least 3 characters.
- Password must contain at least 6 characters.
- Duplicate usernames are not allowed.
- Invalid login credentials display an error message.

## Technologies Used

- C++
- File Handling
- Functions
- Strings
- Hashing
- Standard Template Library

## File Structure

```text
Login-Registration-System/
│
├── main.cpp
├── README.md
└── users.txt
