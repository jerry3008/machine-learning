# Naive Bayes Play Prediction (C++)

This module implements a Naive Bayes classifier to predict whether we can play on a new day based on weather features.

It uses:
- Prior probabilities for the class label
- Likelihoods per feature value with Laplace (add-one) smoothing
- A prediction step that selects the class with the highest probability

---

## Objective

Complete the missing prediction logic in the Naive Bayes classifier:

- Retrieve likelihoods for each feature value given a class
- Apply Laplace smoothing when a feature value is not present
- Multiply priors by likelihoods to compute class probabilities
- Select the class with the maximum probability as the prediction

---

## Dataset

Each record contains:
- Features: Temperature, Outlook
- Label: Yes or No

A new day is represented as a feature map without a label, and the classifier predicts the label.

---

## Build and Run


g++ -std=c++17 cpp/src/naive_bayes/play_prediction/main.cpp -o play_prediction
./play_prediction
Notes
This module belongs to Naive Bayes classification fundamentals.

Laplace smoothing prevents zero-probability issues for missing values.

This task builds on prior probability and likelihood table computation.