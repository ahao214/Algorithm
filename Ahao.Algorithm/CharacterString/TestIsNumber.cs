using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 判断字符串是否是整数
    /// </summary>
    public class TestIsNumber
    {
        private bool Flag { get; set; }
        //判断c是否是数字，如果是返回true，如果不是返回false
        private bool IsNumber(char c)
        {
            return c >= '0' && c <= '9';
        }

        /// <summary>
        /// 判断str是否是数字，如果是返回数字，且设置flag=true，否则设置flag=false
        /// </summary>
        /// <param name="str"></param>
        /// <param name="length"></param>
        /// <returns></returns>
        private int strToInt(string str, int length)
        {
            if (length > 1)
            {
                if (!IsNumber(str[length - 1]))
                {
                    //不是数字
                    Console.WriteLine("不是数字");
                    Flag = false;
                    return -1;
                }
                return str[0] == '-' ?
                    strToInt(str, length - 1) * 10 - (str[length - 1] - '0') :
                    strToInt(str, length - 1) * 10 + str[length - 1] - '0';
            }
            else
            {
                if (str[0] == '-')
                {
                    return 0;
                }
                else
                {
                    if (!IsNumber(str[0]))
                    {
                        Console.WriteLine("不是数字");
                        Flag = false;
                        return -1;
                    }
                    return str[0] - '0';
                }
            }
        }

        public int strToint(String s)
        {
            Flag = true;
            if (s == null || s.Length <= 0 || (s[0] == '-' && s.Length == 1))
            {
                Console.WriteLine("不是数字");
                Flag = false;
                return -1;
            }
            if (s[0] == '+')
            {
                return strToInt(s.Substring(1, s.Length - 1), s.Length - 1);
            }
            else
            {
                return strToInt(s, s.Length);
            }
        }


    }
}
