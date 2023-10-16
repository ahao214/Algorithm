#include<vector>
#include <unordered_map>

using namespace std;


/*
260. ֻ����һ�ε����� III

����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ�
�ҳ�ֻ����һ�ε�������Ԫ�ء�����԰� ����˳�� ���ش𰸡�
*/
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int s = 0;
		for (auto x : nums) {
			s ^= x;
		}
		int k = 0;
		while (!(s >> k & 1)) k++;

		int s2 = 0;
		for (auto x : nums) {
			if (x >> k & 1) {
				s2 ^= x;
			}
		}
		return vector<int>({ s2,s ^ s2 });
	}
};


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (int num : nums) {
            xorsum ^= num;
        }
        // ��ֹ���
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;
        for (int num : nums) {
            if (num & lsb) {
                type1 ^= num;
            }
            else {
                type2 ^= num;
            }
        }
        return { type1, type2 };
    }
};


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        vector<int> ans;
        for (const auto& [num, occ] : freq) {
            if (occ == 1) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
