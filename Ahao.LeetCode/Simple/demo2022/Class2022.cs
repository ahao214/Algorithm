using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo2022
{
    /// <summary>
    /// 2022. 将一维数组转变成二维数组
    /// </summary>
    public class Class2022
    {
        /// <summary>
        /// 
        /// </summary>
        /// <param name="original">一维数组</param>
        /// <param name="m">行</param>
        /// <param name="n">列</param>
        /// <returns></returns>
        public int[][] Construct2DArray(int[] original, int m, int n)
        {
            if (original.Length != m * n)
            {
                return new int[0][];
            }

            int[][] res = new int[m][];
            for (int i = 0; i < m; i++)
            {
                res[i] = new int[n];
            }

            for (int i = 0; i < original.Length; i++)
            {
                res[i / n][i % n] = original[i];
            }
            return res;
        }
    }
}
