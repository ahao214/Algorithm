using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1576
{
    /// <summary>
    /// 1576. 替换所有的问号
    /// </summary>
    public class Class1576
    {
        public string ModifyString(string s)
        {
            if (s == "?")
            {
                return "a";
            }

            char[] chars = s.ToCharArray();

            for (int i = 0; i < chars.Length; i++)
            {
                if (chars[i] == '?')
                {
                    //前面一个字符  如果当前是第0个的话 字符就为‘ ’
                    char ahead = i == 0 ? ' ' : chars[i - 1];
                    //后面一个字符  如果当前是最后一个的话 字符就为‘ ’
                    char behind = i == chars.Length - 1 ? ' ' : chars[i + 1];
                    //从a开始比较  如果等于前面或者后面的话 就+1
                    char temp = 'a';
                    while (temp == ahead || temp == behind)
                    {
                        temp++;
                    }
                    //找到目标字符后 做替换
                    chars[i] = temp;
                }
            }
            return new String(chars);
        }
    }
}
