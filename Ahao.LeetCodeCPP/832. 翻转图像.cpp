#include<vector>

using namespace std;



/*
832. 翻转图像

给定一个 n x n 的二进制矩阵 image ，先 水平 翻转图像，然后 反转 图像并返回 结果 。

水平翻转图片就是将图片的每一行都进行翻转，即逆序。

例如，水平翻转 [1,1,0] 的结果是 [0,1,1]。
反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。

例如，反转 [0,1,1] 的结果是 [1,0,0]。
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

