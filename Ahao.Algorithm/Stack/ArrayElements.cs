using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Stack
{
    /// <summary>
    /// 从数组中找出满足a+b=c+d的两个数对
    /// </summary>
    public class ArrayElements
    {
        public bool findPairs(int[] arr)
        {
            //键为数对的和，值为数对
            Dictionary<int, Pair> sumPair = new Dictionary<int, Pair>();
            int n = arr.Length;

            //遍历数组中所有可能的数对
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    //如果这个数对的和在map中没有，则放入map中
                    int sum = arr[i] + arr[j];
                    if (!sumPair.ContainsKey(sum))
                    {
                        sumPair.Add(sum, new Pair(i, j));
                    }
                    //map中已经存在于sum相同的数对了，找出来并打印出来
                    else
                    {
                        //找出已经遍历过的并存储在map中和为sum的数对
                        Pair p = sumPair[sum];
                        Console.WriteLine("(" + arr[p.First] + "," + arr[p.Second] + "),(" + arr[i] + "," + arr[j] + ")");
                        return true;
                    }
                }
            }
            return false;
        }
    }

    public class Pair
    {
        public int First { get; set; }

        public int Second { get; set; }
        public Pair(int first, int second)
        {
            this.First = first;
            this.Second = second;
        }
    }

}
