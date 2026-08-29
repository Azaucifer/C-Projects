# 🏦 ATM Banking System

A command-line **ATM Banking System written in C** that simulates basic banking operations through an interactive menu-driven interface.

Users can create accounts, log in using an automatically generated account number and 4-digit PIN, check their balance, deposit and withdraw money, transfer funds to other accounts, and log out.

Account data is stored in a `bank.csv` file, allowing information to **persist between program runs**. 💾

---

## ✨ Features

* 👤 Create a new bank account
* 🔐 Login using account number and 4-digit PIN
* 🆔 Automatically generate account numbers
* 💰 Check account balance
* 💵 Deposit money
* 💸 Withdraw money
* 🔄 Transfer money to another account
* 🚫 Prevent withdrawals when funds are insufficient
* 🔎 Verify receiver account before transfers
* 🚪 Logout securely from the account menu
* 💾 Save account information to a CSV file
* 📂 Load existing accounts when the program starts
* 🔄 Persistent account data using file I/O

---

## 🧾 Account Record

Each account contains:

| Field             | Type       | Description               |
| ----------------- | ---------- | ------------------------- |
| 🆔 Account Number | `int`      | Unique account identifier |
| 👤 Name           | `char[50]` | Account holder's name     |
| 🔐 PIN            | `char[5]`  | 4-digit account PIN       |
| 💰 Balance        | `float`    | Current account balance   |

The account information is represented using a C `struct`:

```c
typedef struct
{
    int accountnum;
    char name[50];
    char pin[5];
    float balance;
} Account;
```

---

## 🖥️ Main Menu

When the program starts, users are presented with the following menu:

```text
==== BANK ATM MENU ====
1. Create new Account
2. Login
3. Save & Exit
Please enter a choice:
```

---

## ⚙️ How It Works

### 1️⃣ Create a New Account

The user provides:

* 👤 Name
* 🔐 4-digit PIN

The system then:

1. Validates the PIN.
2. Generates an account number.
3. Initializes the account balance to `$0.00`.
4. Displays the newly created account details.
5. Saves the account to `bank.csv`.

Example:

```text
****************************** Congratulations! *******************************
Dear John, your account has been successfully created.
Ac No: 1001    ***    PIN: 1234    ***    Balance: $0.00
*******************************************************************************
```

---

### 2️⃣ 🔐 Login

Users log in using:

* 🆔 Account number
* 🔑 4-digit PIN

The system verifies that the account exists and checks the entered PIN before granting access to the account menu.

```text
+++++ LOGIN MENU +++++
Enter Account Number: 1001
Welcome John
Enter PIN: 1234
Logged in successfully
```

---

## 👤 Account Menu

After successful authentication, users can access:

```text
===== ACCOUNT MENU =====
1. Check Balance
2. Deposit
3. Withdraw
4. Transfer
5. Logout
Enter your choice:
```

---

### 3️⃣ 💰 Check Balance

Displays the current account balance:

```text
********* ACCOUNT BALANCE *********
Your current balance is $500.00
***********************************
```

---

### 4️⃣ 💵 Deposit

Users can deposit money into their account.

The deposit amount is added to the current balance and the updated account data is saved to `bank.csv`.

```text
****************** DEPOSIT WINDOW ******************
Enter amount to deposit: $250
$250.00 has been successfully added to your account
***************************************************
```

---

### 5️⃣ 💸 Withdraw

Users can withdraw money from their account.

Before completing the transaction, the system checks whether the account has sufficient funds.

```text
****************** WITHDRAWAL WINDOW ******************
Enter amount to withdraw: $100
$100.00 has been withdrawn from your account
*******************************************************
```

If the requested amount exceeds the available balance:

```text
Insufficient Funds
```

---

### 6️⃣ 🔄 Transfer Money

Users can transfer money to another existing account.

The system:

1. Checks whether the sender has sufficient funds.
2. Requests the receiver's account number.
3. Verifies that the receiver account exists.
4. Adds the transfer amount to the receiver's balance.
5. Deducts the amount from the sender's balance.
6. Saves the updated account data.

Example:

```text
****************** TRANSFER WINDOW ******************
Enter Amount to transfer: $150
Transfer of amount $150.00 has been initiated!
Enter Receiver Account Number: 1002
Successfully transferred $150.00 to Sarah
*****************************************************
```

---

### 7️⃣ 🚪 Logout

Users can safely return to the main ATM menu:

```text
======LOGGED OUT SUCCESSFULLY ======
```

The account remains stored in `bank.csv` and can be accessed again by logging in.

---

## 💾 Data Persistence

Account information is stored in:

```text
bank.csv
```

The CSV file follows this structure:

```text
1001,John,1234,500.00
1002,Sarah,5678,750.00
1003,Michael,2468,250.00
```

When the program starts, existing accounts are loaded from the CSV file using `loadfile()`.

Account changes are written back to the file using `writeFile()`.

This allows account balances and other information to **persist after the program is closed**.

---

## 📁 Project Structure

```text
atm-system/
│
├── 🏦 atm_system.c
├── 📊 bank.csv
└── 📖 README.md
```

> 💡 `bank.csv` is created and updated by the program when account data is saved.

---

## 🛠️ Technologies

* 💻 **C**
* 📚 Standard C Library
* 🧱 Structures (`struct`)
* 📦 Arrays
* 🔧 Functions
* 👉 Pointers
* 📂 File I/O
* 📊 CSV data storage
* 🔤 String handling
* 🔐 Basic authentication
* 🔄 Transaction processing

---

## 🧠 Concepts Practiced

This project was built to practice several fundamental C programming concepts:

* 🧱 `struct` data types
* 📦 Arrays of structures
* 🔧 Function declarations and definitions
* 📤 Passing arrays to functions
* 👉 Pointers and pointer parameters
* 📄 `FILE` pointers
* 📖 `fopen()` / `fclose()`
* 📝 `fgets()`
* 💾 `fprintf()`
* 🔍 `sscanf()`
* 🔤 String manipulation with `strlen()`
* 🔐 PIN validation
* 🔎 Account searching
* 💰 Balance management
* 🔄 Transaction processing
* 📂 Persistent data storage
* 🔀 Menu-driven program design
* 🧩 Breaking a program into reusable functions

---

## 🚀 Compilation & Running

### 🔨 Compile with GCC

```bash
gcc atm_system.c -o atm_system
```

### 🪟 Windows

```bash
atm_system.exe
```

### 🐧 Linux / 🍎 macOS

```bash
./atm_system
```

---

## ⚠️ Current Limitations

This is a console-based learning project and currently has some limitations:

* 👥 Supports a maximum of **50 accounts** (but you can increase/decrease this)
* 🆔 Account numbers are generated sequentially based on the current account count
* 🔐 PINs are stored as plain text in `bank.csv`
* 💵 Monetary values use `float`, which is not ideal for real financial applications
* 📊 Deposit and withdrawal amounts are not fully validated
* 🚫 Negative transaction amounts are not currently prevented
* 🧾 CSV parsing is basic and does not handle all possible input formats
* ⌨️ Invalid input types are not fully handled
* 🔒 Authentication is a basic simulation and is not suitable for real banking systems
* 📋 There is no transaction history

> ⚠️ **This project is a programming exercise and is not intended for real financial use.**

---

## 🔮 Future Improvements

Possible improvements include:

* 🛡️ Add comprehensive input validation
* 🔐 Improve authentication and PIN security
* 🔒 Hash or encrypt sensitive credentials
* 💰 Use integer cents instead of `float` for monetary calculations
* 🚫 Prevent negative deposits and withdrawals
* 🆔 Improve account number generation
* 📜 Add transaction history
* 📊 Generate account statements
* 🧾 Add transaction records to a separate CSV file
* 👤 Add account profile management
* 🔑 Add PIN change functionality
* 💳 Add simulated ATM card functionality
* 📈 Add transaction statistics
* 🗂️ Separate functionality into `.c` and `.h` files
* 🧪 Add automated tests
* 🛡️ Improve error handling
* 💾 Replace CSV storage with a database

---

## 🎯 Project Purpose

This project was created as a practical exercise in **C programming, file handling, authentication, and transaction-based application design**.

The goal was to build a small banking simulation that combines multiple programming concepts into a single interactive application.

Rather than only working with simple input and output, the project introduces concepts such as **user authentication, persistent data, account management, balance calculations, and money transfers**.

---

## 📚 What I Learned

Through this project, I practiced:

> 🧱 Designing applications using `struct`
> 🔧 Breaking functionality into reusable functions
> 👉 Working with pointers and arrays
> 🔐 Implementing basic authentication logic
> 📂 Reading and writing persistent data
> 💾 Using CSV files as simple data storage
> 💰 Managing account balances
> 🔄 Implementing transfers between accounts
> 🔎 Searching structured data
> 🧩 Designing multi-level menu systems
> ⚠️ Thinking about validation, security, and real-world limitations

---

## 👨‍💻 Author

**Syed Shams Junaid**

🔗 GitHub: [Azaucifer](https://github.com/Azaucifer)

---

⭐ **If you found this project interesting, feel free to explore the code and follow the project!**
