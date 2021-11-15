using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1207. 独一无二的出现次数
    /// </summary>
    public class UniqueOccurrences
    {
        public bool Method(int[] arr)
        {
            var dic = new Dictionary<int, int>();
            foreach (var item in arr)
            {
                if (!dic.ContainsKey(item))
                {
                    dic.Add(item, 0);
                }
                else
                {
                    dic[item]++;
                }
            }
            var lst = new List<int>();
            foreach (var item in dic.Keys)
            {
                if (lst.Contains(dic[item]))
                {
                    return false;
                }
                lst.Add(dic[item]);
            }
            return true;
        }
    }
}
