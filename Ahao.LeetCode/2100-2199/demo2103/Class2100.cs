using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    public class Class2103
    {
        const int POLE_NUM = 10;
        const int COLOR_NUM = 3;

        public int CountPoints(string rings)
        {
            int[][] state = new int[POLE_NUM][];
            for (int i = 0; i < POLE_NUM; i++)
            {
                state[i] = new int[COLOR_NUM];
            }
            int n = rings.Length;
            for (int i = 0; i < n; i += 2)
            {
                char color = rings[i];
                int poleIndex = rings[i + 1] - '0';
                state[poleIndex][GetColorId(color)] = 1;
            }
            int res = 0;
            for (int i = 0; i < POLE_NUM; i++)
            {
                bool flag = true;
                for (int j = 0; j < COLOR_NUM; j++)
                {
                    if (state[i][j] == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    res++;
                }
            }
            return res;
        }

        public int GetColorId(char color)
        {
            if (color == 'R')
            {
                return 0;
            }
            else if (color == 'G')
            {
                return 1;
            }
            return 2;
        }




        const int POLE_NUM1 = 10;

        public int CountPoints2(string rings)
        {
            int[] state = new int[POLE_NUM1];
            int n = rings.Length;
            for (int i = 0; i < n; i += 2)
            {
                char color = rings[i];
                int poleIndex = rings[i + 1] - '0';
                if (color == 'R')
                {
                    state[poleIndex] |= 1;
                }
                else if (color == 'G')
                {
                    state[poleIndex] |= 2;
                }
                else
                {
                    state[poleIndex] |= 4;
                }
            }
            int res = 0;
            for (int i = 0; i < POLE_NUM; i++)
            {
                res += state[i] == 7 ? 1 : 0;
            }
            return res;
        }


    }
}
