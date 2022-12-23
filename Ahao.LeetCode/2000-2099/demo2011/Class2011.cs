using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2000_2099.demo2011
{
    public class Class2011
    {
        public int FinalValueAfterOperations(string[] operations)
        {
            int x = 0;
            foreach (string op in operations)
            {
                if (op == "X++" || op == "++X")
                {
                    x++;
                }
                else
                {
                    x--;
                }
            }
            return x;
        }
    }
}
