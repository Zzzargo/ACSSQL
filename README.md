# ACSSQL
*POLITEHNICA Bucharest*
*Faculty of Computer Science and Automatic Control*
*Burlacu Vasile - 311CD - 2024*

## 📋 Overview
A C-based secretary tool that implements basic SQL-like operations and encryption capabilities for managing student records, course enrollments, and academic performance data.

## 🛠️ Features

	### 1️⃣ Core Database Operations
	- Read and parse academic database files
	- Memory management for dynamic data structures
	- Student record management
	- Course enrollment tracking
	- Grade calculation and GPA management

	### 2️⃣ SQL-like Query System
	Supports the following operations:
	- `SELECT`: Query data from the database. Supports multiple conditions for filtering.
	- `UPDATE`: Modify existing records with conditional updates
	- `DELETE`: Remove records based on specified conditions
	The syntax for each operation is similar to SQL. For example: `SELECT * FROM studenti;`

	### 3️⃣ Encryption System
	- Cipher block chaining  implementation for student data security
	- Custom S-box transformation
	- XOR-based encryption with key and IV support
	- Multi-block chaining mechanism
	- By default the students vector is split into 4 blocks, but this can be changed just by modifying the constant defined in the header of task3.c

## 🔧 Technical Implementation
- Written in C
- Modular architecture with separate components for:
  - Reading a database from file (task1.c)
  - Query processing (task2.c)
  - Encryption system (task3.c)
- Memory-safe implementation with proper allocation/deallocation
- Custom data structures for academic entities

## 🏗️ Project Structure
```
.
├── src/
│   ├── task1.c    # Database reading
│   ├── task2.c    # SQL query processor
│   └── task3.c    # Encryption implementation
├── include/
    └── structuri.h # Data structures definitions
```
## 🔍 Data Models
Students: ID, name, year, status, GPA
Courses: ID, name, professor
Enrollments: Student ID, Course ID, grades (lab, midterm, final)
