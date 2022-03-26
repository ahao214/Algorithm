using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo88
{
    public class Class88
    {
        public void Merge(int[] nums1, int m, int[] nums2, int n)
        {
            var i = m + n - 1;
            n--;
            m--;
            while (n >= 0)
            {
                nums1[i--] = m < 0 || nums2[n] >= nums1[m] ? nums2[n--] : nums1[m--];
            }
        }

    }
}
