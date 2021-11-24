using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo423
{
    /// <summary>
    /// 423. 从英文中重建数字
    /// </summary>
    public class Class423
    {
        public string OriginalDigits(string s)
        {
            Dictionary<char, int> dic = new Dictionary<char, int>();
            foreach (char c in s)
            {
                if (!dic.ContainsKey(c))
                {
                    dic.Add(c, 0);
                }
                dic[c]++;
            }

            int[] cnt = new int[10];
            cnt[0] = dic.ContainsKey('z') ? dic['z'] : 0;
            cnt[2] = dic.ContainsKey('w') ? dic['w'] : 0;
            cnt[4] = dic.ContainsKey('u') ? dic['u'] : 0;
            cnt[6] = dic.ContainsKey('x') ? dic['x'] : 0;
            cnt[8] = dic.ContainsKey('g') ? dic['g'] : 0;

            cnt[3] = (dic.ContainsKey('h') ? dic['h'] : 0) - cnt[8];
            cnt[5] = (dic.ContainsKey('f') ? dic['f'] : 0) - cnt[4];
            cnt[7] = (dic.ContainsKey('s') ? dic['s'] : 0) - cnt[6];

            cnt[1] = (dic.ContainsKey('o') ? dic['o'] : 0) - cnt[0] - cnt[2] - cnt[4];

            cnt[9] = (dic.ContainsKey('i') ? dic['i'] : 0) - cnt[5] - cnt[6] - cnt[8];

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < cnt[i]; j++)
                {
                    sb.Append((char)(i + '0'));
                }
            }
            return sb.ToString();
        }
    }
}
