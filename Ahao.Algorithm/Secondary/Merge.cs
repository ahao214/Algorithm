using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 88. 合并两个有序数组
    /// </summary>
    public class Merge
    {
        public void Method(int[] nums1, int m, int[] nums2, int n)
        {
            for (int i = m; i < m + n; i++)
            {
                nums1[i] = nums2[i - m];
            }
            Array.Sort(nums1);
        }
    }
}
