using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2800_2899._2824
{
    public class Class2824
    {
        public int CountPairs(IList<int> nums, int target)
        {
            int res = 0;
            for (int i = 0; i < nums.Count; i++)
            {
                for (int j = i + 1; j < nums.Count; j++)
                {
                    if (nums[i] + nums[j] < target)
                        res++;
                }
            }
            return res;
        }


        public int CountPairs2(IList<int> nums, int target)
        {
            ((List<int>)nums).Sort();
            int res = 0;
            for (int i = 1; i < nums.Count; i++)
            {
                int k = BinarySearch(nums, 0, i - 1, target - nums[i]);
                res += k;
            }
            return res;
        }

        public int BinarySearch(IList<int> nums, int lo, int hi, int target)
        {
            int res = hi + 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] >= target)
                {
                    res = mid;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            return res;
        }


        public int CountPairs3(IList<int> nums, int target)
        {
            ((List<int>)nums).Sort();
            int res = 0;
            for (int i = 0, j = nums.Count - 1; i < j; i++)
            {
                while (i < j && nums[i] + nums[j] >= target)
                {
                    j--;
                }
                res += j - i;
            }
            return res;
        }

    }
}
