using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary.LC240
{
    /// <summary>
    /// 240. 搜索二维矩阵 II
    /// </summary>
    public class SearchMatrix
    {
        public bool Method(int[][] matrix, int target)
        {
            foreach (int[] row in matrix)
            {
                foreach (int element in row)
                {
                    if (element == target)
                    {
                        return true;
                    }
                }
            }
            return false;           
        }
    }
}
