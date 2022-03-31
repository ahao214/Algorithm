using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo446
{
  public  class Class446
    {
        public int NumberOfArithmeticSlices(int[] nums)
        {
            int n = nums.Length;
            int ans = 0;
            Dictionary<long, int>[] dic = new Dictionary<long, int>[n];
            for (int i = 0; i < n; i++)
                dic[i] = new Dictionary<long, int>();

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < i; j++)
                {
                    long d = 1L * nums[i] - nums[j];
                    int cnt = dic[j].ContainsKey(d) ? dic[j][d] : 0;
                    ans += cnt;
                    if (dic[i].ContainsKey(d))
                    {
                        dic[i][d] += cnt + 1;
                    }
                    else
                    {
                        dic[i].Add(d, cnt + 1);
                    }
                }
            }
            return ans;

        }

    }
}
