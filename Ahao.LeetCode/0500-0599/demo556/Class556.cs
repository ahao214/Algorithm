using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0500_0599.demo556
{
    public class Class556
    {
        /// <summary>
        /// 下一排列
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public int NextGreaterElement(int n)
        {
            char[] nums = n.ToString().ToCharArray();
            int i = nums.Length - 2;
            while (i >= 0 && nums[i] >= nums[i + 1])
            {
                i--;
            }
            if (i < 0)
            {
                return -1;
            }

            int j = nums.Length - 1;
            while (j >= 0 && nums[i] >= nums[j])
            {
                j--;
            }
            Swap(nums, i, j);
            Reverse(nums, i + 1);
            long ans = long.Parse(new string(nums));
            return ans > int.MaxValue ? -1 : (int)ans;
        }

        public void Reverse(char[] nums, int begin)
        {
            int i = begin, j = nums.Length - 1;
            while (i < j)
            {
                Swap(nums, i, j);
                i++;
                j--;
            }
        }

        public void Swap(char[] nums, int i, int j)
        {
            char temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }


        /// <summary>
        /// 数学
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public int NextGreaterElement2(int n)
        {
            int x = n, cnt = 1;
            for (; x >= 10 && x / 10 % 10 >= x % 10; x /= 10)
            {
                ++cnt;
            }
            x /= 10;
            if (x == 0)
            {
                return -1;
            }

            int targetDigit = x % 10;
            int x2 = n, cnt2 = 0;
            for (; x2 % 10 <= targetDigit; x2 /= 10)
            {
                ++cnt2;
            }
            x += x2 % 10 - targetDigit; // 把 x2 % 10 换到 targetDigit 上

            for (int i = 0; i < cnt; ++i, n /= 10)
            { // 反转 n 末尾的 cnt 个数字拼到 x 后
                int d = i != cnt2 ? n % 10 : targetDigit;
                if (x > int.MaxValue / 10 || x == int.MaxValue / 10 && d > 7)
                {
                    return -1;
                }
                x = x * 10 + d;
            }
            return x;
        }

    }
}
