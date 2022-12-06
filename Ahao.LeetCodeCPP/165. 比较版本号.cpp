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