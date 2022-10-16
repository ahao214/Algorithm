#include<vector>

using namespace std;

/*
886. ���ܵĶ��ַ�

����һ�� n �ˣ����Ϊ 1, 2, ..., n���� �������ÿ���˷ֽ������С�����顣ÿ���˶����ܲ�ϲ�������ˣ���ô���ǲ�Ӧ������ͬһ�顣

�������� n ������ dislikes ������ dislikes[i] = [ai, bi] ����ʾ���������Ϊ ai ��  bi���˹���ͬһ�顣�����������ַ����������˷ֽ�����ʱ������ true�����򷵻� false��
*/

class Solution {
public:
    bool dfs(int curnode, int nowcolor, vector<int>& color, const vector<vector<int>>& g) {
        color[curnode] = nowcolor;
        for (auto& nextnode : g[curnode]) {
            if (color[nextnode] && color[nextnode] == color[curnode]) {
                return false;
            }
            if (!color[nextnode] && !dfs(nextnode, 3 ^ nowcolor, color, g)) {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, 0);
        vector<vector<int>> g(n + 1);
        for (auto& p : dislikes) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0 && !dfs(i, 1, color, g)) {
                return false;
            }
        }
        return true;
    }
};