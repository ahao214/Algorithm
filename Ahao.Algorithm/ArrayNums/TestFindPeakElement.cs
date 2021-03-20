using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找出数组的峰值
    /// </summary>
    public class TestFindPeakElement
    {
        public static int? FindPeakElement(int[] num)
        {
            int left = 0, righ = num.Length - 1;
            while (left <= righ)
            {
                if (left == righ)
                {
                    return left;
                }
                int mid = (left + righ) / 2;
                if (num[mid] < num[mid + 1])
                {
                    left = mid + 1;
                }
                else
                {
                    righ = mid;
                }
            }
            return null;
        }
    }
}
