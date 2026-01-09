# AUC-ROC from Scratch Using the Trapezoidal Rule (C++)

This module computes the AUC-ROC (Area Under the ROC Curve) without using any prebuilt AUC functions.
It uses the trapezoidal rule to integrate the ROC curve built from true outcomes and predicted probabilities.

---

## Objective

Implement the missing code to compute the AUC-ROC value given:
- `y_true`: true binary outcomes (0 or 1)
- `y_score`: predicted probabilities (0.0 to 1.0)

The implementation must:
1. Construct ROC points by sweeping a decision threshold
2. Compute TPR and FPR at each step
3. Sort ROC points by increasing FPR
4. Compute the area under the curve using the trapezoidal rule

---

## Definitions

### Confusion counts (at a threshold)
- TP: predicted 1 and actual 1
- FP: predicted 1 and actual 0
- TN: predicted 0 and actual 0
- FN: predicted 0 and actual 1

### Rates
TPR (Recall) = TP / (TP + FN)
FPR = FP / (FP + TN)

yaml
Copy code

---

## Trapezoidal Rule for AUC

Given ROC points sorted by FPR:
AUC = sum over i of (FPR_i - FPR_{i-1}) * (TPR_i + TPR_{i-1}) / 2



## Requirements

- Do not use prebuilt AUC or ROC functions
- Use the trapezoidal rule for integration
- Handle ties in predicted probabilities consistently (as required by the starter code)
- Ensure ROC includes endpoints:
  - (0, 0)
  - (1, 1)
- Use `double` precision
- Complete only the TODO sections in the starter code

---

## Expected Behavior

Given valid input vectors `y_true` and `y_score` of equal length:
- The computed AUC should fall in [0, 1]
- Higher AUC indicates better ranking of positives above negatives

---

## Build and Run

g++ -std=c++17 cpp/src/model_evaluation/auc_roc_trapezoidal/main.cpp -o auc_roc
./auc_roc