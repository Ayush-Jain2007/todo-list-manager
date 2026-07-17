# 📝 To-Do List Manager

A simple console-based **To-Do List Manager** written in **C**. This project helps users manage their daily tasks with features like adding tasks, viewing tasks, marking tasks as completed, and automatically saving progress using binary file handling.

---

## ✨ Features

- ➕ Add new tasks
- 📋 View all tasks
- ✅ Mark tasks as completed
- 💾 Automatic save/load using binary files
- 📁 Modular project structure (`main.c`, `functions.c`, `functions.h`)

---

## 📂 Project Structure

```
To-Do-List/
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
4. Exit
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

## 📌 Current Features

- Add Task
- View Tasks
- Mark Task as Completed
- Persistent Storage (Binary File Handling)

---

## 🔄 Planned Features

- Delete Task
- Search Tasks
- Task Statistics
- Improved Input Validation
- Enhanced Console UI

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