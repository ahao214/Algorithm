using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo5976
{
    /// <summary>
    /// 5976. 检查是否每一行每一列都包含全部整数
    /// 对一个大小为 n x n 的矩阵而言，如果其每一行和每一列都包含从 1 到 n 的 全部 整数（含 1 和 n），则认为该矩阵是一个 有效 矩阵。
    /// 给你一个大小为 n x n 的整数矩阵 matrix ，请你判断矩阵是否为一个有效矩阵：如果是，返回 true ；否则，返回 false 。
    /// </summary>
    public class Class5976
    {
        public bool CheckValid(int[][] matrix)
        {
            bool result = true;
            int n = matrix.Length;
            Dictionary<int, int> dic;
            for (int i = 0; i < n; i++)
            {
                dic = new Dictionary<int, int>();
                for (int j = 0; j < n; j++)
                {
                    if (dic.ContainsKey(matrix[i][j]))
                    {
                        result = false;
                        break;
                    }
                    dic.Add(matrix[i][j], 1);
                }
            }
            for (int i = 0; i < n; i++)
            {
                dic = new Dictionary<int, int>();
                for (int j = 0; j < n; j++)
                {
                    if (dic.ContainsKey(matrix[j][i]))
                    {
                        result = false;
                        break;
                    }
                    dic.Add(matrix[j][i], 1);
                }
            }
            return result;
        }
    }
}
