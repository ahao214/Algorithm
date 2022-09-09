using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1500_1599.demo1598
{
    public class Class1598
    {
        public int MinOperations(string[] logs)
        {
            int depth = 0;
            foreach (string log in logs)
            {
                if ("./".Equals(log))
                {
                    continue;
                }
                else if ("../".Equals(log))
                {
                    if (depth > 0)
                    {
                        depth--;
                    }
                }
                else
                {
                    depth++;
                }
            }
            return depth;
        }
    }
}
