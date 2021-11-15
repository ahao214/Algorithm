using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 179.最大数
    /// </summary>
    public class LargestNumber
    {
        public string Method(int[] nums)
        {
            List<string> list = new List<string>();
            int sum = 0;
            foreach (int i in nums)
            {
                list.Add(i.ToString());
                sum += i;
            }
            if (sum == 0)
            {
                return "0";
            }
            list.Sort((x, y) =>
            {
                return (x + y).CompareTo(y + x);
            });
            StringBuilder sb = new StringBuilder();
            for (int i = list.Count - 1; i >= 0; i--)
            {
                sb.Append(list[i]);
            }
            string res = sb.ToString();            
            return res;
        }
    }
}
