# Gradient Descent Parameter Adjustment (C++)

This task focuses on the most critical step in gradient descent: **updating model parameters using the gradient and learning rate**.

The goal is to complete the missing logic that adjusts parameters to reduce prediction error.

---

## Objective

Fill in the missing lines of code that update the hypothesis parameters using the gradient descent update rule:

parameter = parameter - learning_rate * gradient


This operation should be applied consistently to all parameters in the model.

---

## Context

Gradient descent is an iterative optimization algorithm used in machine learning to minimize a cost function.

This task isolates the **parameter update step**, which is fundamental to:
- Linear regression
- Logistic regression
- Neural networks
- Many optimization-based learning algorithms

---

## Requirements

- Complete only the sections marked with TODO comments
- Use the provided learning rate
- Update parameters in the opposite direction of the gradient
- Do not modify how gradients are computed
- Use `double` precision for numerical values

---

## Expected Behavior

Given:
- One or more parameters (e.g., theta0, theta1)
- Corresponding gradients
- A learning rate

After the update step, parameters should move closer to values that minimize the cost function.

---

## Build and Run

g++ -std=c++17 cpp/src/gradient_descent/parameter_adjustment/main.cpp -o gd_adjust
./gd_adjust
Notes
This task belongs to machine learning fundamentals, not data structures and algorithms.

It represents the core learning step in gradient-based optimization.

The structure allows easy extension to full gradient descent implementations.

---

### Summary (clear takeaway)

- This **does not** go in `MyDataStructureJourney`
- It **does** belong in your `machine-learning` repo
- The correct path is:

cpp/src/gradient_descent/parameter_adjustment/