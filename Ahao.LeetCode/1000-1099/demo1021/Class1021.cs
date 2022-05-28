using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1021
{
    public class Class1021
    {
        //方法一：栈
        public string RemoveOuterParentheses(string s)
        {
            StringBuilder res = new StringBuilder();
            Stack<char> stack = new Stack<char>();
            foreach (char c in s)
            {
                if (c == ')')
                {
                    stack.Pop();
                }
                if (stack.Count > 0)
                {
                    res.Append(c);
                }
                if (c == '(')
                {
                    stack.Push(c);
                }
            }
            return res.ToString();
        }

        //方法二：计数
        public string RemoveOuterParentheses2(string s)
        {
            int level = 0;
            StringBuilder res = new StringBuilder();
            foreach (char c in s)
            {
                if (c == ')')
                {
                    level--;
                }
                if (level > 0)
                {
                    res.Append(c);
                }
                if (c == '(')
                {
                    level++;
                }
            }
            return res.ToString();
        }


    }
}
