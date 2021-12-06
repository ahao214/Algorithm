using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo201
{
    /// <summary>
    /// 201. 数字范围按位与
    /// </summary>
    public class Class201
    {
        public int RangeBitwiseAnd(int left, int right)
        {
            while (left < right)
            {
                right = right & (right - 1);
            }
            return right;
        }
    }
}
