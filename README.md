# OOP with C++ — Lab Assignments

| | |
|---|---|
| **Name** | Hassan Ali Mir |
| **Roll No.** | 2025-SET-02 |
| **Program** | BS Software Engineering |
| **Subject** | Object-Oriented Programming (OOP) |
| **Language** | C++ |

---

## Overview

This repository contains all lab assignments for the **Object-Oriented Programming** course.  
Each lab explores a core OOP concept, progressing from basic structs and classes through to polymorphism, operator overloading, file I/O, templates, and a complete multi-file system design.

---

## Lab Index

| Lab | Topic | Tasks |
|-----|-------|:-----:|
| [Lab 1](#lab-1--structs-and-basic-classes) | Structs & Basic Classes | 3 |
| [Lab 2](#lab-2--classes-access-specifiers--member-functions) | Classes, Access Specifiers & Member Functions | 5 |
| [Lab 3](#lab-3--encapsulation--getters--setters) | Encapsulation — Getters & Setters | 1 |
| [Lab 4](#lab-4--constructors--destructors) | Constructors & Destructors | 3 |
| [Lab 5](#lab-5--inheritance) | Inheritance | 4 |
| [Lab 6](#lab-6--multilevel--hierarchical-inheritance) | Multilevel & Hierarchical Inheritance | 4 |
| [Lab 7](#lab-7--composition) | Composition | 2 |
| [Lab 8](#lab-8--polymorphism--virtual-functions) | Polymorphism & Virtual Functions | 1 |
| [Lab 9](#lab-9--operator-overloading) | Operator Overloading | 1 |
| [Lab 10](#lab-10--file-handling) | File Handling | 4 |
| [Lab 11 & 12](#lab-11--12--friend-functions--static-members) | Friend Functions & Static Members | 5 |
| [Lab 13](#lab-13--templates) | Templates | 4 |
| [Lab 14](#lab-14--vehicle-rental-system-open-ended) | Vehicle Rental System *(Open-Ended)* | Multi-file |

---

## Lab Details

### Lab 1 — Structs and Basic Classes
> **Concept:** Defining `struct` types with member functions; creating and using objects.

- **Task 1** — `Student` struct storing name, roll number, and marks with a `displayStudentInfo()` method.
- **Task 2** — Extended student record with GPA and grade calculation.
- **Task 3** — Book struct with title, author, and price display.

---

### Lab 2 — Classes, Access Specifiers & Member Functions
> **Concept:** `class` vs `struct`; `private` / `public` access; input and display methods.

- **Task 1** — `Student` class with `getData()` and `displayData()` methods.
- **Task 2** — `BankAccount` class with deposit and withdrawal operations.
- **Task 3** — `Rectangle` class computing area and perimeter.
- **Task 4** — `Car` class with fuel-level tracking.
- **Task 5** — `Library` class managing book availability.

---

### Lab 3 — Encapsulation — Getters & Setters
> **Concept:** Data hiding with `private` members and validated setter methods.

- **Task 1** — `Product` class (name, price, quantity) with input validation in every setter; negative price or quantity is rejected with an error message.

---

### Lab 4 — Constructors & Destructors
> **Concept:** Default and parameterised constructors; destructor lifecycle.

- **Task 1** — `Employee` class with a default constructor initialising all fields.
- **Task 2** — Parameterised constructor for a `Circle` computing area on creation.
- **Task 3** — Multiple constructors demonstrating constructor overloading.

---

### Lab 5 — Inheritance
> **Concept:** Single and multi-level inheritance; base/derived class relationships.

- **Task 1** — `Person` base class → `Student` derived class (adds student ID).
- **Task 2** — `Animal` → `Dog` hierarchy with overridden `speak()` method.
- **Task 3** — `Vehicle` → `Car` with additional attributes.
- **Task 4** — `Shape` → `Rectangle` and `Circle` computing areas.

---

### Lab 6 — Multilevel & Hierarchical Inheritance
> **Concept:** Chains of inheritance; multiple classes deriving from one base.

- **Task 1** — `Product` → `Electronics` (adds warranty) demonstrating constructor chaining.
- **Task 2** — `Person` → `Employee` → `Manager` three-level chain.
- **Task 3** — `Animal` → `Bird` and `Fish` hierarchical inheritance.
- **Task 4** — Online shopping system with a base `Product` and multiple specialised categories.

---

### Lab 7 — Composition
> **Concept:** Building complex objects by embedding other objects as members ("has-a" relationship).

- **Task 1** — `Calculator` class that owns a `Display` object; results are passed to the display after each operation.
- **Task 2** — `Engine` embedded inside a `Car`; starting the car delegates to the engine.

---

### Lab 8 — Polymorphism & Virtual Functions
> **Concept:** Runtime polymorphism via `virtual` functions and base-class pointers.

- **Task 1** — `Shape*` base pointer pointing to `Rectangle` and `Circle` objects; `area()` resolves at runtime through the vtable.

---

### Lab 9 — Operator Overloading
> **Concept:** Redefining built-in operators for user-defined types.

- **Task 1** — `Distance` class (feet + inches) with overloaded `==` operator for equality comparison.

---

### Lab 10 — File Handling
> **Concept:** Reading, writing, and appending data using `fstream`.

- **Task 1** — Write lines to a `.txt` file, read them back, then append additional data.
- **Task 2** — Write student records to a file and read them line by line.
- **Task 3** — Search for a specific record inside a text file.
- **Task 4** — Count lines and words inside a given file.

---

### Lab 11 & 12 — Friend Functions & Static Members
> **Concept:** `friend` keyword granting external access; `static` data shared across all instances.

- **Task 1** — `friend` function accessing a `private` member of `Box`.
- **Task 2** — `friend` function comparing two objects of different classes.
- **Task 3** — `static` counter tracking the total number of `Student` objects created.
- **Task 4** — `static` method returning the shared instance count.
- **Task 5** — Combined scenario using both friend and static members.

---

### Lab 13 — Templates
> **Concept:** Generic programming with function and class templates.

- **Task 1** — Generic `Calculator<T>` class supporting `add`, `subtract`, and `multiply` for both `int` and `double`.
- **Task 2** — Template function finding the maximum of two values.
- **Task 3** — Generic `Stack<T>` class with push, pop, and peek.
- **Task 4** — Template function swapping two variables of any type.

---

### Lab 14 — Vehicle Rental System *(Open-Ended)*
> **Concept:** Full multi-file OOP design — abstract base class, inheritance, runtime polymorphism, encapsulation, and `unique_ptr` ownership.

**Architecture**

```
Vehicle (abstract base)
├── Car          — plain daily rate
├── Motorbike    — 10% discount for rentals > 7 days
└── Truck        — 20% surcharge on every rental

Customer   — one active rental at a time (business rule)
Rental     — immutable cost record; stays in history after return
RentalSystem — central coordinator; owns fleet, customers, ledger
```

**Features**
- Interactive menu: add vehicles, register customers, rent, return, and view reports
- Vehicle type selected by the user at runtime (Car / Motorbike / Truck)
- All pricing applied automatically via virtual `calculateCost()`
- Full validation: duplicate IDs, already-rented vehicle, zero/negative days, unknown IDs
- Rental history preserved after return (records are closed, never deleted)

**Files**

| File | Role |
|------|------|
| `Vehicle.h / .cpp` | Abstract base class |
| `Car.h / .cpp` | Derived — plain rate |
| `Motorbike.h / .cpp` | Derived — long-stay discount |
| `Truck.h / .cpp` | Derived — surcharge |
| `Customer.h / .cpp` | Customer entity |
| `Rental.h / .cpp` | Rental record |
| `RentalSystem.h / .cpp` | System coordinator |
| `main.cpp` | Interactive menu driver |

**Build & Run**
```bash
g++ -std=c++14 -Wall -o VehicleRental.exe main.cpp Vehicle.cpp Car.cpp \
    Motorbike.cpp Truck.cpp Customer.cpp Rental.cpp RentalSystem.cpp
.\VehicleRental.exe
```

---

## How to Compile Any Single-File Lab

```bash
g++ -std=c++14 -o output TaskN.cpp
.\output.exe
```

---

*Object-Oriented Programming — 2nd Semester, BS Software Engineering*

