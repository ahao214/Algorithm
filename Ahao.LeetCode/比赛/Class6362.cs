using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.比赛
{

    /*
     6362. 合并两个二维数组 - 求和法  

给你两个 二维 整数数组 nums1 和 nums2.

nums1[i] = [idi, vali] 表示编号为 idi 的数字对应的值等于 vali 。
nums2[i] = [idi, vali] 表示编号为 idi 的数字对应的值等于 vali 。
每个数组都包含 互不相同 的 id ，并按 id 以 递增 顺序排列。

请你将两个数组合并为一个按 id 以递增顺序排列的数组，并符合下述条件：

只有在两个数组中至少出现过一次的 id 才能包含在结果数组内。
每个 id 在结果数组中 只能出现一次 ，并且其对应的值等于两个数组中该 id 所对应的值求和。如果某个数组中不存在该 id ，则认为其对应的值等于 0 。
返回结果数组。返回的数组需要按 id 以递增顺序排列。


输入：nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
输出：[[1,6],[2,3],[3,2],[4,6]]
解释：结果数组中包含以下元素：
- id = 1 ，对应的值等于 2 + 4 = 6 。
- id = 2 ，对应的值等于 3 。
- id = 3 ，对应的值等于 2 。
- id = 4 ，对应的值等于5 + 1 = 6 。
     */
    public class Class6362
    {
        public int[][] MergeArrays(int[][] nums1, int[][] nums2)
        {
            int n1 = nums1.Length;
            int n2 = nums2.Length;
            int i1 = 0, i2 = 0;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < n1; i++)
            {
                dic.Add(nums1[i][0], nums1[i][1]);
            }
            for (int i = 0; i < n2; i++)
            {
                if (!dic.ContainsKey(nums2[i][0]))
                    dic.Add(nums2[i][0], nums2[i][1]);
                else
                    dic[nums2[i][0]] += nums2[i][1];
            }
            int[][] res = new int[dic.Count][];
            for (int i = 0; i < dic.Count; i++)
                res[i] = new int[2];
            while (i1 < n1 || i2 < n2)
            {
                if (i1 >= n1)
                {
                    res.Append(nums2[i2]);
                    i2++;
                    continue;
                }
                if (i2 >= n2)
                {
                    res.Append(nums1[i1]);
                    i1++;
                    continue;
                }
                if (nums1[i1][0] == nums2[i2][0])
                {
                    int[] newArr = new int[2];
                    newArr[0] = nums1[i1][0];
                    newArr[1] = nums1[i1][1] + nums2[i2][1];
                    res.Append(newArr);
                    i1++; i2++;
                }
                else if (nums1[i1][0] > nums2[i2][0])
                {
                    res.Append(nums2[i2]);
                    i2++;
                }
                else
                {
                    res.Append(nums1[i1]);
                    i1++;
                }
            }
            return res;




            //int[][] res = new int[dic.Count][];
            //for (int i = 0; i < dic.Count; i++)
            //{
            //    res[i] = new int[2];
            //}
            //int k = 0;
            //foreach (KeyValuePair<int, int> pair in dic)
            //{
            //    if (k < dic.Count)
            //    {
            //        res[k++][0] = pair.Key;
            //        res[k++][1] = pair.Value;
            //    }
            //}



            //return res;
        }
    }
}
