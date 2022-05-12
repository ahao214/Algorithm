using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo944
{
    public class Class944
    {
        public int MinDeletionSize(string[] strs)
        {
            int row = strs.Length;
            int col = strs[0].Length;
            int ans = 0;
            for (int j = 0; j < col; ++j)
            {
                for (int i = 1; i < row; ++i)
                {
                    if (strs[i - 1][j] > strs[i][j])
                    {
                        ans++;
                        break;
                    }
                }
            }
            return ans;
        }
    }
}
