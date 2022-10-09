using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo856
{
    public class Class856
    {
        //方法一：分治
        public int ScoreOfParentheses(string s)
        {
            if (s.Length == 2)
            {
                return 1;
            }
            int bal = 0, n = s.Length, len = 0;
            for (int i = 0; i < n; i++)
            {
                bal += (s[i] == '(' ? 1 : -1);
                if (bal == 0)
                {
                    len = i + 1;
                    break;
                }
            }
            if (len == n)
            {
                return 2 * ScoreOfParentheses(s.Substring(1, n - 2));
            }
            else
            {
                return ScoreOfParentheses(s.Substring(0, len)) + ScoreOfParentheses(s.Substring(len));
            }
        }


        //方法二：栈
        public int ScoreOfParentheses2(string s)
        {
            Stack<int> st = new Stack<int>();
            st.Push(0);
            foreach (char c in s)
            {
                if (c == '(')
                {
                    st.Push(0);
                }
                else
                {
                    int v = st.Pop();
                    int top = st.Pop() + Math.Max(2 * v, 1);
                    st.Push(top);
                }
            }
            return st.Peek();
        }

        //方法三：计算最终分数和
        public int ScoreOfParentheses3(string s)
        {
            int bal = 0, n = s.Length, res = 0;
            for (int i = 0; i < n; i++)
            {
                bal += (s[i] == '(' ? 1 : -1);
                if (s[i] == ')' && s[i - 1] == '(')
                {
                    res += 1 << bal;
                }
            }
            return res;
        }

    }
}
