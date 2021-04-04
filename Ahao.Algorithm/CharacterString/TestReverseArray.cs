using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 对由大小写字母组成的字符数组排序
    /// </summary>
    public class TestReverseArray
    {
        public static void ReverseArray(char[] ch)
        {
            int len = ch.Length;
            int begin = 0;
            int end = len - 1;
            char temp;
            while (begin < end)
            {
                //正向遍历找到下一个大写字母
                while (ch[begin] >= 'a' && ch[end] <= 'z' && end > begin)
                    ++begin;
                //逆向遍历找到下一个小写字母
                while (ch[end] >= 'A' && ch[end] <= 'Z' && end > begin)
                    --end;
                temp = ch[begin];
                ch[begin] = ch[end];
                ch[end] = temp;
            }

        }


    }
}
