#include<vector>
#include<string>

using namespace std;



/*
offer 12 ¾ØÕóÖĞµÄÂ·¾¶
*/
class Solution {
public:
    bool hasPath(vector<vector<char> >& matrix, string word) {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (dfs(matrix, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& matrix, string word, int i, int j, int index) {
        if (i >= matrix.size() || i < 0 || j >= matrix[0].size() || j < 0 || matrix[i][j] != word[index])
        {
            return false;
        }
        if (index == word.size() - 1)
        {
            return true;
        }
        char tmp = matrix[i][j];
        matrix[i][j] = '*';
        index++;
        bool res = dfs(matrix, word, i + 1, j, index) ||
            dfs(matrix, word, i - 1, j, index) ||
            dfs(matrix, word, i, j + 1, index) ||
            dfs(matrix, word, i, j - 1, index);
        matrix[i][j] = tmp;
        return res;
    }
};