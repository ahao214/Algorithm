using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 判断字符串A中是否包含有字符串B中字符重新排列成的新字符串
    /// </summary>
    public class TestContin
    {
        public static bool Contin(string str1, string str2)
        {
            if (str1.Length < str2.Length)
            {
                return false;
            }

            if (str2.Length == 0)
            {
                return true;
            }

            //字典A
            Dictionary<char, int> aMap = new Dictionary<char, int>();
            //字典B
            Dictionary<char, int> bMap = new Dictionary<char, int>();
            //初始化字典A数据
            foreach (var item in str1)
            {
                if (aMap.ContainsKey(item))
                {
                    aMap[item] = aMap[item] + 1;
                }
                else
                {
                    aMap[item] = 1;
                }
            }
            //初始化字典B数据
            foreach (var item in str2)
            {
                if (bMap.ContainsKey(item))
                {
                    bMap[item] = bMap[item] + 1;
                }
                else
                {
                    bMap[item] = 1;
                }
            }
            //判断字段B中的key是否完全出现在A中
            foreach (var item in bMap)
            {
                if (aMap.ContainsKey(item.Key))
                {
                    return aMap[item.Key] >= item.Value;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }

    }
}
