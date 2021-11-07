using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary.LC299
{
    /// <summary>
    /// 299. 猜数字游戏
    /// </summary>
    public class Class299
    {
        public string GetHint(string secret, string guess)
        {
            int bulls = 0;
            int[] cntS = new int[10];
            int[] cntG = new int[10];
            for (int i = 0; i < secret.Length; i++)
            {
                if (secret[i] == guess[i])
                {
                    ++bulls;
                }
                else
                {
                    ++cntS[secret[i] - '0'];
                    ++cntG[guess[i] - '0'];
                }
            }
            int cows = 0;
            for (int i = 0; i < 10; i++)
            {
                cows += Math.Min(cntS[i], cntG[i]);
            }
            return bulls.ToString() + "A" + cows.ToString() + "B";
        }
    }
}
