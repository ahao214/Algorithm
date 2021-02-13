using System;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 用链表实现栈
    /// </summary>
    public class TestStackByLink
    {
        class LNode<T>
        {
            public T data;
            public LNode<T> next;
        }

        public class MyStack<T>
        {
            private LNode<T> pHead;
            public MyStack()
            {
                pHead = new LNode<T>();
                pHead.data = default(T);
                pHead.next = null;
            }

            //判断stack是否为空，如果为空返回true,否则返回false
            public bool IsEmpty()
            {
                if (pHead.next == null)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            //获取栈中元素的个数
            public int Size()
            {
                int size = 0;
                LNode<T> p = pHead.next;
                while (p != null)
                {
                    p = p.next;
                    size++;
                }
                return size;
            }

            //入栈：把e放到栈顶
            public void Push(T e)
            {
                LNode<T> p = new LNode<T>();
                p.data = e;
                p.next = pHead.next;
                pHead.next = p;
            }

            //出栈，同时返回栈顶元素
            public T Pop()
            {
                LNode<T> tmp = pHead.next;
                if (tmp != null)
                {
                    pHead.next = tmp.next;
                    T data = tmp.data;
                    return data;
                }
                Console.WriteLine("栈已经为空");
                return default(T);
            }

            //取得栈顶元素
            public T Top()
            {
                if (pHead.next != null)
                {
                    return pHead.next.data;
                }
                Console.WriteLine("栈已经为空");
                return default(T);
            }
        }
    }
}
