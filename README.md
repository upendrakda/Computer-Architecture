# 🖥️ Computer Organization & Binary Arithmetic Programs in C

## 📌 Introduction
This repository contains C programs that implement fundamental binary number system operations and computer arithmetic algorithms used in Computer Organization and Architecture (COA).

The programs demonstrate:
- Binary ↔ Decimal conversions
- 1’s and 2’s Complement
- Binary addition and subtraction
- Signed Magnitude arithmetic
- 2’s Complement arithmetic
- Booth’s Multiplication
- Signed Magnitude Division

These programs simulate how arithmetic operations are performed at the hardware level (ALU level) using fixed-width representations.

---

## 📚 Table of Contents
1. Binary ↔ Decimal Conversion
2. 1’s Complement & 2’s Complement
3. Binary Addition & Subtraction
4. Signed Magnitude Addition
5. Signed Magnitude Subtraction
6. 2’s Complement Addition
7. 2’s Complement Subtraction
8. Signed Magnitude Multiplication
9. Booth’s Multiplication
10. Signed Magnitude Division

---

### 1️⃣ Binary ↔ Decimal Conversion

#### 🔹 Introduction
Binary and decimal conversions are fundamental operations in digital systems.

---

#### 🔹 Core Concepts
Binary to Decimal:  
decimal=Σ(bit×2<sup>position</sup>)

Decimal to Binary:  
Repeated division by 2

---

#### 🔹 Key Points
- Binary uses base 2
- Decimal uses base 10
- Conversion is essential for understanding machine-level data

---

#### 🔹 Use of the Program
- Convert binary input to decimal
- Convert decimal input to binary

---

#### 🔹 Advantages
- Simple implementation
- Helps understand positional number systems

---

#### 🔹 Disadvantages
- Limited to fixed integer sizes
- No fractional support

---

### 2️⃣ 1’s Complement & 2’s Complement

#### 🔹 Introduction
Complements are used to represent negative numbers in digital systems.

---

#### 🔹 Core Concepts
- 1’s Complement → Flip all bits
- 2’s Complement → 1’s complement + 1

---

#### 🔹 Key Points
- 2’s complement is used in modern computers
- Avoids two zero representations (unlike 1’s complement)

---

#### 🔹 Use of the Program
- Generate 1’s complement
- Generate 2’s complement

---

#### 🔹 Advantages
- Simplifies subtraction
- Hardware efficient

---

#### 🔹 Disadvantages
- Fixed bit-width required
- Overflow must be handled carefully

---

### 3️⃣ Binary Addition & Subtraction

#### 🔹 Introduction
Implements binary arithmetic similar to hardware adders.

---

#### 🔹 Core Concepts
- XOR → sum
- AND/OR → carry
- Subtraction using 2’s complement

---

#### 🔹 Key Points
- Carry propagation is important
- Subtraction = Addition of 2’s complement

---

#### 🔹 Advantages
- Simulates real digital logic
- Reinforces Boolean algebra concepts

---

#### 🔹 Disadvantages
- Manual carry handling required
- Limited bit-length

---

### 4️⃣ Signed Magnitude Addition

#### 🔹 Introduction
Signed magnitude representation separates sign and magnitude bits.

---

#### 🔹 Core Concepts
- MSB = Sign bit
- Same sign → Add magnitudes
- Different sign → Subtract magnitudes

---

#### 🔹 Key Points
- Two representations of zero possible
- Sign must be handled separately

---

#### 🔹 Advantages
- Conceptually simple
- Easy to understand manually

---

#### 🔹 Disadvantages
- Not used in modern processors
- Arithmetic logic is more complex than 2’s complement

---

### 5️⃣ Signed Magnitude Subtraction

#### 🔹 Introduction
Subtraction in signed magnitude is performed as:
```Code
A - B = A + (-B)
```

---

#### 🔹 Core Concepts
- Flip sign of second operand
- Apply signed magnitude addition rules

---

#### 🔹 Advantages
- Logical and easy to follow
- Clear separation of sign handling

---

#### 🔹 Disadvantages
- Requires multiple condition checks
- Not hardware efficient

---

### 6️⃣ 2’s Complement Addition

#### 🔹 Introduction
2’s complement is the standard representation for signed integers in modern systems.

---

#### 🔹 Core Concepts
- Same as normal binary addition
- Detect overflow when:
- Two positives give negative
- Two negatives give positive

---

#### 🔹 Key Points
- Range (8-bit): -128 to +127
- Single representation of zero

---

#### 🔹 Advantages
- Simple hardware implementation
- Efficient subtraction handling

---

#### 🔹 Disadvantages
- Overflow detection required

---

### 7️⃣ 2’s Complement Subtraction

#### 🔹 Introduction
Subtraction is directly performed as:
```Code
A - B
```
because 2’s complement internally handles sign.

---

#### 🔹 Core Concepts
- No manual sign management needed
- Overflow detection required

---

#### 🔹 Advantages
- Very hardware efficient
- Used in real CPUs

---

#### 🔹 Disadvantages
- Fixed width limitation

---

### 8️⃣ Signed Magnitude Multiplication

#### 🔹 Introduction
Multiplication using signed magnitude separates sign and magnitude.

---

#### 🔹 Core Concepts
- Result sign = XOR of operand signs
- Multiply magnitudes
- Check overflow

---

#### 🔹 Key Points
- 8-bit signed magnitude range: -127 to +127
- Overflow possible if result magnitude > 127

---

#### 🔹 Advantages
- Conceptually simple
- Good for theoretical understanding

---

#### 🔹 Disadvantages
- Overflow frequent
- Not hardware preferred method

---

### 9️⃣ Booth’s Multiplication

#### 🔹 Introduction
Booth’s Algorithm efficiently multiplies signed 2’s complement numbers.

---

#### 🔹 Core Concepts
- Uses registers: A, Q, Q-1
- Decision based on Q₀ and Q₋₁:
    - 01 → Add M
    - 10 → Subtract M
    - 00 / 11 → No operation
- Arithmetic right shift after each step

---

#### 🔹 Key Points
- Reduces number of additions
- Handles negative numbers naturally
- Uses fixed-width registers

---

#### 🔹 Advantages
- Efficient for signed multiplication
- Hardware-friendly
- Reduces operations for consecutive 1s

---

#### 🔹 Disadvantages
- More complex logic
- Requires careful bit manipulation

---

### 🔟 Signed Magnitude Division

#### 🔹 Introduction
Division using signed magnitude separates sign and magnitude before division.

---

#### 🔹 Core Concepts
- Quotient sign = XOR of operand signs
- Magnitude division performed normally
- Remainder sign = Same as dividend

---

#### 🔹 Key Points
- Division by zero must be handled
- Overflow possible in fixed-width systems

---

#### 🔹 Advantages
- Simple conceptual model
- Easy to implement logically

---

#### 🔹 Disadvantages
- Not used in real hardware
- Requires manual sign management

---

## 🧠 Overall Learning Outcomes
By completing these programs, you understand:
- Fixed-width number representation
- Overflow behavior
- Difference between Signed Magnitude and 2’s Complement
- Hardware-level arithmetic simulation
- Booth’s algorithm implementation
- Binary arithmetic fundamentals

---

## ⚙️ Requirements
- C Compiler (GCC / MinGW / Clang)
- Standard C Library
- Works on Linux / Windows (modify system("clear") if needed)

---

## 📌 Conclusion
These programs collectively demonstrate how arithmetic is performed inside a computer system using different signed number representations and algorithms.

They are especially useful for:

- Computer Organization & Architecture labs
- Digital Logic courses
- Exam preparation
- Understanding ALU behavior

---

✨ *Built with logic. Implemented with C. Inspired by Computer Architecture.*

Stay curious. Keep coding.

---