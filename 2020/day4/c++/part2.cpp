#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <cctype>

using namespace std;

vector<string> req_fields;

long
to_long(const string & s)
{
    long value_int = -1;
    try {
        value_int = stol(s);
    } catch (const invalid_argument & e) { }
    return value_int;
}

bool
all_digits(const string & s)
{
    for (size_t i=0; i < s.length(); i++)
        if (!isdigit(s.at(i)))
            return false;
    return true;
}

bool
valid_byr(const string & s)
{
    long value_int = to_long(s);
    if (!all_digits(s) || (s.length() != 4) || (value_int < 1920) || (value_int > 2002))
        return false;
    return true;
}

bool
valid_iyr(const string & s)
{
    long value_int = to_long(s);
    if (!all_digits(s) || (s.length() != 4) || (value_int < 2010) || (value_int > 2020))
        return false;
    return true;
}

bool
valid_eyr(const string & s)
{
    long value_int = to_long(s);
    if (!all_digits(s) || (s.length() != 4) || (value_int < 2020) || (value_int > 2030))
        return false;
    return true;
}

bool
valid_hgt(const string & s)
{
    bool end_in_cm = (s.length() >= 2) && s.substr(s.length()-2, 2) == "cm";
    bool end_in_in = (s.length() >= 2) && s.substr(s.length()-2, 2) == "in";
    long value_int = (s.length() > 2) ? to_long(s.substr(0, s.length()-2)) : -1;
    if (end_in_cm) {
        if ((value_int < 150) || (value_int > 193))
            return false;
    } else if (end_in_in) {
        if ((value_int < 59) || (value_int > 76))
            return false;
    } else {
        return false;
    }

    return true;
}

bool
valid_hcl(const string & s)
{
    if (s.length() != 7)
        return false;
    if (s.at(0) != '#')
        return false;
    for (size_t i=1; i < s.length(); i++)
        if (((s[i] < '0') || (s[i] > '9')) && ((s[i] < 'a') || (s[i] > 'f')))
            return false;
    return true;
}

bool
valid_ecl(const string & s)
{
    if (s != "amb" && s != "blu" && s != "brn" && s != "gry" && s != "grn" && s != "hzl" && s != "oth")
        return false;
    return true;
}

bool
valid_pid(const string & s)
{
    if ((s.length() != 9) || !all_digits(s))
        return false;
    return true;
}

bool
passport_valid(const map<string, string> & fields)
{
    for (auto it = fields.begin(); it != fields.end(); it++) {
        const string & field = it->first;
        const string & value = it->second;
        bool fields_valid = true;
        if      (field == "byr") { fields_valid &= valid_byr(value); }
        else if (field == "iyr") { fields_valid &= valid_iyr(value); }
        else if (field == "eyr") { fields_valid &= valid_eyr(value); }
        else if (field == "hgt") { fields_valid &= valid_hgt(value); }
        else if (field == "hcl") { fields_valid &= valid_hcl(value); }
        else if (field == "ecl") { fields_valid &= valid_ecl(value); }
        else if (field == "pid") { fields_valid &= valid_pid(value); }
        else if (field == "cid") { }
        else { fields_valid = false; }

        if (!fields_valid)
            return false;
    }

    for (auto it = req_fields.begin(); it != req_fields.end(); it++) {
        if (fields.find(*it) == fields.end())
            return false;
    }

    return true;
}

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
    map<string, string> fields;
    bool in_passport = false;
    while (getline(infile, s)) {
        if (s == "") {
            if (passport_valid(fields))
                num_valid++;
            fields.clear();
            in_passport = false;
            continue;
        }
        in_passport = true;

        stringstream ss(s);
        string temp_str;

        while (getline(ss, temp_str, ' ')) {
            size_t pos = temp_str.find(':');
            string field = temp_str.substr(0, pos);
            string value = temp_str.substr(pos+1);
            fields[field] = value;
        }
    }

    if (in_passport) {
        if (passport_valid(fields))
            num_valid++;
    }

    cout << num_valid << endl;

    return 0;
}
