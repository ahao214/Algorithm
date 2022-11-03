#include<vector>

using namespace std;


/*
1720. �������������
δ֪ �������� arr �� n ���Ǹ�������ɡ�

��������Ϊ����Ϊ n - 1 ����һ���������� encoded ������ encoded[i] = arr[i] XOR arr[i + 1] �����磬arr = [1,0,2,1] �������õ� encoded = [1,2,3] ��

������������� encoded ��ԭ���� arr �ĵ�һ��Ԫ�� first��arr[0]����

����뷵��ԭ���� arr ������֤���𰸴��ڲ�����Ψһ�ġ�
*/
class Solution {
public:
	vector<int> decode(vector<int>& encoded, int first) {
		vector<int> res(encoded.size() + 1, first);
		for (int i = 1; i <= encoded.size(); i++)
			res[i] = res[i - 1] ^ encoded[i - 1];
		return res;
	}
};