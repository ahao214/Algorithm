using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Caching;
using System.Web.UI.WebControls;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 数组实现队列
    /// </summary>
    public class TestQueueByArray
    {
        public class MyQueue<T>
        {
            private T[] arr;
            private int maxSize;    //数组中存储元素的个数

            private int front;
            private int rear;

            public MyQueue(int size)
            {
                maxSize = size; //初始化队列大小
                arr = new T[size];
            }

            //判断队列是否为空
            public bool IsEmpty()
            {
                return front == rear;
            }

            //判断队列是否已满
            public bool IsFull()
            {
                if (front != -1)  //如果已经有元素出过对
                {
                    //为了区分与IsEmpth的区别，有元素出过对以后，就只有浪费一个位置来保持逻辑正确性
                    return (rear + 1) % maxSize == front;
                }
                else
                {
                    return rear == maxSize - 1;
                }
            }

            //返回队列的大小
            public int Count()
            {
                if (rear > front)
                {
                    return rear - front;
                }
                else
                {
                    return (rear - front + maxSize) % maxSize;
                }
            }

            //返回队列首元素
            public T Peek()
            {
                if (IsEmpty())
                {
                    Console.WriteLine("Queue is empty");
                    return default(T);
                }
                return arr[(front + 1) % maxSize];
            }

            //进队列
            public void Enquene(T item)
            {
                if (IsFull())
                {
                    Console.WriteLine("Queue is full");
                    return;
                }
                if (rear == maxSize - 1)   //如果rear到头了，则循环重来
                {
                    rear = 0;
                }
                else
                {
                    rear++;
                }
                arr[rear] = item;
            }

            //出队列
            public T Dequene()
            {
                if (IsEmpty())
                {
                    Console.WriteLine("Queue is empty");
                    return default(T);
                }
                if (front == maxSize - 1)   //如果front到头了，则重新置0
                {
                    front = 0;
                }
                else
                {
                    front++;
                }
                return arr[front];
            }
        }
    }
}
