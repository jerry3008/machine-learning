# ROC Curve Computation and Plotting (C++)

This module computes the key components of a ROC curve and visualizes it using `matplotlib-cpp`.
The task focuses on calculating the True Positive Rate (TPR) and False Positive Rate (FPR) across thresholds and plotting the resulting ROC curve.

---

## Objective

Implement the missing code to:

1. Compute True Positive Rate (TPR)
2. Compute False Positive Rate (FPR)
3. Generate ROC curve points
4. Plot the ROC curve using `matplotlib-cpp`

---

## Definitions

Given a binary classification problem:

### True Positive Rate (TPR)
TPR = TP / (TP + FN)


### False Positive Rate (FPR)
FPR = FP / (FP + TN)

yaml
Copy code

Where:
- TP = True Positives
- FP = False Positives
- FN = False Negatives
- TN = True Negatives

---

## Requirements

- Use the provided true labels and predicted probabilities
- Sweep across thresholds to compute (FPR, TPR) points
- Ensure the ROC curve includes:
  - (0, 0)
  - (1, 1)
- Use `double` precision for all rates
- Plot the ROC curve using `matplotlib-cpp`
- Complete only the sections marked with TODO comments

---

## Visualization

The plotted ROC curve should:
- Have FPR on the x-axis
- Have TPR on the y-axis
- Show a curve from (0,0) to (1,1)
- Optionally include a diagonal reference line (random classifier)

---

## Build and Run

Ensure Python and matplotlib are available, and `matplotlib-cpp` is properly configured.


g++ -std=c++17 cpp/src/model_evaluation/roc_curve_plot/main.cpp -o roc_plot
./roc_plot
Notes
This module belongs to machine learning model evaluation.

ROC curves visualize classifier performance across all thresholds.

This task complements the AUC-ROC computation module.

Keep plotting logic separate from metric computation for clarity.