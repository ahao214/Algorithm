using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Web.UI;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 从给定的车票中找出旅程的路线
    /// </summary>
    public class Itinerary
    {
        public static void PrintResult(Dictionary<String, String> input)
        {
            //用来存储把input的键与值调换后的信息
            Dictionary<String, String> reverseInput = new Dictionary<String, String>();
            foreach (var item in input)
            {
                reverseInput.Add(item.Value, item.Key);
            }

            String start = null;
            //找到起点
            foreach (var item in input)
            {
                if (!reverseInput.ContainsKey(item.Key))
                {
                    start = item.Key;
                    break;
                }
            }

            if (start == null)
            {
                Console.WriteLine("输入不合理");
                return;
            }

            //从起点出发按照顺序遍历路径
            String to = input[start];
            Console.Write(start + "->" + to);
            start = to;
            to = input[to];
            while (to != null)
            {
                Console.Write("," + start + "->" + to);
                start = to;
                if (input.ContainsKey(to))
                {
                    to = input[to];
                }
                else
                {
                    to = null;
                }
            }
        }
    }
}
