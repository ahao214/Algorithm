using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo6
{
    /*
     6. Z 字形变换
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
     */
    public class Class6
    {
        public string Convert(string s, int numRows)
        {
            if (string.IsNullOrEmpty(s))
                return string.Empty;
            if(numRows == 1)
            {
                return s;
            }
            var rows = new StringBuilder[numRows];
            for (int i = 0; i < rows.Length; i++)
            {
                rows[i] = new StringBuilder();
            }
            var row = 0;
            var step = 1;
            for(int i = 0; i < s.Length; i++)
            {
                rows[row].Append(s[i]);
                row += step;
                if(row ==numRows)
                {
                    row = numRows - 2;
                    step = -1;
                }else if(row == -1)
                {
                    row = 1;
                    step = 1;
                }
            }
            var sb = new StringBuilder(s.Length);
            foreach (var line in rows)
            {
                sb.Append(line);
            }
            return sb.ToString();
        }
    }
}
