using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 查找到达目标词的最短链长度
    /// </summary>
    public class TestIsAdjacent
    {
        //用来存储单词链的队列
        class QItem
        {
            public String word;
            public int Len;
            public QItem(String word, int len)
            {
                this.word = word;
                this.Len = len;
            }
        }


        //判断两个字符串是否只有一个不同的字符
        public bool IsAdjacent(String a, String b)
        {
            int diff = 0;
            int len = a.Length;

            for (int i = 0; i < len; i++)
            {
                if (a[i] != b[i])
                {
                    diff++;
                }
                if (diff > 1)
                    return false;
            }
            return diff == 1 ? true : false;
        }

        //返回从start到target的最短链
        public int shortestChainLen(String start, String target, List<String> D)
        {
            Queue<QItem> Q = new Queue<QItem>();
            QItem item = new QItem(start, 1);
            Q.Enqueue(item);    //把第一个字符串添加进来


            while (Q.Count > 0)
            {
                QItem curr = Q.Peek();
                Q.Dequeue();

                for (int i = D.Count - 1; i >= 0; i--)
                {
                    String temp = D[i];
                    //如果这两个字符串只有一个字符不同
                    if (IsAdjacent(curr.word, temp))
                    {
                        item.word = temp;
                        item.Len = curr.Len + 1;
                        Q.Enqueue(item);    //把这个字符串放入到队列中

                        //把这个字符串从队列中删除来避免被重复遍历
                        D.Remove(D[i]);

                        //通过转变后得到了目标字符
                        if (temp == target)
                            return item.Len;
                    }
                }
            }
            return 0;
        }
    }
}
