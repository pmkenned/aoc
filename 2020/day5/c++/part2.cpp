#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int
sum_arith_seq(int n)
{
    return (n*(n+1))/2;
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

    int max = 0;
    int min = INT_MAX;
    int sum = 0;
    while (getline(infile, s)) {
        int bitvalue = 512;
        int seat_id = 0;
        for (size_t i = 0; i < 10; i++) {
            if (s[i] == 'B' || s[i] == 'R')
                seat_id += bitvalue;
            bitvalue >>= 1;
        }
        max = (seat_id > max) ? seat_id : max;
        min = (seat_id < min) ? seat_id : min;
        sum += seat_id;
    }
    cout << sum_arith_seq(max) - sum_arith_seq(min-1) - sum << endl;

    return 0;
}
