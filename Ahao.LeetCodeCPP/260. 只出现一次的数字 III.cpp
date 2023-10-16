#include<vector>
#include <unordered_map>

using namespace std;


/*
260. 只出现一次的数字 III

给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。
找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
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
        // 防止溢出
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
