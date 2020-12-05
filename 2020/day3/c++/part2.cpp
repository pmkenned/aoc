#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<char>>
get_trees()
{
    string s;
    vector<vector<char>> trees;
    ifstream input_file;

    input_file.open("../input.txt", ios::in);
    if (!input_file) {
        cerr << "cannot open file" << endl;
        exit(1);
    }
    size_t j=0;
    while (getline(input_file, s)) {
        vector<char> v;
        for (size_t i=0; i < s.length(); i++)
            v.push_back(s.at(i));
        trees.push_back(v);
        j++;
    }
    input_file.close();

    return trees;
}

int
count_trees(const vector<vector<char>> & trees, int right, int down)
{
    size_t nrows = trees.size();
    size_t ncols = trees[0].size();
    int num_trees = 0;
    size_t row = 0, col = 0;
    while (row < nrows) {
        if (trees[row % nrows][col % ncols] == '#')
            num_trees++;
        row += down;
        col += right;
    }
    return num_trees;
}

int main()
{
    vector<vector<char>> trees = get_trees();
    int slopes[][2] = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
    long answer = 1;
    for (size_t i=0; i<sizeof(slopes)/sizeof(slopes[0]); i++)
        answer *= count_trees(trees, slopes[i][0], slopes[i][1]);
    cout << answer <<endl;
    return 0;
}
