#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {
    MatrixXf house_size(3, 1);
    house_size << 1200, 1500, 1000;
    VectorXf prices(3);
    prices << 240000, 300000, 200000;
    VectorXf theta(2);
    theta << 100000, 100;

    float learning_rate = 0.01;
    int m = prices.size();

    MatrixXf X_b(house_size.rows(), 2);
    X_b << MatrixXf::Ones(3, 1), house_size;
    
    
    VectorXf gradient = (1.0f / m ) * (X_b.transpose() * (X_b *  theta - prices ));
    theta -= learning_rate * gradient;
    cout << "Predicted prices: " << (X_b * theta).transpose() << endl;

    // TODO: Update the theta parameters using the gradient descent rule

    cout << "Updated parameters: " << theta.transpose() << endl;

    return 0;
}