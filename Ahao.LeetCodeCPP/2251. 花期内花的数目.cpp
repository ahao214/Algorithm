#include<vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

/*
2251. �����ڻ�����Ŀ

����һ���±�� 0 ��ʼ�Ķ�ά�������� flowers ������ flowers[i] = [starti, endi] ��ʾ�� i �仨�� ���� �� starti �� endi ���� ��������ͬʱ����һ���±�� 0 ��ʼ��СΪ n ���������� people ��people[i] �ǵ� i ������������ʱ�䡣

���㷵��һ����СΪ n ���������� answer ������ answer[i]�ǵ� i ���˵���ʱ�ڻ����ڻ��� ��Ŀ ��
*/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n = flowers.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int m = persons.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int x = upper_bound(starts.begin(), starts.end(), persons[i]) - starts.begin();
            int y = lower_bound(ends.begin(), ends.end(), persons[i]) - ends.begin();
            ans[i] = x - y;
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> cnt;
        for (auto& flower : flowers) {
            cnt[flower[0]]++;
            cnt[flower[1] + 1]--;
        }
        int m = persons.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return persons[a] < persons[b];
            });

        vector<int> ans(m);
        int curr = 0;
        auto it = cnt.begin();
        for (int x : indices) {
            while (it != cnt.end() && it->first <= persons[x]) {
                curr += it->second;
                it++;
            }
            ans[x] = curr;
        }
        return ans;
    }
};

