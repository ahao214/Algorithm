#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
	bool checkLength(vector<int>& v1, vector<int>& v2) {
		return (v1[0] * v1[0] + v1[1] * v1[1]) == (v2[0] * v2[0] + v2[1] * v2[1]);
	}

	bool checkMidPoint(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		return (p1[0] + p2[0]) == (p3[0] + p4[0]) && (p1[1] + p2[1]) == (p3[1] + p4[1]);
	}

	int calCos(vector<int>& v1, vector<int>& v2) {
		return (v1[0] * v2[0] + v1[1] * v2[1]) == 0;
	}

	bool help(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		vector<int> v1 = { p1[0] - p2[0], p1[1] - p2[1] };
		vector<int> v2 = { p3[0] - p4[0], p3[1] - p4[1] };
		if (checkMidPoint(p1, p2, p3, p4) && checkLength(v1, v2) && calCos(v1, v2)) {
			return true;
		}
		return false;
	}

	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		if (p1 == p2) {
			return false;
		}
		if (help(p1, p2, p3, p4)) {
			return true;
		}
		if (p1 == p3) {
			return false;
		}
		if (help(p1, p3, p2, p4)) {
			return true;
		}
		if (p1 == p4) {
			return false;
		}
		if (help(p1, p4, p2, p3)) {
			return true;
		}
		return false;
	}
};



class Solution {
private:
	int getLen(vector<int>& p1, vector<int>& p2)
	{
		return pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2);
	}

public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		vector<int> lens;
		lens.resize(6, 0);

		lens[0] = getLen(p1, p2);
		lens[1] = getLen(p1, p3);
		lens[2] = getLen(p1, p4);
		lens[3] = getLen(p2, p4);
		lens[4] = getLen(p2, p3);
		lens[5] = getLen(p3, p4);

		for (int i = 0; i < 6; i++)
			if (lens[i] == 0)
				return false;

		sort(lens.begin(), lens.end());

		if (lens[0] == lens[1] && lens[1] == lens[2] && lens[2] == lens[3] && lens[4] == lens[5] && lens[0] * 2 == lens[5])
		{
			return true;
		}
		return false;
	}
};