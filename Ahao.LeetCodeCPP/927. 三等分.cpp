#include<vector>
#include <numeric>

using namespace std;

/*
927. ���ȷ�


����һ���� 0 �� 1 ��ɵ����� arr ��������ֳ�  3 ���ǿյĲ��� ��ʹ��������Щ���ֱ�ʾ��ͬ�Ķ�����ֵ��

��������������뷵���κ� [i, j]������ i+1 < j������һ����

arr[0], arr[1], ..., arr[i] Ϊ��һ���֣�
arr[i + 1], arr[i + 2], ..., arr[j - 1] Ϊ�ڶ����֣�
arr[j], arr[j + 1], ..., arr[arr.length - 1] Ϊ�������֡�
��������������ʾ�Ķ�����ֵ��ȡ�
����޷��������ͷ��� [-1, -1]��

ע�⣬�ڿ���ÿ����������ʾ�Ķ�����ʱ��Ӧ�����俴��һ�����塣���磬[1,1,0] ��ʾʮ�����е� 6���������� 3�����⣬ǰ����Ҳ�Ǳ�����ģ����� [0,1,1] �� [1,1] ��ʾ��ͬ��ֵ��
*/

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) {
            return { -1, -1 };
        }
        if (sum == 0) {
            return { 0, 2 };
        }

        int partial = sum / 3;
        int first = 0, second = 0, third = 0, cur = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                if (cur == 0) {
                    first = i;
                }
                else if (cur == partial) {
                    second = i;
                }
                else if (cur == 2 * partial) {
                    third = i;
                }
                cur++;
            }
        }

        int len = (int)arr.size() - third;
        if (first + len <= second && second + len <= third) {
            int i = 0;
            while (third + i < arr.size()) {
                if (arr[first + i] != arr[second + i] || arr[first + i] != arr[third + i]) {
                    return { -1, -1 };
                }
                i++;
            }
            return { first + len - 1, second + len };
        }
        return { -1, -1 };
    }
};
