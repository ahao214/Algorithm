#include<vector>
using namespace std;


class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> st;
		for (auto aster : asteroids) {
			bool alive = true;
			while (alive && aster < 0 && !st.empty() && st.back() > 0) {
				alive = st.back() < -aster; // aster ÊÇ·ñ´æÔÚ
				if (st.back() <= -aster) {  // Õ»¶¥ÐÐÐÇ±¬Õ¨
					st.pop_back();
				}
			}
			if (alive) {
				st.push_back(aster);
			}
		}
		return st;
	}
};
