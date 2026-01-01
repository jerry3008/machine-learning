# Gradient Descent Parameter Update (C++)

This module implements the parameter update step of gradient descent for a simple hypothesis model, framed in the context of real estate market data.

The focus of this task is to update model parameters using a learning rate and computed gradients.

---

## Objective

Implement the missing code that updates hypothesis parameters according to the gradient descent update rule:

theta = theta - learning_rate * gradient



This update should be applied consistently to all parameters in the model.

---

## Context

Gradient descent is an optimization algorithm used to minimize a cost function by iteratively adjusting parameters in the direction that reduces error.

This task isolates the **parameter update step**, which is a core building block for:
- Linear regression
- Logistic regression
- Neural networks

---

## Requirements

- Complete only the sections marked with TODO comments
- Use the learning rate to scale parameter updates
- Do not modify the gradient calculation logic
- Use double precision for all numerical values

---

## Expected Behavior

Given:
- A set of parameters (e.g., theta0, theta1)
- Corresponding gradients
- A learning rate

The updated parameters should move in the opposite direction of the gradients.

---

## Build and Run


g++ -std=c++17 cpp/src/gradient_descent/parameter_update/main.cpp -o gd_update
./gd_update
Notes
This module belongs to machine learning fundamentals.

It is not a data structures and algorithms problem.

This structure allows easy extension to batch, stochastic, or mini-batch gradient descent in the future.