using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 91.解码方法
    /// </summary>
    public class NumDecodings
    {
        public int Method(string s)
        {
            if (s[0] == '0')
                return 0;

            int pre = 1, cur = 1;

            //下标从1开始，0的情况已经考虑了
            for (int i = 1; i < s.Length; ++i)
            {
                //因为cur会发生变化，所以用一个变量提前保存
                int temp = cur;
                if (s[i] == '0')
                {
                    if (s[i - 1] != '1' && s[i - 1] != '2')
                        return 0;   //因为数字只有10和20符合要求，如果0的前面数字不是1或者不是2，则不符合
                    else
                        cur = pre;
                }
                //当前数字是0的时候，前一位数字只能是1或者2
                //当前数字是2的时候，后一位数字只能是1到6
                else if (s[i - 1] == '1' || (s[i - 1] == '2' && int.Parse("" + s[i]) > 0 && int.Parse("" + s[i]) < 7))
                {
                    cur = cur + pre;
                }
                pre = temp;
            }

            return cur;

        }
    }
}
