#include<vector>
#include<string>
#include <stack>

using namespace std;


/*
2866. ������ II

����һ������Ϊ n �±�� 0 ��ʼ���������� maxHeights ��

������������������Ͻ� n �������� i �������±�Ϊ i ���߶�Ϊ heights[i] ��

��������������㣬���ǳ���Щ���� ���� �ģ�

1 <= heights[i] <= maxHeights[i]
heights ��һ�� ɽ�� ���顣
��������±� i ����������������ô���ǳ����� heights ��һ�� ɽ�� ���飺

�������� 0 < j <= i ������ heights[j - 1] <= heights[j]
�������� i <= k < n - 1 ������ heights[k + 1] <= heights[k]
���㷵������ ������ Ҫ��ķ����У��߶Ⱥ͵����ֵ ��
*/

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long res = 0;
        vector<long long> prefix(n), suffix(n);
        stack<int> stack1, stack2;

        for (int i = 0; i < n; i++) {
            while (!stack1.empty() && maxHeights[i] < maxHeights[stack1.top()]) {
                stack1.pop();
            }
            if (stack1.empty()) {
                prefix[i] = (long long)(i + 1) * maxHeights[i];
            }
            else {
                prefix[i] = prefix[stack1.top()] + (long long)(i - stack1.top()) * maxHeights[i];
            }
            stack1.emplace(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!stack2.empty() && maxHeights[i] < maxHeights[stack2.top()]) {
                stack2.pop();
            }
            if (stack2.empty()) {
                suffix[i] = (long long)(n - i) * maxHeights[i];
            }
            else {
                suffix[i] = suffix[stack2.top()] + (long long)(stack2.top() - i) * maxHeights[i];
            }
            stack2.emplace(i);
            res = max(res, prefix[i] + suffix[i] - maxHeights[i]);
        }
        return res;
    }
};
