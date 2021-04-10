using System;
using System.Collections.Generic;
using System.Data.OleDb;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 实现字符串的替换
    /// </summary>
    public class TestReplaceSpace
    {
        public void ReplaceSpace(char[] str)
        {
            //空格的数量
            int blankNumber = 0;
            //记录原字符串的有效长度
            int oldstringLen;
            //原字符串的长度
            int length = str.Length;
            //首先遍历原字符数组，找出字符数组的长度以及其中的空格数量
            for (oldstringLen = 0; str[oldstringLen] != '\0'; oldstringLen++)
            {
                if (str[oldstringLen] == ' ')
                    blankNumber++;
            }
            //根据原字符数组的长度和空格的数量可以求出最后新字符数组的长度
            int newstringLen = oldstringLen + blankNumber * 2;  //新字符串的长度
            if (newstringLen > length)
            {
                return;
            }

            str[newstringLen] = '\0';

            //设置两个指针point1和point2分别指向原字符数组和新字符数组的末尾位置
            int point1 = oldstringLen - 1, point2 = newstringLen - 1;
            while (point1 >= 0 && point2 > point1)
            {
                //两指针相同时，跳出循环
                if (str[point1] == ' ')
                {
                    //如果point1指向为空格，那么从point2开始赋值“02%”
                    str[point2--] = '0';
                    str[point2--] = '2';
                    str[point2--] = '%';
                }
                else
                {
                    //如果point1指向内容不为空格，那么将内容赋值给point2指向的位置
                    str[point2--] = str[point1];
                }
                point1--;   //不管是if还是else都要把point1前移，为了便于下一次的执行

            }
        }

    }
}
