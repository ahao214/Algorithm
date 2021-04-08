using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 进行字符串的串联
    /// </summary>
    public class TestMaxString
    {
        bool Isconnect(string str1, string str2)
        {
            if (str1.Length != str2.Length)
            {
                return false;
            }
            int m = str1.Length;
            for (int i = 0; i < m - 1; i++)
            {
                if (str1[i + 1] != str2[i])
                    return false;
            }
            return true;
        }

        public void MaxString(string[] arr)
        {
            int[][] G = new int[arr.Length][];
            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = 0; j < arr.Length; j++)
                {
                    if (Isconnect(arr[i], arr[j]))
                    {
                        //标记存在两点间连线
                        G[i][j] = 1;
                    }
                }
            }
            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = 0; j < arr.Length; j++)
                {
                    for (int k = 0; k < arr.Length; k++)
                    {
                        if (G[i][k] != 0 && G[k][j] != 0)
                        {
                            int dis = G[i][k] + G[k][j];
                            //计算最大路径
                            if (dis > G[i][j])
                                G[i][j] = dis;
                        }
                    }
                }
            }

            for (int i = 0; i < arr.Length; i++)
            {
                if (G[i][i] > 1)
                {
                    Console.WriteLine("存在环");
                    return;
                }
            }
            int max = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = 0; j < arr.Length; j++)
                {
                    if (G[i][j] > max)
                        max = G[i][j];
                }
            }
            Console.WriteLine("最大长度为：" + (max + arr[0].Length));
        }

    }
}
