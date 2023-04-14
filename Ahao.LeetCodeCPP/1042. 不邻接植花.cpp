#include<vector>

using namespace std;

/*
1042. ���ڽ�ֲ��

�� n ����԰������ 1 �� n ��ǡ��������� paths ������ paths[i] = [xi, yi] �����˻�԰ xi ����԰ yi ��˫��·������ÿ����԰�У�������������ֻ�֮һ��

���⣬���л�԰ ��� �� 3 ��·�����Խ�����뿪.

����ҪΪÿ����԰ѡ��һ�ֻ���ʹ��ͨ��·���������κ�������԰�еĻ������໥����ͬ��

��������ʽ���� ��һ ���еķ�����Ϊ�� answer������ answer[i] Ϊ�ڵ� (i+1) ����԰����ֲ�Ļ������ࡣ����������  1��2��3��4 ��ʾ����֤���ڴ𰸡�
*/

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for (auto& path : paths) {
            adj[path[0] - 1].emplace_back(path[1] - 1);
            adj[path[1] - 1].emplace_back(path[0] - 1);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            vector<bool> colored(5, false);
            for (auto& vertex : adj[i]) {
                colored[ans[vertex]] = true;
            }
            for (int j = 1; j <= 4; j++) {
                if (colored[j] == 0) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};
