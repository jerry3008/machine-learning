#include <iostream>
#include <Eigen/Dense>
#include <cmath>

using namespace std;
using namespace Eigen;

VectorXf sigmoid(const VectorXf& z)
    {
        return 1.0/ (1.0 + (-z.array()).exp());
    }
int main() {
    VectorXf email_scores(3);
    email_scores << 2.5f, -1.3f, 0.6f;
    
    VectorXf email_probabilities = sigmoid(email_scores);

    // TODO: Compute the probabilities of the emails being spam using the sigmoid function

    cout << "Email probabilities:\n" << email_probabilities << endl;

    return 0;
}