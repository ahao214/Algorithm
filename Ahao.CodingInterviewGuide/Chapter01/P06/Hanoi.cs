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

    }
}
