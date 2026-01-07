#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 float precision(float TP, float FP)
{
    return TP / (TP + FP);
}

 float recall(float TP, float FN)
{
    return TP / (TP + FN);
}

int main() {
    // Scenario: Medical Diagnostics

    vector<int> true_disease = {1, 0, 1, 1, 0, 0, 1, 1, 0, 1};  // 1 indicates disease, 0 no disease
    vector<int> predicted_disease = {1, 0, 0, 1, 0, 1, 1, 1, 1, 0};

    int TP = 0, FP = 0, FN = 0, TN = 0;

    for (size_t i = 0; i < true_disease.size(); ++i) 
    {
        if (true_disease[i] == 1 && predicted_disease[i] == 1) 
        {
            TP++;
        } else if (true_disease[i] == 0 && predicted_disease[i] == 1) 
        {
            FP++;
        } else if (true_disease[i] == 1 && predicted_disease[i] == 0) 
        {
            FN++;
        }else if(true_disease[i] == 0 && predicted_disease[i] == 0)
        {
            TN++;
        }
    }
        
    float precision_val = precision(TP, FP);
    float recall_val = recall(TP, FN);
    // TODO: Compute the precision of the test.
   
    // TODO: Compute the recall of the test.

    cout << "Precision: " << round(precision_val  * 100) / 100.0 << endl;
    cout << "Recall: " << round(recall_val * 100) / 100.0 << endl;

    return 0;
}