using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo6
{
    public class Class6
    {
        public string Convert(string s, int numRows)
        {
            if (string.IsNullOrEmpty(s))
                return string.Empty;
            if (numRows == 1)
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
            for (int i = 0; i < s.Length; i++)
            {
                rows[row].Append(s[i]);
                row += step;
                if (row == numRows)
                {
                    row = numRows - 2;
                    step = -1;
                }
                else if (row == -1)
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

        public string Convert1(string s, int numRows)
        {
            if (string.IsNullOrEmpty(s))
                return string.Empty;
            if (numRows == 1)
                return s;
            var k = numRows * 2 - 2;
            var sb = new StringBuilder(s.Length);
            var i = 0;
            while (i < s.Length)
            {
                sb.Append(s[i]);
                i += k;
            }
            for (int row = 1; row < numRows - 1; row++)
            {
                i = row;
                var j = k - i;
                while (i < s.Length)
                {
                    sb.Append(s[i]);
                    if (j < s.Length)
                    {
                        sb.Append(s[j]);
                    }
                    i += k;
                    j += k;
                }
            }
            i = numRows - 1;
            while (i < s.Length)
            {
                sb.Append(s[i]);
                i += k;
            }
            return sb.ToString();
        }
    }
}
