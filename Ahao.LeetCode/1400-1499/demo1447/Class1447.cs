using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1447
{
    public class Class1447
    {
        public IList<string> SimplifiedFractions(int n)
        {
            IList<string> res = new List<string>();
            for (int down = 2; down <= n; down++)
            {
                for (int up = 1; up < down; up++)
                {
                    if (gcd(up, down) == 1)
                    {
                        res.Add(up + "/" + down);
                    }
                }
            }
            return res;
        }

        //求两个数字的最大公约数
        public int gcd(int a, int b)
        {
            return b != 0 ? gcd(b, a % b) : a;
        }
    }
}
