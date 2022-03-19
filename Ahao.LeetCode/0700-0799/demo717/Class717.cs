using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo717
{
    /*
     717. 1比特与2比特字符
有两种特殊字符：

第一种字符可以用一个比特 0 来表示
第二种字符可以用两个比特(10 或 11)来表示、
给定一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一位字符，则返回 true 。
     */
    public class Class717
    {
        public bool IsOneBitCharacter(int[] bits)
        {
            int i = 0;
            while (i < bits.Length - 1)
            {
                i = bits[i] == 1 ? i + 2 : i + 1;
            }
            if (i == bits.Length - 1)
                return true;
            else
                return false;
        }
    }
}
