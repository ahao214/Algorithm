using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1337. 矩阵中战斗力最弱的 K 行
    /// </summary>
    public class KWeakestRows
    {
        public int[] Method(int[][] mat, int k)
        {
            Dictionary<int, int> dict = new Dictionary<int, int>();
            for (int i = 0; i < mat.Length; i++)
            {
                dict.Add(i, mat[i].Sum());
            }

            return dict.OrderBy(t => t.Value).Select(t => t.Key).Take(k).ToArray();
        }
    }
}
