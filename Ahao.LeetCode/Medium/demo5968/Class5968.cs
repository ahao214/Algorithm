using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo5968
{
    /// <summary>
    /// 5968. 银行中的激光束数量
    /// </summary>
    public class Class5968
    {
        public int NumberOfBeams(string[] bank)
        {
            int n = bank.Length;
            int m = bank[0].Length;
            int Ans = 0;
            int last = 0; //上一行里面1的个数
            for (int i = 0; i < n; ++i)
            {
                int cnt = 0; //当前行里面1的个数
                //遍历每一行,获取1的个数
                for (int j = 0; j < m; ++j)
                {
                    if (bank[i][j] == '1')
                    {
                        cnt++;
                    }
                }
                if (cnt != 0)
                {
                    //当前行里面1的个数*上一行里面1的个数
                    Ans += last * cnt;
                    last = cnt;
                }
            }
            return Ans;
        }
    }
}
