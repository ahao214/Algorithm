using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    ///判断两个字符串的包含关系 
    /// </summary>
    public class TestIsContain
    {

        #region 直接法

        public static bool IsContain(String str1, String str2)
        {
            int len1 = str1.Length;
            int len2 = str2.Length;
            int i, j;
            //字符串ch1比ch2短
            if (len1 < len2)
            {
                for (i = 0; i < len1; i++)
                {
                    for (j = 0; j < len2; j++)
                    {
                        if (str1[i] == str2[j])
                            break;
                    }
                    if (j >= len2)
                        return false;
                }
            }
            else
            {
                //字符串ch1比ch2长
                for (i = 0; i < len2; i++)
                {
                    for (j = 0; j < len1; j++)
                    {
                        if (str1[j] == str2[i])
                            break;
                    }
                    if (j >= len1)
                        return false;
                }
            }
            return true;
        }

        #endregion


        #region 空间换时间法

        public static bool IsContainT(String str1, String str2)
        {
            int i;
            int k = 0;  //字母对应数组的下标
            int[] flag = new int[52];
            for (i = 0; i < 52; i++)
            {
                flag[i] = 0;
            }
            int count = 0;  //记录段字符串中不同字符出现的个数
            int len1 = str1.Length;
            int len2 = str2.Length;
            string shortStr, longStr;   //分别用来记录较短和较长的字符串
            int maxLen, minLen;         //分别用来记录较长和较短字符的长度
            if (len1 < len2)
            {
                shortStr = str1;
                minLen = len1;
                longStr = str2;
                maxLen = len2;
            }
            else
            {
                shortStr = str2;
                minLen = len2;
                longStr = str1;
                maxLen = len1;
            }
            //遍历短字符串
            for (i = 0; i < minLen; i++)
            {
                //把字符串换成数组对应的下标(大写字母0-25 小写字母26-51)
                if (shortStr[i] >= 'A' && shortStr[i] <= 'Z')
                    k = shortStr[i] - 'A';
                else
                    k = shortStr[i] - 'a' + 26;
                if (flag[k] == 0)
                {
                    flag[k] = 1;
                    count++;
                }
            }
            //遍历长字符串
            for (int j = 0; j < maxLen; j++)
            {
                if (longStr[j] >= 'A' & longStr[j] <= 'Z')
                {
                    k = longStr[i] - 'A';
                }
                else
                {
                    k = longStr[j] - 'a' + 26;
                }
                if (flag[k] == 1)
                {
                    flag[k] = 0;
                    count--;
                    if (count == 0)
                        return true;
                }
            }
            return false;
        }

        #endregion
    }
}
