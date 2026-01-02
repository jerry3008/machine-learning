#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>

using namespace std;
using namespace Eigen;

tuple<VectorXf, VectorXf> gradient_descent(MatrixXf X, VectorXf y, VectorXf theta, float alpha, int iterations) {
    int m = y.size();
    VectorXf cost_history(iterations);

    for (int i = 0; i < iterations; ++i) 
    {
        VectorXf prediction = X * theta;
        VectorXf gradient = (1.0f/ m) * X.transpose() * (prediction - y);
        theta -= alpha  * gradient;
        cost_history(i)= (1.0f/ (2 * m)) * (prediction - y).squaredNorm(); 
        // TODO: Adjust the parameters 'theta' using the gradient descent update rule
        // TODO: Calculate the mean square error cost and record it into cost_history
    }

    return {theta, cost_history};
}

int main() {
    MatrixXf house_sizes(3, 1);
    house_sizes << 1000, 1500, 2000;
    house_sizes = (house_sizes.array() - house_sizes.mean()) / std::sqrt((house_sizes.array() - house_sizes.mean()).square().mean());

    MatrixXf house_prices(3, 1);
    house_prices << 300, 450, 600;

    VectorXf theta_real_estate = VectorXf::Random(2);
    float alpha_real_estate = 0.01;
    int iterations = 500;

    MatrixXf X_b_real_estate(house_sizes.rows(), 2);
    X_b_real_estate << MatrixXf::Ones(3, 1), house_sizes;

    // TODO: Use the gradient_descent function to update 'theta_real_estate' and 'cost_history'
    auto [theta, cost_history] = gradient_descent( X_b_real_estate,  house_prices, theta_real_estate, alpha_real_estate, iterations);

    for (int i = 0; i < iterations; i += 10) {
        cout << "Iteration " << i << ": Cost = " << cost_history(i) << endl;
    }

    return 0;
}