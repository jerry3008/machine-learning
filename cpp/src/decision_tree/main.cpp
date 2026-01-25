#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

string create_terminal(const vector<vector<string>>& group) 
{
    map<string, int> labs;
    string majority_class;
    int max_count = 0;
    for(const auto lab : group)
    {
        labs[lab.back()]++;
    }
    for(const auto [class1, count] : labs)
    {
        if(count > max_count)
        {
            max_count = count;
            majority_class = class1;
        }
    }
    return majority_class;
     
    // TODO: Return the most common output in the group (this will be our terminal node)
}

int main() {
    vector<vector<string>> group_1 = {
        {"2", "2", "Apple"}, {"1", "1", "Apple"}, {"2", "1", "Banana"},
        {"1", "2", "Banana"}, {"2", "1", "Apple"}
    };
    vector<vector<string>> group_2 = {
        {"3", "3", "Pear"}, {"3", "2", "Pear"}, {"3", "1", "Mango"},
        {"3", "3", "Pear"}, {"3", "2", "Mango"}
    };

    cout << create_terminal(group_1) << endl;  // Output: Apple
    cout << create_terminal(group_2) << endl;  // Output: Pear

    return 0;
}