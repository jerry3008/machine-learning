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

map<string, map<string, map<string, double>>> calculate_likelihoods_with_smoothing(
    const vector<DataPoint>& data, const vector<string>& feature_names) {

    map<string, map<string, map<string, double>>> likelihoods;

    vector<string> classes;
    for (const DataPoint& point : data) {
        if (find(classes.begin(), classes.end(), point.label) == classes.end()) {
            classes.push_back(point.label);
        }
    }

    for (const string& feature : feature_names) 
    {
        likelihoods[feature] = map<string, map<string, double>>();
        
        vector<string> unique_values;
        for (const DataPoint& point : data) 
        {
            string value = point.features.at(feature);
            if (find(unique_values.begin(), unique_values.end(), value) == unique_values.end()) 
            {
                unique_values.push_back(value);
            }
        }

        // TODO: Write code to select class_data from data where corresponding label values are equal to class_
        for (const string& class_ : classes) 
        {
            map<string, int> feature_counts;
            int class_count = 0;
            for(const DataPoint& point : data)
            {
                if(point.label == class_)
                {
                    feature_counts[point.features.at(feature)]++;
                    class_count++;
                }
            }
            // Count feature values for this class
            // (Loop through data, check if point.label == class_, then count feature values)


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

int main() {
    // Create the features (X) and target (y) DataFrames
    vector<DataPoint> weather_data = {
        DataPoint({{"Temperature", "Hot"}, {"Humidity", "High"}}, "Sunny"),
        DataPoint({{"Temperature", "Mild"}, {"Humidity", "High"}}, "Cloudy"),
        DataPoint({{"Temperature", "Cold"}, {"Humidity", "High"}}, "Rainy"),
        DataPoint({{"Temperature", "Hot"}, {"Humidity", "Normal"}}, "Sunny"),
        DataPoint({{"Temperature", "Mild"}, {"Humidity", "Normal"}}, "Cloudy"),
        DataPoint({{"Temperature", "Cold"}, {"Humidity", "Normal"}}, "Rainy"),
        DataPoint({{"Temperature", "Hot"}, {"Humidity", "Low"}}, "Sunny")
    };

    vector<string> feature_names = {"Temperature", "Humidity"};
    auto likelihoods = calculate_likelihoods_with_smoothing(weather_data, feature_names);
    for (const auto& feature_pair : likelihoods) {
    cout << "Feature: " << feature_pair.first << endl;
    for (const auto& class_pair : feature_pair.second) {
        cout << "  Class: " << class_pair.first << endl;
        for (const auto& value_pair : class_pair.second) {
            cout << "    " << value_pair.first << ": " << value_pair.second << endl;
        }
    }
}

    // TODO: Call the calculate_likelihoods_with_smoothing function with weather_data and feature_names and print its return value.
}