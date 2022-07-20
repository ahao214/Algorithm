#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> res(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int index = (i * n + j + k) % (m * n);
				res[index / n][index % n] = grid[i][j];
			}
		}
		return res;
	}
};



class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>>res(m, vector<int>(n));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; ++j) {
				int a = i;
				int b = j + k;
				a = (a + b / n) % m;
				b = b % n;
				res[a][b] = grid[i][j];
			}
		}
		return res;
	}
};