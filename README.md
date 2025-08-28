# 🧮 Advanced Calculator Suite

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](<https://en.wikipedia.org/wiki/C_(programming_language)>)
[![Data Structures](https://img.shields.io/badge/Data%20Structures-Linked%20Lists%20%26%20Stacks-green.svg)](#)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg)](#)
[![GitHub](https://img.shields.io/badge/GitHub-Repository-black.svg)](https://github.com/HasanQarmash/linkedlist-arithmetic-calculator)
[![Stars](https://img.shields.io/github/stars/HasanQarmash/linkedlist-arithmetic-calculator?style=social)](https://github.com/HasanQarmash/linkedlist-arithmetic-calculator/stargazers)

> A comprehensive mathematical computation system featuring large integer arithmetic operations and expression evaluation, implemented using advanced data structures in C.

## 📋 Table of Contents

- [🎯 Overview](#-overview)
- [⚡ Quick Start](#-quick-start)
- [✨ Features](#-features)
- [🏗️ Architecture](#️-architecture)
- [🚀 Getting Started](#-getting-started)
- [💻 Usage](#-usage)
- [📊 Examples](#-examples)
- [🔧 Technical Implementation](#-technical-implementation)
- [📁 Project Structure](#-project-structure)
- [🧪 Testing](#-testing)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)

## 🎯 Overview

This project consists of two powerful mathematical tools:

### 1. 🔢 Large Integer Calculator

Performs arithmetic operations on arbitrarily large integers using **doubly linked lists** to overcome traditional integer size limitations.

### 2. 📝 Expression Evaluator

Converts infix mathematical expressions to prefix notation and evaluates them using **stack-based algorithms**.

## ⚡ Quick Start

```bash
# Clone the repository
git clone https://github.com/HasanQarmash/linkedlist-arithmetic-calculator.git
cd linkedlist-arithmetic-calculator

# Compile the programs
gcc -o calculator P1_1210611_HasanQarmash_2.c -lm
gcc -o expression_evaluator main.c -lm

# Run the large integer calculator
./calculator

# Run the expression evaluator
./expression_evaluator
```

## ✨ Features

### Large Integer Calculator

- ➕ **Addition** of numbers with unlimited digits
- ➖ **Subtraction** with proper sign handling
- ✖️ **Multiplication** using optimized algorithms
- ➗ **Division** with remainder calculation
- 📁 **File I/O** for reading/writing large numbers
- 🔄 **Sign management** for positive and negative numbers

### Expression Evaluator

- 🔄 **Infix to Prefix** conversion
- ✅ **Syntax validation** with detailed error reporting
- 🧮 **Expression evaluation** with operator precedence
- 📊 **Parentheses balancing** checker
- 📝 **Batch processing** from input files
- 📋 **Comprehensive reporting** to output files

## 🏗️ Architecture

### Data Structures Used

#### Doubly Linked List (Large Numbers)

```c
struct node {
    int digit;                  // Single digit (0-9)
    pointerToNode Next;         // Next digit
    pointerToNode prev;         // Previous digit
};
```

#### Stack (Expression Evaluation)

```c
struct stack {
    int Element;                // Numeric value
    char operation;             // Operator character
    pointerToTop Next;          // Next stack element
};
```

## 🚀 Getting Started

### Prerequisites

- GCC Compiler
- C Standard Library
- Text editor or IDE (VS Code, Code::Blocks, etc.)

### Compilation

```bash
gcc -o calculator P1_1210611_HasanQarmash_2.c -lm
```

### Input File Format

#### For Large Integer Calculator (`read.txt`):

```
123456789012345678901234567890
-987654321098765432109876543210
555666777888999000111222333444
```

#### For Expression Evaluator (`reader.txt`):

```
(2+3)*4-5
[10/2]+3*4
2^3+4*5-6
```

## 💻 Usage

### Large Integer Calculator

```bash
./calculator
# Select option 1-7 from the menu:
# 1. Read numbers from file
# 2. Addition
# 3. Subtraction
# 4. Multiplication
# 5. Division
# 6. Save result to file
# 7. Exit
```

### Expression Evaluator

```bash
./main
# Select option 1-7 from the menu:
# 1. Read expressions from file
# 2. Check validity of equations
# 3. Convert to prefix notation
# 4. Evaluate prefix expressions
# 5. Display invalid equations
# 6. Export results to file
# 7. Exit
```

## 📊 Examples

### Large Integer Arithmetic

#### Input:

```
Number 1: 999999999999999999999999999999
Number 2: 111111111111111111111111111111
Operation: Addition
```

#### Output:

```
Result: 1111111111111111111111111111110
```

### Expression Evaluation

#### Input:

```
Infix: (2+3)*4-5
```

#### Processing:

```
1. Validation: ✅ Valid
2. Prefix: -*+2345
3. Evaluation: 15
```

## 🔧 Technical Implementation

### Key Algorithms

#### 1. Large Integer Addition

- **Time Complexity**: O(max(m,n)) where m,n are digit counts
- **Space Complexity**: O(max(m,n))
- **Method**: Digit-by-digit addition with carry propagation

#### 2. Large Integer Multiplication

- **Time Complexity**: O(m×n)
- **Space Complexity**: O(m+n)
- **Method**: Grade school multiplication with linked list optimization

#### 3. Infix to Prefix Conversion

- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- **Method**: Modified Shunting Yard algorithm with stack

#### 4. Expression Validation

- **Parentheses Balancing**: Stack-based matching
- **Operator Validation**: Precedence and syntax checking
- **Error Reporting**: Detailed diagnostic messages

### Memory Management

- Dynamic allocation for unlimited number size
- Proper deallocation to prevent memory leaks
- Error handling for out-of-memory conditions

## 📁 Project Structure

```
📦 Calculator-Suite/
├── 📄 P1_1210611_HasanQarmash_2.c    # Large integer calculator
├── 📄 main.c                          # Expression evaluator
├── 📄 README.md                       # Project documentation
├── 📁 bin/Release/                    # Compiled executables
├── 📁 input/
│   ├── 📄 read.txt                    # Numbers input file
│   └── 📄 reader.txt                  # Expressions input file
├── 📁 output/
│   ├── 📄 write.txt                   # Calculator results
│   └── 📄 output.txt                  # Expression results
└── 📁 docs/
    └── 📄 Project 1 Spring 2023.pdf  # Project specifications
```

## 🧪 Testing

### Test Cases Included
- ✅ Large number arithmetic (1000+ digits)
- ✅ Negative number handling
- ✅ Edge cases (zero, single digit)
- ✅ Complex nested expressions
- ✅ Invalid syntax detection
- ✅ File I/O operations

### Sample Test Files

Create `read.txt` for large integer calculator:
```
999999999999999999999999999999
123456789012345678901234567890
-555666777888999000111222333444
```

Create `reader.txt` for expression evaluator:
```
(2+3)*4-5
[10/2]+3*4
2^3+4*5-6
```

## 🎯 Use Cases

### Academic Applications

- **Computer Science Education**: Data structures demonstration
- **Mathematics**: Large number computations
- **Algorithm Analysis**: Complexity studies

### Practical Applications

- **Cryptography**: Large prime number operations
- **Financial Systems**: High-precision calculations
- **Scientific Computing**: Arbitrary precision arithmetic

## 🏆 Performance Highlights

- **Handles numbers with 10,000+ digits**
- **Processes complex expressions with multiple operators**
- **Validates and reports syntax errors accurately**
- **Memory-efficient linked list implementation**
- **Fast stack-based expression evaluation**

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. 🍴 Fork the repository
2. 🌿 Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. ✅ Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. 📤 Push to the branch (`git push origin feature/AmazingFeature`)
5. 🔄 Open a Pull Request

### Areas for Enhancement

- [ ] GUI interface development
- [ ] Additional mathematical operations (sqrt, power, etc.)
- [ ] Floating-point support
- [ ] Performance optimizations
- [ ] Unit test suite expansion

## 👨‍💻 Author

**Hasan Qarmash**

- Student ID: 1210611
- Section: 2
- Course: COMP2421 (Data Structures)
- University: Birzeit University

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **Birzeit University** - Computer Science Department
- **COMP2421 Course** - Data Structures and Algorithms
- **C Programming Community** - For excellent documentation and examples

---

<div align="center">
  <strong>🌟 If this project helped you, please consider giving it a star! 🌟</strong>
</div>

---

_"Mathematics is not about numbers, equations, computations, or algorithms: it is about understanding."_ - William Paul Thurston
