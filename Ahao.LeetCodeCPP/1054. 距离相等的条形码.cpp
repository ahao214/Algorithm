#include<vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
1054. ������ȵ�������

��һ���ֿ����һ�������룬���е� i ��������Ϊ barcodes[i]��

��������������Щ�����룬ʹ���������������ڵ������벻����ȡ� ����Է����κ������Ҫ��Ĵ𰸣����Ᵽ֤���ڴ𰸡�

*/


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> count;
        for (int b : barcodes) {
            count[b]++;
        }
        priority_queue<pair<int, int>> q;
        for (const auto& [x, cx] : count) {
            q.push({ cx, x });
        }
        vector<int> res;
        while (q.size()) {
            auto [cx, x] = q.top();
            q.pop();
            if (res.empty() || res.back() != x) {
                res.push_back(x);
                if (cx > 1) {
                    q.push({ cx - 1, x });
                }
            }
            else {
                if (q.size() < 1) return res;
                auto [cy, y] = q.top();
                q.pop();
                res.push_back(y);
                if (cy > 1) {
                    q.push({ cy - 1, y });
                }
                q.push({ cx, x });
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int length = barcodes.size();
        if (length < 2) {
            return barcodes;
        }

        unordered_map<int, int> counts;
        int maxCount = 0;
        for (int b : barcodes) {
            maxCount = max(maxCount, ++counts[b]);
        }

        int evenIndex = 0, oddIndex = 1, halfLength = length / 2;
        vector<int> res(length);
        for (auto& [x, cx] : counts) {
            while (cx > 0 && cx <= halfLength && oddIndex < length) {
                res[oddIndex] = x;
                cx--;
                oddIndex += 2;
            }
            while (cx > 0) {
                res[evenIndex] = x;
                cx--;
                evenIndex += 2;
            }
        }
        return res;
    }
};
