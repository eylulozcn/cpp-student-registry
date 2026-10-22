# C++ Student Registry System

A console-based Student Registry System developed in **C++14** using Object-Oriented Programming (OOP) and the Standard Template Library (STL).

This project was created as part of the **Object-Oriented Programming II** course.

## Features

* **Add Student:** Register a new student with a unique student number and name.
* **Display Students:** View all registered students in their original insertion order.
* **Sort by Number:** Display students sorted by student number in ascending order.
* **Sort by Name:** Display students in alphabetical order.
* **Delete Student:** Remove a student using their student number.
* **Insert at Position:** Insert a new student at a specific position in the list.
* **Search Student:** Find a student using their student number.
* **Student Count:** Display the total number of registered students.
* **Duplicate Prevention:** Prevent students from being registered with the same student number.

## Technologies Used

* **Language:** C++14
* **Programming Paradigm:** Object-Oriented Programming (OOP)
* **Data Structure:** `std::list`
* **Libraries:** `<iostream>`, `<string>`, `<list>`

## Concepts Applied

* Classes and Objects
* Encapsulation
* Constructors
* Member Functions
* STL Containers
* Iterators
* Lambda Expressions
* Sorting Algorithms
* Functions and References
* Loops and Switch Statements

## Project Structure

```text
cpp-student-registry/
├── main.cpp
├── README.md
└── .gitignore
```

## How to Run

### 1. Requirements

A C++ compiler supporting **C++14**, such as GCC (g++).

### 2. Compile the Program

Open a terminal in the project directory and run:

```bash
g++ -std=c++14 main.cpp -o student
```

### 3. Run the Program

**Windows (PowerShell):**

```powershell
.\student.exe
```

**Linux / macOS:**

```bash
./student
```

## Menu

When the program starts, the following menu appears:

```text
=================== STUDENT REGISTRY ===================

1. Add Student
2. Display Students
3. Sort Students by Number
4. Sort Students by Name
5. Delete Student by Number
6. Insert Student at Position
7. Search Student
8. Total Student Count
0. Exit

Enter your choice:
```

## Example Usage

**Adding a student:**

```text
Enter your choice: 1
Enter student number: 20001
Enter student name: Eylul Ozcan
Student added successfully!
```

**Displaying students:**

```text
Enter your choice: 2

--- Student List ---
Number: 20001 | Name: Eylul Ozcan
```

**Searching for a student:**

```text
Enter your choice: 7
Enter student number to search: 20001
Student found!
Number: 20001
Name: Eylul Ozcan
```

## Notes

* Student numbers must be unique.
* Sorting is performed on a copy of the list, preserving the original insertion order.
* The program uses a menu-driven interface.
* Student records are stored in memory and are not saved after the program closes.
* The program is designed for valid numeric inputs.

## About

This project was developed as part of my **Object-Oriented Programming II** coursework to practice C++ programming, object-oriented design, and STL operations.
