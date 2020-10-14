using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1002. 查找常用字符
    /// </summary>
    public class CommonChars
    {
        public IList<string> Method(string[] A)
        {            
            List<Dictionary<char, int>> list = new List<Dictionary<char, int>>();
            foreach (var str in A)
            {
                Dictionary<char, int> dic = new Dictionary<char, int>();
                foreach (var cha in str)
                {
                    if (!dic.ContainsKey(cha))
                    {
                        dic.Add(cha, 1);
                    }
                    else
                    {
                        dic[cha] += 1;
                    }
                }
                list.Add(dic);
            }

            list.Sort((x, y) => x.Count.CompareTo(y.Count));
            var minListItem = list[0];
            List<string> result = new List<string>();
            foreach (var item in minListItem.Keys)
            {
                int flag = 0;
                int minNum = minListItem[item];
                for (int i = 1; i < list.Count; i++)
                {
                    if (list[i].ContainsKey(item))
                    {
                        flag++;
                        minNum = Math.Min(minNum, list[i][item]);
                    }
                }
                if (flag == list.Count - 1)
                {
                    for (int i = 0; i < minNum; i++)
                    {
                        result.Add(item.ToString());
                    }
                }
            }
            return result;
        }
    }
}
