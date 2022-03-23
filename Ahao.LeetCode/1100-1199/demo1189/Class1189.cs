using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1189
{
    public class Class1189
    {
        public int MaxNumberOfBalloons(string text)
        {
            if (string.IsNullOrEmpty(text))
                return 0;
            int[] count = new int[5];
            foreach (char c in text)
            {
                if (c == 'b')
                {
                    count[0]++;
                }
                else if (c == 'a')
                {
                    count[1]++;
                }
                else if (c == 'l')
                {
                    count[2]++;
                }
                else if (c == 'o')
                {
                    count[3]++;
                }
                else if (c == 'n')
                {
                    count[4]++;
                }
            }
            count[2] /= 2;
            count[3] /= 2;
            return count.Min();
        }
    }
}
