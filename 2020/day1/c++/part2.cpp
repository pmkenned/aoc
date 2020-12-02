#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int>::iterator NumIt;

int prod_sum(NumIt first, NumIt last, int sum, int n)
{
    int p = -1;
    for (auto i = first; i != last-1; i++) {
        int sought = sum - *i;
        if (n == 2) {
            auto it = lower_bound(i+1, last, sought);
            if (it != last && *it == sought) {
                p = *i * sought;
                break;
            }
        } else {
            int prod = prod_sum(i+1, last, sought, n-1);
            if (prod < 0)
                continue;
            p = *i * prod;
            break;
        }
    }
    return p;
}

int main()
{
    string s;
    vector<int> numbers;
    ifstream input_file;

    input_file.open("../input.txt", ios::in);
    if (!input_file) {
        cerr << "cannot open file" << endl;
        exit(1);
    }
    while (getline(input_file, s))
        numbers.push_back(stoi(s));
    input_file.close();

    if (numbers.empty())
        return 0;

    sort(numbers.begin(), numbers.end());

    cout << prod_sum(numbers.begin(), numbers.end(), 2020, 3) << endl;

    return 0;
}
