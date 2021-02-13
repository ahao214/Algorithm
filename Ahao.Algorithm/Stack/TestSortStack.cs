using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 给栈排序
    /// </summary>
    public class TestSortStack
    {
        /// <summary>
        /// 方法功能：把栈底元素移动到栈顶
        /// 参数：s 栈的引用
        /// </summary>
        /// <param name="s"></param>
        private static void MoveBottonToTop(Stack<int> s)
        {
            if(s.Count<=0)
            {
                return;
            }
            int topOne = s.Peek();
            s.Pop();
            if(s.Count >0)
            {
                MoveBottonToTop(s);
                int topTwo = s.Peek();
                if(topOne >topTwo)
                {
                    s.Pop();
                    s.Push(topOne);
                    s.Push(topTwo);
                    return;
                }
            }
            s.Push(topOne);
        }

        public static void SortStack(Stack<int> s)
        {
            if(s.Count<=0)
            {
                return;
            }
            //把栈底元素移动到栈顶
            MoveBottonToTop(s);
            int top = s.Peek();
            s.Pop();
            //递归处理子栈
            SortStack(s);
            s.Push(top);
        }
    }
}
