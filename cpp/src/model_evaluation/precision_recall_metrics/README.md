# Precision and Recall Metrics (C++)

This module calculates key classification metrics for a medical diagnostics scenario. The goal is to evaluate how reliable a diagnostic test is when it predicts a disease, and how often it successfully detects disease cases.

---

## Objective

Implement the missing code to compute:

- Precision: how many predicted positives are truly positive
- Recall (detection rate / sensitivity): how many actual positives are correctly detected

These metrics are computed using counts from a confusion matrix:
- True Positives (TP)
- False Positives (FP)
- False Negatives (FN)
- True Negatives (TN)

---

## Definitions

### Precision
precision = TP / (TP + FP)


Interpretation:
- Of all patients predicted as positive, how many truly have the disease?

### Recall (Sensitivity / Detection Rate)
recall = TP / (TP + FN)


Interpretation:
- Of all patients who truly have the disease, how many were detected by the test?

---

## Requirements

- Complete only the sections marked with TODO comments in the starter code
- Use `double` precision for computed metrics
- Handle edge cases safely:
  - If (TP + FP) == 0, precision should avoid division by zero
  - If (TP + FN) == 0, recall should avoid division by zero
- Ensure the output formatting matches the starter code expectations

---

## Expected Behavior

Given a confusion matrix with TP, FP, FN, TN:
- Precision and recall should be computed accurately
- Values should fall in the range [0, 1]

---

## Build and Run


g++ -std=c++17 cpp/src/model_evaluation/precision_recall_metrics/main.cpp -o metrics
./metrics
Notes
This module belongs to machine learning model evaluation.

Precision and recall are especially important in medical diagnostics where false positives and false negatives have different costs.

This module can be extended later to include F1 score, specificity, and accuracy.

