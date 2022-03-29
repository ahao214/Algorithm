using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo239
{
    public class Class239
    {
        public int[] MaxSlidingWindow(int[] nums, int k)
        {
            if (nums == null || nums.Length == 0 || k < 1)
                return null;
            if (k == 1)
                return nums;
            int n = nums.Length;
            int[] res = new int[n - k + 1];
            LinkedList<int> dq = new LinkedList<int>();
            for (int i = 0; i < n; i++)
            {
                if (dq.Count != 0 && dq.First.Value < (i - k + 1))
                {
                    dq.RemoveFirst();//超出窗口长度时删除队首
                }
                while (dq.Count != 0 && nums[i] >= nums[dq.Last.Value])
                {
                    dq.RemoveLast();//如果遍历的元素大于队尾元素就删除队尾
                }
                dq.AddLast(i);//添加
                if (i >= k - 1)
                {
                    res[i - k + 1] = nums[dq.First.Value];//结果
                }
            }
            return res;

        }


        /// <summary>
        /// 超出时间限制
        /// </summary>
        /// <param name="nums"></param>
        /// <param name="k"></param>
        /// <returns></returns>
        public int[] MaxSlidingWindow2(int[] nums, int k)
        {
            if (nums == null || nums.Length == 0 || k < 1)
                return nums;
            if (k == 1)
                return nums;

            int[] maxValue = new int[nums.Length - k + 1];

            //当前滑动窗口最大值的索引
            int maxIdx = 0;
            for (int i = 1; i < k; ++i)
            {
                if (nums[i] > nums[maxIdx])
                {
                    maxIdx = i;
                }
            }
            //left是滑动窗口的最左索引
            for (int left = 0; left < maxValue.Length; left++)
            {
                //right是滑动窗口的最右索引
                int right = left + k - 1;
                if (maxIdx < left)
                {
                    //最大值索引不在滑动窗口范围内
                    //求[left,right]内最大值的索引
                    maxIdx = left;
                    for (int i = left + 1; i <= right; i++)
                    {
                        if (nums[i] > nums[maxIdx])
                        {
                            maxIdx = i;
                        }
                    }
                }
                else if (nums[right] >= nums[maxIdx])
                {
                    maxIdx = right;
                }
                maxValue[left] = nums[maxIdx];
            }
            return maxValue;

        }
    }
}
