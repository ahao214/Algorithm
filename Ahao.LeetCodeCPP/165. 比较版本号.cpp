#include<vector>
#include <string>

using namespace std;


/*
165. �Ƚϰ汾��

���������汾�� version1 �� version2 ������Ƚ����ǡ�

�汾����һ�������޶�����ɣ����޶�����һ�� '.' ���ӡ�ÿ���޶����� ��λ���� ��ɣ����ܰ��� ǰ���� ��ÿ���汾�����ٰ���һ���ַ����޶��Ŵ����ұ�ţ��±�� 0 ��ʼ������ߵ��޶����±�Ϊ 0 ����һ���޶����±�Ϊ 1 ���Դ����ơ����磬2.5.33 �� 0.1 ������Ч�İ汾�š�

�Ƚϰ汾��ʱ���밴�����ҵ�˳�����αȽ����ǵ��޶��š��Ƚ��޶���ʱ��ֻ��Ƚ� �����κ�ǰ����������ֵ ��Ҳ����˵���޶��� 1 ���޶��� 001 ��� ������汾��û��ָ��ĳ���±괦���޶��ţ�����޶�����Ϊ 0 �����磬�汾 1.0 С�ڰ汾 1.1 ����Ϊ�����±�Ϊ 0 ���޶�����ͬ�����±�Ϊ 1 ���޶��ŷֱ�Ϊ 0 �� 1 ��0 < 1 ��

���ع������£�

��� version1 > version2 ���� 1��
��� version1 < version2 ���� -1��
����֮�ⷵ�� 0��
*/
class Solution {
public:
	vector<int> get_num(string version)
	{
		vector<int> res;
		for (int i = 0; i < version.size(); i++)
		{
			int j = i, s = 0;
			while (j < version.size() && version[j] != '.')
			{
				s = s * 10 + version[j] - '0';
				j++;
			}
			i = j;
			res.push_back(s);
		}
		while (res.size() && res.back() == 0) res.pop_back();
		return res;
	}

	int compareVersion(string version1, string version2) {
		auto n1 = get_num(version1);
		auto n2 = get_num(version2);
		if (n1 < n2) return -1;
		if (n1 == n2) return 0;
		return 1;
	}
};




class Solution {
public:
	int compareVersion(string version1, string version2) {
		for (int i = 0, j = 0; i < version1.size() || j < version2.size();)
		{
			int a = i, b = j;
			while (a < version1.size() && version1[a] != '.') a++;
			while (b < version2.size() && version2[b] != '.') b++;
			int x = a == i ? 0 : stoi(version1.substr(i, a - i));
			int y = b == j ? 0 : stoi(version2.substr(j, b - j));
			if (x > y) return 1;
			if (x < y) return -1;
			i = a + 1, j = b + 1;
		}
		return 0;
	}
};
