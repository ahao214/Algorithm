#include<vector>
#include <string>

using namespace std;


/*
392. �ж�������
�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�

�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ����������磬"ace"��"abcde"��һ�������У���"aec"���ǣ���
*/
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int k = 0;
		for (int i = 0; i < t.size() && k < s.size(); i++) {
			if (t[i] == s[k])
				k++;
		}
		return k == s.size();
	}
};