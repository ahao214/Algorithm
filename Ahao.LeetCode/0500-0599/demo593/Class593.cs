using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0500_0599.demo593
{
    public class Class593
    {
        public bool ValidSquare(int[] p1, int[] p2, int[] p3, int[] p4)
        {
            if (p1[0] == p2[0] && p1[1] == p2[1])
            {
                return false;
            }
            if (Help(p1, p2, p3, p4))
            {
                return true;
            }
            if (p1[0] == p3[0] && p1[1] == p3[1])
            {
                return false;
            }
            if (Help(p1, p3, p2, p4))
            {
                return true;
            }
            if (p1[0] == p4[0] && p1[1] == p4[1])
            {
                return false;
            }
            if (Help(p1, p4, p2, p3))
            {
                return true;
            }
            return false;
        }

        public bool Help(int[] p1, int[] p2, int[] p3, int[] p4)
        {
            int[] v1 = { p1[0] - p2[0], p1[1] - p2[1] };
            int[] v2 = { p3[0] - p4[0], p3[1] - p4[1] };
            if (CheckMidPoint(p1, p2, p3, p4) && CheckLength(v1, v2) && CalCos(v1, v2))
            {
                return true;
            }
            return false;
        }

        public bool CheckLength(int[] v1, int[] v2)
        {
            return (v1[0] * v1[0] + v1[1] * v1[1]) == (v2[0] * v2[0] + v2[1] * v2[1]);
        }

        public bool CheckMidPoint(int[] p1, int[] p2, int[] p3, int[] p4)
        {
            return (p1[0] + p2[0]) == (p3[0] + p4[0]) && (p1[1] + p2[1]) == (p3[1] + p4[1]);
        }

        public bool CalCos(int[] v1, int[] v2)
        {
            return (v1[0] * v2[0] + v1[1] * v2[1]) == 0;
        }


        public bool ValidSquare2(int[] p1, int[] p2, int[] p3, int[] p4)
        {
            int[] lens = new int[6];
            lens[0] = getLen(p1, p2);
            lens[1] = getLen(p1, p3);
            lens[2] = getLen(p1, p4);
            lens[3] = getLen(p2, p4);
            lens[4] = getLen(p2, p3);
            lens[5] = getLen(p3, p4);

            for (int i = 0; i < 6; i++)
            {
                if (lens[i] == 0)
                {
                    return false;
                }
            }

            Array.Sort(lens);
            if (lens[0] == lens[1])
                if (lens[0] == lens[1] && lens[1] == lens[2] && lens[2] == lens[3] && lens[4] == lens[5] && lens[0] * 2 == lens[5])
                {
                    return true;
                }
            return false;
        }

        private int getLen(int[] p1, int[] p2)
        {
            return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
        }
    }
}
