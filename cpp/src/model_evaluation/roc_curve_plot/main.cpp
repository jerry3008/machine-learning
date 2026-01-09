#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <iomanip>
#include <matplotlibcpp.h>
namespace plt = matplotlibcpp;
using namespace std;

pair<vector<double>, vector<double>> roc_curve(const vector<int>& truth_labels,
                                              const vector<double>& predicted_probs) {
    vector<double> thresholds;
    for (int i = 0; i <= 10; ++i) {
        thresholds.push_back(0.1 * i);
    }

    vector<double> tprs, fprs;

    for (double threshold : thresholds) 
    {
        int tp = 0, fp = 0, tn = 0, fn = 0;
        // TODO: calculate TP, FP, TN, FN
        for(int i = 0;  i < truth_labels.size(); ++i)
        {
            if(predicted_probs[i] >= threshold)
            {
                if(truth_labels[i]  == 1)
                {
                    tp++;
                }else 
                {
                    fp++;
                }
            }else if (predicted_probs[i] < threshold) 
            {
                if(truth_labels[i]  == 0)
                {
                    tn ++;
                }else 
                {
                    fn++;
                }
            
            }
        }
        
        double tpr = (tp + fn) > 0 ? static_cast<double>(tp) / (tp + fn) : 0.0;
        double fpr = (tn + fp) > 0 ? static_cast<double>(fp)/ (tn + fp) : 0.0;
        tprs.push_back(tpr);
        fprs.push_back(fpr);
    }
    

    return make_pair(tprs, fprs);
}

double compute_aucroc(const vector<double>& tprs, const vector<double>& fprs) {
    double aucroc = 0.0;
    for (size_t i = 1; i < tprs.size(); ++i) {
        aucroc += 0.5 * abs(fprs[i] - fprs[i - 1]) * (tprs[i] + tprs[i - 1]);
    }
    return aucroc;
}

int main() {
    // Set random seed for reproducibility
    random_device rd;
    mt19937 gen(rd());
    gen.seed(42);

    vector<int> truth_labels;
    vector<double> predicted_probs;

    // Generate truth labels
    uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < 100; ++i) {
        truth_labels.push_back(dis(gen) > 0.6 ? 1 : 0);
    }

    // Generate predicted probabilities
    normal_distribution<> normal_dis(0.0, 0.3);
    for (int label : truth_labels) {
        double prob = label + normal_dis(gen);
        prob = max(0.0, min(1.0, prob));
        predicted_probs.push_back(prob);
    }

    auto [tprs, fprs] = roc_curve(truth_labels, predicted_probs);

    // Plot ROC curve
    plt::plot(fprs, tprs, {{"marker", "."}});
    plt::xlabel("False Positive Rate (FPR)");
    plt::ylabel("True Positive Rate (TPR)");
    plt::title("Receiver Operating Characteristic (ROC) Curve");
    plt::save("static/images/plot.png");

    double aucroc = compute_aucroc(tprs, fprs);
    cout << "The AUC-ROC value is: " << fixed << setprecision(6) << aucroc << endl;

    return 0;
}