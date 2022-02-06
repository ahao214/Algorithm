using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    /*
     6001. 重排数字的最小值
给你一个整数 num 。重排 num 中的各位数字，使其值 最小化 且不含 任何 前导零。

返回不含前导零且值最小的重排数字。

注意，重排各位数字后，num 的符号不会改变。
     */
    public class Class6001
    {
        public long SmallestNumber(long num)
        {
            if (num ==0)
            {
                return 0;
            }
            long res = 0;            
            long oldNum = num;
            if (oldNum < 0)
            {
                oldNum = -oldNum;
            }

            List<long> lst = new List<long>();
            while (oldNum != 0)
            {
                lst.Add(oldNum % 10);
                oldNum /= 10;
            }
            lst.Sort();
            if (num < 0)
            {
                for (int i = lst.Count - 1; i >= 0; i--)
                {                   
                    res = res * 10 + lst[i];
                }                
                res = -res;
            }
            else
            {
                if (lst[0] == 0)
                {
                    for (int i = 0; i < lst.Count; i++)
                    {
                        if (lst[i] > 0)
                        {
                            long tmp = lst[0];
                            lst[0] = lst[i];
                            lst[i] = tmp;
                            break;
                        }
                    }
                }
                for (int i = 0; i < lst.Count; i++)
                {                  
                    res = res * 10 + lst[i];
                }                
            }
            return res;
        }
    }
}
