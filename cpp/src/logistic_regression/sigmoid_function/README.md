# Sigmoid Function (C++)

This module implements the **sigmoid function**, a fundamental building block of logistic regression.
The sigmoid function transforms real-valued inputs into probabilities between 0 and 1.

---

## Objective

Implement the sigmoid function used in logistic regression to convert model outputs into probabilities.

The sigmoid function is defined as:

sigmoid(z) = 1 / (1 + exp(-z))

---

## Context

In logistic regression, the sigmoid function is applied to the linear combination of inputs and weights to:

- Produce probabilistic outputs
- Enable binary classification
- Support gradient-based optimization

This function is essential for:
- Prediction
- Loss computation (log loss)
- Gradient calculation

---

## Requirements

- Implement the sigmoid function using `std::exp`
- Use `double` precision for all calculations
- Follow the provided starter code and TODO comments
- Ensure numerical stability where applicable

---

## Expected Behavior

Given input values:

| Input (z) | Output (sigmoid(z)) |
|----------|----------------------|
| 0.0 | 0.5 |
| Positive value | Output approaches 1 |
| Negative value | Output approaches 0 |

The function must always return a value strictly between 0 and 1.

---

## Build and Run

g++ -std=c++17 cpp/src/logistic_regression/sigmoid_function/main.cpp -o sigmoid
./sigmoid
Notes
This task belongs to machine learning fundamentals.

It is not a data structures and algorithms problem.

The sigmoid function is reused across multiple ML models.

This module will be extended later for prediction and training steps