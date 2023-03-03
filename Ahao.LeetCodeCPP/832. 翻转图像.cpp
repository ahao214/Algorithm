#include<vector>

using namespace std;



/*
832. ��תͼ��

����һ�� n x n �Ķ����ƾ��� image ���� ˮƽ ��תͼ��Ȼ�� ��ת ͼ�񲢷��� ��� ��

ˮƽ��תͼƬ���ǽ�ͼƬ��ÿһ�ж����з�ת��������

���磬ˮƽ��ת [1,1,0] �Ľ���� [0,1,1]��
��תͼƬ����˼��ͼƬ�е� 0 ȫ���� 1 �滻�� 1 ȫ���� 0 �滻��

���磬��ת [0,1,1] �Ľ���� [1,0,0]��
*/
class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
		int n = image.size(), m = image[0].size();
		for (int i = 0; i < n; i++)
		{
			reverse(image[i].begin(), image[i].end());
			for (int j = 0; j < m; j++)
				image[i][j] ^= 1;
		}
		return image;
	}
};

