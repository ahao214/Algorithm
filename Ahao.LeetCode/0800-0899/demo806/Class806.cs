using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo806
{
    public class Class806
    {
        public int[] NumberOfLines(int[] widths, string s)
        {
            int maxWidth = 100;
            int lines = 0;
            int width = 0;
            for (int i = 0; i < s.Length; i++)
            {
                int wantWidth = widths[s[i] - 'a'];
                width += wantWidth;
                if (width > maxWidth)
                {
                    lines++;
                    width = wantWidth;
                }
            }
            return new int[] { lines, width };
        }
    }
}
