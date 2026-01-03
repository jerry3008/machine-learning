#include <iostream>
#include <Eigen/Dense>
#include <cstdlib>

using namespace std;
using namespace Eigen;

tuple<VectorXf, std::vector<float>> gradient_descent(MatrixXf X, VectorXf y, VectorXf theta, float alpha, int iterations) {
    int m = y.size();
    std::vector<float> cost_history;
    float cost = 1000.0f; // Start with a large value
    int i = 0;

    while (cost > 0.01f) 
    {
        VectorXf prediction = X * theta;
        theta = theta - (1.0f / m) * alpha * (X.transpose() * (prediction - y));
        
        cost  = (1.0f / (2 * m)) * (prediction - y).squaredNorm();
        cost_history.push_back(cost);
        i++;
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

    auto [theta, cost_history] = gradient_descent(X_b_real_estate, house_prices, theta_real_estate, alpha_real_estate, iterations);

    for (int i = 0; i < iterations; i += 10) {
        cout << "Iteration " << i << ": Cost = " << cost_history[i] << endl;
    }

    return 0;
}