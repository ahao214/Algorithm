using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 用数组实现栈
    /// </summary>
    public class TestStackByArray
    {
        public class MyStack<T>
        {
            private List<T> arr;
            private int stackSize;  //数组中存储元素的个数

            public MyStack()
            {
                stackSize = 0;  //初始化初始栈大小
                arr = new List<T>();
            }

            //判断栈是否为空
            public bool IsEmpty()
            {
                return stackSize == 0;
            }

            //返回栈的大小
            public int Size()
            {
                return stackSize;
            }

            //返回栈顶元素
            public T Top()
            {
                if (IsEmpty())
                {
                    return default(T);
                }
                return arr[stackSize - 1];
            }

            //弹栈
            public T Pop()
            {
                if (stackSize > 0)
                {
                    return arr[--stackSize];
                }
                else
                {
                    Console.WriteLine("栈已经为空");
                    return default(T);
                }
            }

            //压栈
            public void Push(T item)
            {
                arr.Add(item);
                stackSize++;
            }
        }
    }
}
