# 📝 To-Do List Manager

A console-based **To-Do List Manager** built in **C** that allows users to manage daily tasks through an interactive menu. The project demonstrates concepts such as modular programming, file handling, structures, and persistent data storage using binary files.

---

## ✨ Features

- ➕ Add new tasks
- 📋 View all tasks
- ✅ Mark tasks as completed
- 🗑️ Delete tasks
- 🔍 Search tasks by keyword
- 📊 View task statistics (total, completed, pending, completion rate)
- ✏️ Edit existing tasks
- 💾 Persistent task storage using binary file handling (`tasks.dat`)
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
- File Handling
- Structures
- Modular Programming

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
8. Exit
---------------------------------------------------------
Enter your choice:
```

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

- 📂 Filter completed and pending tasks
- 🔤 Sort tasks alphabetically
- 🛡️ Improved input validation
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

---

## 👨‍💻 Author

**Ayush Jain**

Learning C by building practical console applications and sharing them on GitHub.