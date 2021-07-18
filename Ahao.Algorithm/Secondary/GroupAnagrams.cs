using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 面试题 10.02. 变位词组
    /// </summary>
    public class GroupAnagrams
    {
        public IList<IList<string>> Method(string[] strs)
        {
            IList<IList<string>> result = new List<IList<string>>();
            Dictionary<string, List<string>> dic = new Dictionary<string, List<string>>();

            for (int i = 0; i < strs.Length; i++)
            {
                var str = strs[i].ToArray().ToList();
                str.Sort(); //排序
                var key = new string(str.ToArray());
                if (dic.ContainsKey(key))
                {
                    dic[key].Add(strs[i]);
                }
                else
                {
                    dic.Add(key, new List<string>() { strs[i] });
                }
            }

            foreach (var item in dic)
                result.Add(item.Value);
            return result;

        }
    }
}
