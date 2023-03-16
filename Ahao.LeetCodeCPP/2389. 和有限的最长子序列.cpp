#include<vector>
#include <algorithm>

using namespace std;


/*
2389. �����޵��������
����һ������Ϊ n ���������� nums ����һ������Ϊ m ���������� queries ��

����һ������Ϊ m ������ answer ������ answer[i] �� nums �� Ԫ��֮��С�ڵ��� queries[i] �� ������ �� ��� ����  ��

������ ����һ������ɾ��ĳЩԪ�أ�Ҳ���Բ�ɾ���������ı�ʣ��Ԫ��˳��õ���һ�����顣
*/
class Solution {
public:
	vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i) {
			nums[i] += nums[i - 1];
		}
		vector<int> res;
		for (auto& q : queries) {
			int index = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
			res.push_back(index);
		}
		return res;
	}
};


class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> f(n + 1);
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i] + nums[i];
        }
        vector<int> answer(m);
        for (int i = 0; i < m; i++) {
            answer[i] = upper_bound(f.begin(), f.end(), queries[i]) - f.begin() - 1;
        }
        return answer;
    }
};
