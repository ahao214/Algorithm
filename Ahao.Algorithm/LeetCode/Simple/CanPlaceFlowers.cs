using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 605.种花问题
    /// </summary>
    public class CanPlaceFlowers
    {
        public bool Method(int[] flowerbed, int n)
        {
            int count = 0, num = 0;
            var temp = new int[flowerbed.Length + 2];
            temp[0] = 0;
            temp[temp.Length - 1] = 0;
            for (int i = 0; i < flowerbed.Length; i++)
            {
                temp[i + 1] = flowerbed[i];
            }
            for (int i = 0; i < temp.Length; i++)
            {
                if (temp[i] == 0)
                {
                    count++;
                    if (count == 3)
                    {
                        num++;
                        count = 0;
                        i = i - 1;
                    }
                }
                else
                {
                    count = 0;
                }
            }
            return num >= n;
        }
    }
}
