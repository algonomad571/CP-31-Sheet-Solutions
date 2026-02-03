# 🧮 Zero Array — Feasibility via Invariants

## 🧠 Problem Overview

You are given an array `a₁, a₂, …, aₙ`.

In **one operation**, you may:
- Choose **two distinct indices** `i ≠ j`
- Decrease **both** `a[i]` and `a[j]` by `1`

Your task is to determine whether it is **possible to make all elements equal to `0`**.

---

## 🎯 Objective

Check if the array can be transformed into an array of all zeros using the allowed operation.  
Print `"YES"` if possible, otherwise print `"NO"`.

---

## 🔑 Key Observations

### 1️⃣ Parity of the total sum

Let:
\[
S = a_1 + a_2 + \dots + a_n
\]

- Each operation decreases the total sum by **2**
- Therefore, the **parity of the sum is invariant**

To end at all zeros:
\[
S \equiv 0 \pmod{2}
\]

❌ If `S` is odd → **impossible**

---

### 2️⃣ Dominant element constraint

Let:
- `mx` = maximum element in the array

In each operation:
- An element can decrease by **at most 1**
- It must be paired with **another element**

So the rest of the array must have enough total value to “support” reducing the maximum.

Formally:
\[
mx \le S - mx
\]

❌ If this fails → the largest element cannot be fully reduced

---

## ✅ Necessary and Sufficient Conditions

The transformation is possible **if and only if**:

1. The total sum is **even**
2. The maximum element is **not greater than the sum of the remaining elements**

---

## 🧮 Algorithm Summary

1. Read the array
2. Compute:
   - Total sum `S`
   - Maximum element `mx`
3. Check:
   - `S % 2 == 0`
   - `mx ≤ S - mx`
4. Output `"YES"` if both conditions hold, else `"NO"`

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`
- Works efficiently for large inputs (`n ≤ 10⁵`)

---

## 🧠 Key Takeaways

- Track **invariants** instead of simulating operations
- Each operation affects the array in a predictable way
- Dominant elements often determine feasibility

---

## 🏷️ Tags

`Greedy` · `Math` · `Invariants` · `Implementation`

---

## ⭐ Final Note

This problem highlights how simple mathematical reasoning can completely eliminate the need for simulation.  
Once the invariants are identified, the solution becomes immediate and elegant.
