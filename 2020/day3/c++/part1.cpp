#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int num_trees = 0;
    size_t i, j;
    size_t nrows = 1, ncols = 1;
    string s;
    ifstream input_file;
    vector<vector<char>> trees;

    input_file.open("../input.txt", ios::in);
    if (!input_file) {
        cerr << "cannot open file" << endl;
        exit(1);
    }
    j=0;
    while (getline(input_file, s)) {
        vector<char> v;
        ncols = s.length();
        for (i=0; i < ncols; i++)
            v.push_back(s.at(i));
        trees.push_back(v);
        j++;
    }
    nrows = j;
    input_file.close();

    int right = 3;
    int down = 1;
    size_t row = 0, col = 0;

    while (row < nrows) {
        if (trees[row % nrows][col % ncols] == '#')
            num_trees++;
        row += down;
        col += right;
    }

    cout << num_trees <<endl;

    return 0;
}
