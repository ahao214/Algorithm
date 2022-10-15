using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1400_1499.demo1441
{
    public class Class1441
    {
        public IList<string> BuildArray(int[] target, int n)
        {
            IList<string> lst = new List<string>();
            int prev = 0;
            foreach (var item in target)
            {
                for (int i = 0; i < item - prev - 1; i++)
                {
                    lst.Add("Push");
                    lst.Add("Pop");
                }
                lst.Add("Push");
                prev = item;
            }
            return lst;
        }
    }
}
