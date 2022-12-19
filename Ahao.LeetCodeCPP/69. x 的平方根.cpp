using namespace std;

/*
69. x ��ƽ����
����һ���Ǹ����� x �����㲢���� x �� ����ƽ���� ��

���ڷ������������������ֻ���� �������� ��С�����ֽ��� ��ȥ ��

ע�⣺������ʹ���κ�����ָ����������������� pow(x, 0.5) ���� x ** 0.5 ��
*/
class Solution {
public:
	/*
	Times:O(logN)
	Space:O(1)
	����
	*/
	int mySqrt(int x) {
		int left = 0, right = x;
		while (left < right)
		{
			int mid = left + (right - left) / 2 + 1;
			if ((long long)mid * mid <= x)
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}
};


/*
69. x ��ƽ����
����һ���Ǹ����� x �����㲢����x������ƽ���� ��

���ڷ������������������ֻ������������ ��С�����ֽ��� ��ȥ ��

ע�⣺������ʹ���κ�����ָ����������������� pow(x, 0.5) ���� x ** 0.5 ��
*/
class Solution {
public:
	int mySqrt(int x) {
		int left = 0, right = x;
		while (left < right)
		{
			long long mid = left + 1ll + right >> 1;
			if (mid * mid <= x)
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}
};
