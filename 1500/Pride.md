# 🧮 A. Pride — Making All Elements Equal to 1

## 🧠 Problem Overview

You are given an array `a` of length `n`.  
You can perform the following operation any number of times:

- Choose **two adjacent elements** `x` and `y`
- Replace **one of them** with `gcd(x, y)`

Your goal is to make **all elements of the array equal to `1`** using the **minimum number of operations**.

If it is **impossible**, output `-1`.

---

## 🎯 Objective

Determine the **minimum number of operations** required to transform the entire array into all `1`s, or decide that it cannot be done.

---

## 🔑 Key Observations

### 1️⃣ Presence of `1` simplifies everything

- If the array already contains `k` elements equal to `1`
- Any adjacent element can be turned into `1` in **one operation**, because:
  \[
  \gcd(x, 1) = 1
  \]
- Therefore:
  - Each non-`1` element needs exactly **one operation**

✅ **Answer = `n - k`**

---

### 2️⃣ No `1` in the array — harder case

- The only way to create a `1` is by taking a **subarray whose GCD is `1`**
- If **no such subarray exists**, it is **impossible** to ever reach `1`

❌ In this case, output `-1`

---

## 🧩 Optimal Strategy (No `1` Case)

1. Find the **shortest subarray** whose GCD equals `1`
   - Let its length be `L`
2. Operations required:
   - `L - 1` operations to reduce that subarray into a single `1`
   - `n - 1` operations to spread that `1` across the entire array

### ✅ Total operations:
\[
(L - 1) + (n - 1)
\]

---

## 🧮 Algorithm Summary

1. Count how many elements are already `1`
2. If at least one `1` exists:
   - Output `n - (count of 1s)`
3. Otherwise:
   - Search all subarrays to find the minimum length with GCD = `1`
   - If none exists → output `-1`
   - Else → compute `(L - 1) + (n - 1)`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n² log A)`
- **Space Complexity:** `O(1)` extra space
- Efficient enough for `n ≤ 2000`

---

## 🧠 Key Takeaways

- `1` is a **powerful element** under GCD operations
- Creating `1` is the **core challenge**
- Always aim for the **shortest GCD-1 subarray**

---

## ⭐ Final Note

This problem is a great example of how **mathematical properties (GCD)** drive optimal strategies in competitive programming.

Once you see how `1` propagates, the problem becomes much simpler.
