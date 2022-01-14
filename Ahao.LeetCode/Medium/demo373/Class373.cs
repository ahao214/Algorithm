using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo373
{
    /// <summary>
    /// 373. 查找和最小的K对数字
    ///给定两个以升序排列的整数数组 nums1 和 nums2, 以及一个整数 k 。
    ///定义一对值(u, v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
    ///请找到和最小的 k 个数对(u1, v1),  (u2, v2)  ...  (uk, vk) 。
    /// </summary>
    public class Class373
    {
        /*
         输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
        输出: [1,2],[1,4],[1,6]
        解释: 返回序列中的前 3 对数：[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
         */
        public IList<IList<int>> KSmallestPairs(int[] nums1, int[] nums2, int k)
        {
            int m = nums1.Length;
            int n = nums2.Length;

            /*二分查找第 k 小的数对和的大小*/
            int left = nums1[0] + nums2[0];
            int right = nums1[m - 1] + nums2[n - 1];
            int pairSum = right;
            while (left <= right)
            {
                int mid = left + ((right - left) >> 1);
                long cnt = 0;
                int start = 0;
                int end = n - 1;
                while (start < nums1.Length && end >= 0)
                {
                    if (nums1[start] + nums2[end] > mid)
                    {
                        end--;
                    }
                    else
                    {
                        cnt += end + 1;
                        start++;
                    }
                }
                if (cnt < k)
                {
                    left = mid + 1;
                }
                else
                {
                    pairSum = mid;
                    right = mid - 1;
                }
            }

            IList<IList<int>> ans = new List<IList<int>>();
            int pos = n - 1;
            /*找到小于目标值 pairSum 的数对*/
            for (int i = 0; i < m; i++)
            {
                while (pos >= 0 && nums1[i] + nums2[pos] >= pairSum)
                {
                    pos--;
                }
                for (int j = 0; j <= pos && k > 0; j++, k--)
                {
                    IList<int> list = new List<int>();
                    list.Add(nums1[i]);
                    list.Add(nums2[j]);
                    ans.Add(list);
                }
            }
            /*找到等于目标值 pairSum 的数对*/
            pos = n - 1;
            for (int i = 0; i < m && k > 0; i++)
            {
                while (pos >= 0 && nums1[i] + nums2[pos] > pairSum)
                {
                    pos--;
                }
                for (int j = i; k > 0 && j >= 0 && nums1[j] + nums2[pos] == pairSum; j--, k--)
                {
                    IList<int> list = new List<int>();
                    list.Add(nums1[j]);
                    list.Add(nums2[pos]);
                    ans.Add(list);
                }
            }
            return ans;
        }
    }
}
