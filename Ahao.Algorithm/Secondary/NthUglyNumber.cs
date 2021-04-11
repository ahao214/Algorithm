using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 264-丑数(2)
    /// </summary>
    public class NthUglyNumber
    {
        public int Method(int n)
        {
            if (n == 1)
                return n;
            //SortedSet<long> lst = new SortedSet<long>();
            List<long> lst = new List<long>();
            lst.Add(1);
            int count = 1;
           while (count <n )
            {
                //var min = lst.Min;
                var min = lst[0];
                lst.Remove(min);
                lst.Add(min * 2);
                lst.Add(min * 3);
                lst.Add(min * 5);
                lst.Sort();
                count++;
                for(int i=0;i<lst.Count-1;i++)
                {
                    if(lst [i]==lst[i+1])
                    {
                        lst.RemoveAt(i);
                    }
                }
            }
            //return (int)lst.Min;
            return (int)lst[0];
        }

    }
}
