﻿using Ahao.Algorithm.Simple;
using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace Ahao.Algorithm
{
    class Program
    {
        static void Main(string[] args)
        {

            #region 238.除自身以外数组的乘积

            //int[] nums = { 1, 2, 3, 4 };
            //ProductExceptSelf productExceptSelf = new ProductExceptSelf();
            //int[] newNums = productExceptSelf.productExceptSelf(nums);

            #endregion

            #region 363.丑数

            //IsUgly isUgly = new IsUgly();
            //bool result = isUgly.Method(3);
            //WriteLine(result);

            #endregion

            #region 633.平方数之和

            //JudgeSquareSum judgeSquareSum = new JudgeSquareSum();
            //for(int i=1;i<101;i++)
            //{
            //    WriteLine($"当前值{i}是否是：" + judgeSquareSum.Method(i));
            //}
            //WriteLine(judgeSquareSum.Method(int.MaxValue));

            #endregion

            #region 1014.最佳观光组合

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

            //IsHappy isHappy = new IsHappy();
            //Console.WriteLine(isHappy.Method(123));

            #endregion

            #region 37.解数独

            //SolveSudoku solveSudoku = new SolveSudoku();
            //char[][] board = null;

            #endregion

            #region 58. 最后一个单词的长度

            //LengthOfLastWord lengthOfLastWord = new LengthOfLastWord();
            //Console.WriteLine(lengthOfLastWord.Method("hello world"));

            #endregion

            #region 231. 2的幂

            //IsPowerOfTwo isPowerOfTwo = new IsPowerOfTwo();
            //Console.WriteLine(isPowerOfTwo.Method(14));

            #endregion

            #region 326.3的幂

            //IsPowerOfThree isPowerOfThree = new IsPowerOfThree();
            //Console.WriteLine(isPowerOfThree.Method(9));

            #endregion

            #region 20.有效的括号

            //IsValid isValid = new IsValid();
            //Console.WriteLine(isValid.Method("([)]"));

            #endregion

            #region 21. 合并两个有序链表

            //MergeTwoLists mergeTwoLists = new MergeTwoLists();


            #endregion

            #region 53. 最大子序和

            //MaxSubArray maxSubArray = new MaxSubArray();
            //int[] nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
            //Console.WriteLine(maxSubArray.Methd(nums));

            #endregion

            #region 226. 翻转二叉树

            InvertTree invertTree = new InvertTree();

            #endregion

            #region 441. 排列硬币

            //ArrangeCoins arrangeCoins = new ArrangeCoins();
            //WriteLine(arrangeCoins.Method(8));

            #endregion

            #region 83.删除排序链表中的重复元素

            DeleteDuplicates deleteDuplicates = new DeleteDuplicates();


            #endregion

            #region 342.4的幂

            //IsPowerOfFour isPowerOfFour = new IsPowerOfFour();
            //WriteLine(isPowerOfFour.Method(5));

            #endregion

            #region 367. 有效的完全平方数

            //IsPerfectSquare isPerfectSquare = new IsPerfectSquare();
            //WriteLine(isPerfectSquare.Method(160000));

            #endregion

            #region 198.打家劫舍

            //Rob rob = new Rob();
            //int[] nums1 = { 1, 2, 3, 1 };
            //int[] nums2 = { 2, 7, 9, 3, 1 };
            //int[] nums3 = { 9, 1, 1, 9 };
            //WriteLine(rob.Method(nums3));

            #endregion

            #region 387.字符串中的第一个唯一字符

            //FirstUniqChar firstUniqChar = new FirstUniqChar();
            //WriteLine(firstUniqChar.Method("aabcc"));

            #endregion

            #region 412.Fizz Buzz

            FizzBuzz fizzBuzz = new FizzBuzz();
            //fizzBuzz.Method(9);

            #endregion

            #region 121.买卖股票的最佳时机

            //MaxProfit maxProfit = new MaxProfit();
            //int[] nums = { 7, 1, 5, 3, 6, 4 };
            //WriteLine(maxProfit.Method(nums));

            #endregion

            #region 139.单词拆分

            //WordBreak wordBreak = new WordBreak();
            //string s = "cars";
            //string[] wordDict = { "cars", "ar", "rs" };
            //WriteLine(wordBreak.Method(s, wordDict));

            #endregion

            #region 47.全排列

            //PermuteUnique permuteUnique = new PermuteUnique();
            //int[] nums = { 1, 1, 2 };            
            //IList<IList<int>> result = permuteUnique.Method(nums);

            #endregion

            #region 219.存在重复元素(2)

            //ContainsNearbyDuplicate containsNearbyDuplicate = new ContainsNearbyDuplicate();
            //int[] nums = { 1, 0, 1, 1 };
            //int k = 1;
            //WriteLine(containsNearbyDuplicate.Method(nums, k));

            #endregion

            #region 404.左叶子之和



            #endregion

            #region 78.子集

            //int[] nums = { 1, 2, 3 };
            //Subsets subsets = new Subsets();
            //subsets.Method(nums);

            #endregion

            #region 538.把二叉搜索树转换为累加树

            ConvertBST convertBST = new ConvertBST();

            #endregion

            #region 88.合并两个有序数组

            //int[] num1 = { 1, 2, 3,0,0,0 };
            //int m = 3;
            //int[] num2 = { 2, 5, 6 };
            //int n = 3;

            //Merge merge = new Merge();
            //merge.Method(num1, m, num2, n);

            #endregion

            #region 125.验证回文串

            //IsPalindrome isPalindrome = new IsPalindrome();
            //string item = "race a car";
            //WriteLine(isPalindrome.Method(item));

            #endregion

            #region 349和350.两个数组的交集

            //Intersection intersection = new Intersection();
            //int[] num1 = { 1, 2, 2, 1 };
            //int[] num2 = { 2, 2 };
            //intersection.Method2(num1, num2);

            #endregion

            #region 617.合并二叉树



            #endregion

            #region 3.无重复字符的最长子串

            //LengthOfLongestSubstring lengthOfLongestSubstring = new LengthOfLongestSubstring();
            //WriteLine(lengthOfLongestSubstring.Method("abcabcbb"));

            #endregion

            #region 12.整数转罗马数字

            //IntToRoman intToRoman = new IntToRoman();
            //WriteLine(intToRoman.Method(40));

            #endregion

            #region 11.盛做多水的容器

            //MaxArea maxArea = new MaxArea();
            //int[] height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
            //WriteLine(maxArea.Method(height));

            #endregion

            #region 75.颜色分类

            SortColors sortColors = new SortColors();
            int[] nums = { 1, 2, 0, 0, 0, 1, 2 };
            sortColors.Method(nums);

            #endregion

            #region 501.二叉搜索树中的众数

            //FindMode findMode = new FindMode();


            #endregion

            #region 112.路径总和

            HasPathSum hasPathSum = new HasPathSum();


            #endregion

            #region 290.单词规则

            //WordPattern wordPattern = new WordPattern();
            //string pattern = "abab";
            //string str = "dog cat dog cat";
            //WriteLine(wordPattern.Method(pattern, str));

            #endregion

            #region 709. 转换成小写字母

            //ToLowerCase toLowerCase = new ToLowerCase();
            //WriteLine(toLowerCase.Method("ABC"));

            #endregion

            #region 106. 从中序与后序遍历序列构造二叉树

            BuildTree buildTree = new BuildTree();


            #endregion

            #region 118.杨辉三角

            //Generate generate = new Generate();
            //generate.Method(3);

            #endregion

            #region 119.杨辉三角(2)

            GetRow getRow = new GetRow();
            getRow.Method(3);

            #endregion


            ReadLine();
        }
    }
}
