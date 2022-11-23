using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1742
{
    public class Class1742
    {
        public int CountBalls(int lowLimit, int highLimit)
        {
            IDictionary<int, int> count = new Dictionary<int, int>();
            int res = 0;
            for (int i = lowLimit; i <= highLimit; i++)
            {
                int box = 0, x = i;
                while (x != 0)
                {
                    box += x % 10;
                    x /= 10;
                }
                count.TryAdd(box, 0);
                count[box]++;
                res = Math.Max(res, count[box]);
            }
            return res;
        }
    }
}
