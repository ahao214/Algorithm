
#include<vector>
#include<string>

using namespace std;

/*
2697. �ֵ�����С���Ĵ�

����һ���� СдӢ����ĸ ��ɵ��ַ��� s ������Զ���ִ��һЩ��������һ�������У������������СдӢ����ĸ �滻  s �е�һ���ַ���

����ִ�� �������ٵĲ��� ��ʹ s ���һ�� ���Ĵ� �����ִ�� ���� ���������ķ�����ֹһ�֣���ֻ��ѡȡ �ֵ�����С �ķ�����

��������������ͬ���ַ��� a �� b ���� a �� b ���ֲ�ͬ�ĵ�һ��λ�ã������λ���� a �ж�Ӧ��ĸ�� b �ж�Ӧ��ĸ����ĸ���г���˳����磬����Ϊ a ���ֵ���� b ���ֵ���ҪС��

�������յĻ����ַ�����
*/






class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                s[left] = s[right] = min(s[left], s[right]);
            }
            ++left;
            --right;
        }
        return s;
    }
};