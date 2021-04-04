using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 求两个字符串的最长公共子串
    /// </summary>
    public class TestGetMaxSubStr
    {
        #region 动态规划法
        public static String GetMaxSubStr(String str1, String str2)
        {
            int lenone = str1.Length;
            int lentwo = str2.Length;
            StringBuilder sb = new StringBuilder("");
            int i, j, max = 0;  //max用来记录最长公共字串的长度
            int max1 = 0;   //用来记录最长公共字串最后一个字符的位置
            int[,] M = new int[lenone + 1, lentwo + 2];
            for (i = 0; i < lenone + 1; i++)
            {
                M[i, 0] = 0;
            }
            for (j = 0; j < lentwo + 1; j++)
            {
                M[0, j] = 0;
            }

            //通过利用递归公式填写新建的二维数组
            for (i = 1; i < lenone + 1; i++)
            {
                for (j = 1; j < lentwo + 1; j++)
                {
                    if (str1[i - 1] == str2[j - 1])
                    {
                        M[i, j] = M[i - 1, j - 1] + 1;
                        if (M[i, j] > max)
                        {
                            max = M[i, j];
                            max1 = i;
                        }
                    }
                    else
                    {
                        M[i, j] = 0;
                    }
                }
            }
            //找出公共字串
            for (i = max1 - max; i < max1; i++)
            {
                sb.Append(str1[i]);
            }
            return sb.ToString();



        }

        #endregion

        #region 滑动比较法

        public static String GetMaxSubStrHD(String str1, String str2)
        {
            int lenone = str1.Length;
            int lentwo = str2.Length;
            int i, j;
            int s1begin, s2begin;
            int maxLen = 0, tmpMaxLen = 0;
            int maxLenEnd1 = 0;
            StringBuilder sb = new StringBuilder("");
            for (i = 0; i < lenone + lentwo; i++)
            {
                s1begin = s2begin = 0;
                tmpMaxLen = 0;
                if (i < lenone)
                    s1begin = lenone - i;
                else
                    s2begin = i - lenone;
                for (j = 0; (s1begin + j < lenone) && (s2begin + j < lentwo); j++)
                {
                    if (str1[s1begin + j] == str2[s2begin + j])
                        tmpMaxLen++;
                    else
                    {
                        if (tmpMaxLen > maxLen)
                        {
                            maxLen = tmpMaxLen;
                            maxLenEnd1 = s1begin + j;
                        }
                        else
                        {
                            tmpMaxLen = 0;
                        }
                    }
                }
                if (tmpMaxLen > maxLen)
                {
                    maxLen = tmpMaxLen;
                    maxLenEnd1 = s1begin + j;
                }
            }
            for (i = maxLenEnd1 - maxLen; i < maxLenEnd1; i++)
            {
                sb.Append(str1[i]);
            }
            return sb.ToString();


            #endregion
        }
    }
}
