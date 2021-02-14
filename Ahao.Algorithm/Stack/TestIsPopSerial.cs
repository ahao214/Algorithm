using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 根据入栈序列判断可能的出栈序列
    /// </summary>
    public class TestIsPopSerial
    {
        public static bool IsPopSerial(String push, String pop)
        {
            if (push == null || pop == null)
            {
                return false;
            }
            int pushLen = push.Length;
            int popLen = pop.Length;
            if (pushLen != popLen)
            {
                return false;
            }

            int pushIndex = 0;
            int popIndex = 0;
            Stack<char> stack = new Stack<char>();
            while (pushIndex < pushLen)
            {
                //把push序列依次入栈，直到栈顶元素等于pop序列的第一个元素
                stack.Push(push[pushIndex]);
                pushIndex++;
                //栈顶元素出栈，pop序列移动到下一个元素
                while (stack.Count > 0 && stack.Peek() == pop[popIndex])
                {
                    stack.Pop();
                    popIndex++;
                }
            }

            //栈为空，且pop序列中元素都被遍历过
            if (stack.Count == 0 && popIndex == popLen)
            {
                return true;
            }
            return false;
        }
    }
}
