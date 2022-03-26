using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0600_0699.demo682
{
   public class Class682
    {
        public int CalPoints(string[] ops)
        {
            int res = 0;

            IList<int> lst = new List<int>();
            foreach(var item in ops)
            {
                if (item != "C" && item != "D" && item != "+")
                    lst.Add(Convert.ToInt32(item));
                if (item == "C") {
                    lst.RemoveAt(lst.Count - 1);
                }
                if (item == "D")
                {
                    lst.Add(Convert.ToInt32(lst[lst.Count - 1]) * 2);
                }
                if (item == "+")
                {
                    lst.Add(Convert.ToInt32(lst[lst.Count - 1]) + Convert.ToInt32(lst[lst.Count - 2]));
                }
            }
            res = lst.Sum();
            return res;
            
        }
    }
}
