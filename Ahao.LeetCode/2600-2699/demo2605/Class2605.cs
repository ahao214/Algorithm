using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2600_2699.demo2605
{
    public class Class2605
    {
        public int MinNumber(int[] nums1, int[] nums2)
        {
            Array.Sort(nums1);
            Array.Sort(nums2);

            int n1 = nums1.Length;
            int n2 = nums2.Length;
            int i = 0;
            int j = 0;
            while (i < n1 && j < n2)
            {
                if (nums1[i] == nums2[j])
                {
                    return nums1[i];
                }
                else if (nums1[i] > nums2[j])
                {
                    j++;
                }
                else
                {
                    i++;
                }
            }
            return nums1[0] < nums2[0] ? nums1[0] * 10 + nums2[0] : nums2[0] * 10 + nums1[0];
        }



        public int MinNumber2(int[] nums1, int[] nums2)
        {
            int s = Same(nums1, nums2);
            if (s != -1)
            {
                return s;
            }

            int x = nums1.Min();
            int y = nums2.Min();
            return Math.Min(x * 10 + y, y * 10 + x);
        }

        public int Same(int[] nums1, int[] nums2)
        {
            ISet<int> s = new HashSet<int>();
            foreach (int num in nums1)
            {
                s.Add(num);
            }
            int x = 10;
            foreach (int num in nums2)
            {
                if (s.Contains(num))
                {
                    x = Math.Min(x, num);
                }
            }
            return x == 10 ? -1 : x;
        }
    }
}
