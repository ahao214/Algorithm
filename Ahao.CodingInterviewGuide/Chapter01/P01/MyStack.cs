using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter01.P01
{
    /*
     设计一个有getMin功能的栈
     */
    public class MyStack1
    {
        private Stack<int> stkData;
        private Stack<int> stkMin;

        public MyStack1()
        {
            stkData = new Stack<int>();
            stkMin = new Stack<int>();
        }

        public void Push(int newNum)
        {
            if (stkMin.Count == 0)
            {
                stkMin.Push(newNum);
            }
            else if (newNum <= getMin())
            {
                stkMin.Push(newNum);
            }
            stkData.Push(newNum);
        }

        public int Pop()
        {
            if (stkData.Count == 0)
            {
                throw new ArgumentException("Your stack is empty");
            }
            int value = stkData.Pop();
            if (value == getMin())
            {
                stkMin.Pop();
            }
            return value;
        }

        public int getMin()
        {
            if (stkMin.Count == 0)
            {
                throw new ArgumentException("Your stack is empty");
            }
            return stkMin.Peek();
        }
    }
}
