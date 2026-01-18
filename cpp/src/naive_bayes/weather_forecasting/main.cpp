#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<string, double> calculate_prior_probabilities(const vector<string>& labels) 
{
    map<string,  int>Label_count;
    for(const auto label  : labels)
    {
        Label_count[label]++;
    } 
    map<string, double> probabilities;
    int total_count = labels.size();
    for(const auto [lab1, lab2] : Label_count)
    {
        probabilities[lab1] = static_cast<double>(lab2)/ total_count;
    }
    
    return probabilities;
    // TODO: Calculate and return the frequency of each unique value in labels
}


int main() {
    // Example dataset for weather forecasting
    vector<map<string, string>> data = {
        {{"Outlook", "Sunny"}, {"Temperature", "Hot"}, {"Forecast", "Clear"}},
        {{"Outlook", "Rainy"}, {"Temperature", "Hot"}, {"Forecast", "Rain"}},
        {{"Outlook", "Sunny"}, {"Temperature", "Cold"}, {"Forecast", "Clear"}},
        {{"Outlook", "Sunny"}, {"Temperature", "Warm"}, {"Forecast", "Cloudy"}},
        {{"Outlook", "Rainy"}, {"Temperature", "Cold"}, {"Forecast", "Snow"}}
    };
    
    vector<string>forecast_labels;
    for(const auto& row : data)
    {
        forecast_labels.push_back(row.at("Forecast"));
    }
    auto result = calculate_prior_probabilities(forecast_labels);
    // TODO: Use the above function to calculate and print these important values for 'Forecast'
    for (const auto& [label, prob] : result) 
    {
        cout << label << ": " << prob << endl;
    }
}