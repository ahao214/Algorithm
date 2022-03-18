using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1405
{
    /*
     1405. 最长快乐字符串
    如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符就是一个「快乐字符串」。
    给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：
    s 是一个尽可能长的快乐字符串。
    s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
    s 中只含有 'a'、'b' 、'c' 三种字母。
    如果不存在这样的字符串 s ，请返回一个空字符串 ""。
     */
    public class Class1405
    {
        public string LongestDiverseString(int a, int b, int c)
        {
            StringBuilder res = new StringBuilder();
            Pair[] arr = { new Pair(a, 'a'), new Pair(b, 'b'), new Pair(c, 'c') };

            while (true)
            {
                Array.Sort(arr, (p1, p2) => p2.Freq - p1.Freq);
                bool hasNext = false;
                foreach (Pair pair in arr)
                {
                    if (pair.Freq <= 0)
                    {
                        break;
                    }
                    int m = res.Length;
                    if (m >= 2 && res[m - 2] == pair.Ch && res[m - 1] == pair.Ch)
                    {
                        continue;
                    }
                    hasNext = true;
                    res.Append(pair.Ch);
                    pair.Freq--;
                    break;
                }
                if (!hasNext)
                {
                    break;
                }
            }

            return res.ToString();
        }
    }

    class Pair
    {
        public int Freq
        {
            get; set;
        }
        public char Ch
        {
            get; set;
        }

        public Pair(int Freq, char Ch)
        {
            this.Freq = Freq;
            this.Ch = Ch;
        }
    }
}
