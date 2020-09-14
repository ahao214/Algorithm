using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Ahao.Algorithm
{
    class Program
    {
        static void Main(string[] args)
        {

            #region 238.除自身以外数组的乘积

            //int[] nums = { 1, 2, 3, 4 };
            //_238 a = new _238();
            //int[] newNums = a.productExceptSelf(nums);

            #endregion

            #region 丑数

            //IsUgly isUgly = new IsUgly();
            //bool result = isUgly.Method(3);
            //WriteLine(result);

            #endregion

            #region 平方数之和
            //JudgeSquareSum judgeSquareSum = new JudgeSquareSum();
            //for(int i=1;i<101;i++)
            //{
            //    WriteLine($"当前值{i}是否是：" + judgeSquareSum.Method(i));
            //}

            //WriteLine(judgeSquareSum.Method(int.MaxValue));

            #endregion

            #region 最佳观光组合

            //MaxScoreSightseeingPair maxScoreSightseeingPair = new MaxScoreSightseeingPair();
            //int[] a = { 8, 1, 5, 2, 6 };
            //int value = maxScoreSightseeingPair.Method(a);
            //Console.WriteLine(value);

            #endregion

            #region 215. 数组中的第K个最大元素

            //FindKthLargest findKthLargest = new FindKthLargest();
            //int[] nums = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
            //int k = 2;
            //findKthLargest.Method(nums, k);

            #endregion

            #region 217.存在重复元素

            //int[] nums = { 1, 3, 4, 5, 2 };
            //ContainsDuplicate containsDuplicate = new ContainsDuplicate();
            //Console.WriteLine(containsDuplicate.Method(nums));

            #endregion

            #region 657.机器人能否返回原点

            //JudgeCircle judgeCircle = new JudgeCircle();
            //string moves = "lrudd";
            //Console.WriteLine(judgeCircle.Method(moves));


            #endregion

            #region 60.第K个排列

            //GetPermutation getPermutation = new GetPermutation();
            //Console.WriteLine(getPermutation.Method(3, 6));

            #endregion

            #region 107. 二叉树的层次遍历 II



            #endregion

            #region 347.前K个高频元素

            //TopKFrequent topKFrequent = new TopKFrequent();
            //int[] nums = { 4, 1, -1, 2, -1, 2, 3 ,0,0};
            //int k = 3;
            //int[] newNums = topKFrequent.Method(nums, k);
            //foreach(var item in newNums)
            //{
            //    WriteLine(item);
            //}

            #endregion

            #region 77.组合

            //int n = 4;
            //int k = 2;
            //Combine combine = new Combine();
            //combine.Method(n, k);

            #endregion

            #region 39.组合综合

            //int[] candidates = { 2, 3, 5 };
            //int target = 7;
            //CombinationSum combinationSum = new CombinationSum();
            //combinationSum.Method(candidates, target);

            #endregion

            #region 40.组合总和(二)

            //int[] candidates = { 2, 5, 2, 1, 2 };
            //int target = 5;
            //CombinationSum2 combinationSum2 = new CombinationSum2();
            //combinationSum2.Method(candidates, target);

            #endregion

            #region 216.组合总和(三

            //CombinationSum3 combinationSum3 = new CombinationSum3();
            //int k = 9;
            //int n = 7;
            //combinationSum3.Method(k, n);

            #endregion

            #region 637. 二叉树的层平均值



            #endregion

            #region 79.单词搜索



            #endregion

            #region 13.罗马数字转整数

            //RomanToInt romanToInt = new RomanToInt();
            //string s = "III";
            //Console.WriteLine(romanToInt.Method(s));

            #endregion

            #region 14. 最长公共前缀

            //string[] strs = { "flower", "fo", "foo" };
            //LongestCommonPrefix longestCommonPrefix = new LongestCommonPrefix();
            //Console.WriteLine(longestCommonPrefix.Method(strs));

            #endregion

            #region 724. 寻找数组的中心索引

            //PivotIndex pivotIndex = new PivotIndex();
            //int[] nums = { -1, -1, 0, 0, -1, -1 };
            //Console.WriteLine("打印出第一个中心索引");
            //Console.WriteLine(pivotIndex.Method(nums));

            //Console.WriteLine("-----------------");
            //Console.WriteLine("打印出所有的中心索引");
            //List<int> result = pivotIndex.Method2(nums);
            //foreach(var item in result)
            //{
            //    Console.WriteLine(item);
            //}

            #endregion


            #region  202.快乐数

            IsHappy isHappy = new IsHappy();
            Console.WriteLine(isHappy.Method(123));

            #endregion


            ReadLine();
        }
    }
}
