#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct {
    string color;
    map<string, int> contains;
} rule_t;

vector<rule_t> rules;

rule_t
parse_rule(const string & rule_str)
{
    rule_t rule;
    stringstream ss(rule_str);
    string tmp_str;
    bool seen_bags = false;
    bool seen_contain = false;
    bool is_number = true;
    int num = 0;

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
            if (is_number)
                num = stoi(tmp_str);
            else
                color_rhs += tmp_str;
            is_number = false;
        } else if (seen_contain && (tmp_str.substr(0,3) == "bag")) {
            rule.contains[color_rhs] = num;
            color_rhs = "";
            is_number = true;
        }
    }

    return rule;
}

int
count_bags(const string & color)
{
    int count = 0;
    for (auto it = rules.begin(); it != rules.end(); it++) {
        if (it->color == color) {
            for (auto it2 = it->contains.begin(); it2 != it->contains.end(); it2++) {
                const string & new_color = it2->first;
                int n = it2->second;
                count += n*(count_bags(new_color)+1);
            }
        }
    }
    return count;
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

    while (getline(infile, s)) {
        rules.push_back(parse_rule(s));
    }

    cout << count_bags("shinygold") << endl;

    return 0;
}
