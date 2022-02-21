using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter01
{
    /*
     设计一个有getMin功能的栈
     */
    public class MyStack
    {
        private Stack<int> stkData;
        private Stack<int> stkMin;

        public MyStack()
        {
            this.stkData = new Stack<int>();
            this.stkMin = new Stack<int>();
        }

        public void Push(int newNum)
        {
            if (this.stkMin.Count == 0)
            {
                this.stkMin.Push(newNum);
            }
            else if (newNum <= this.getMin())
            {
                this.stkMin.Push(newNum);
            }
            this.stkData.Push(newNum);
        }

        public int Pop()
        {
            if (this.stkData.Count == 0)
            {
                throw new ArgumentException("Your stack is empty");
            }
            int value = this.stkData.Pop();
            if (value == this.getMin())
            {
                this.stkMin.Pop();
            }
            return value;
        }

        public int getMin()
        {
            if (this.stkMin.Count == 0)
            {
                throw new ArgumentException("Your stack is empty");
            }
            return this.stkMin.Peek();
        }
    }
}
