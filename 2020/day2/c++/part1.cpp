#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    ifstream input_file;

    input_file.open("../input.txt", ios::in);
    if (!input_file) {
        cerr << "cannot open file" << endl;
        exit(1);
    }
    int good = 0;
    while (getline(input_file, s)) {

        size_t dp = s.find("-");
        size_t sp = s.find(" ");
        size_t cp = s.find(": ");

        int min = stoi(s.substr(0, dp));
        int max = stoi(s.substr(dp+1, sp - (dp+1)));
        char c = s.substr(sp+1, cp - (sp+1))[0];
        string pw = s.substr(cp+2);

        int n = (int) std::count(pw.begin(), pw.end(), c);
        if (n >= min && n <= max)
            good++;
    }
    input_file.close();

    cout << good << endl;

    return 0;
}
