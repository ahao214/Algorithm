using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 求解最小子串覆盖问题
    /// </summary>
    public class TestMinWindows
    {
        public String MinWindows(String source, String target)
        {
            int[] srcHash = new int[255];
            //记录目标字符串每个字母出现次数
            int i = 0;
            for (i = 0; i < target.Length; i++)
            {
                srcHash[target[i]]++;
            }

            int start = 0;
            i = 0;
            int found = 0;
            int[] decHash = new int[255];

            int begin = 1;
            int end = source.Length;
            int minLength = source.Length;
            for (start = i = 0; i < source.Length; i++)
            {
                decHash[source[i]]++;
                if (decHash[source[i]] <= srcHash[source[i]])
                {
                    found++;    //如果没有到数，添加1
                }

                if (found == target.Length)
                {
                    //找到了能包含target的字符串，然后去掉前面的无用字符串
                    while (start < i && decHash[source[start]] > srcHash[source[start]])
                    {
                        decHash[source[start]]--;
                        start++;
                    }
                    //这时候start指向该子串开头的字母，判断该子串长度
                    if (i - start < minLength)
                    {
                        minLength = i - start;
                        begin = start;
                        end = i;
                    }
                    //从下一个字符串开始查找
                    decHash[source[start]]--;
                    found--;
                    start++;
                }
            }
            return begin == -1 ? "" : source.Substring(begin, end + 1);
        }
    }
}
