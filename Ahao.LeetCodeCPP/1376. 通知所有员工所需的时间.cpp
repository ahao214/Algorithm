#include<vector>

using namespace std;


/*
1376. ֪ͨ����Ա�������ʱ��
��˾���� n ��Ա����ÿ��Ա���� ID ���Ƕ�һ�޶��ģ���Ŵ� 0 �� n - 1����˾���ܸ�����ͨ�� headID ���б�ʶ��

�� manager �����У�ÿ��Ա������һ��ֱ�������ˣ����� manager[i] �ǵ� i ��Ա����ֱ�������ˡ������ܸ����ˣ�manager[headID] = -1����Ŀ��֤������ϵ���������ṹ��ʾ��

��˾�ܸ�������Ҫ��˾����Ա��ͨ��һ��������Ϣ������������֪ͨ����ֱ�������ǣ�Ȼ������Щ����֪ͨ���ǵ�������ֱ�����е�Ա������֪����������Ϣ��

�� i ��Ա����Ҫ informTime[i] ������֪ͨ��������ֱ��������Ҳ����˵�� informTime[i] ���Ӻ���������ֱ�����������Կ�ʼ������һ��Ϣ����

����֪ͨ����Ա����һ������Ϣ����Ҫ�ķ����� ��
*/
class Solution {
public:
	vector<vector<int>> son;

	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		son = vector<vector<int>>(n);

		for (int i = 0; i < n; i++)
		{
			if (i != headID)
			{
				son[manager[i]].push_back(i);
			}
		}
		return dfs(headID, informTime);
	}

	int dfs(int u, vector<int>& informTime)
	{
		int res = 0;
		for (auto s : son[u])
			res = max(res, dfs(s, informTime));
		return res + informTime[u];
	}
};
