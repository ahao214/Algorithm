#include<vector>

using namespace std;


/*
offer 33 二叉搜索树的后续遍历序列
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
		//根节点
		int root = s[right];
		int i = left;
		//i位置左边的是左子树，右边的是右子树
		for (; i < right; ++i) {
			if (s[i] > root) break;
		}
		for (int j = i; j < right; j++) {
			if (s[j] < root) return false;
		}
		//左子树和右子树
		return helper(s, left, i - 1) && helper(s, i, right - 1);
	}
};