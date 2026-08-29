# 🎓 Student Dashboard System

A command-line **Student Dashboard System written in C** that allows users to manage student records through a simple interactive menu.

Student information is stored in a `students.csv` file, allowing data to **persist between program runs**. 💾

---

## ✨ Features

* ➕ Add a new student
* 👀 View all students
* 🔎 Search for a student by ID
* 🗑️ Delete a student by ID
* ✏️ Update a student's grade
* 💾 Save student records to a CSV file
* 📂 Load existing records when the program starts
* 🔄 Persistent data storage using file I/O

---

## 👨‍🎓 Student Record

Each student record contains:

| Field    | Type       | Description                       |
| -------- | ---------- | --------------------------------- |
| 🆔 ID    | `int`      | Unique identifier for the student |
| 👤 Name  | `char[50]` | Student's name                    |
| 📊 Grade | `float`    | Student's grade percentage        |

The records are represented using a C `struct`:

```c
typedef struct 
{
    int id;
    char name[50];
    float grade;
} Student;
```

---

## 🖥️ Dashboard

When the program starts, the following menu is displayed:

```text
======  STUDENT DASHBOARD ======
1. Add a New Student
2. View All Students
3. Search Student by ID
4. Delete Student by ID
5. Update Grade by ID
6. Exit
Please Enter your choice:
```

---

## ⚙️ How It Works

### 1️⃣ Add a Student

The user enters:

* 🆔 Student ID
* 👤 Student name
* 📊 Grade percentage

The new record is added to the in-memory student array and saved to `students.csv`.

### 2️⃣ View All Students

Displays all currently loaded student records in a formatted table.

```text
 ID                       Name                           Grade %
----- ------------------------------------------------- ---------
-1001  John Smith                                         85.00
-1002  Sarah Johnson                                      92.50
```

### 3️⃣ 🔎 Search Student by ID

The program searches the student array for the requested ID.

If the student exists, their details are displayed:

```text
************ STUDENT DETAILS *******************
ID: 1001
Name: John Smith
Grade: 85.00
************************************************
```

### 4️⃣ 🗑️ Delete Student by ID

The program locates the student and removes their record from the array.

The remaining records are shifted one position to fill the deleted student's position.

The CSV file is then rewritten with the updated data.

### 5️⃣ ✏️ Update Grade

The user enters a student ID and provides a new grade.

The updated student data is then written back to `students.csv`.

### 6️⃣ 🚪 Exit

The program exits after displaying a confirmation message.

> 💡 Student data is saved during add, update, and delete operations.

---

## 💾 Data Persistence

Student records are stored in:

```text
students.csv
```

The file uses a simple comma-separated format:

```text
1001,John Smith,85.00
1002,Sarah Johnson,92.50
1003,Michael Brown,78.00
```

When the program starts, existing records are loaded from the CSV file using `loadfile()`.

Changes such as deleting or updating records cause the CSV file to be rewritten using `writeFile()`.

---

## 📁 Project Structure

```text
student-dashboard/
│
├── 📝 student_system.c
├── 📊 students.csv
└── 📖 README.md
```

> 💡 `students.csv` is created and updated by the program when student data is saved.

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

---

## 🧠 Concepts Practiced

This project was built to practice fundamental C programming concepts:

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
* 📍 `fseek()` / `ftell()`
* 🔤 String manipulation with `strlen()`
* 🔎 Searching arrays
* 🗑️ Deleting elements by shifting array contents
* 💾 Reading and writing persistent data

---

## 🚀 Compilation & Running

### 🔨 Compile with GCC

```bash
gcc student_system.c -o student_system
```

### 🪟 Windows

```bash
student_system.exe
```

### 🐧 Linux / 🍎 macOS

```bash
./student_system
```

---

## ⚠️ Current Limitations

As a console-based learning project, it currently has some limitations:

* 👥 Maximum of **100 students** (the array size can be changed)
* 🆔 Student IDs are not automatically checked for duplicates
* 📊 Grade input is not fully validated
* ⚠️ Names containing commas may interfere with the CSV format
* ⌨️ Invalid input types are not fully handled
* 📋 The CSV file does not contain a header row

---

## 🔮 Future Improvements

Possible improvements include:

* ✅ Add comprehensive input validation
* 🆔 Prevent duplicate student IDs
* 📊 Validate grades between `0` and `100`
* 📋 Add a CSV header
* 📈 Add student statistics
* 🏆 Display highest and lowest grades
* 📊 Calculate average grade
* 🔤 Sort students by name, ID, or grade
* 💾 Support more than 100 students using dynamic memory
* 🧩 Separate functionality into `.c` and `.h` files
* 🧪 Add automated tests
* 🛡️ Improve error handling
* 📄 Improve CSV parsing

---

## 🎯 Project Purpose

This project was created as a practical exercise in **C programming, data structures, and file handling**.

The goal was to move beyond basic programming exercises and build a small but functional application that combines multiple core programming concepts into one project.

---

## 📚 What I Learned

Through this project, I practiced:

> 🧠 Designing a program using `struct`
> 🔧 Breaking functionality into reusable functions
> 👉 Working with pointers and arrays
> 📂 Reading and writing files in C
> 💾 Persisting application data using CSV
> 🔎 Searching and modifying structured data
> 🗑️ Managing array elements when deleting records

---

## 👨‍💻 Author

**Syed Shams Junaid**

🔗 GitHub: [@Azaucifer](https://github.com/Azaucifer)

---

⭐ **If you found this project interesting, feel free to explore the code and follow the project!**
