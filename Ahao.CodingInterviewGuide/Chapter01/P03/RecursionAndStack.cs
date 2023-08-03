using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter01.P03
{
    public class RecursionAndStack
    {
        /// <summary>
        /// 递归函数一
        /// </summary>
        /// <param name="stk"></param>
        /// <returns></returns>
        public static int GetAndRemoveLastElement(Stack<int> stk)
        {
            int result = stk.Pop();
            if (stk.Count == 0)
            {
                return result;
            }
            else
            {
                int last = GetAndRemoveLastElement(stk);
                stk.Push(result);
                return last;
            }
        }


        /// <summary>
        /// 递归函数二
        /// </summary>
        /// <param name="stk"></param>
        public static void Reverse(Stack<int> stk)
        {
            if (stk.Count == 0)
            {
                return;
            }
            int i = GetAndRemoveLastElement(stk);
            Reverse(stk);
            stk.Push(i);
        }

    }
}
