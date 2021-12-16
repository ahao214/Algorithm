using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1518
{
    /// <summary>
    /// 1518. 换酒问题
    /// </summary>
    public class Class1518
    {
        public int NumWaterBottles(int numBottles, int numExchange)
        {
            //喝的酒瓶数量
            int result = numBottles;
            //剩余的酒瓶数量
            int rest = numBottles;
            while (rest >= numExchange)
            {
                int newBottles = rest / numExchange;
                result += newBottles;
                int mod = rest % numExchange;
                rest = mod + newBottles;
            }
            return result;
        }
    }
}
