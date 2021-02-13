using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 翻转栈的所有元素
    /// </summary>
    public class TestMoveBottomToTop
    {
        /// <summary>
        /// 方法功能：把栈底元素移动到栈顶
        /// 参数：s 栈的引用
        /// </summary>
        /// <param name="s"></param>
        private static void MoveBottomToTop(Stack<int> s)
        {
            if (s == null || s.Count <= 0)
            {
                return;
            }
            int top1 = s.Peek();
            //弹出栈顶元素
            s.Pop();
            if (s.Count > 0)
            {
                //递归处理不包含栈顶元素的子栈
                MoveBottomToTop(s);
                int top2 = s.Peek();
                s.Pop();
                //交换栈顶元素与子栈顶元素
                s.Push(top1);
                s.Push(top2);
            }
            else
            {
                s.Push(top1);
            }
        }


        public static void Reverse(Stack<int> s)
        {
            if (s == null || s.Count <= 0)
            {
                return;
            }
            //把栈底元素移动到栈顶
            MoveBottomToTop(s);
            int top = s.Peek();
            s.Pop();
            //递归处理子栈
            Reverse(s);
            s.Push(top);
        }
    }
}
