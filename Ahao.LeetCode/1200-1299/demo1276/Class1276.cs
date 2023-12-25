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


    }
}
