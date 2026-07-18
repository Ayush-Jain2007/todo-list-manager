# 📝 To-Do List Manager

A console-based **To-Do List Manager** built in **C** that allows users to manage daily tasks through an interactive menu. The project demonstrates concepts such as modular programming, file handling, structures, and persistent data storage using binary files.

---

## ✨ Features

- ➕ Add new tasks
- 📋 View all tasks
- ✅ Mark tasks as completed
- 🗑️ Delete tasks
- ✏️ Edit existing tasks
- 🔍 Search tasks by keyword
- 📊 View task statistics (total, completed, pending, completion rate)
- 🏷️ Assign priority levels (High, Medium, Low)
- 🔄 Sort tasks
  - By Priority
  - Alphabetically
  - By Status
- 📂 Filter tasks
  - All Tasks
  - Pending Tasks
  - Completed Tasks
- 🛡️ Improved input validation
- 💾 Persistent task storage using binary files (`tasks.dat`)
- 📁 Modular project structure (`main.c`, `functions.c`, `functions.h`)
---

## 📂 Project Structure

```
todo-list-manager/
│
├── main.c
├── functions.c
├── functions.h
├── .gitignore
├── README.md
├── tasks.dat          # Created automatically
└── output/            # Build output (ignored by Git)
```

---

## 🛠️ Technologies Used

- C Programming Language
- Standard C Library
- Structures
- Arrays
- Modular Programming
- File Handling
- Binary File I/O

---

## 🚀 How to Compile

### Using GCC

```bash
gcc main.c functions.c -o ToDoList
```

### Run

#### Windows

```bash
ToDoList.exe
```

#### Linux / macOS

```bash
./ToDoList
```

---

## 📸 Current Menu

```
=========================================================
                 TO-DO LIST MANAGER
=========================================================
1. Add Task
2. View Tasks
3. Complete Task
4. Delete Task
5. Search Task
6. Task Statistics
7. Edit Task
8. Filter Tasks
9. Sort Tasks
10. Exit
---------------------------------------------------------
Enter your choice:
```

---

## 📌 Current Version

**v3.0.0**

Latest additions:
- Task priorities
- Edit task
- Input validation
- Task filtering
- Task sorting

---

## 💾 Data Storage

Tasks are stored in a binary file:

```
tasks.dat
```

The file is automatically:

- Loaded when the program starts
- Saved whenever tasks are modified

---

## 🔄 Planned Features

- 📅 Due Dates
- 🏷️ Task Categories
- ⭐ Pin/Favorite Tasks
- 📄 Export tasks to a text file
- 🎨 Enhanced console interface 

---

## 📖 Concepts Practiced

- Structures
- Arrays
- Functions
- Header Files
- Modular Programming
- File Handling
- Binary Files (`fread()` / `fwrite()`)
- Input Validation
- Searching Algorithms
- Sorting Algorithms
- Menu-driven Programming

---

## 👨‍💻 Author

**Ayush Jain**

Learning C by building practical console applications and sharing them on GitHub.