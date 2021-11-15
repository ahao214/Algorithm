using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 830.较大分组的位置
    /// </summary>
    public class LargeGroupPositions
    {
        public IList<IList<int>> Method(string s)
        {
            var result = new List<IList<int>>();
            int index = 0;
            while (index < s.Length)
            {
                int start = index;
                while (index < s.Length && s[index] == s[start]) index++;
                if (index - start >= 3)
                {
                    result.Add((new int[] { start, index - 1 }).ToList());
                }
            }
            return result;
        }
    }
}
