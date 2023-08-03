using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter03.P01.递归方法
{

    public class PreOrder
    {
        /// <summary>
        /// 先序遍历
        /// </summary>
        /// <param name="head"></param>
        public void PreOrderRecur(Node head)
        {
            if (head == null)
            {
                return;
            }

            Console.WriteLine(head.value + " ");
            PreOrderRecur(head.left);
            PreOrderRecur(head.right);
        }
    }
}
