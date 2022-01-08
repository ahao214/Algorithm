using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo89
{
    /// <summary>
    /// 89. 格雷编码
    /// </summary>
    public class Class89
    {
        public IList<int> GrayCode(int n)
        {
            if (n == 0)
            {
                return new int[] { 0 };
            }
            if (n == 1)
            {
                return new int[] { 0, 1 };
            }

            var result = new int[1 << n];
            result[0] = 0;
            result[1] = 1;
            var m = 2;
            while (m < result.Length)
            {

                for (int i = 0, j = m - 1; i < m; i++, j--)
                {
                    result[i + m] = result[j] + m;
                }
                m *= 2;
            }
            return result;
        }

        public IList<int> GrayCode1(int n)
        {
            IList<int> ret = new List<int>();
            for (int i = 0; i < 1 << n; i++)
            {
                ret.Add((i >> 1) ^ i);
            }
            return ret;
        }


    }
}
