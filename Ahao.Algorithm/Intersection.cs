using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 349.两个数组的交集
    /// </summary>
    public class Intersection
    {
        public int[] Method(int[] nums1, int[] nums2)
        {
            return nums1.Intersect(nums2).ToArray();
        }
    }
}
