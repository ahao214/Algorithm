using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1200_1299.demo1276
{
    public class Class1276
    {
        public IList<int> NumOfBurgers(int tomatoSlices, int cheeseSlices)
        {
            if (tomatoSlices % 2 != 0 || tomatoSlices < cheeseSlices * 2 || cheeseSlices * 4 < tomatoSlices)
            {
                return new List<int>();
            }
            IList<int> ans = new List<int>();
            ans.Add(tomatoSlices / 2 - cheeseSlices);
            ans.Add(cheeseSlices * 2 - tomatoSlices / 2);
            return ans;
        }

        public IList<int> NumOfBurgers1(int tomatoSlices, int cheeseSlices)
        {
            IList<int> res = new List<int>();

            for (int i = 0; i <= cheeseSlices; i++)
            {
                if ((i * 4 + (cheeseSlices - i) * 2) == tomatoSlices)
                {
                    res.Add(i);
                    res.Add(cheeseSlices - i);
                }
            }
            return res;

        }


    }
}
