using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
    /*
     20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
     */
    public class Class20
    {
        public bool IsValid(string s)
        {
            var stk = new Stack<char>(s.Length);
            foreach (var c in s)
            {
                switch (c)
                {
                    case '(':
                    case '[':
                    case '{':
                        stk.Push(c);
                        break;

                    case ')':
                        if (stk.Count == 0 || stk.Pop() != '(')
                            return false;
                        break;

                    case ']':
                        if (stk.Count == 0 || stk.Pop() != '[')
                            return false;
                        break;

                    case '}':
                        if (stk.Count == 0 || stk.Pop() != '{')
                            return false;
                        break;

                    default:
                        throw new ArgumentException();
                }
            }
            return stk.Count == 0;
        }
    }
}
