using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 如何计算两个单链表所代表的数之和
    /// </summary>
    public class TestAdd
    {

        #region 链表相加法

        public static LNode Add(LNode h1, LNode h2) 
        {
            if (h1 == null || h1.next == null)
            {
                return h2;
            }
            if (h2 == null || h2.next == null)
            {
                return h1;
            }
            int c = 0;  //用来记录进位
            int sum = 0;
            LNode p1 = h1.next;
            LNode p2 = h2.next;
            LNode tmp = null;
            LNode resultHead = new LNode();
            resultHead.next = null;
            LNode p = resultHead;
            while(p1!=null && p2!=null )
            {
                tmp = new LNode();
                tmp.next = null;
                sum = p1.data + p2.data + c;
                tmp.data = sum % 10;
                c = sum / 10;   //进位
                p.next = tmp;
                p = tmp;
                p1 = p1.next;
                p2 = p2.next;
            }
            //链表h2比h1长，接下来只需要考虑h2剩余结点的值
            if (p1==null)
            {
                while(p2!=null)
                {
                    tmp = new LNode();
                    tmp.next = null;
                    sum = p2.data + c;
                    tmp.data = sum % 10;
                    c = sum / 10;
                    p.next = tmp;
                    p = tmp;
                    p2 = p2.next;
                }
            }

            //链表h1比h2长，接下来只需要考虑h1剩余结点的值
            if(p2==null )
            {
                while(p1!=null)
                {
                    tmp = new LNode();
                    tmp.next = null;
                    sum = p1.data + c;
                    tmp.data = sum % 10;
                    c = sum / 10;
                    p.next = tmp;
                    p = tmp;
                    p1 = p1.next;
                }
            }
            //如果计算完成后还有进位，则增加新的结点
            if (c==1)
            {
                tmp = new LNode();
                tmp.next = null;
                tmp.data = 1;
                p.next = tmp;
            }
            return resultHead;
        }

        #endregion


        #region


        #endregion

    }
}
