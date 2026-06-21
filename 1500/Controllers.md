# 🎮 Controllers — Balancing Score with Two Buttons

## 🧠 Problem Overview

You are playing a game consisting of `n` rounds.  
In each round, a symbol appears on the screen:

- `'+'` → your score **increases**
- `'-'` → your score **decreases**

You have a controller with **two buttons**, each labeled with a number.  
In every round, you must press **exactly one button**.

- If the symbol is `'+'`, your score increases by the pressed button’s value
- If the symbol is `'-'`, your score decreases by the pressed button’s value

The game starts with score `0`.

---

## 🎯 Objective

After all `n` rounds, your **final score must be exactly `0`** to win.

You are given `q` different controllers, each with button values `(a, b)`.

For **each controller**, determine whether it is **possible to win the game**.

---

## 🔑 Key Observation

The **order of rounds does not matter** — only the **count** of `'+'` and `'-'` symbols matters.

Let:
- `P` = number of `'+'` rounds
- `M` = number of `'-'` rounds

Each `'+'` adds either `a` or `b`  
Each `'-'` subtracts either `a` or `b`

---

## 🧩 Reformulating the Problem

Let:
- `x` = number of times button `a` is pressed during `'+'` rounds  
- `P - x` = number of times button `b` is pressed during `'+'` rounds  

Similarly, let:
- `y` = number of times button `a` is pressed during `'-'` rounds  
- `M - y` = number of times button `b` is pressed during `'-'` rounds  

### Final score equation:

\[
(x \cdot a + (P - x) \cdot b) - (y \cdot a + (M - y) \cdot b) = 0
\]

Simplifying:

\[
(a - b)(x - y) + b(P - M) = 0
\]

Let:
\[
t = x - y
\]

We now solve:

\[
(a - b)t = -b(P - M)
\]

---

## 📐 Case Analysis

### ✅ Case 1: `a == b`

Both buttons are identical.

- Every `'+'` adds `a`
- Every `'-'` subtracts `a`

Final score:
\[
a(P - M)
\]

✔️ You win **if and only if**:
\[
P = M
\]

---

### ✅ Case 2: `a ≠ b`

We need an **integer solution** to:

\[
t = \frac{-b(P - M)}{a - b}
\]

And it must satisfy **feasibility constraints**:

- You can press button `a` at most `P` times in `'+'` rounds
- You can press button `a` at most `M` times in `'-'` rounds

This gives:
\[
-M \le t \le P
\]

✔️ If both conditions hold:
- Division is exact
- `t` is within bounds

→ The game **is winnable**

---

## 🧮 Algorithm Summary

1. Count number of `'+'` → `P`
2. Count number of `'-'` → `M`
3. For each controller `(a, b)`:
   - If `a == b`, check `P == M`
   - Else:
     - Check divisibility of the equation
     - Check bounds on `t`

---

## ⏱️ Complexity

- **Preprocessing:** `O(n)`
- **Each query:** `O(1)`
- **Total:** `O(n + q)`

Efficient for large constraints (`n ≤ 2×10⁵`, `q ≤ 10⁵`).

---

## 🧠 Key Takeaways

- Order doesn’t matter → **count-based reasoning**
- Reduce to a **linear Diophantine equation**
- Feasibility comes from **bounds on button usage**

This is a powerful pattern for problems involving **choices with fixed counts** and **score balancing**.
