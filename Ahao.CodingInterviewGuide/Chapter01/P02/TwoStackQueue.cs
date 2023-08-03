using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter01.P02
{
    public class TwoStackQueue
    {
        public Stack<int> stackPush;
        public Stack<int> stackPop;

        public TwoStackQueue()
        {
            stackPush = new Stack<int>();
            stackPop = new Stack<int>();
        }

        //push栈向pop栈倒入数据
        private void PushToPop()
        {
            if (stackPop.Count == 0)
            {
                while (stackPush.Count != 0)
                {
                    stackPop.Push(stackPop.Pop());
                }
            }
        }


        public void Add(int pushInt)
        {
            stackPush.Push(pushInt);
            PushToPop();
        }

        public int Poll()
        {
            if (stackPop.Count == 0 && stackPush.Count == 0)
            {
                throw new ArgumentException("Queue is empty");
            }
            PushToPop();
            return stackPop.Pop();
        }

        public int Peek()
        {
            if (stackPop.Count == 0 && stackPush.Count == 0)
            {
                throw new ArgumentException("Queue is empty");
            }
            PushToPop();
            return stackPop.Peek();
        }

    }
}
