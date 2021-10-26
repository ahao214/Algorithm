using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 496. 下一个更大元素 I
    /// </summary>
    public class NextGreaterElement
    {
        public int[] Method(int[] nums1, int[] nums2)
        {
            //输入: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2].
            //输出: [-1,3,-1]
            int[] res = new int[nums1.Length];
            for (int i = 0; i < nums1.Length; i++)
            {
                int j = 0;
                //找到数组2中和数组1中相等的数字
                while (j < nums2.Length && nums1[i] != nums2[j])
                {
                    j++;
                }
                int m = j + 1;
                while (m < nums2.Length && nums2[m] < nums2[j])
                {
                    m++;
                }
                if (m < nums2.Length)
                    res[i] = nums2[m];
                else
                    res[i] = -1;
            }
            return res;
        }
    }
}
