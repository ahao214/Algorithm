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
            bool result = true;
            for (int i = 0; i < s.Length / 2; i++)
            {
                if (s.Substring(i, 1) != s.Substring(s.Length - 1 - i, 1))
                {
                    result = false;
                }
            }
            return result;
        }
    }
}
