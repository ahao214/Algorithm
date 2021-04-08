using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 找出字符串中连续最长的数字串
    /// </summary>
    public class TestFindMaxLength
    {
        public static int FindMaxLength(char[] arr)
        {
            //定义最大长度
            int max = 0;
            //定义计数器
            int count = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] >= '0' && arr[i] <= '9')
                {
                    count++;
                }
                else
                {
                    max = count > max ? count : max;
                    count = 0;
                }
            }
            return max;
        }
    }
}
