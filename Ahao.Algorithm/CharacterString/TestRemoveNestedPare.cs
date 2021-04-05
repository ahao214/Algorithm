using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 去掉字符串中嵌套的括号
    /// </summary>
    public class TestRemoveNestedPare
    {
        public static string RemoveNestedPare(string str)
        {
            if (str == null)
                return str;
            int Parentheses_num = 0;    //用来记录不匹配的"("出现的次数
            if (str[0] != '(' || str[str.Length - 1] != ')')
            {
                return null;
            }
            StringBuilder sb = new StringBuilder("(");
            char ch;
            //字符串首位的括号可以单独处理
            for (int i = 0; i < str.Length; i++)
            {
                ch = str[i];
                if (ch == '(')
                {
                    Parentheses_num++;
                }
                else if (ch == ')')
                {
                    Parentheses_num--;
                }
                else
                {
                    sb.Append(str[i]);
                }
            }
            //判断括号是否匹配
            if (Parentheses_num != 0)
            {
                Console.WriteLine("由于括号不匹配，因此不做任何操作");
                return null;
            }
            //处理字符串结尾的')'
            sb.Append(')');
            return sb.ToString();
        }

    }
}
