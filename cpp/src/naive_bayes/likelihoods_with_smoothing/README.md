# Naive Bayes Likelihoods with Laplace Smoothing (C++)

This module implements the computation of normalized value counts with Laplace smoothing for a Naive Bayes classifier, using a simple weather analysis dataset.

---

## Objective

- Compute conditional probabilities of feature values given a class label
- Apply Laplace (add-one) smoothing to handle unseen feature values
- Normalize counts to produce valid probability distributions
- Support categorical features used in Naive Bayes classification

---

## Context

In Naive Bayes classification, likelihoods are defined as:

P(feature = value | class)

Laplace smoothing is applied to avoid zero probabilities when a feature value does not appear for a given class in the training data.

This is especially important for:
- Small datasets
- Categorical features
- Robust prediction on unseen data

---

## What This Module Covers

- Extraction of unique class labels
- Extraction of unique feature values
- Counting feature occurrences per class
- Applying Laplace smoothing:
  
  (count + 1) / (class_count + number_of_unique_values)

- Producing normalized likelihood tables

---

## Expected Outcome

For each feature:
- For each class label:
  - A probability distribution over all possible feature values
- All probabilities for a given feature and class sum to 1

---

## Build and Run

g++ -std=c++17 cpp/src/naive_bayes/likelihoods_with_smoothing/main.cpp -o nb_smoothing
./nb_smoothing
Notes
This module is part of the Naive Bayes implementation path.

It builds on prior probability computation.

It can be extended later with:

Prediction logic

Log-probabilities

Multinomial or Bernoulli Naive Bayes variants