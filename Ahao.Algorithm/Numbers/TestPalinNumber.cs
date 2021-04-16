using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Numbers
{
    /// <summary>
    /// 判断一个数是否是回文数
    /// </summary>
    public class TestPalinNumber
    {
        public static bool PalinNumber(int n)
        {
            int original = n;
            long m = 0;
            int result = 0;
            while (n != 0)
            {
                m = m * 10 + n % 10;
                n = n / 10;
            }
            if (m > int.MaxValue)
            {
                result = 0;
            }
            else
            {
                result = (int)m;
            }
            if (result == original)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


        public static bool PalinNum(int n)
        {
            bool result = false;
            string strNum = n.ToString();
            int len = strNum.Length;
            int left = 0;
            int right = len - 1;
            for (int i = 0; i < len / 2; i++)
            {
                if (strNum[left] == strNum[right])
                {
                    left++;
                    right--;
                    result = true;
                    continue;
                }
                else
                {
                    result = false;
                    break;
                }
            }
            
            return result;
        }

    }
}
