using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 用两个栈模拟队列操作
    /// </summary>
    public class TestTwoStack
    {
        public class MyStack<T>
        {
            private Stack<T> A = new Stack<T>();    //用来存储栈中元素
            private Stack<T> B = new Stack<T>();    //用来存储当前栈中最小的元素

            public void push(T data)
            {
                A.Push(data);
            }

            public T pop()
            {
                if(B.Count<=0)
                {
                    while(A.Count>0)
                    {
                        B.Push(A.Peek());
                        A.Pop();
                    }
                }
                T first = B.Peek();
                B.Pop();
                return first;
            }
        }
    }
}
