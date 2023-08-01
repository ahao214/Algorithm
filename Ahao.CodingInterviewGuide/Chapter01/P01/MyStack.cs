using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter01.P01
{
    /// <summary>
    /// 第一种设计方案
    /// </summary>
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

    /// <summary>
    /// 第二种设计方案
    /// </summary>
    public class MyStack2
    {
        private Stack<int> stackData;
        private Stack<int> stackMin;

        public MyStack2()
        {
            this.stackData = new Stack<int>();
            this.stackMin = new Stack<int>();
        }

        public void Push(int newNum)
        {
            if (this.stackMin.Count == 0)
            {
                this.stackMin.Push(newNum);
            }
            else if (newNum < this.GetMin())
            {
                this.stackMin.Push(newNum);
            }
            else
            {
                int newMin = this.stackMin.Peek();
                this.stackMin.Push(newMin);
            }
            this.stackData.Push(newNum);
        }

        public int Pop()
        {
            if (this.stackData.Count == 0)
            {
                throw new ArgumentException("Your stack is empty");
            }
            this.stackMin.Pop();
            return this.stackData.Pop();
        }

        public int GetMin()
        {
            if (this.stackData.Count == 0)
            {
                throw new ArgumentException("Your stack is empty");
            }
            return this.stackData.Peek();
        }
    }

}
