# Decision Tree – Recursive Splitting (C++)

This module focuses on **recursively building a Decision Tree** by splitting data into
left and right child nodes until stopping conditions are met.

It is part of the larger **Decision Tree implementation** within the
*Machine Learning from Scratch* project.

---

## What This Module Covers

This folder demonstrates how a Decision Tree grows using **recursion**.

Specifically, it implements:
- Selecting the best split for a node
- Creating left and right child nodes
- Recursively splitting child nodes
- Stopping recursion when conditions are met
- Creating terminal (leaf) nodes

---

## Core Idea (Simple Explanation)

1. Start with a dataset at a node
2. Find the best feature and value to split the data
3. Divide the data into:
   - Left group
   - Right group
4. Repeat the process on each group
5. Stop splitting when:
   - Maximum depth is reached
   - A group is too small
   - A split produces an empty group
6. Assign a **terminal value** (majority class) at the leaf

This recursive process builds the full Decision Tree.

---

## Stopping Conditions Used

A node becomes a **terminal (leaf) node** when:
- The current depth reaches the maximum allowed depth
- The number of rows in a group is less than or equal to the minimum size
- One side of a split is empty

In these cases, the node predicts the **most common class** in its group.

---

## Files in This Folder

- `main.cpp`
  - Implements recursive splitting logic
  - Builds the tree using depth and node-size constraints
  - Prints the tree structure for visualization



## How to Compile and Run

From the repository root:

g++ cpp/src/decision_tree/recursive_split/main.cpp -o recursive_tree
./recursive_tree