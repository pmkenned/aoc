#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef struct {
    string color;
    vector<string> contains;
} rule_t;

rule_t
parse_rule(const string & rule_str)
{
    rule_t rule;
    stringstream ss(rule_str);
    string tmp_str;
    bool seen_bags = false;
    bool seen_contain = false;
    bool is_number = true;

    string color_rhs;

    while (getline(ss, tmp_str, ' ')) {
        if (!seen_bags && tmp_str != "bags") {
            rule.color += tmp_str;
        } else if (!seen_bags && tmp_str == "bags") {
            seen_bags = true;
        } else if (seen_bags && tmp_str == "contain") {
            seen_contain = true;
        } else if (seen_contain && (tmp_str.substr(0,3) != "bag")) {
            if (tmp_str == "no")
                break;
            if (!is_number)
                color_rhs += tmp_str;
            is_number = false;
        } else if (seen_contain && (tmp_str.substr(0,3) == "bag")) {
            rule.contains.push_back(color_rhs);
            color_rhs = "";
            is_number = true;
        }
    }

    return rule;
}

int main()
{
    string s;
    ifstream infile;

    infile.open("../input.txt", ios::in);
    if (!infile) {
        cerr << "cannot open file" << endl;
        exit(1);
    }

    vector<rule_t> rules;

    while (getline(infile, s)) {
        rules.push_back(parse_rule(s));
    }

    set<string> unique_colors;
    vector<string> colors_to_find;
    vector<string> colors_to_find2;
    colors_to_find.push_back("shinygold");

    while (!colors_to_find.empty()) {
        for (auto it3 = colors_to_find.begin(); it3 != colors_to_find.end(); it3++) {
            for (auto it = rules.begin(); it != rules.end(); it++) {
                auto it2 = find(it->contains.begin(), it->contains.end(), *it3);
                if (it2 != it->contains.end()) {
                    // avoid infinite loop case
                    if (find(unique_colors.begin(), unique_colors.end(), it->color) == unique_colors.end()) {
                        colors_to_find2.push_back(it->color);
                        unique_colors.insert(it->color);
                    }
                }
            }
        }
        colors_to_find = colors_to_find2;
        colors_to_find2.clear();
    }

    cout << unique_colors.size() << endl;

    return 0;
}
