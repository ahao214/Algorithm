using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2389
{
    public class Class2389
    {
        public int[] AnswerQueries(int[] nums, int[] queries)
        {
            int n = nums.Length, m = queries.Length;
            Array.Sort(nums);
            int[] f = new int[n + 1];
            for (int i = 0; i < n; i++)
            {
                f[i + 1] = f[i] + nums[i];
            }
            int[] answer = new int[m];
            for (int i = 0; i < m; i++)
            {
                answer[i] = BinarySearch(f, queries[i]) - 1;
            }
            return answer;
        }

        public int BinarySearch(int[] f, int target)
        {
            int low = 1, high = f.Length;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if (f[mid] > target)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return low;
        }

    }
}
