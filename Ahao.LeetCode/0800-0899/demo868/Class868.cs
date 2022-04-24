using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo868
{
    public class Class868
    {
        public int BinaryGap(int n)
        {
            int last = -1, ans = 0;
            for (int i = 0; n != 0; ++i)
            {
                if ((n & 1) == 1)
                {
                    if (last != -1)
                    {
                        ans = Math.Max(ans, i - last);
                    }
                    last = i;
                }
                n >>= 1;
            }
            return ans;
        }
    }
}
