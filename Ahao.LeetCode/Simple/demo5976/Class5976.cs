using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo5976
{
    /// <summary>
    /// 5976. 检查是否每一行每一列都包含全部整数
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
