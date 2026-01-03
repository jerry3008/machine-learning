cpp/src/gradient_descent/cost_threshold_convergence/README.md:

# Gradient Descent with Cost Threshold Convergence (C++)

This module implements a variation of gradient descent where training continues until the cost function drops below a specified threshold, rather than running for a fixed number of iterations.

The task focuses on controlling convergence using a stopping condition based on model performance.

---

## Objective

Modify the gradient descent training loop to:

- Use a `while` loop instead of a fixed iteration count
- Continue updating model parameters until the cost is less than `0.01`
- Stop training once the threshold is reached

---

## Context

In practical machine learning systems, it is often preferable to stop training based on model performance rather than an arbitrary iteration count.

This task demonstrates a **cost-based convergence criterion**, which is commonly used in:
- Linear regression
- Logistic regression
- Neural network training
- Optimization algorithms

---

## Requirements

- Use a `while` loop for the training process
- Recompute the cost after each parameter update
- Stop training when:


cost < 0.01

- Do not modify the cost calculation logic
- Complete only the sections marked with TODO comments
- Use `double` precision for all numerical values

---

## Expected Behavior

Given:
- Initial model parameters
- A learning rate
- A cost function

The training loop should:
1. Compute gradients
2. Update parameters
3. Recompute cost
4. Repeat until the cost threshold is met

Training must terminate automatically once the model converges.

---

## Build and Run


g++ -std=c++17 cpp/src/gradient_descent/cost_threshold_convergence/main.cpp -o gd_threshold
./gd_threshold

Notes

This module belongs to machine learning fundamentals.

It is not a data structures and algorithms problem.

Cost-based stopping criteria are more adaptive than fixed-iteration approaches.

This structure allows easy comparison with iteration-based gradient descent implementations.


---

## Clear takeaway

- Correct repo: `machine-learning`
- Correct path:


cpp/src/gradient_descent/cost_threshold_convergence/