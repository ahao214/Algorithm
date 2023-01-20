#include<vector>
#include <unordered_map>
#include<unordered_set>
#include<algorithm>
#include <chrono>

using namespace std;

/*
1817. �����û���Ծ������

�����û��� LeetCode �Ĳ�����־����һ������ k ����־��һ����ά�������� logs ��ʾ������ÿ�� logs[i] = [IDi, timei] ��ʾ ID Ϊ IDi ���û��� timei ����ʱִ����ĳ��������

����û� ����ͬʱִ�в����������û�������ͬһ������ִ�� ������� ��

ָ���û��� �û���Ծ��������user active minutes��UAM�� ����Ϊ�û��� LeetCode ִ�в����� Ψһ������ �� ��ʹһ������ִ�ж��������Ҳֻ�ܰ�һ���Ӽ�����

����ͳ���û���Ծ�������ķֲ������ͳ�ƽ����һ������Ϊ k �� �±�� 1 ��ʼ���� ������ answer ������ÿ�� j��1 <= j <= k����answer[j] ��ʾ �û���Ծ������ ���� j ���û�����

�������������Ĵ����� answer ��
*/


class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> activeMinutes;
        for (auto&& log : logs) {
            int id = log[0], time = log[1];
            activeMinutes[id].emplace(time);
        }
        vector<int> answer(k);
        for (auto&& [_, minutes] : activeMinutes) {
            int activeCount = minutes.size();
            answer[activeCount - 1]++;
        }
        return answer;
    }
};

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        const int n = logs.size();
        vector<int> ans(k, 0);
        unordered_map<int, unordered_set<int>> mp;

        for (auto log : logs) {
            int uID = log[0], time = log[1];
            mp[uID].emplace(time);
        }

        for (auto it : mp)  ans[it.second.size() - 1]++;
        return ans;
    }
};