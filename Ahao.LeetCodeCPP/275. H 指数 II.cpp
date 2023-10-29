#include<vector>

using namespace std;



/*
275. H ָ�� II

����һ���������� citations ������ citations[i] ��ʾ�о��ߵĵ� i
ƪ���ı����õĴ�����citations �Ѿ������������� ��
���㲢���ظ��о��ߵ� h ָ����

h ָ���Ķ��壺h ���������ô�������high citations����
һ��������Ա�� h ָ����ָ���������� ��n ƪ�����У�
�ܹ��� h ƪ���ķֱ����������� h �Ρ�
������� n - h ƪ����ÿƪ�����ô��� ������ h �Ρ�

��ʾ����� h �ж��ֿ��ܵ�ֵ��h ָ�� �����������Ǹ���

������Ʋ�ʵ�ֶ���ʱ�临�Ӷȵ��㷨��������⡣
*/
class Solution {
public:
	int hIndex(vector<int>& citations) {
		int left = 0, right = citations.size();
		while (left < right)
		{
			int mid = (left + right + 1ll) >> 1;
			if (citations[citations.size() - mid] >= mid) left = mid;
			else right = mid - 1;
		}
		return right;
	}
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return n - left;
    }
};
