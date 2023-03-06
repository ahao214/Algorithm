using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1653
{
    public class Class1653
    {

        public int MinimumDeletions(string s)
        {
            int leftb = 0, righta = 0;
            foreach (char c in s)
            {
                if (c == 'a')
                {
                    righta++;
                }
            }
            int res = righta;
            foreach (char c in s)
            {
                if (c == 'a')
                {
                    righta--;
                }
                else
                {
                    leftb++;
                }
                res = Math.Min(res, leftb + righta);
            }
            return res;
        }

    }
}
