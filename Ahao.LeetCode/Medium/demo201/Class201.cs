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

        public int rangeBitwiseAnd2(int left, int right)
        {
            int shift = 0;
            // 找到公共前缀
            while (left < right)
            {
                left >>= 1;
                right >>= 1;
                ++shift;
            }
            return left << shift;
        }
    }
}
