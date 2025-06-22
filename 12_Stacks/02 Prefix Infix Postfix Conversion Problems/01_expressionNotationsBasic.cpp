/*
===============================================================================
 File Name    : expression_notation_basics.cpp
 Description  :
     This file provides a conceptual introduction to different mathematical
     expression notations used in programming: infix, prefix (Polish), and
     postfix (Reverse Polish).

     The file explains:
     - What each notation means
     - Their respective syntaxes and evaluation rules
     - Step-by-step breakdown of evaluating a sample expression in each format
     - Operator precedence and associativity concerns

     These concepts are essential for understanding how compilers and interpreters
     parse and evaluate expressions, and lay the foundation for implementing
     algorithms that convert or evaluate expressions (to be added in future files).

 Expression Example Used:
     Prefix   : * + p q - m n
     Infix    : (p + q) * (m - n)
     Postfix  : p q + m n - *

 Upcoming:
     Future files will include C++ implementations for:
     - Converting between notations
     - Evaluating expressions using stack-based algorithms
     - Handling operator precedence and associativity

===============================================================================
*/

/*
1. Operand
--> a to z
--> A to Z
--> 0 to 9

2. Operator

exponentiation--> ^ (priority)--> 3
mulitiplication,division --> *, / --> 2
subtraction, addition --> +, - --> 1
others -- > -1

What is prefix expression?
The prefix expression as the name suggests has the operator placed before the operand is specified.
It is of the form <operator><operand><operand>.
It works entirely in the same manner as the postfix expression.
While evaluating a prefix expression, the operators are applied to the operands immediately on the right of the operator.
For evaluation, we evaluate it from left to right. Prefix expressions are also called polish notation.


What is postfix expression?
The postfix expression as the name suggests has the operator placed right after the two operands.
It is of the form <operand><operand><operator>
In the infix expressions, it is difficult to keep track of the operator precedence whereas here the postfix expression itself determines the precedence of operators (which is done by the placement of operators)i.e the operator which occurs first operates on the operand.
E.g. PQ-C/, here – operation is done on P and Q and then / is applied on C and the previous result.
A postfix expression is a parenthesis-free expression. For evaluation, we evaluate it from left to right.


What is infix expression?
The traditional method of writing mathematical expressions is called infix expressions.
It is of the form <operand><operator><operand>.
As the name suggests, here the operator is fixed inside between the operands. e.g. A+B here the plus operator is placed inside between the two operators, (A*B)/Q.
Such expressions are easy to understand and evaluate for human beings. However, the computer finds it difficult to parse - Information is needed about operator precedence and associativity rules, and brackets that override these rules.
Hence we have postfix and prefix notations which make the computer take less effort to solve the problem.




Certainly! Let’s walk through **how prefix, infix, and postfix expressions are evaluated step-by-step**, and then use the example:

---

## 🧠 Understanding the Notations

### 🔹 1. **Infix Expression**

* **Form:** `operand operator operand` (e.g., `A + B`)
* **Evaluation Rule:**

  * Follows **operator precedence** and **parentheses**.
  * Evaluated naturally (the way we do in math).

---

### 🔹 2. **Prefix Expression (Polish Notation)**

* **Form:** `operator operand operand` (e.g., `+ A B`)
* **Evaluation Rule:**

  * Scan **right to left**
  * When an operator is found, apply it to the **next two operands** from the right
  * Replace the operator and operands with the result and continue

---

### 🔹 3. **Postfix Expression (Reverse Polish Notation)**

* **Form:** `operand operand operator` (e.g., `A B +`)
* **Evaluation Rule:**

  * Scan **left to right**
  * When an operator is found, apply it to the **two most recent operands**
  * Replace the operands and operator with the result and continue

---

## 🔁 Let’s Use This Example:

* **Prefix:** `* + p q - m n`
* **Infix:** `(p + q) * (m - n)`
* **Postfix:** `p q + m n - *`

We'll evaluate **all three** step-by-step:

---

### ✅ **Step-by-step Evaluation**

---

### 🔸 Prefix: `* + p q - m n`

**Step-by-step:**

1. Start **right to left**
2. First, evaluate `-mn`
   → result = `(m-n)`
3. Then evaluate `+pq`
   → result = `(p+q)`
4. Now evaluate `* (p + q) (m - n)`
   → final result = `(p + q) * (m - n)`

---

### 🔸 Infix: `(p + q) * (m - n)`

**Step-by-step:**

1. Parentheses force you to evaluate `(p + q)` and `(m - n)` first
2. Evaluate `(p + q)` → result 1
3. Evaluate `(m - n)` → result 2
4. Multiply result 1 and result 2
   → final result = `(p + q) * (m - n)`

> This is the easiest to understand since it's natural mathematical order.

---

### 🔸 Postfix: `p q + m n - *`

**Step-by-step:**

1. Scan **left to right**
2. `p q +` → add `p` and `q` → result = `(p + q)`
3. `m n -` → subtract `n` from `m` → result = `(m - n)`
4. Now apply `*` on the two results → final = `(p + q) * (m - n)`

---

## ✅ Summary Table

| Notation | Expression          | Evaluation Order                  |
| -------- | ------------------- | --------------------------------- |
| Prefix   | `* + p q - m n`     | Right to Left:  `-`, `+`,then `*` |
| Infix    | `(p + q) * (m - n)` | Natural: Parentheses then `*`     |
| Postfix  | `p q + m n - *`     | Left to Right: `+`, `-`, then `*` |




*/