#include<vector>
#include <unordered_map>
#include <string>

using namespace std;

/*
828. ͳ���Ӵ��е�Ψһ�ַ�

���Ƕ�����һ������ countUniqueChars(s) ��ͳ���ַ��� s �е�Ψһ�ַ���������Ψһ�ַ��ĸ�����

���磺s = "LEETCODE" �������� "L", "T","C","O","D" ����Ψһ�ַ�����Ϊ����ֻ����һ�Σ����� countUniqueChars(s) = 5 ��

���⽫�����һ���ַ��� s ��������Ҫ���� countUniqueChars(t) ���ܺͣ����� t �� s �����ַ���������������֤����ֵΪ 32 λ������

ע�⣬ĳЩ���ַ����������ظ��ģ�����ͳ��ʱҲ����������Щ�ظ������ַ�����Ҳ����˵�������ͳ�� s ���������ַ����е�Ψһ�ַ�����
*/

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> index;
        for (int i = 0; i < s.size(); i++) {
            index[s[i]].emplace_back(i);
        }
        int res = 0;
        for (auto&& [_, arr] : index) {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(s.size());
            for (int i = 1; i < arr.size() - 1; i++) {
                res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return res;
    }
};
