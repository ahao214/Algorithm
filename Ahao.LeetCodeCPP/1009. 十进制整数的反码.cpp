using namespace std;

class Solution {
public:
	/*
	1009. ʮ���������ķ���
	*/
	int bitwiseComplement(int n) {
		if (n == 0)
			return 1;
		int tmp = n, bit = 1;
		while (tmp != 0)
		{
			n = n ^ bit;
			bit = bit << 1;
			tmp = tmp >> 1;
		}
		return n;
	}
};