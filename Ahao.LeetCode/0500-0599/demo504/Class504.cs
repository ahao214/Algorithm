using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo504
{
    public class Class504
    {
        public string ConvertToBase7(int num)
        {
            if (num == 0)
                return "0";
            var isNeg = num < 0;
            num = Math.Abs(num);
            var lstNum = new List<int>();
            while (num != 0)
            {
                lstNum.Add(num % 7);
                num /= 7;
            }
            lstNum.Reverse();
            var res = string.Join("", lstNum);
            //是负数
            if (isNeg)
                res = "-" + res;
            return res;
        }
    }
}
