using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo599
{
    /*
599. 两个列表的最小索引总和
假设 Andy 和 Doris 想在晚餐时选择一家餐厅，
并且他们都有一个表示最喜爱餐厅的列表，
每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 
如果答案不止一个，则输出所有答案并且不考虑顺序。
 你可以假设答案总是存在。
*/
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
