using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo466
{
    public class Class466
    {
        public int GetMaxRepetitions(string s1, int n1, string s2, int n2)
        {
            // 题干
            // [str, n]表示字符串连续重复n次
            // 题目所求为：[s1,n1]最多包含多少个[s2,n2]
            // 即[s1,n1]包含s2的数量 / n2

            // 方法二：循环节
            // s1循环若干次后包含若干次s2，找到这个规律后即可快速计算


            int s1Len = s1.Length, s2Len = s2.Length;

            // 快速退出
            // s1空 或者 s2空 或者 [s2,n2]比[s1,n1]要长
            if (s1Len == 0 || s2Len == 0 || s1Len * n1 < s2Len * n2) return 0;

            // 另一种退出情况，s2中有s1中不存在的字符
            HashSet<char> set = new HashSet<char>();
            foreach (char c in s2) set.Add(c);
            foreach (char c in s1) set.Remove(c);
            if (set.Count > 0) return 0;

            // 如何寻找循环节? 整体思路如下
            // 对于每一个s1，记录最后一个匹配的s2字符(index)
            // 如果某一个s2字符再次出现，则标识一次循环，此时可以计算循环节大小

            // index：在单个s1中，最后一个匹配s2的字符的下标
            // s1Count: s1经过的数量， s2Count: s2经过的数量
            // 例子：s1 = abaacdbac; s2 = adcbd;
            // [s1,n1] = abaacdbac | abaacdbac | abaacdbac | abaacdbac | ...
            // [s2,n2] = a    d  c    b   d a         d  c    b   d a
            //                   ⬇          ⬇            ⬇          ⬇
            // index   =         2          0            2          0
            // s1Count =         1          2            3          4
            // s2Count =         0          1            1          2
            //                                           x (index 2 再次出现)
            // 此时s1循环数量为3-1=2； s2循环数量为1-0=1


            // 用于记录 index, s1Count s2Count
            // 最后求得循环节： 头部 (preLoop) + 循环体 (inLoop)
            int index = 0, s1Count = 0, s2Count = 0;
            int[] preLoop = new int[2], inLoop = new int[2];
            Dictionary<int, int[]> dict = new Dictionary<int, int[]>();

            // 开始寻找循环节
            while (true)
            {
                // 遍历一个s1
                s1Count++;
                for (int i = 0; i < s1Len; ++i)
                {
                    if (s1[i] == s2[index])
                    {
                        index++;
                        if (index == s2.Length)
                        {
                            s2Count++;
                            index = 0;
                        }
                    }
                }

                // 只有n1足够大时，必然存在循环节
                // 有可能所有s1遍历完，依然没有找到循环节
                if (s1Count == n1) return s2Count / n2;

                // 找到循环节，即index存在
                if (dict.ContainsKey(index))
                {
                    // 计算循环节长度

                    // 头部前x个s1包含y个s2
                    preLoop = new int[2] { dict[index][0], dict[index][1] };

                    // 循环部
                    inLoop = new int[2] { s1Count - dict[index][0], s2Count - dict[index][1] };

                    // 退出while(true)循环
                    break;
                }
                // else压入数据
                else dict[index] = new int[2] { s1Count, s2Count };
            }
            // 结束寻找循环节


            // 根据循环节长度，计算s2出现的次数
            // 注意需要考虑，[s1,n1]尾部会出现非完整的循环节
            int res = preLoop[1] + (n1 - preLoop[0]) / inLoop[0] * inLoop[1];

            // 尾部处理
            int tail = (n1 - preLoop[0]) % inLoop[0]; // 尾部字符包含s1的个数
            for (int i = 0; i < tail; ++i)
            {
                for (int j = 0; j < s1Len; ++j)
                {
                    if (s1[j] == s2[index])
                    {
                        index++;
                        if (index == s2Len)
                        {
                            res++;
                            index = 0;
                        }
                    }
                }
            }

            // [s1,n1]包含m个[s2,n2]
            // 即[s1,n1]包含m*n2个s2
            return res / n2;

        }


    }
}
