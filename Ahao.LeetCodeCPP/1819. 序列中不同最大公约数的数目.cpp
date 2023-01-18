#include<vector>
#include <algorithm>

using namespace std;

/*
1819. �����в�ͬ���Լ������Ŀ

����һ������������ɵ����� nums ��

�������е� ���Լ�� ����Ϊ���������������Ĺ���Լ���е����������

���磬���� [4,6,16] �����Լ���� 2 ��
�����һ�� ������ ������һ�����У�����ͨ��ɾ�������е�ĳЩԪ�أ����߲�ɾ�����õ���

���磬[2,5,10] �� [1,2,1,2,4,1,5,10] ��һ�������С�
���㲢���� nums ������ �ǿ� �������� ��ͬ ���Լ���� ��Ŀ ��
*/

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> occured(maxVal + 1, false);
        for (int num : nums) {
            occured[num] = true;
        }
        int ans = 0;
        for (int i = 1; i <= maxVal; i++) {
            int subGcd = 0;
            for (int j = i; j <= maxVal; j += i) {
                if (occured[j]) {
                    if (subGcd == 0) {
                        subGcd = j;
                    }
                    else {
                        subGcd = __gcd(subGcd, j);
                    }
                    if (subGcd == i) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};




class Solution {
    int g[200001];
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        for (auto num : nums)
        {
            for (int i = 1; i <= sqrt(num); i++)
            {
                if (num % i == 0)
                {
                    if (g[i] == 0)
                        g[i] = num;
                    else
                        g[i] = gcd(g[i], num);
                    if (num / i != i)
                    {
                        if (g[num / i] == 0)
                            g[num / i] = num;
                        else
                            g[num / i] = gcd(g[num / i], num);
                    }
                }
            }
        }

        int count = 0;
        for (int f = 1; f <= 200000; f++)
            if (f == g[f])
                count++;
        return count;
    }
};