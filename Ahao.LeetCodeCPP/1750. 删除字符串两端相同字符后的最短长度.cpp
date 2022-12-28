#include<string>

using namespace std;



/*
1750. ɾ���ַ���������ͬ�ַ������̳���
����һ��ֻ�����ַ� 'a'��'b' �� 'c' ���ַ��� s �������ִ���������������5 �����裩����Σ�

ѡ���ַ��� s һ�� �ǿյ�ǰ׺�����ǰ׺�������ַ�����ͬ��
ѡ���ַ��� s һ�� �ǿյĺ�׺�������׺�������ַ�����ͬ��
ǰ׺�ͺ�׺���ַ���������λ�ö������н�����
ǰ׺�ͺ�׺�����������ַ���Ҫ��ͬ��
ͬʱɾ��ǰ׺�ͺ�׺��
���㷵�ض��ַ��� s ִ���������������Ժ󣨿��� 0 �Σ����ܵõ��� ��̳��� ��
*/
class Solution {
public:
	int minimumLength(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			if (s[i] != s[j])
				break;
			char c = s[i];
			while (i <= j && s[i] == c) i++;
			while (i <= j && s[j] == c) j--;
		}
		return j - i + 1;
	}
};


class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right && s[left] == s[right]) {
            char c = s[left];
            while (left <= right && s[left] == c) {
                left++;
            }
            while (left <= right && s[right] == c) {
                right--;
            }
        }
        return right - left + 1;
    }
};
