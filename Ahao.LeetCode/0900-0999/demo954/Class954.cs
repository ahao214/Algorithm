using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo954
{
    public class Class954
    {
        public bool CanReorderDoubled(int[] arr)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (int i in arr)
            {
                if (dic.ContainsKey(i))
                    dic[i]++;
                else
                    dic[i] = 1;
            }
            foreach (int key in dic.Keys.OrderBy(a => a))
            {
                if (dic[key] <= 0) continue;
                if (key == 0) //0只能和0本身配对，所以0的个数必须是偶数
                {
                    if ((dic[key] & 1) == 1) return false;
                    continue;
                }
                int i;
                if (key < 0)//排序后负数绝对值大的在前，所以找比当前负数绝对值小的负数配对
                {
                    if ((key * -1 & 1) == 1) return false;//奇负数无法配对
                    i = key / 2;
                }
                else //排序后正数绝对值小的在前，所以找比当前正数大的正数配对
                {
                    i = key * 2;
                }
                if (dic.ContainsKey(i) && dic[i] >= dic[key])//目标值的数量要大于等于当前值的数量
                {
                    dic[i] -= dic[key];
                    dic[key] = 0;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }


        public bool CanReorderDoubled2(int[] arr)
        {
            Dictionary<int, int> cnt = new Dictionary<int, int>();
            foreach (int x in arr)
            {
                if (!cnt.ContainsKey(x))
                {
                    cnt.Add(x, 1);
                }
                else
                {
                    ++cnt[x];
                }
            }
            if (cnt.ContainsKey(0) && cnt[0] % 2 != 0)
            {
                return false;
            }

            List<int> vals = new List<int>();
            foreach (int x in cnt.Keys)
            {
                vals.Add(x);
            }
            vals.Sort((a, b) => Math.Abs(a) - Math.Abs(b));

            foreach (int x in vals)
            {
                if ((cnt.ContainsKey(2 * x) ? cnt[2 * x] : 0) < cnt[x])
                { // 无法找到足够的 2x 与 x 配对
                    return false;
                }
                if (cnt.ContainsKey(2 * x))
                {
                    cnt[2 * x] -= cnt[x];
                }
                else
                {
                    cnt.Add(2 * x, -cnt[x]);
                }
            }
            return true;
        }

    }
}
