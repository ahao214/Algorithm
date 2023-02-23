#include<vector>

using namespace std;


/*
1238. ѭ��������

������������ n �� start����������Ƿ������� (0,1,2,,...,2^n-1) ������ p���������㣺

p[0] = start
p[i] �� p[i+1] �Ķ����Ʊ�ʾ��ʽֻ��һλ��ͬ
p[0] �� p[2^n -1] �Ķ����Ʊ�ʾ��ʽҲֻ��һλ��ͬ
*/

//���ɷ�
class Solution {
public:
	vector<int> circularPermutation(int n, int start) {
		vector<int> ret;
		ret.reserve(1 << n);
		ret.push_back(start);
		for (int i = 1; i <= n; i++) {
			int m = ret.size();
			for (int j = m - 1; j >= 0; j--) {
				ret.push_back(((ret[j] ^ start) | (1 << (i - 1))) ^ start);
			}
		}
		return ret;
	}
};


//��ʽ��
class Solution {
public:
	vector<int> circularPermutation(int n, int start) {
		vector<int> ret(1 << n);
		for (int i = 0; i < ret.size(); i++) {
			ret[i] = (i >> 1) ^ i ^ start;
		}
		return ret;
	}
};
