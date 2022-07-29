#include<vector>

using namespace std;


/*
offer 33 �����������ĺ�����������
*/
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) return false;
		return helper(sequence, 0, sequence.size() - 1);
	}

	bool helper(vector<int>& s, int left, int right) {
		if (left >= right) {
			return true;
		}
		//���ڵ�
		int root = s[right];
		int i = left;
		//iλ����ߵ������������ұߵ���������
		for (; i < right; ++i) {
			if (s[i] > root) break;
		}
		for (int j = i; j < right; j++) {
			if (s[j] < root) return false;
		}
		//��������������
		return helper(s, left, i - 1) && helper(s, i, right - 1);
	}
};