using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple
{
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
