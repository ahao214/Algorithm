#include<vector>
#include <unordered_map>

using namespace std;


/*
1125. ��С�ı�Ҫ�Ŷ�

��Ϊ��Ŀ������滮��һ������ļ����嵥 req_skills��������ӱ�ѡ��Ա���� people ��ѡ��Щ�����һ������Ҫ�Ŷӡ��� ���Ϊ i �ı�ѡ��Ա people[i] ����һ�ݸñ�ѡ��Ա���յļ����б���

��ν����Ҫ�Ŷӡ�������������Ŷ��У�����������ļ����б� req_skills ���г���ÿ��ܣ��Ŷ���������һ����Ա�Ѿ����ա�������ÿ���˵ı������ʾ�Ŷ��еĳ�Ա��

���磬�Ŷ� team = [0, 1, 3] ��ʾ���ռ��ֱܷ�Ϊ people[0]��people[1]���� people[3] �ı�ѡ��Ա��
���㷵�� ��һ ��ģ��С�ı�Ҫ�Ŷӣ��Ŷӳ�Ա����Ա��ű�ʾ������԰� ����˳�� ���ش𰸣���Ŀ���ݱ�֤�𰸴��ڡ�
*/

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();
        unordered_map<string, int> skill_index;
        for (int i = 0; i < n; ++i) {
            skill_index[req_skills[i]] = i;
        }
        vector<vector<int>> dp(1 << n);
        for (int i = 0; i < m; ++i) {
            int cur_skill = 0;
            for (string& s : people[i]) {
                cur_skill |= 1 << skill_index[s];
            }
            for (int prev = 0; prev < dp.size(); ++prev) {
                if (prev > 0 && dp[prev].empty()) {
                    continue;
                }
                int comb = prev | cur_skill;
                if (comb == prev) {
                    continue;
                }
                if (dp[comb].empty() || dp[prev].size() + 1 < dp[comb].size()) {
                    dp[comb] = dp[prev];
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};



class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();
        unordered_map<string, int> skill_index;
        for (int i = 0; i < n; ++i) {
            skill_index[req_skills[i]] = i;
        }
        vector<int> dp(1 << n, m);
        dp[0] = 0;
        vector<int> prev_skill(1 << n, 0);
        vector<int> prev_people(1 << n, 0);
        for (int i = 0; i < m; ++i) {
            int cur_skill = 0;
            for (string& skill : people[i]) {
                cur_skill |= 1 << skill_index[skill];
            }
            for (int prev = 0; prev < (1 << n); prev++) {
                int comb = prev | cur_skill;
                if (dp[comb] > dp[prev] + 1) {
                    dp[comb] = dp[prev] + 1;
                    prev_skill[comb] = prev;
                    prev_people[comb] = i;
                }
            }
        }
        vector<int> res;
        int i = (1 << n) - 1;
        while (i > 0) {
            res.push_back(prev_people[i]);
            i = prev_skill[i];
        }
        return res;
    }
};

