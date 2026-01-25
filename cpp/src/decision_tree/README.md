# Decision Tree (C++)

This folder is part of the **Machine Learning from Scratch** repository.  
Here we implement key building blocks of a **Decision Tree classifier** in C++ (no external ML libraries).

## What a Decision Tree Does (simple explanation)

A Decision Tree makes predictions by repeatedly asking questions about the input features, such as:

- “Is feature_1 <= 2?”
- “Is feature_2 == 'High'?”

Each question splits the dataset into smaller groups.  
The tree continues splitting until it reaches a point where it should stop.  
When it stops, it creates a **leaf node** (also called a **terminal node**) that returns a final prediction.

## What This Folder Implements Right Now

###  Terminal Node (Leaf) Creation

When the tree decides it can’t (or shouldn’t) split anymore, it needs a final answer.

We create a terminal node by selecting the **most common label** in a dataset group:

- Count how many times each class label appears in the group
- Choose the label with the highest count
- Return that label as the leaf’s prediction

This is called the **majority class**.


## Input Format Used in This Implementation

We represent a dataset group as:

vector<vector<string>>
Each row is:

{ feature_1, feature_2, ..., label }

So the label is always the last element in the row (row.back()).

Example row:

{ "2", "1", "Apple" }
Example

If a group contains:

Apple: 3 rows

Banana: 2 rows

Then the terminal node returns:

Apple
Files

main.cpp

Contains the Decision Tree terminal node function (leaf creation)

Includes a small test dataset to confirm correct output

How to Compile and Run

From the repository root (machine-learning/):

g++ cpp/src/decision_tree/main.cpp -o decision_tree
./decision_tree
Next Steps (planned)

As you build the full Decision Tree, this folder can grow to include:

Gini Index / Entropy calculations

Best split selection

Recursive tree building

Prediction function for new samples