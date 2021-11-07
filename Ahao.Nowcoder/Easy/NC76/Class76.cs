using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.NC76
{
    /// <summary>
    /// NC76 用两个栈实现队列
    /// </summary>
    public class Class76
    {
        private Stack<int> A = new Stack<int>();
        private Stack<int> B = new Stack<int>();

        public void push(int node)
        {
            A.Push(node);
        }
        public int pop()
        {
            if(B.Count<=0)
            {
                while(A.Count>0)
                {
                    B.Push(A.Peek());
                    A.Pop();
                }
            }
            int x = B.Peek();
            B.Pop();
            return x;
        }
    }
}
