using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 找到数组删除K个数字之后的最小正整数
    /// </summary>
    public class TestDeleteKNumbers
    {
        public string DeleteKNumbers(string str, int k)
        {
            StringBuilder sb = new StringBuilder(str);
            int start = 0;
            bool flag;
            for (int i = k; i > 0; i--)
            {
                flag = false;
                for (start = 0; start < str.Length - 1; start++)
                {
                    if (sb[start] > sb[start + 1])  //每次删除第一个比下一个数字大的数
                    {
                        sb.Remove(start, 1);
                        flag = true;
                        break;
                    }
                }
                if (!flag) //如果所有数字递增，则删除最后几个数字后直接返回
                {
                    sb.Remove(str.Length - k, k);
                    break;
                }
            }
            return sb.ToString();
        }

    }
}
