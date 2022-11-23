#include<vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;


/*
1487. ��֤�ļ���Ψһ
����һ������Ϊ n ���ַ������� names ���㽫�����ļ�ϵͳ�д��� n ���ļ��У��ڵ� i ���ӣ��½���Ϊ names[i] ���ļ��С�

���������ļ� ���� ������ͬ���ļ������������½��ļ���ʹ�õ��ļ����Ѿ���ռ�ã�ϵͳ���� (k) ����ʽΪ���ļ��е��ļ�����Ӻ�׺������ k ���ܱ�֤�ļ���Ψһ�� ��С������ ��

���س���Ϊ n ���ַ������飬���� ans[i] �Ǵ����� i ���ļ���ʱϵͳ��������ļ��е�ʵ�����ơ�
*/
class Solution {
public:
	//��ʱ��
	vector<string> getFolderNames(vector<string>& names) {
		unordered_set<string> hash;

		vector<string> res;
		for (auto name : names)
		{
			string suc;
			int k = 0;
			while (hash.count(name + suc))
			{
				k++;
				suc = "(" + to_string(k) + ")";
			}
			hash.insert(name + suc);
			res.push_back(name + suc);
		}
		return res;
	}


	vector<string> getFolderNames(vector<string>& names) {
		unordered_map<string, int> cnt;
		unordered_set<string> hash;

		vector<string> res;
		for (auto name : names)
		{
			string suc;
			int k = 0;
			if (cnt.count(name)) k = cnt[name];

			while (hash.count(name + suc))
			{
				k++;
				suc = "(" + to_string(k) + ")";
			}

			cnt[name] = k;
			hash.insert(name + suc);
			res.push_back(name + suc);
		}
		return res;
	}
};
