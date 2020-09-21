using System;
using System.Text.RegularExpressions;


namespace Ahao.Algorithm
{
    /// <summary>
    /// 125.验证回文串
    /// </summary>
    public class IsPalindrome
    {
        public bool Method(string s)
        {
            //使用正则表达式
            s = Regex.Replace(s, "[^A-Za-z0-9]", "").ToLower();

            #region 第一种

            //bool result = true;
            //for (int i = 0; i < s.Length / 2; i++)
            //{
            //    if (s.Substring(i, 1) != s.Substring(s.Length - 1 - i, 1))
            //    {
            //        result = false;
            //    }
            //}
            //return result;

            #endregion

            #region 第二种

            bool result = true;
            string half = s.Substring(0, s.Length / 2);

            char[] item = half.ToCharArray();
            Array.Reverse(item);
            string newHalf = new string(item);
            int middle = s.Length / 2;
            if (s.Length % 2 == 1)
            {
                middle += 1;
            }
            if (newHalf != s.Substring(middle))
            {
                result = false;
            }
            return result;

            #endregion
        }
    }
}
