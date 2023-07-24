using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0700_0799.demo771
{
    internal class Class771
    {

        public int NumJewelsInStones(String jewels, String stones)
        {
            int jewelsCount = 0;
            int jewelsLength = jewels.Length, stonesLength = stones.Length;
            for (int i = 0; i < stonesLength; i++)
            {
                string stone = stones.Substring(i, 1);
                for (int j = 0; j < jewelsLength; j++)
                {
                    string jewel = jewels.Substring(j, 1);
                    if (stone == jewel)
                    {
                        jewelsCount++;
                        break;
                    }
                }
            }
            return jewelsCount;
        }



        public int NumJewelsInStones2(String jewels, String stones)
        {
            int jewelsCount = 0;
            ISet<string> jewelsSet = new HashSet<string>();
            int jewelsLength = jewels.Length, stonesLength = stones.Length;
            for (int i = 0; i < jewelsLength; i++)
            {
                string jewel = jewels.Substring(i, 1);
                jewelsSet.Add(jewel);
            }
            for (int i = 0; i < stonesLength; i++)
            {
                string stone = stones.Substring(i, 1);
                if (jewelsSet.Contains(stone))
                {
                    jewelsCount++;
                }
            }
            return jewelsCount;
        }


    }
}
