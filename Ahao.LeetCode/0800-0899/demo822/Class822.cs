using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo822
{
    internal class Class822
    {

        public int Flipgame(int[] fronts, int[] backs)
        {
            var res = int.MaxValue;
            HashSet<int> set = new();
            for (var i = 0; i < fronts.Length; ++i)
            {
                if (fronts[i] == backs[i])
                    set.Add(fronts[i]);
            }

            for (var i = 0; i < fronts.Length; ++i)
            {
                if (!set.Contains(backs[i]))
                {
                    res = Math.Min(res, backs[i]);
                }
                if (!set.Contains(fronts[i]))
                {
                    res = Math.Min(res, fronts[i]);
                }
            }

            return res == int.MaxValue ? 0 : res;

        }

    }
}
