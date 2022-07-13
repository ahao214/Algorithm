#include<vector>
using namespace std;


class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> st;
		for (auto aster : asteroids) {
			bool alive = true;
			while (alive && aster < 0 && !st.empty() && st.back() > 0) {
				alive = st.back() < -aster; // aster �Ƿ����
				if (st.back() <= -aster) {  // ջ�����Ǳ�ը
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
