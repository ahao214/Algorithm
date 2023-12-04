#include <functional>
#include<vector>

using namespace std;


/*
2477. �����׶��������ͺ�

����һ�� n ���ڵ������һ��������ͨ���޻�ͼ����ÿ���ڵ��ʾһ�����У���Ŵ� 0 �� n - 1 ����ǡ���� n - 1 ��·��0 ���׶�������һ����ά�������� roads ������ roads[i] = [ai, bi] ����ʾ���� ai �� bi ֮����һ�� ˫��· ��

ÿ����������һ���������Ƕ�Ҫȥ�׶��μ�һ�����顣

ÿ����������һ����������һ������ seats ��ʾÿ����������λ����Ŀ��

������Ĵ������ѡ��������ڳ��еĳ������߳����������еĳ������ڳ���֮��һ�������ͺ���һ�����͡�

���㷵�ص����׶�������Ҫ���������͡�
*/

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> g(n + 1);
        for (auto& e : roads) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        long long res = 0;
        function<int(int, int)> dfs = [&](int cur, int fa) -> int {
            int peopleSum = 1;
            for (auto ne : g[cur]) {
                if (ne != fa) {
                    int peopleCnt = dfs(ne, cur);
                    peopleSum += peopleCnt;
                    res += (peopleCnt + seats - 1) / seats;
                }
            }
            return peopleSum;
            };
        dfs(0, -1);
        return res;
    }
};