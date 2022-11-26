#include<vector>
#include <queue>

using namespace std;


/*
1361. ��֤������
���������� n ���ڵ㣬���� 0 �� n - 1 ��ţ�
���нڵ� i �������ӽڵ�ֱ��� leftChild[i] �� rightChild[i]��

ֻ�� ���� �ڵ��ܹ��γ��� ֻ �γ� һ�� ��Ч�Ķ�����ʱ������ true��
���򷵻� false��

����ڵ� i û�����ӽڵ㣬��ô leftChild[i] �͵��� -1��
���ӽڵ�Ҳ���ϸù���

ע�⣺�ڵ�û��ֵ���������н���ʹ�ýڵ��š�
*/
class Solution {
public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		vector<int> d(n);
		for (int i = 0; i < n; i++)
		{
			if (leftChild[i] != -1) d[leftChild[i]]++;
			if (rightChild[i] != -1) d[rightChild[i]]++;
		}

		int root = 0;
		while (root < n && d[root]) root++;
		if (root == n) return false;

		vector<bool> st(n);
		st[root] = true;
		queue<int> q;
		q.push(root);

		while (q.size())
		{
			int t = q.front();
			q.pop();

			int sons[] = { leftChild[t],rightChild[t] };
			for (auto s : sons)
			{
				if (s != -1)
				{
					if (st[s]) return false;
					st[s] = true;
					q.push(s);
				}
			}
		}

		for (auto state : st)
		{
			if (!state)
				return false;
		}
		return true;
	}
};
