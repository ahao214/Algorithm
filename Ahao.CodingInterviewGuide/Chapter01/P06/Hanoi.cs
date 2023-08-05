using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter01.P06
{
    public class Hanoi
    {
        #region 递归方法

        public int HanoiProblem1(int num, string left, string mid, string right)
        {
            if (num < 1)
            {
                return 0;
            }
            return Process(num, left, mid, right, left, right);
        }


        public int Process(int num, string left, string mid, string right, string from, string to)
        {
            if (num == 1)
            {
                if (from.Equals(mid) || to.Equals(mid))
                {
                    Console.WriteLine("Move 1 from " + from + "to " + to);
                    return 1;
                }
                else
                {
                    Console.WriteLine("Move 1 from " + from + "to" + mid);
                    Console.WriteLine("Move 1 from " + mid + "to" + mid);
                    return 2;
                }
            }

            if (from.Equals(mid) || to.Equals(mid))
            {
                string another = (from.Equals(left) || to.Equals(left)) ? right : left;
                int part1 = Process(num - 1, left, mid, right, from, another);
                int part2 = 1;
                Console.WriteLine("Move" + num + "from " + from + "to" + to);
                int part3 = Process(num - 1, left, mid, right, another, to);
                return part1 + part2 + part3;
            }
            else
            {
                int part1 = Process(num - 1, left, mid, right, from, to);
                int part2 = 1;
                Console.WriteLine("Move" + num + "from " + from + "to" + mid);
                int part3 = Process(num - 1, left, mid, right, to, from);
                int part4 = 1;
                Console.WriteLine("Move" + num + "from " + mid + "to" + to);
                int part5 = Process(num - 1, left, mid, right, from, to);
                return part1 + part2 + part3 + part4 + part5;
            }

        }

        #endregion


        #region 非递归的方法——用栈来模拟整个过程

        public enum Action
        {
            No, LToM, MToL, MToR, RToM
        }

        public int HanoiProblem2(int num, string left, string mid, string right)
        {
            Stack<int> lS = new Stack<int>();
            Stack<int> mS = new Stack<int>();
            Stack<int> rS = new Stack<int>();
            lS.Push(int.MaxValue);
            mS.Push(int.MaxValue);
            rS.Push(int.MaxValue);

            for (int i = num; i > 0; i--)
            {
                lS.Push(i);
            }

            Action[] record = { Action.No };
            int step = 0;
            while (rS.Count != num + 1)
            {
                step += FStackToStack(record, Action.MToL, Action.LToM, lS, mS, left, mid);
                step += FStackToStack(record, Action.LToM, Action.MToL, mS, lS, mid, left);
                step += FStackToStack(record, Action.RToM, Action.MToR, mS, rS, mid, right);
                step += FStackToStack(record, Action.MToR, Action.RToM, rS, mS, right, mid);
            }
            return step;

        }

        public static int FStackToStack(Action[] record, Action preNoAct, Action nowAct, Stack<int> fStk, Stack<int> tStk, string from, string to)
        {
            if (record[0] != preNoAct && fStk.Peek() < tStk.Peek())
            {
                Console.WriteLine("Move" + tStk.Peek() + "from" + from + "to" + to);
                record[0] = nowAct;
                return 1;
            }
            return 0;
        }


        #endregion

    }
}
