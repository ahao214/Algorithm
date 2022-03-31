using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo992
{
  public  class Class992
    {
        public int SubarraysWithKDistinct(int[] nums, int k)
        {
            int n = nums.Length;
            int[] lessCounts = new int[n + 1];  //k-1种数的窗口词频统计
            int[] equalCounts = new int[n + 1]; //k种数的窗口词频统计
            int lessLeft = 0, equalLeft = 0, lessKinds = 0, equalKinds = 0;
            int ans = 0;

            for(int r = 0; r < n; r++)
            {
                if (lessCounts[nums[r]] == 0)
                    lessKinds++;
                if (equalCounts[nums[r]] == 0)
                    equalKinds++;

                lessCounts[nums[r]]++;
                equalCounts[nums[r]]++;

                while (lessKinds == k)
                {
                    if (lessCounts[nums[lessLeft]] == 1)
                        lessKinds--;
                    lessCounts[nums[lessLeft++]]--;
                }

                while (equalKinds > k)
                {
                    if (equalCounts[nums[equalLeft]] == 1)
                        equalKinds--;
                    equalCounts[nums[equalLeft++]]--;
                }

                ans += lessLeft - equalLeft;

            }

            return ans;
        }
    }
}
