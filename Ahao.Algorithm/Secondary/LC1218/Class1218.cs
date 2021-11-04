using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 1218. 最长定差子序列
    /// </summary>
    public class Class1218
    {
        public int LongestSubsequence(int[] arr, int difference)
        {
            int res = 0;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var v in arr)
            {
                int pre = dic.ContainsKey(v - difference) ? dic[v - difference] : 0;
                if (dic.ContainsKey(v))
                {
                    dic[v] = pre + 1;
                }
                else
                {
                    dic.Add(v, pre + 1);
                }
                res = Math.Max(res, dic[v]);
            }
            return res;
        }
    }
}
