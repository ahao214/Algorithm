using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1636
{
    public class Class1636
    {
        public int[] FrequencySort(int[] nums)
        {
            Dictionary<int, int> cnt = new Dictionary<int, int>();
            foreach (int num in nums)
            {
                cnt.TryAdd(num, 0);
                cnt[num]++;
            }
            List<int> list = new List<int>();
            foreach (int num in nums)
            {
                list.Add(num);
            }
            list.Sort((a, b) => {
                int cnt1 = cnt[a], cnt2 = cnt[b];
                return cnt1 != cnt2 ? cnt1 - cnt2 : b - a;
            });
            return list.ToArray();
        }
    }
}
