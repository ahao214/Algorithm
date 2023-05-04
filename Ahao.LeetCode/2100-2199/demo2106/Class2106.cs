using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2100_2199.demo2106
{
    public class Class2106
    {
        public int MaxTotalFruits(int[][] fruits, int startPos, int k)
        {
            int n = fruits.Length;
            int[] sum = new int[n + 1];
            int[] indices = new int[n];
            sum[0] = 0;
            for (int i = 0; i < n; i++)
            {
                sum[i + 1] = sum[i] + fruits[i][1];
                indices[i] = fruits[i][0];
            }
            int ans = 0;
            for (int x = 0; x <= k / 2; x++)
            {
                /* 向左走 x 步，再向右走 k - x 步 */
                int y = k - 2 * x;
                int left = startPos - x;
                int right = startPos + y;
                int start = LowerBound(indices, 0, n - 1, left);
                int end = UpperBound(indices, 0, n - 1, right);
                ans = Math.Max(ans, sum[end] - sum[start]);
                /* 向右走 x 步，再向左走 k - x 步 */
                y = k - 2 * x;
                left = startPos - y;
                right = startPos + x;
                start = LowerBound(indices, 0, n - 1, left);
                end = UpperBound(indices, 0, n - 1, right);
                ans = Math.Max(ans, sum[end] - sum[start]);
            }
            return ans;
        }

        public int LowerBound(int[] arr, int left, int right, int val)
        {
            int res = right + 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (arr[mid] >= val)
                {
                    res = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return res;
        }

        public int UpperBound(int[] arr, int left, int right, int val)
        {
            int res = right + 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (arr[mid] > val)
                {
                    res = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return res;
        }



        public int MaxTotalFruits2(int[][] fruits, int startPos, int k)
        {
            int left = 0;
            int right = 0;
            int n = fruits.Length;
            int sum = 0;
            int ans = 0;
            // 每次固定住窗口右边界
            while (right < n)
            {
                sum += fruits[right][1];
                // 移动左边界
                while (left <= right && Step(fruits, startPos, left, right) > k)
                {
                    sum -= fruits[left][1];
                    left++;
                }
                ans = Math.Max(ans, sum);
                right++;
            }
            return ans;
        }

        public int Step(int[][] fruits, int startPos, int left, int right)
        {
            if (fruits[right][0] <= startPos)
            {
                return startPos - fruits[left][0];
            }
            else if (fruits[left][0] >= startPos)
            {
                return fruits[right][0] - startPos;
            }
            else
            {
                return Math.Min(Math.Abs(startPos - fruits[right][0]), Math.Abs(startPos - fruits[left][0])) + fruits[right][0] - fruits[left][0];
            }
        }

    }
}
