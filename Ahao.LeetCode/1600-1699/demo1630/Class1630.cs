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
    }
}
