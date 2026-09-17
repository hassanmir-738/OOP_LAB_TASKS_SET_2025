<div align="center">

# Object-Oriented Programming with C++

**Lab Portfolio — 2nd Semester**

![C++](https://img.shields.io/badge/C%2B%2B-14-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Labs](https://img.shields.io/badge/Labs-14-4C1?style=for-the-badge)
![Tasks](https://img.shields.io/badge/Tasks-37%2B-0AA?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)

<br>

<h3>H A S S A N &nbsp; A L I &nbsp; M I R</h3>

<sub>`2025-SET-02` &nbsp;·&nbsp; BS Software Engineering &nbsp;·&nbsp; Object-Oriented Programming</sub>

</div>

---

## Overview

A complete, self-contained collection of lab work for the **Object-Oriented Programming** course.

The labs are arranged as a deliberate progression: they begin with plain `struct` types and basic classes, move through encapsulation, object lifetime, inheritance hierarchies and runtime polymorphism, and finish with a full multi-file **Vehicle Rental System** that brings every earlier concept together in one working application.

Every task is written in standard C++ and compiles cleanly with `-Wall`.

---

## Lab Index

| Lab | Topic | Core Concept | Tasks |
|:---:|-------|--------------|:-----:|
| [01](#lab-1--structs-and-basic-classes) | Structs & Basic Classes | User-defined types | 3 |
| [02](#lab-2--classes-access-specifiers--member-functions) | Classes & Access Specifiers | `public` / `private` | 5 |
| [03](#lab-3--encapsulation) | Encapsulation | Getters, setters, validation | 1 |
| [04](#lab-4--constructors--destructors) | Constructors & Destructors | Object lifetime | 3 |
| [05](#lab-5--inheritance) | Inheritance | "is-a" relationships | 4 |
| [06](#lab-6--multilevel--hierarchical-inheritance) | Multilevel & Hierarchical Inheritance | Class chains & trees | 4 |
| [07](#lab-7--composition) | Composition | "has-a" relationships | 2 |
| [08](#lab-8--polymorphism--virtual-functions) | Polymorphism | Virtual dispatch | 1 |
| [09](#lab-9--operator-overloading) | Operator Overloading | Custom operators | 1 |
| [10](#lab-10--file-handling) | File Handling | `fstream` I/O | 4 |
| [11–12](#lab-11--12--friend-functions--static-members) | Friend Functions & Static Members | Shared & privileged access | 5 |
| [13](#lab-13--templates) | Templates | Generic programming | 4 |
| [14](#lab-14--vehicle-rental-system) | **Vehicle Rental System** *(Open-Ended)* | Full system design | Multi-file |

---

## Lab Details

### Lab 1 — Structs and Basic Classes

![Concept](https://img.shields.io/badge/Concept-Structs%20%26%20Objects-informational)

Defining `struct` types with member functions, then creating and using objects of those types.

| # | Task |
|:-:|------|
| 1 | `Student` struct holding name, roll number and marks, with a `displayStudentInfo()` method. |
| 2 | Extended student record that calculates GPA and derives a letter grade. |
| 3 | `Book` struct storing title, author and price, with formatted display. |

---

### Lab 2 — Classes, Access Specifiers & Member Functions

![Concept](https://img.shields.io/badge/Concept-Access%20Control-informational)

The difference between `class` and `struct`, control of visibility through `private` and `public`, and separating input from output in member functions.

| # | Task |
|:-:|------|
| 1 | `Student` class with paired `getData()` and `displayData()` methods. |
| 2 | `BankAccount` class supporting deposit and withdrawal operations. |
| 3 | `Rectangle` class computing area and perimeter. |
| 4 | `Car` class that tracks and reports its fuel level. |
| 5 | `Library` class managing book availability. |

---

### Lab 3 — Encapsulation

![Concept](https://img.shields.io/badge/Concept-Data%20Hiding-informational)

Protecting internal state behind `private` members so that invalid data can never enter an object.

| # | Task |
|:-:|------|
| 1 | `Product` class (name, price, quantity) where **every setter validates its input** — a negative price or quantity is rejected with a clear error message and the object keeps its previous valid state. |

---

### Lab 4 — Constructors & Destructors

![Concept](https://img.shields.io/badge/Concept-Object%20Lifetime-informational)

How objects are initialised when they are created and cleaned up when they go out of scope.

| # | Task |
|:-:|------|
| 1 | `Employee` class with a default constructor that initialises all fields. |
| 2 | `Circle` with a parameterised constructor that computes its area at construction time. |
| 3 | A single class carrying multiple constructors to demonstrate constructor overloading. |

---

### Lab 5 — Inheritance

![Concept](https://img.shields.io/badge/Concept-Base%20%26%20Derived-informational)

Reusing and extending existing classes through base/derived relationships.

| # | Task |
|:-:|------|
| 1 | `Person` → `Student`, the derived class adding a student ID. |
| 2 | `Animal` → `Dog`, overriding the `speak()` method. |
| 3 | `Vehicle` → `Car`, adding attributes specific to cars. |
| 4 | `Shape` → `Rectangle` and `Circle`, each computing its own area. |

---

### Lab 6 — Multilevel & Hierarchical Inheritance

![Concept](https://img.shields.io/badge/Concept-Class%20Hierarchies-informational)

Longer inheritance chains, and several classes branching from a single shared base.

| # | Task |
|:-:|------|
| 1 | `Product` → `Electronics` (adds warranty), demonstrating constructor chaining. |
| 2 | `Person` → `Employee` → `Manager`, a three-level chain. |
| 3 | `Animal` → `Bird` and `Fish`, hierarchical inheritance from one base. |
| 4 | Online shopping system built on a base `Product` with several specialised categories. |

---

### Lab 7 — Composition

![Concept](https://img.shields.io/badge/Concept-Has--a%20Relationship-informational)

Assembling complex objects by embedding other objects as members, and delegating work to them.

| # | Task |
|:-:|------|
| 1 | `Calculator` that owns a `Display` object; each result is handed to the display for output. |
| 2 | `Engine` embedded inside a `Car`, so starting the car delegates to the engine. |

---

### Lab 8 — Polymorphism & Virtual Functions

![Concept](https://img.shields.io/badge/Concept-Runtime%20Dispatch-informational)

Choosing behaviour at run time rather than compile time.

| # | Task |
|:-:|------|
| 1 | A `Shape*` base pointer aimed at `Rectangle` and `Circle` objects, where the correct `area()` is resolved at run time through the vtable. |

---

### Lab 9 — Operator Overloading

![Concept](https://img.shields.io/badge/Concept-Custom%20Operators-informational)

Giving built-in operators meaningful behaviour for user-defined types.

| # | Task |
|:-:|------|
| 1 | `Distance` class (feet and inches) with an overloaded `==` operator for direct equality comparison between two distances. |

---

### Lab 10 — File Handling

![Concept](https://img.shields.io/badge/Concept-fstream%20I%2FO-informational)

Persisting data beyond the life of the program using file streams.

| # | Task |
|:-:|------|
| 1 | Write lines to a `.txt` file, read them back, then reopen in append mode to add more. |
| 2 | Write student records to a file and read them back line by line. |
| 3 | Search a text file for a specific record and report whether it was found. |
| 4 | Count the total lines and words in a given file. |

---

### Lab 11 & 12 — Friend Functions & Static Members

![Concept](https://img.shields.io/badge/Concept-friend%20%26%20static-informational)

Granting controlled external access with `friend`, and sharing a single value across every instance with `static`.

| # | Task |
|:-:|------|
| 1 | A `friend` function reaching a `private` member of `Box`. |
| 2 | A `friend` function comparing objects of two different classes. |
| 3 | A `static` counter tracking how many `Student` objects have been created. |
| 4 | A `static` method that returns the shared instance count without needing an object. |
| 5 | A combined scenario using friend functions and static members together. |

---

### Lab 13 — Templates

![Concept](https://img.shields.io/badge/Concept-Generic%20Programming-informational)

Writing code once and reusing it across types.

| # | Task |
|:-:|------|
| 1 | Generic `Calculator<T>` supporting `add`, `subtract` and `multiply` for both `int` and `double`. |
| 2 | Template function returning the maximum of two values of any comparable type. |
| 3 | Generic `Stack<T>` with `push`, `pop` and `peek`. |
| 4 | Template function that swaps two variables of any type. |

---

## Lab 14 — Vehicle Rental System

![Open Ended](https://img.shields.io/badge/Open--Ended%20Project-8A2BE2?style=flat-square)
![Multi File](https://img.shields.io/badge/Multi--File-15%20files-orange?style=flat-square)
![Smart Pointers](https://img.shields.io/badge/Ownership-unique__ptr-red?style=flat-square)

The capstone lab: a complete rental application built from an abstract base class, inheritance, runtime polymorphism, strict encapsulation and `unique_ptr`-based ownership.

### Architecture

```
Vehicle (abstract base)
├── Car          — plain daily rate
├── Motorbike    — 10% discount for rentals longer than 7 days
└── Truck        — 20% surcharge on every rental

Customer      — one active rental at a time (business rule)
Rental        — immutable cost record; kept in history after return
RentalSystem  — central coordinator; owns the fleet, customers and ledger
```

### Features

- **Interactive menu** — add vehicles, register customers, rent, return and view reports.
- **Runtime type selection** — the user chooses Car, Motorbike or Truck while the program runs.
- **Automatic pricing** — every rate rule is applied through the virtual `calculateCost()`, so the system never needs to ask what type a vehicle is.
- **Full validation** — duplicate IDs, already-rented vehicles, zero or negative day counts and unknown IDs are all caught and reported.
- **Preserved history** — returned rentals are closed, never deleted, so the ledger stays complete.

### File Layout

| File | Role |
|------|------|
| `Vehicle.h` / `.cpp` | Abstract base class |
| `Car.h` / `.cpp` | Derived — plain daily rate |
| `Motorbike.h` / `.cpp` | Derived — long-stay discount |
| `Truck.h` / `.cpp` | Derived — surcharge |
| `Customer.h` / `.cpp` | Customer entity |
| `Rental.h` / `.cpp` | Rental record |
| `RentalSystem.h` / `.cpp` | System coordinator |
| `main.cpp` | Interactive menu driver |

### Build & Run

```bash
g++ -std=c++14 -Wall -o VehicleRental.exe main.cpp Vehicle.cpp Car.cpp \
    Motorbike.cpp Truck.cpp Customer.cpp Rental.cpp RentalSystem.cpp

.\VehicleRental.exe
```

---

## Compiling Any Single-File Lab

```bash
g++ -std=c++14 -o output TaskN.cpp
.\output.exe
```

---

<div align="center">

**Object-Oriented Programming**  ·  2nd Semester  ·  BS Software Engineering

</div>
