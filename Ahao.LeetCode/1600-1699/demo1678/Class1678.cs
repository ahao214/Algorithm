using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1678
{
    public class Class1678
    {
        public string Interpret(string command)
        {
            StringBuilder res = new StringBuilder();
            for (int i = 0; i < command.Length; i++)
            {
                if (command[i] == 'G')
                {
                    res.Append("G");
                }
                else if (command[i] == '(')
                {
                    if (command[i + 1] == ')')
                    {
                        res.Append("o");
                    }
                    else
                    {
                        res.Append("al");
                    }
                }
            }
            return res.ToString();
        }
    }
}
