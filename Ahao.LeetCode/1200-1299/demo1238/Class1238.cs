using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1238
{
    public class Class1238
    {
        /// <summary>
        /// 归纳法
        /// </summary>
        /// <param name="n"></param>
        /// <param name="start"></param>
        /// <returns></returns>
        public IList<int> CircularPermutation(int n, int start)
        {
            IList<int> ret = new List<int>();
            ret.Add(start);
            for (int i = 1; i <= n; i++)
            {
                int m = ret.Count;
                for (int j = m - 1; j >= 0; j--)
                {
                    ret.Add(((ret[j] ^ start) | (1 << (i - 1))) ^ start);
                }
            }
            return ret;
        }

    }
}
