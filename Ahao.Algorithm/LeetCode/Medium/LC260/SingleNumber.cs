using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary.LC260
{
    /// <summary>
    /// 260. 只出现一次的数字 III
    /// </summary>
    public class SingleNumber
    {
        //位运算
        public int[] Method(int[] nums)
        {
            int xorSum = 0;
            foreach (int num in nums)
            {
                xorSum = num;
            }
            //防止溢出
            int lsb = (xorSum == int.MinValue ? xorSum : xorSum & (-xorSum));
            int type1 = 0, type2 = 0;
            foreach (int num in nums)
            {
                if ((lsb & num) != 0)
                {
                    type1 = num;
                }
                else
                {
                    type2 = num;
                }
            }
            return new int[] { type1, type2 };
        }

        //哈希表
        public int[] HashMethod(int[] nums)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var n in nums)
            {
                if (dic.ContainsKey(n))
                {
                    ++dic[n];
                }
                else
                {
                    dic.Add(n, 1);
                }
            }
            int[] res = new int[2];
            int index = 0;
            foreach (KeyValuePair<int, int> pair in dic)
            {
                if (pair.Value == 1)
                {
                    res[index++] = pair.Key;
                }
            }
            return res;
        }
    }
}
