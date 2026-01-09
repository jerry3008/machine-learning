#include <cstddef>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// TODO: Define a function to compute AUCROC using the Trapezoidal rule based on lists of TPRs and FPRs
double compute_aucroc(const vector<double>& tprs, const vector<double>&fprs)
{
    double aucroc = 0.0;
    for(size_t i = 1; i < tprs.size(); ++i)
    {
        aucroc += 0.5 * abs(fprs[i] - fprs[i -1]) * (tprs[i] + tprs[i - 1]);
    }
    
    return aucroc;
}

int main() 
{
    // These lists would normally be obtained by running a function calculating TPRs and FPRs at various thresholds
    vector<double> tprs = {0, 0.33, 0.67, 1, 1};  // True Positive Rates
    vector<double> fprs = {0, 0.25, 0.5, 0.75, 1};  // False Positive Rates

    // TODO: Use your function to compute AUCROC and print the result
    double aucroc = compute_aucroc(tprs, fprs);
    cout << "AUCROC for the test is: " << aucroc << endl;

    return 0;
}