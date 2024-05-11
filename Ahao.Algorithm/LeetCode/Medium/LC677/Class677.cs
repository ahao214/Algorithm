using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary.LC677
{
    /// <summary>
    /// 677. 键值映射
    /// </summary>
    public class MapSum
    {
        Dictionary<string, int> dic;
        public MapSum()
        {
            dic = new Dictionary<string, int>();
        }

        public void Insert(string key, int val)
        {
            if (dic.ContainsKey(key))
            {
                dic[key] = val;
            }
            else
            {
                dic.Add(key, val);
            }
        }

        public int Sum(string prefix)
        {
            int res = 0;
            foreach (KeyValuePair<string, int> pair in dic)
            {
                if (pair.Key.StartsWith(prefix))
                {
                    res += pair.Value;
                }
            }
            return res;
        }
    }
}
