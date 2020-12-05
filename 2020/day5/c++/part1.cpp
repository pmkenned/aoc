#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string s;
    ifstream infile;

    infile.open("../input.txt", ios::in);
    if (!infile) {
        cerr << "cannot open file" << endl;
        exit(1);
    }

    int max = 0;
    while (getline(infile, s)) {
        int bitvalue = 512;
        int seat_id = 0;
        for (size_t i = 0; i < 10; i++) {
            if (s[i] == 'B' || s[i] == 'R')
                seat_id += bitvalue;
            bitvalue >>= 1;
        }
        max = (seat_id > max) ? seat_id : max;
    }
    cout << max << endl;

    return 0;
}
