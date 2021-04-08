using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 从一个字符串中删除另一个字符串的所有的字符
    /// </summary>
    public class TestDeleteChars
    {
        public static void DeleteChars(char[] first, char[] second)
        {
            if (first.Length == 0 || second.Length == 0)
                return;

            //hashTable标记字符是否在字符串second中出现
            bool[] hashTable = new bool[256];
            int len1 = first.Length;
            int len2 = second.Length;
            //扫描字符串second，在hashTable中标记出现的字符
            for (int i = 0; i < len2; i++)
            {
                if (!hashTable[second[i]])
                {
                    hashTable[second[i]] = true;
                }
            }

            int fast = 0;
            int slow = 0;

            //删除first中出现在second中的字符
            while (fast < len1)
            {
                if (!hashTable[first[fast]])
                {
                    first[slow] = first[fast];
                    ++slow;
                }
                ++fast;
            }
            //针对后续字符做处理，防止后续内存中存在无效字符
            for (int i = slow; i < fast; i++)
            {
                first[i] = '\0';
            }
        }
    }
}
