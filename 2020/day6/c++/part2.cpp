#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

enum { NUM_QS = 26 };

int main()
{
    string s;
    ifstream infile;

    infile.open("../input.txt", ios::in);
    if (!infile) {
        cerr << "cannot open file" << endl;
        exit(1);
    }

    bool qs[NUM_QS];

    for (size_t i=0; i<NUM_QS; i++)
        qs[i] = true;

    int count = 0;
    while (getline(infile, s)) {
        if (s == "") {
            for (size_t i=0; i<NUM_QS; i++)
                if (qs[i])
                    count++;
            for (size_t i=0; i<NUM_QS; i++)
                qs[i] = true;
            continue;
        }
        for (char c='a'; c <= 'z'; c++) {
            if (s.find(c) == string::npos)
                qs[c - 'a'] = false;
        }
	}
    cout << count << endl;

    return 0;
}
