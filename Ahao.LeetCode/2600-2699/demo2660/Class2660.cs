using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RTools_NTS.Util;

namespace Ahao.LeetCode._2600_2699.demo2660
{
    public class Class2660
    {
        public int IsWinner(int[] player1, int[] player2)
        {
            int sumOne = 0;
            int sumTow = 0;
            for (int i = 0; i < player1.Length; i++)
            {
                if ((i - 1 >= 0 && player1[i - 1] == 10) || (i - 2 >= 0 && player1[i - 2] == 10))
                {
                    sumOne += player1[i] * 2;
                }
                else
                {
                    sumOne += player1[i];
                }
            }
            for (int i = 0; i < player2.Length; i++)
            {
                if ((i - 1 >= 0 && player2[i - 1] == 10) || (i - 2 >= 0 && player2[i - 2] == 10))
                {
                    sumTow += player2[i] * 2;
                }
                else
                {
                    sumTow += player2[i];
                }
            }
            int res = 0;

            if (sumOne > sumTow)
                res = 1;
            if (sumOne < sumTow)
                res = 2;
            return res;
        }


        public int IsWinner2(int[] player1, int[] player2)
        {
            int s1 = Score(player1);
            int s2 = Score(player2);
            return s1 == s2 ? 0 : s1 > s2 ? 1 : 2;
        }

        public int Score(int[] player)
        {
            int res = 0;
            for (int i = 0; i < player.Length; i++)
            {
                if ((i > 0 && player[i - 1] == 10) || (i > 1 && player[i - 2] >= 10))
                {
                    res += 2 * player[i];
                }
                else
                {
                    res += player[i];
                }
            }
            return res;
        }


    }
}
