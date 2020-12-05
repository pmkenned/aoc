#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<string> req_fields;

int main()
{
    req_fields.push_back("byr");
    req_fields.push_back("iyr");
    req_fields.push_back("eyr");
    req_fields.push_back("hgt");
    req_fields.push_back("hcl");
    req_fields.push_back("ecl");
    req_fields.push_back("pid");
    //req_fields.push_back("cid");

    string s;
    ifstream infile;

    infile.open("../input.txt", ios::in);
    if (!infile) {
        cerr << "cannot open file" << endl;
        exit(1);
    }

    int num_valid = 0;
    set<string> fields;

    while (getline(infile, s)) {
        if (s == "") {
            num_valid++;
            for (auto it = req_fields.begin(); it != req_fields.end(); it++) {
                if (fields.find(*it) == fields.end()) {
                    num_valid--;
                    break;
                }
            }
            fields.clear();
            continue;
        }

        stringstream ss(s);
        string temp_str;

        while (getline(ss, temp_str, ' ')) {
            size_t pos = temp_str.find(':');
            string field = temp_str.substr(0, pos);
            fields.insert(field);
        }
    }
    cout << num_valid << endl;

    return 0;
}
