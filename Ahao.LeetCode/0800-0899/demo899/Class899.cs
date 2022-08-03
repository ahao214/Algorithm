using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo899
{
    public class Class899
    {
        public string OrderlyQueue(string s, int k)
        {
            if (k == 1)
            {
                string smallest = s;
                StringBuilder sb = new StringBuilder(s);
                int n = s.Length;
                for (int i = 1; i < n; i++)
                {
                    char c = sb[0];
                    sb.Remove(0, 1);
                    sb.Append(c);
                    if (sb.ToString().CompareTo(smallest) < 0)
                    {
                        smallest = sb.ToString();
                    }
                }
                return smallest;
            }
            else
            {
                char[] arr = s.ToCharArray();
                Array.Sort(arr);
                return new string(arr);
            }
        }
    }
}
