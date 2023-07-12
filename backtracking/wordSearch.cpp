#include <bits/stdc++.h>
using namespace std;
// problem description here
//  Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

bool dfs(vector<vector<char>> &v, string word, int ind, int x, int y)
{
    int m = v.size(), n = v[0].size();
    if (v.size() == 0)
        return false;
    if (x < 0 || y < 0 || x == m || y == n || word[ind] != v[x][y])
        return false;
    if (ind == word.length() - 1)
        return true;
    char c = v[x][y];
    v[x][y] = '#';
    // can update this with dirs matrix
    bool found = dfs(v, word, ind + 1, x + 1, y) ||
                 dfs(v, word, ind + 1, x, y + 1) ||
                 dfs(v, word, ind + 1, x - 1, y) ||
                 dfs(v, word, ind + 1, x, y - 1);
    v[x][y] = c;
    return found;
}
bool exist(vector<vector<char>> &board, string word)
{
    if (board.size() == 0)
        return false;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (dfs(board, word, 0, i, j))
                return true;
        }
    }
    return false;
}
