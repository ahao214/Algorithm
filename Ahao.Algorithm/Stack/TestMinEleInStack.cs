using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 求栈中最小元素
    /// </summary>
    public class TestMinEleInStack
    {
        public class MyStack
        {
            //用来存储栈中元素
            private Stack<int> elemStack = new Stack<int>();
            //栈顶永远存储当前elemStack中最小的值
            private Stack<int> minStack = new Stack<int>();

            public void Push(int data)
            {
                elemStack.Push(data);
                //更新保存最小元素的栈
                if (minStack.Count <= 0)
                {
                    minStack.Push(data);
                }
                else
                {
                    if (data <= minStack.Peek())
                    {
                        minStack.Push(data);
                    }
                }
            }


            public int Pop()
            {
                int topData = elemStack.Peek();
                elemStack.Pop();
                if (topData == Min())
                {
                    minStack.Pop();
                }
                return topData;
            }

            public int Min()
            {
                if (minStack.Count <= 0)
                {
                    return int.MaxValue;
                }
                else
                {
                    return minStack.Peek();
                }
            }
        }
    }
}
