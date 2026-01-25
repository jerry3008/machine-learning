#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

// Select the best split point for a dataset
struct TreeNode {
    int index;
    double value;
    vector<vector<vector<string>>> groups;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : index(-1), value(0.0), left(nullptr), right(nullptr) {}
};

pair<vector<vector<string>>, vector<vector<string>>> test_split(int index, double value, const vector<vector<string>>& dataset) {
    vector<vector<string>> left, right;
    for (const auto& row : dataset) {
        if (stod(row[index]) < value) {
            left.push_back(row);
        } else {
            right.push_back(row);
        }
    }
    return make_pair(left, right);
}

double gini_index(const vector<vector<vector<string>>>& groups, const vector<string>& classes) {
    double total_instances = 0.0;
    for (const auto& group : groups) {
        total_instances += group.size();
    }

    double gini = 0.0;
    for (const auto& group : groups) {
        double size = group.size();
        if (size == 0) continue;

        double score = 0.0;
        for (const string& class_val : classes) {
            int count = 0;
            for (const auto& row : group) {
                if (row.back() == class_val) count++;
            }
            score += (count / size) * (count / size);
        }
        gini += (1.0 - score) * (size / total_instances);
    }
    return gini;
}

string create_terminal(const vector<vector<string>>& group) {
    map<string, int> outcomes;
    for (const auto& row : group) {
        outcomes[row.back()]++;
    }

    string majority_class;
    int max_count = 0;
    for (const auto& pair : outcomes) {
        if (pair.second > max_count) {
            max_count = pair.second;
            majority_class = pair.first;
        }
    }
    return majority_class;
}

void recurse_split(TreeNode* node, int max_depth, int min_size, int depth);

TreeNode* get_split(const vector<vector<string>>& dataset) {
    set<string> class_values_set;
    for (const auto& row : dataset) {
        class_values_set.insert(row.back());
    }
    vector<string> class_values(class_values_set.begin(), class_values_set.end());

    int b_index = 999;
    double b_value = 999.0;
    double b_score = 999.0;
    vector<vector<vector<string>>> b_groups;

    for (int index = 0; index < dataset[0].size() - 1; ++index) {
        for (const auto& row : dataset) {
            auto groups_pair = test_split(index, stod(row[index]), dataset);
            vector<vector<vector<string>>> groups = {groups_pair.first, groups_pair.second};
            double gini = gini_index(groups, class_values);
            if (gini < b_score) {
                b_index = index;
                b_value = stod(row[index]);
                b_score = gini;
                b_groups = groups;
            }
        }
    }

    TreeNode* node = new TreeNode();
    node->index = b_index;
    node->value = b_value;
    node->groups = b_groups;
    return node;
}

TreeNode* build_tree(const vector<vector<string>>& train, int max_depth, int min_size) {
    TreeNode* root = get_split(train);
    recurse_split(root, max_depth, min_size, 1);
    return root;
}

void recurse_split(TreeNode* node, int max_depth, int min_size, int depth) {
    auto left = node->groups[0];
    auto right = node->groups[1];
    node->groups.clear();
    if(left.empty() || right.empty())
    {
        vector<vector<string>> combined;
        combined.insert(combined.end(), left.begin(), left.end());
        combined.insert(combined.end(), right.begin(), right.end());
        string terminal_value = create_terminal(combined);
        node -> left = new TreeNode();
        node -> right = new TreeNode();
        node -> left -> value = stod(terminal_value);
        node -> right -> value = stod(terminal_value);
        return;
    }
    
    if(depth >= max_depth)
    {
        node -> left = new TreeNode();
        node -> right = new TreeNode();
        node -> left -> value = stod(create_terminal((left)));
        node -> right -> value = stod(create_terminal(right));
        return;
    }
    
    
    if(left.size() <= min_size)
    {
        node -> left = new TreeNode();
        node -> left -> value = stod(create_terminal(left));
        
    }else 
    {
        node -> left = get_split(left);
        recurse_split(node->left, max_depth, min_size, depth + 1);
    }
    if(right.size() <= min_size)
    {
        node -> right = new TreeNode();
        node -> right -> value = stod(create_terminal(right));
        
    }else 
    {
        node -> right = get_split(right);
        recurse_split(node->right, max_depth, min_size, depth + 1);
    }

    // TODO: Handle the case if either left or right group is empty.

    // TODO: Handle the case if the current depth has reached or exceeded the maximum depth.

    // TODO: Process the left group, call `create_terminal` or `get_split` method based on group size. Implement recursion if necessary.

    // TODO: Process the right group, call `create_terminal` or `get_split` method based on group size. Implement recursion if necessary.
}

void print_tree(TreeNode* node, int depth = 0) {
    if (node->left != nullptr && node->right != nullptr) {
        string indent(depth * 2, ' ');
        cout << indent << "[X" << (node->index + 1) << " < " << fixed << setprecision(3) << node->value << "]" << endl;
        print_tree(node->left, depth + 1);
        print_tree(node->right, depth + 1);
    } else {
        string indent(depth * 2, ' ');
        cout << indent << "[" << node->value << "]" << endl;
    }
}

int main() {
    // Sample dataset from the lesson
    vector<vector<string>> dataset = {
        {"5", "3", "0"}, {"6", "3", "0"}, {"6", "4", "0"}, {"10", "3", "1"},
        {"11", "4", "1"}, {"12", "8", "0"}, {"5", "5", "0"}, {"12", "4", "1"}
    };
    int max_depth = 2;
    int min_size = 1;
    TreeNode* tree = build_tree(dataset, max_depth, min_size);
    print_tree(tree);

    return 0;
}