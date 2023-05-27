#include<vector>
#include <numeric>

using namespace std;

/*
1093. 大样本统计

我们对 0 到 255 之间的整数进行采样，并将结果存储在数组 count 中：count[k] 就是整数 k 在样本中出现的次数。

计算以下统计数据:

minimum ：样本中的最小元素。
maximum ：样品中的最大元素。
mean ：样本的平均值，计算为所有元素的总和除以元素总数。
median ：
如果样本的元素个数是奇数，那么一旦样本排序后，中位数 median 就是中间的元素。
如果样本中有偶数个元素，那么中位数median 就是样本排序后中间两个元素的平均值。
mode ：样本中出现次数最多的数字。保众数是 唯一 的。
以浮点数数组的形式返回样本的统计信息 [minimum, maximum, mean, median, mode] 。与真实答案误差在 10-5 内的答案都可以通过。
*/


class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        int total = accumulate(count.begin(), count.end(), 0);
        double mean = 0.0;
        double median = 0.0;
        int minnum = 256;
        int maxnum = 0;
        int mode = 0;

        int left = (total + 1) / 2;
        int right = (total + 2) / 2;
        int cnt = 0;
        int maxfreq = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)count[i] * i;
            if (count[i] > maxfreq) {
                maxfreq = count[i];
                mode = i;
            }
            if (count[i] > 0) {
                if (minnum == 256) {
                    minnum = i;
                }
                maxnum = i;
            }
            if (cnt < right && cnt + count[i] >= right) {
                median += i;
            }
            if (cnt < left && cnt + count[i] >= left) {
                median += i;
            }
            cnt += count[i];
        }
        mean = (double)sum / total;
        median = median / 2.0;
        return { (double)minnum, (double)maxnum, mean, median, (double)mode };
    }
};
