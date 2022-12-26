#include<vector>

using namespace std;



/*
733. ͼ����Ⱦ
��һ���Զ�ά���������ʾ��ͼ����ÿһ��������ʾ��ͼ��������ֵ��С����ֵ�� 0
�� 65535 ֮�䡣

����һ������ (sr, sc) ��ʾͼ����Ⱦ��ʼ������ֵ���� ���У�
��һ���µ���ɫֵ newColor������������ɫ���ͼ��

Ϊ�������ɫ�������ӳ�ʼ���꿪ʼ����¼��ʼ��������������ĸ�����
������ֵ���ʼ������ͬ���������ص㣬�����ټ�¼���ĸ������Ϸ�������������
�������Ƕ�Ӧ�ĸ�����������ֵ���ʼ������ͬ���������ص㣬�������ظ��ù��̡�
�������м�¼�����ص����ɫֵ��Ϊ�µ���ɫֵ��
��󷵻ؾ�����ɫ��Ⱦ���ͼ��
*/
class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image.empty() || image[0].empty()) return image;
		//�ĸ�����
		int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
		int oldColor = image[sr][sc];
		if (oldColor == newColor) return image;
		image[sr][sc] = newColor;
		for (int i = 0; i < 4; i++) {
			int x = sr + dx[i], y = sc + dy[i];
			if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == oldColor) {
				floodFill(image, x, y, newColor);
			}
		}
		return image;
	}
};