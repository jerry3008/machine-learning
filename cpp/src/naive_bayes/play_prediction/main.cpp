#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct DataPoint {
    map<string, string> features;
    string label;

    DataPoint(const map<string, string>& f, const string& l) : features(f), label(l) {}
};

// Function to calculate prior probabilities
map<string, double> calculate_prior_probabilities(const vector<string>& labels) {
    map<string, int> class_counts;
    int total_count = labels.size();

    for (const string& label : labels) {
        class_counts[label]++;
    }

    map<string, double> priors;
    for (const auto& pair : class_counts) {
        priors[pair.first] = static_cast<double>(pair.second) / total_count;
    }

    return priors;
}

// Function to calculate likelihoods with Laplace smoothing
map<string, map<string, map<string, double>>> calculate_likelihoods_with_smoothing(
    const vector<DataPoint>& data, const vector<string>& feature_names) {

    map<string, map<string, map<string, double>>> likelihoods;

    vector<string> classes;
    for (const DataPoint& point : data) {
        if (find(classes.begin(), classes.end(), point.label) == classes.end()) {
            classes.push_back(point.label);
        }
    }

    for (const string& feature : feature_names) {
        likelihoods[feature] = map<string, map<string, double>>();

        for (const string& class_ : classes) {
            likelihoods[feature][class_] = map<string, double>();

            map<string, int> feature_counts;
            int class_count = 0;

            for (const DataPoint& point : data) {
                if (point.label == class_) {
                    feature_counts[point.features.at(feature)]++;
                    class_count++;
                }
            }

            vector<string> unique_values;
            for (const DataPoint& point : data) {
                string value = point.features.at(feature);
                if (find(unique_values.begin(), unique_values.end(), value) == unique_values.end()) {
                    unique_values.push_back(value);
                }
            }

            int total_with_smoothing = class_count + unique_values.size();
            for (const string& value : unique_values) {
                int count = (feature_counts.find(value) != feature_counts.end()) ?
                           feature_counts[value] : 0;
                likelihoods[feature][class_][value] =
                    static_cast<double>(count + 1) / total_with_smoothing;
            }
        }
    }

    return likelihoods;
}

// Naive Bayes classifier function
vector<string> naive_bayes_classifier(
    const vector<DataPoint>& test_data,
    const map<string, double>& priors,
    const map<string, map<string, map<string, double>>>& likelihoods,
    const vector<string>& feature_names) {

    vector<string> predictions;

    for (const DataPoint& data_point : test_data) {
        map<string, double> class_probabilities;

        for (const auto& prior_pair : priors) {
            string class_ = prior_pair.first;
            class_probabilities[class_] = prior_pair.second;

            for (const string& feature : feature_names) {
                string feature_value = data_point.features.at(feature);
                double likelihood;
                if(likelihoods.at(feature).at(class_).find(feature_value) != likelihoods.at(feature).at(class_).end())
                {
                    likelihood = likelihoods.at(feature).at(class_).at(feature_value);
                }else
                {
                    likelihood = 1.0/(likelihoods.at(feature).at(class_).size()+1);
                }
                class_probabilities[class_] *= likelihood;

                // TODO: Retrieve the likelihood for this feature value, class, and feature.
                // Use Laplace smoothing if the value is not present.
                // double likelihood = ...;

                // TODO: Multiply the class probability by the likelihood.
                // class_probabilities[class_] *= likelihood;
            }
        }
        string predicted_class = class_probabilities.begin()->first;
        double max_prob = class_probabilities.begin()->second;
        for (const auto& prob_pair : class_probabilities) {
            if (prob_pair.second > max_prob) {
                max_prob = prob_pair.second;
                predicted_class = prob_pair.first;
            }
        }
        predictions.push_back(predicted_class);

        // TODO: Find the class with the maximum probability and add it to predictions.
        // string predicted_class = ...;
        // predictions.push_back(predicted_class);
    }

    return predictions;
}

int main() {
    vector<DataPoint> df = {
        DataPoint({{"Temperature", "Hot"}, {"Outlook", "Sunny"}}, "Yes"),
        DataPoint({{"Temperature", "Cold"}, {"Outlook", "Rainy"}}, "Yes"),
        DataPoint({{"Temperature", "Cold"}, {"Outlook", "Rainy"}}, "No"),
        DataPoint({{"Temperature", "Hot"}, {"Outlook", "Sunny"}}, "Yes"),
        DataPoint({{"Temperature", "Cold"}, {"Outlook", "Sunny"}}, "No")
    };

    // Extract labels
    vector<string> labels;
    for (const DataPoint& point : df) {
        labels.push_back(point.label);
    }

    // Calculate the prior probabilities
    map<string, double> priors = calculate_prior_probabilities(labels);

    // Calculate the likelihoods with Laplace smoothing
    vector<string> feature_names = {"Temperature", "Outlook"};
    auto likelihoods = calculate_likelihoods_with_smoothing(df, feature_names);

    // Predicting whether we can play or not on a new day
    vector<DataPoint> new_day = {
        DataPoint({{"Temperature", "Hot"}, {"Outlook", "Sunny"}}, "")
    };

    vector<string> predictions = naive_bayes_classifier(new_day, priors, likelihoods, feature_names);
    cout << "Can we play on a new day? " << predictions[0] << endl;

    return 0;
}