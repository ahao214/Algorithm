using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 把数字转换为二级制
    /// </summary>
    public class TestConvetToBinary
    {
        public static String ConvetToBinary(decimal d)
        {
            int strInt = (int)d;
            decimal strDec = d - strInt;
            //利用C#内置函数实现整数部分的二进制转换
            var binaryInt = Convert.ToString(strInt, 2);
            var binaryDec = ConverToBinary_Dec(strDec, 2);
            return binaryInt + binaryDec;
        }

        /// <summary>
        /// 将小数部分转换为二级制
        /// </summary>
        /// <param name="d"></param>
        /// <param name="scale"></param>
        /// <returns></returns>
        private static String ConverToBinary_Dec(decimal d, int scale)
        {
            if (d == 0)
                return "";

            //为了防止程序因所转换的数据转换后的结果是一个无限循环的二级制小数，因此给器一个默认的精确到
            if (scale == 0)
                scale = (d.ToString().Length - 2) * 4;

            int index = 0;
            StringBuilder inteStr = new StringBuilder();
            decimal tempD = 0.0M;
            while (true)
            {
                if (d == 0 || index == scale)
                {
                    while (index % 4 != 0)
                    {
                        inteStr.Append("0");
                        index++;
                    }
                    break;
                }
                if (index == 0)
                {
                    inteStr.Append(".");
                }
                tempD = d * 2;
                inteStr.Append((int)tempD);
                d = tempD - (int)tempD;
                index++;
                if (index % 4 == 0)
                    inteStr.Append(" ");
            }
            return inteStr.ToString();
        }
    }
}
