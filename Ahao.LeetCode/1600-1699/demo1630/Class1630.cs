using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1630
{
    public class Class1630
    {
        public IList<bool> CheckArithmeticSubarrays(int[] nums, int[] l, int[] r)
        {
            IList<bool> res = new List<bool>();
            int len = l.Length;
            for (int i = 0; i < len; i++)
            {
                int left = l[i];
                int right = r[i];
                List<int> lst = new List<int>();
                for (int k = left; k <= right; k++)
                {
                    lst.Add(nums[k]);
                }
                res.Add(IsEqualSubarray(lst.ToArray()));
            }
            return res;
        }

        private bool IsEqualSubarray(int[] arr)
        {
            bool res = true;
            Array.Sort(arr);
            for (int i = 0; i < arr.Length - 2; i++)
            {
                if ((arr[i + 1] - arr[i]) != (arr[i + 2] - arr[i + 1]))
                {
                    res = false;
                    break;
                }
            }

            return res;
        }




        public IList<bool> CheckArithmeticSubarrays2(int[] nums, int[] l, int[] r)
        {
            int n = l.Length;
            IList<bool> ans = new List<bool>();
            for (int i = 0; i < n; ++i)
            {
                int left = l[i], right = r[i];
                int minv = nums[left], maxv = nums[left];
                for (int j = left + 1; j <= right; ++j)
                {
                    minv = Math.Min(minv, nums[j]);
                    maxv = Math.Max(maxv, nums[j]);
                }

                if (minv == maxv)
                {
                    ans.Add(true);
                    continue;
                }
                if ((maxv - minv) % (right - left) != 0)
                {
                    ans.Add(false);
                    continue;
                }

                int d = (maxv - minv) / (right - left);
                bool flag = true;
                bool[] seen = new bool[right - left + 1];
                for (int j = left; j <= right; ++j)
                {
                    if ((nums[j] - minv) % d != 0)
                    {
                        flag = false;
                        break;
                    }
                    int t = (nums[j] - minv) / d;
                    if (seen[t])
                    {
                        flag = false;
                        break;
                    }
                    seen[t] = true;
                }
                ans.Add(flag);
            }
            return ans;
        }

    }
}
