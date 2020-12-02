#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

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

    // when array is sorted, can use lower_bound, which is O(log n), instead of find, which is O(n)
    sort(numbers.begin(), numbers.end());

    for (auto i = numbers.begin(); i != numbers.end()-1; i++) {
        int sought = 2020 - *i;
        auto it = lower_bound(i+1, numbers.end(), sought);
        if (it != numbers.end() && *it == sought) {
            cout << *i * sought << endl;
            break; // comment if there could be more than one pair
        }
    }

    return 0;
}
