using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo780
{
    public class Class780
    {
        public bool ReachingPoints(int sx, int sy, int tx, int ty)
        {
            while (tx > sx && ty > sy && tx != ty)
            {
                if (tx > ty)
                {
                    tx %= ty;
                }
                else
                {
                    ty %= tx;
                }
            }
            if (tx == sx && ty == sy)
            {
                return true;
            }
            else if (tx == sx)
            {
                return ty > sy && (ty - sy) % tx == 0;
            }
            else if (ty == sy)
            {
                return tx > sx && (tx - sx) % ty == 0;
            }
            else
            {
                return false;
            }
        }

    }
}
