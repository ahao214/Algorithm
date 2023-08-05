using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter01.P05
{
    public class StackByStack
    {
        public void SortStackByStack(Stack<int> stack)
        {
            Stack<int> help = new Stack<int>();
            while (stack.Count != 0)
            {
                int cur = stack.Pop();
                while (help.Count != 0 && help.Peek() < cur)
                {
                    stack.Push(help.Pop());
                }
                help.Push(cur);
            }
            while (help.Count != 0)
            {
                stack.Push(help.Pop());
            }
        }

    }
}
