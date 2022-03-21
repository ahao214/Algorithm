using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo599
{
    public class Class599
    {
        public string[] FindRestaurant(string[] list1, string[] list2)
        {
            IList<string> res = new List<string>();
            Dictionary<string, int> dic = new Dictionary<string, int>();
            for (int i = 0; i < list1.Length; i++)
            {
                dic.Add(list1[i], i);
            }
            int minValue = int.MaxValue;
            for (int i = 0; i < list2.Length; i++)
            {
                if (dic.ContainsKey(list2[i]))
                {
                    int j = dic[list2[i]];
                    if (i + j < minValue)
                    {
                        res.Clear();
                        res.Add(list2[i]);
                        minValue = i + j;
                    }
                    else if (i + j == minValue)
                    {
                        res.Add(list2[i]);
                    }
                }
            }
            return res.ToArray();
        }
    }
}
