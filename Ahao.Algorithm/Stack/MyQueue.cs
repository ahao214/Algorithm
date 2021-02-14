using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Stack
{
    class MyQueue
    {
        private List<TestUser> q = new List<TestUser>();

        public void EnQueue(TestUser u) //进入队列尾部
        {
            u.Seq = q.Count + 1;
            q.Add(u);
        }

        //队头出队列
        public void DeQueue()
        {
            q.First();
            DeQueue(q.First());
        }

        //队列中的人随机离开
        public void DeQueue(TestUser u)
        {
            if (u != null)
            {
                q.Remove(u);
                UpdateSeq();
            }
        }

        //出队列后更新队列中每个人的序列
        void UpdateSeq()
        {
            int i = 1;
            q.ForEach(p => p.Seq = i++);
        }

        //打印队列的信息
        public void PrintList()
        {
            foreach (var item in q)
            {
                Console.WriteLine(item.toString());
            }
        }

    }
}
