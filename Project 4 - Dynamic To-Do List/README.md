# ✅ Dynamic To-Do List

A command-line **To-Do List application written in C** that allows users to create, manage, complete, and delete tasks.

Unlike a fixed-size array implementation, this project uses **dynamic memory allocation** with `malloc()` and `realloc()`, allowing the task list to grow and shrink as needed. 💾

Task data is saved to a `todo.txt` file, allowing tasks to persist between program runs. 📂

---

## ✨ Features

* ➕ Add a new task
* 👀 View all tasks
* ✅ Mark a task as completed
* 🔄 Mark a task as incomplete
* 🗑️ Delete a specific task
* 🧹 Delete all completed tasks
* 💾 Save tasks to a file
* 📂 Load existing tasks when the program starts
* 📈 Dynamically expand the task list
* 📉 Dynamically shrink the task list
* 🧠 Manually manage dynamically allocated memory

---

## 📋 Task Structure

Each task contains three pieces of information:

| Field          | Type     | Description                            |
| -------------- | -------- | -------------------------------------- |
| 🆔 ID          | `int`    | Unique task identifier                 |
| 📝 Description | `char *` | Dynamically allocated task description |
| 📌 Status      | `int`    | `0` = Pending, `1` = Completed         |

The task structure is defined using a C `struct`:

```c
typedef struct
{
    int id;
    char *description;
    int status;
} Tasks;
```

---

## 🖥️ Main Menu

When the program starts, the following menu is displayed:

```text
=== TO-DO LIST MENU ===
1. Add Task
2. View All Tasks
3. Mark Task as Completed
4. Mark Task as Incomplete
5. Delete Task
6. Delete all Completed Tasks
7. Save & Exit
Enter your choice (Ex: 1 to 7):
```

---

## ⚙️ How It Works

### 1️⃣ Add Task

The user enters a task description.

The program:

1. Allocates memory for a new `Tasks` structure.
2. Uses `realloc()` when additional task space is required.
3. Dynamically allocates memory for the task description.
4. Assigns an ID to the task.
5. Sets the task status to `0` (Pending).
6. Saves the updated task list to `todo.txt`.

Example:

```text
=== ADD TASK ===
Enter Description: Complete C project

ID: 1
Description: Complete C project
Status: 0
```

---

### 2️⃣ 👀 View All Tasks

Displays all currently stored tasks.

```text
(Note: Status: 0 = Pending & Status: 1 = Completed)

ID: 1
Task: Complete C project
Status: 0

ID: 2
Task: Push project to GitHub
Status: 1
```

If there are no tasks:

```text
No tasks available
```

---

### 3️⃣ ✅ Mark Task as Completed

The user enters a task ID.

The program searches the dynamically allocated array and changes the task status from:

```text
0 = Pending
```

to:

```text
1 = Completed
```

The updated data is then saved to `todo.txt`.

---

### 4️⃣ 🔄 Mark Task as Incomplete

If a task was accidentally marked as completed, the user can change it back to pending.

The status changes from:

```text
1 = Completed
```

to:

```text
0 = Pending
```

---

### 5️⃣ 🗑️ Delete Task

The user enters the ID of the task they want to delete.

The program:

1. Finds the task.
2. Frees the memory used by its description.
3. Shifts the remaining tasks left.
4. Reassigns task IDs.
5. Reduces the allocated array size using `realloc()`.
6. Saves the updated task list.

This helps prevent memory leaks while keeping the task array compact. 🧠

---

### 6️⃣ 🧹 Delete All Completed Tasks

The program searches through the entire task list and removes every task with:

```text
status = 1
```

Each deleted task has its dynamically allocated description freed before the remaining tasks are shifted.

The array is then resized using `realloc()`.

---

### 7️⃣ 🚪 Save & Exit

The program releases all dynamically allocated memory before exiting.

The `freeTasks()` function:

* 🧹 Frees every task description
* 🗑️ Frees the task array
* 🔄 Resets the task pointer
* 🔢 Resets the task counter

---

## 💾 Data Persistence

Tasks are stored in:

```text
todo.txt
```

Each task is stored using the following format:

```text
ID~Description~Status
```

Example:

```text
1~Complete C project~0
2~Push project to GitHub~1
3~Study pointers~0
```

The `~` character is used as the separator between fields.

### 📂 Loading Data

When the program starts, `loadFile()` reads the existing `todo.txt` file.

It then:

* Reads each line.
* Extracts the ID, description, and status.
* Dynamically allocates memory for each task.
* Reconstructs the task array using `malloc()` and `realloc()`.

### 💾 Saving Data

The `writeFile()` function rewrites `todo.txt` with the current task list whenever tasks are added or modified.

---

## 🧠 Dynamic Memory Management

One of the main goals of this project is to practice **dynamic memory allocation in C**.

The task array does not have a fixed size.

Instead, memory is allocated as tasks are added:

```c
malloc()
```

and resized when necessary:

```c
realloc()
```

Individual task descriptions are also dynamically allocated based on their required length:

```c
(*task)[*taskCounter].description =
    malloc(strlen(tempDescription) + 1);
```

When tasks are deleted, their allocated memory is released using:

```c
free()
```

This allows the application to efficiently increase and decrease its memory usage based on the number of tasks.

---

## 📁 Project Structure

```text
todo-list/
│
├── 📝 todo.c
├── 📋 todo.txt
└── 📖 README.md
```

> 💡 `todo.txt` is created and updated by the program when task data is saved.

---

## 🛠️ Technologies

* 💻 **C**
* 📚 Standard C Library
* 🧱 Structures (`struct`)
* 📦 Dynamic arrays
* 👉 Pointers
* 🧠 Dynamic memory allocation
* ➕ `malloc()`
* 🔄 `realloc()`
* 🗑️ `free()`
* 📂 File I/O
* 🔤 String handling
* 🔍 Searching and array manipulation

---

## 🧠 Concepts Practiced

This project focuses on several important C programming concepts:

* 🧱 Structures
* 📦 Arrays of structures
* 👉 Pointers
* 👉 Double pointers (`Tasks **`)
* 🧠 Dynamic memory allocation
* ➕ `malloc()`
* 🔄 `realloc()`
* 🗑️ `free()`
* 📏 Dynamic string allocation
* 🔧 Functions and function prototypes
* 📂 File handling
* 📖 `fopen()` / `fclose()`
* 📝 `fgets()`
* 💾 `fprintf()`
* 🔍 `sscanf()`
* 🔤 `strlen()`
* 🔤 `strcpy()`
* 🔎 Searching arrays
* 🗑️ Deleting array elements
* 🔄 Shifting array elements
* 🧹 Memory cleanup

---

## 🚀 Compilation & Running

### 🔨 Compile with GCC

```bash
gcc todo.c -o todo
```

### 🪟 Windows

```bash
todo.exe
```

### 🐧 Linux / 🍎 macOS

```bash
./todo
```

---

## ⚠️ Current Limitations

As a learning project, the program currently has some limitations:

* 🆔 Task IDs are regenerated after deletion.
* ⌨️ Input validation could be improved.
* 📝 Task descriptions are limited to 255 characters during input.
* `~` should not be used in task descriptions because it is the file separator.
* ⚠️ Some memory-allocation failure paths could be handled more robustly.
* 📄 The file format is a simple custom text format rather than a standardized format.
* 🔐 There is no authentication or user management.

---

## 🔮 Future Improvements

Possible improvements include:

* 🔢 Improve task ID generation
* 📅 Add due dates
* 🚦 Add task priorities
* 🏷️ Add categories/tags
* 🔎 Search tasks
* 🔤 Sort tasks
* 📊 Display task statistics
* 🧪 Add automated tests
* 🛡️ Improve input validation
* 💾 Improve file error handling
* 📋 Add a more robust data format
* 🧩 Split the project into `.c` and `.h` files
* 🎨 Improve the command-line interface
* 🧠 Further optimize memory management

---

## 🎯 Project Purpose

This project was created as a practical exercise in **C programming and dynamic memory management**.

The main goal was to move beyond fixed-size arrays and practice building a program that dynamically allocates, resizes, and frees memory while also maintaining persistent data.

---

## 📚 What I Learned

Through this project, I practiced:

> 🧠 Managing dynamically allocated memory
> 👉 Working with pointers and double pointers
> ➕ Using `malloc()` to allocate memory
> 🔄 Using `realloc()` to resize memory
> 🗑️ Using `free()` to prevent memory leaks
> 📦 Building dynamic arrays
> 🔤 Dynamically allocating strings
> 📂 Reading and writing persistent data
> 🔎 Searching and modifying structured data
> 🗑️ Removing elements from dynamic arrays
> 🧹 Cleaning up allocated memory before program termination

---

## 👨‍💻 Author

**Syed Shams Junaid**

🔗 GitHub: [Azaucifer](https://github.com/Azaucifer)

---

⭐ **If you found this project interesting, feel free to explore the code and follow the project!**
