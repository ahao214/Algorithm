#include <numeric>
#include<vector>
#include <stack>

using namespace std;


/*
2735. �ռ��ɿ���

����һ������Ϊ n ���±�� 0 ��ʼ���������� nums ����ʾ�ռ���ͬ�ɿ����ĳɱ���ÿ���ɿ�������Ӧһ����ͬ�����ͣ������λ���±� i ���ɿ����Ͷ�Ӧ�� i �����͡�

��һ�������У�������óɱ� x ִ��������Ϊ��

ͬʱ�޸������ɿ��������ͣ����ɿ��������� ith �޸�Ϊ���� ((i + 1) mod n)th��
���������ִ������β������뷵���ռ����������ɿ����������С�ɱ���
*/





class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> f(nums);
        long long ans = accumulate(f.begin(), f.end(), 0LL);
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                f[i] = min(f[i], nums[(i + k) % n]);
            }
            ans = min(ans, static_cast<long long>(k) * x + accumulate(f.begin(), f.end(), 0LL));
        }
        return ans;
    }
};





class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        // �ҳ� nums ����С��Ԫ�أ�������Ϊ��Ԫ�ع���һ���µ�����
        int min_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            tmp.push_back(nums[(min_idx + i) % n]);
        }
        nums = move(tmp);

        vector<int> L(n), R(n);
        L[0] = n - 1;
        // ѭ���������Ҳ� nums[0] �Ǹ�С��Ԫ�أ�����һ���ǵ�һ����С��Ԫ�أ���Ҫ�õ���ջ����õ�
        for (int i = 0; i < n; ++i) {
            R[i] = n - i - 1;
        }
        stack<int> s;
        s.push(0);
        for (int i = 1; i < n; ++i) {
            while (!s.empty() && nums[i] < nums[s.top()]) {
                R[s.top()] = i - s.top() - 1;
                s.pop();
            }
            L[i] = i - s.top() - 1;
            s.push(i);
        }

        vector<long long> F(n);
        // ����������һ�β�֣��� F[l..r] ������ d
        auto diff_once = [&](int l, int r, long long d) {
            if (l > r) {
                return;
            }
            if (l < n) {
                F[l] += d;
            }
            if (r + 1 < n) {
                F[r + 1] -= d;
            }
            };
        // �������������β�֣��� F[l..r] ���� ki + b��i ���±�
        auto diff_twice = [&](int l, int r, long long k, long long b) {
            if (l > r) {
                return;
            }
            diff_once(l, l, k * l + b);
            diff_once(l + 1, r, k);
            diff_once(r + 1, r + 1, -(k * r + b));
            };

        // ���в�����Ҫ�ĳɱ�
        diff_twice(0, n - 1, x, 0);

        for (int i = 0; i < n; ++i) {
            int minv = min(L[i], R[i]);
            int maxv = max(L[i], R[i]);
            // ��һ��������������� k+1���ܺ� nums[i] * k + nums[i]
            diff_twice(0, minv, nums[i], nums[i]);
            // �ڶ���������������� minv+1���ܺ� 0 * k + nums[i] * (minv + 1)
            diff_twice(minv + 1, maxv, 0, static_cast<long long>(nums[i]) * (minv + 1));
            // ������������������� L[i]+R[i]-k+1���ܺ� -nums[i] * k + nums[i] * (L[i] + R[i] + 1)
            diff_twice(maxv + 1, L[i] + R[i], -nums[i], static_cast<long long>(nums[i]) * (L[i] + R[i] + 1));
        }

        // ��������ǰ׺��
        for (int i = 0; i < 2; ++i) {
            vector<long long> G(n);
            partial_sum(F.begin(), F.end(), G.begin());
            F = move(G);
        }

        return *min_element(F.begin(), F.end());
    }
};
