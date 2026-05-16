# Result Record System

## Overview

The **Result Record System** is a robust, terminal-based application designed to streamline the management of student academic performance. Developed in C, this system provides a secure and efficient way for lecturers to manage student grades and for students to view their results and academic progress.

## Key Features

### 👨‍🏫 Lecturer Module
- **Record Management**: Create, update, and delete student academic records.
- **Data Insertion**: Input Student ID, Name, Subject Code, and Marks.
- **Bulk View**: Display all student records with automatically calculated grades.
- **Advanced Search**: Quickly locate specific student results by ID.
- **Secure Access**: Dedicated lecturer registration and login system.

### 🎓 Student Module
- **Result Query**: Students can search for their own academic records using their Student ID.
- **Performance Summary**: Automatically calculates and displays the student's average mark across subjects.
- **Secure Access**: Individual student accounts for privacy.

### ⚙️ Core Functionality
- **Automated Grading**: System automatically assigns grades based on MMU standards (A+ to F).
- **Persistent Storage**: All data is stored in localized `.txt` files for easy portability.
- **Input Validation**: Ensures data integrity during record entry and updates.

## Technology Stack

- **Language**: C
- **Libraries**: `stdio.h`, `stdlib.h`, `string.h`, `conio.h`
- **Data Storage**: Text-based file system (`Record`, `l_login.txt`, `s_login.txt`)

## Getting Started

### Prerequisites
- A C compiler (e.g., GCC, MinGW, or Clang).

### Execution
1.  Compile the source code:
    ```bash
    gcc "Result Record.c" -o ResultRecord
    ```
2.  Run the executable:
    ```bash
    ./ResultRecord
    ```

## Project Structure

- `Result Record.c`: The main source code containing system logic.
- `Record`: Binary/Text data file for storing student results.
- `l_login.txt`: Registry for lecturer credentials.
- `s_login.txt`: Registry for student credentials.

## Team Members

1. **Kho Wei Cong**
2. **Lim Swee Ming**
3. **Choi Zhong Zhi**
4. **Chan Yar Jing**

