using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 链表实现队列
    /// </summary>
    public class TestQueueByLink
    {
        public class MyQueue<T>
        {
            class LNode<T>
            {
                public T Data;
                public LNode<T> Next;

                public LNode(T data)
                {
                    this.Data = data;   //初始化队列大小
                }
            }


            private LNode<T> front; //队列头
            private LNode<T> rear;  //队列尾
            private int num;    //队列元素个数

            public MyQueue()
            {
                //初始时front,rear置为null，num置0
                num = 0;
            }

            public int Count()
            {
                return this.num;
            }

            public void Clear()
            {
                front = rear = null;
                num = 0;
            }

            public bool IsEmpty()
            {
                return (front == rear && num == 0);
            }

            //入对列
            public void Enqueue(T item)
            {
                LNode<T> q = new LNode<T>(item);
                if (rear == null) //第一个元素入对时
                {
                    front = rear = q;
                }
                else
                {
                    //把新元素挂到链尾
                    rear.Next = q;
                    //修正rear指向为最后一个元素
                    rear = q;
                }
                //元素总数+1
                num++;
            }

            //出队列
            public T Dequeue()
            {
                if(IsEmpty())
                {
                    Console.WriteLine("Queue is empty");
                    return default(T);
                }
                //取链首元素
                LNode<T> p = front;
                //链头指向后移一位
                front = front.Next;
                //如果此时链表为空，则同步修正rear
                if(front ==null )
                {
                    rear = null;
                }
                num--;
                return p.Data;
            }


            public T Peek()
            {
                if(IsEmpty())
                {
                    Console.WriteLine("Queue is empty");
                    return default(T);
                }
                return front.Data;
            }
        }
    }
}
