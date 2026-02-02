# 📌 Eastern Exhibition — Manhattan Distance Optimization

## 🧠 Problem Overview

You are given the locations of `n` houses on a 2D plane, each with **integer coordinates**.  
Your task is to determine **how many integer-coordinate points** can serve as a location for an exhibition such that the **sum of Manhattan distances** from all houses to the exhibition is **minimized**.

The Manhattan distance between two points is defined as:

\[
|x_1 - x_2| + |y_1 - y_2|
\]

The exhibition **may be built at the same location as any house**.

---

## 🎯 Objective

For each test case, compute:

> **The number of distinct integer points** where placing the exhibition yields the **minimum possible total Manhattan distance** from all houses.

---

## 🔑 Key Insight

The Manhattan distance is **separable by dimensions**:

\[
\sum (|x_i - X| + |y_i - Y|)
=
\sum |x_i - X| + \sum |y_i - Y|
\]

This means:
- The optimal **x-coordinate** can be determined independently
- The optimal **y-coordinate** can be determined independently

So the 2D problem reduces to solving **two independent 1D problems**.

---

## 📐 1D Optimization Rule (Crucial)

Given numbers:

\[
x_1, x_2, \dots, x_n
\]

The value of `X` that minimizes:

\[
\sum |x_i - X|
\]

is any **median** of the array.

---

### 📌 Case Analysis

#### ✅ When `n` is **odd**
- There is **exactly one median**
- Only **one optimal coordinate** exists

#### ✅ When `n` is **even**
- Any integer value between the **two middle elements (inclusive)** is optimal
- This forms a **continuous interval of optimal values**

---

## 🧩 Applying This to 2D

- Let the optimal x-values lie in range **[lx, rx]**
- Let the optimal y-values lie in range **[ly, ry]**

Every pair `(X, Y)` such that:
- `X ∈ [lx, rx]`
- `Y ∈ [ly, ry]`

produces the **minimum total distance**.

---

## 🧮 Final Count Formula

The total number of valid exhibition positions is:

\[
(rx - lx + 1) \times (ry - ly + 1)
\]

This represents the **area of the rectangle** formed by optimal x and y ranges.

---

## ⚙️ Algorithm Summary

For each test case:

1. Separate all x-coordinates and y-coordinates
2. Sort both arrays
3. Determine median (or median range) for x and y
4. Compute the number of valid positions using the formula above

---

## ⏱️ Complexity

- **Time:** `O(n log n)` (due to sorting)
- **Space:** `O(n)`
- Efficient for large inputs since the total `n` across test cases is bounded

---

## 🧠 Takeaway

> **Minimizing Manhattan distance ⇒ choose medians**  
> **Even-sized input ⇒ interval of optimal solutions**  
> **Independent dimensions ⇒ rectangular solution space**

This technique is widely applicable in **facility location**, **grid optimization**, and **competitive programming problems involving Manhattan distance**.
