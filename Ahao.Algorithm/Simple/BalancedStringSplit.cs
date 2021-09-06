using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 1221. 分割平衡字符串
    /// </summary>
   public  class BalancedStringSplit
    {
        public int Method (string s)
        {
            int result = 0, word = 0;
            foreach(char item in s)
            {
                if(item=='L')
                {
                    word++;
                }
                else
                {
                    word--;
                }
                if(word ==0)
                {
                    result++;
                }
            }
            return result;
        }
    }
}
