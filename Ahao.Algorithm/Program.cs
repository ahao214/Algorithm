using Ahao.Algorithm.LNode;
using Ahao.Algorithm.Secondary;
using Ahao.Algorithm.Simple;
using Ahao.Algorithm.Stack;
using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Runtime.DesignerServices;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Web.UI.WebControls;
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

            //SortColors sortColors = new SortColors();
            //int[] nums = { 1, 2, 0, 0, 0, 1, 2 };
            //sortColors.Method(nums);

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

            //GetRow getRow = new GetRow();
            //getRow.Method(3);

            #endregion

            #region 100.相同的树

            IsSameTree isSameTree = new IsSameTree();

            #endregion

            #region 101.对称二叉树

            IsSymmetric isSymmetric = new IsSymmetric();

            #endregion

            #region 113.路径总和(2)

            PathSum pathSum = new PathSum();


            #endregion

            #region 235. 二叉搜索树的最近公共祖先

            LowestCommonAncestor lowestCommonAncestor = new LowestCommonAncestor();

            #endregion

            #region 137.只出现一次的数字(2)

            //SingleNumber singleNumber = new SingleNumber();
            //int[] num1 = { 2, 2, 3, 2 };
            //int[] num2 = { 0, 1, 0, 1, 0, 1, 99 };
            //WriteLine(singleNumber.Method(num2));

            #endregion

            #region 141.环形链表

            HasCycle hasCycle = new HasCycle();

            #endregion

            #region 142.环形链表(2)

            DetectCycle detectCycle = new DetectCycle();

            #endregion

            #region 168.Excel表列名称

            //ConvertToTitle convertToTitle = new ConvertToTitle();
            //WriteLine(convertToTitle.Method(2));

            #endregion

            #region 179.最大数

            //LargestNumber largestNumber = new LargestNumber();
            //int[] numLarge = { 9, 5, 3, 30, 34 };
            //WriteLine(largestNumber.Method(numLarge));

            #endregion

            #region 145.二叉树的后序遍历

            PostorderTraversal postorderTraversal = new PostorderTraversal();

            #endregion

            #region 701. 二叉搜索树中的插入操作

            InsertIntoBST insertIntoBST = new InsertIntoBST();


            #endregion

            #region LCP 19. 秋叶收藏集

            //MinimumOperations minimumOperations = new MinimumOperations();
            //string leaves = "ryr";
            //WriteLine(minimumOperations.Method(leaves));

            #endregion

            #region 771.宝石与石头

            //NumJewelsInStones numJewelsInStones = new NumJewelsInStones();
            //string J = "z";
            //string s = "ZZ";
            //WriteLine(numJewelsInStones.Method(J, s));

            #endregion

            #region 2.两数相加

            AddTwoNumbers addTwoNumbers = new AddTwoNumbers();

            #endregion

            #region 18.四数之和

            FourSum fourSum = new FourSum();
            int[] num = { 1, 0, -1, 0, -2, 2 };
            int target = 0;
            fourSum.Method(num, target);

            #endregion

            #region 416. 分割等和子集

            //CanPartition canPartition = new CanPartition();
            //int[] numCan = { 1, 2, 3, 5, 5 };
            //WriteLine(canPartition.Method(numCan));

            #endregion

            #region 530. 二叉搜索树的最小绝对差

            GetMinimumDifference getMinimumDifference = new GetMinimumDifference();


            #endregion

            #region 24.两两交换链表中的节点

            SwapPairs swapPairs = new SwapPairs();

            #endregion

            #region 1002. 查找常用字符

            //CommonChars commonChars = new CommonChars();
            //string[] A = { "cool", "lock", "cook" };
            //WriteLine(commonChars.Method(A));

            #endregion

            #region 977. 有序数组的平方

            //SortedSquares sortedSquares = new SortedSquares();
            //int[] A = { -4, -1, 0, 3, 10 };
            //WriteLine(sortedSquares.Method(A));

            #endregion

            #region 844. 比较含退格的字符串

            //BackspaceCompare backspaceCompare = new BackspaceCompare();
            //string S = "ab#c";
            //string T = "ad#c";
            //WriteLine(backspaceCompare.Method(S, T));

            #endregion

            #region 925.长按键入

            //IsLongPressedName isLongPressedName = new IsLongPressedName();
            //string name = "alex";
            //string typed = "aaleex";
            //WriteLine(isLongPressedName.Method(name, typed));

            #endregion

            #region 234.回文链表

            IsPalindromeNum isPalindromeNum = new IsPalindromeNum();


            #endregion

            #region 845. 数组中的最长山脉 

            //LongestMountain longestMountain = new LongestMountain();
            //int[] A = { 1,2,0,2,0,2};
            //WriteLine(longestMountain.Method(A));

            #endregion

            #region 1365. 有多少小于当前数字的数字

            //SmallerNumbersThanCurrent smallerNumbersThanCurrent = new SmallerNumbersThanCurrent();
            //int[] A = { 8, 1, 2, 2, 3 };
            //smallerNumbersThanCurrent.Method(A);           

            #endregion

            #region 1207. 独一无二的出现次数

            //UniqueOccurrences uniqueOccurrences = new UniqueOccurrences();
            //int[] arr = { 1, 2, 3, 2, 1, 1, };
            //WriteLine(uniqueOccurrences.Method(arr));

            #endregion

            #region 922. 按奇偶排序数组 II

            //SortArrayByParityII sortArrayByParityII = new SortArrayByParityII();
            //int[] A = { 1, 2, 3, 4 };
            //sortArrayByParityII.Method(A);

            #endregion

            #region  1122.数组的相对排序

            //RelativeSortArray relativeSortArray = new RelativeSortArray();
            //int[] arr1 = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
            //int[] arr2 = { 2, 1, 4, 3, 9, 6 };
            //relativeSortArray.Method(arr1, arr2);

            #endregion

            #region 34. 在排序数组中查找元素的第一个和最后一个位置

            //SearchRange searchRange = new SearchRange();
            //int[] numSearch = { 5, 7, 7, 8, 8, 10 };            
            //int targetSearch = 8;
            //searchRange.Method(numSearch, targetSearch);

            #endregion

            #region 204.计算质数

            //CountPrimes countPrimes = new CountPrimes();
            //int countN = 10;
            //Console.WriteLine(countPrimes.Method(countN));

            #endregion

            #region 659. 分割数组为连续子序列

            //IsPossible isPossible = new IsPossible();
            //int[] possibleNums = { 1, 2, 3, 3, 4, 5 };

            //WriteLine(isPossible.Method(possibleNums));


            #endregion

            #region 62.不同路径

            //UniquePaths uniquePaths = new UniquePaths();
            //int m = 3;
            //int n = 3;
            //WriteLine(uniquePaths.Method(m, n));


            #endregion

            #region 860.柠檬水找零

            //LemonadeChange lemonadeChange = new LemonadeChange();
            //int[] bills = { };
            //WriteLine(lemonadeChange.Method(bills));

            #endregion

            #region 605.种花问题

            //CanPlaceFlowers canPlaceFlowers = new CanPlaceFlowers();
            //int[] flowerbed = { 1, 0, 0, 0, 1 };
            //int c = 1;
            //WriteLine(canPlaceFlowers.Method(flowerbed, c));

            #endregion

            #region 830.较大分组的位置

            //LargeGroupPositions largeGroupPositions = new LargeGroupPositions();
            //string s = "aaabbccc";
            //largeGroupPositions.Method(s);


            #endregion

            #region 1232. 缀点成线




            #endregion

            #region 628.三个数的最大乘积

            //MaximumProduct maximumProduct = new MaximumProduct();
            //int[] maxValue = { 1, 2, 0 };
            //WriteLine(maximumProduct.Method(maxValue));

            #endregion

            #region 989. 数组形式的整数加法

            //int[] A = { 1, 2, 0, 0 };
            //int K = 34;
            //AddToArrayForm addToArrayForm = new AddToArrayForm();
            //Console.WriteLine(addToArrayForm.Method(A, K));

            #endregion

            #region 674.最长连续递增序列

            //FindLengthOfLCIS findLengthOfLCIS = new FindLengthOfLCIS();
            //int[] numLength = { 3, 3, 5, 4, 7 };
            //Console.WriteLine(findLengthOfLCIS.Method(numLength));

            #endregion

            #region 888.公平的糖果棒交换

            //FairCandySwap fairCandySwap = new FairCandySwap();
            //int[] A = { 1, 1 };
            //int[] B = { 2, 2 };

            //fairCandySwap.Method(A, B);

            #endregion

            #region 424. 替换后的最长重复字符

            //string s = "ABAB";
            //int k = 2;
            //CharacterReplacement characterReplacement = new CharacterReplacement();
            //WriteLine(characterReplacement.Method(s, k));

            #endregion

            #region 643.子数组最大平均数-1

            //FindMaxAverage findMaxAverage = new FindMaxAverage();
            //int[] nums = { 1, 12, -5, -6, 50, 3 };
            //int k = 6;
            //WriteLine(findMaxAverage.Method(nums, k));

            #endregion

            #region 1423. 可获得的最大点数

            //int[] cardPoints = { 96,90,41,82,39,74,64,50,30 };
            //int k = 8;
            //MaxScore maxScore = new MaxScore();

            //WriteLine(maxScore.Method(cardPoints, k));

            #endregion

            #region 665. 非递减数列

            //int[] nums = { 5, 7, 1, 8 };
            //CheckPossibility checkPossibility = new CheckPossibility();
            //WriteLine(checkPossibility.Method(nums));

            #endregion

            #region 如何实现链表的逆序

            // int i = 0;
            // //链表头结点
            // Ahao.Algorithm.LNode.LNode head = new Ahao.Algorithm.LNode.LNode();
            // head.next = null;
            // Ahao.Algorithm.LNode.LNode tmp = null;
            // Ahao.Algorithm.LNode.LNode cur = head;
            // //构造单链表
            // for (; i < 8; i++)
            // {
            //     tmp = new Ahao.Algorithm.LNode.LNode();
            //     tmp.data = i;
            //     tmp.next = null;
            //     cur.next = tmp;
            //     cur = tmp;
            // }

            // Console.WriteLine("逆序前：");
            // for (cur = head.next; cur != null; cur = cur.next)
            // {
            //     Console.Write(cur.data + " ");
            // }
            // Console.WriteLine("\n逆序后：");
            // //就地逆序
            // //Ahao.Algorithm.LNode.TestReverse.Reverse(head);
            // //递归法
            // //Ahao.Algorithm.LNode.TestReverse.ReverseDG(head);
            // //插入法
            ////Ahao.Algorithm.LNode.TestReverse.ReverseInsert(head);

            // for (cur = head.next; cur != null; cur = cur.next)
            // {
            //     Console.Write(cur.data + " ");
            // }

            #endregion

            #region 如何从无序链表中移除重复项

            //int i = 1;
            ////链表头指针            
            //LNode.LNode head = new LNode.LNode();
            //head.next = null;
            //LNode.LNode tmp = null;
            //LNode.LNode cur = head;
            //for (; i < 7; i++)
            //{
            //    tmp = new LNode.LNode();
            //    if (i % 2 == 0)
            //    {
            //        tmp.data = i + 1;
            //    }
            //    else if (i%3==0)
            //    {
            //        tmp.data = i - 2;
            //    }
            //    else
            //    {
            //        tmp.data = i;
            //    }
            //    tmp.next = null;
            //    cur.next = tmp;
            //    cur = tmp;
            //}
            //Console.Write("删除重复结点前：");
            //for(cur=head .next;cur!=null;cur=cur.next )
            //{
            //    Console.Write(cur.data + " ");
            //}
            //#region 顺序删除

            ////TestRemoveDup.RemoveDup(head);

            //#endregion

            //#region 递归法
            //TestRemoveDup.RemoveDupDG(head);
            //#endregion

            //Console.Write("\n删除重复结点后：");
            //for(cur =head.next;cur !=null;cur =cur .next )
            //{
            //    Console.Write(cur.data + " ");
            //}


            #endregion

            #region 如何计算两个单链表所代表的数之和

            //int i = 1;
            ////链表头指针
            //LNode.LNode head1 = new LNode.LNode();
            //head1.next = null;
            //LNode.LNode head2 = new LNode.LNode();
            //head2.next = null;
            //LNode.LNode tmp = null;
            //LNode.LNode cur = head1;
            //LNode.LNode addResult = null;
            ////构造第一个链表
            //for (; i < 7; i++)
            //{
            //    tmp = new LNode.LNode();
            //    tmp.data = i + 2;
            //    tmp.next = null;
            //    cur.next = null;
            //    cur.next = tmp;
            //    cur = tmp;
            //}
            //cur = head2;
            ////构造第二个链表
            //for (i = 9; i > 4; i--)
            //{
            //    tmp = new LNode.LNode();
            //    tmp.data = i;
            //    tmp.next = null;
            //    cur.next = tmp;
            //    cur = tmp;
            //}
            //Write("Head1:");
            //for (cur = head1.next; cur != null; cur = cur.next)
            //{
            //    Write(cur.data + " ");
            //}
            //Write("\nHead2:");


            //for (cur = head2.next; cur != null; cur = cur.next)
            //{
            //    Write(cur.data + " ");
            //}
            //addResult = Ahao.Algorithm.LNode.TestAdd.Add(head1, head2);
            //Write("\n相加后:");
            //for (cur = addResult.next; cur != null; cur = cur.next)
            //{
            //    Write(cur.data + " ");
            //}

            #endregion

            #region 对链表进行重新排序

            //int i = 1;
            ////链表头指针
            //LNode.LNode head = new LNode.LNode();
            //head.next = null;
            //LNode.LNode tmp = null;
            //LNode.LNode cur = head;
            ////构造第一个链表
            //for (; i < 8; i++)
            //{
            //    tmp = new LNode.LNode();
            //    tmp.data = i;
            //    tmp.next = null;
            //    cur.next = tmp;
            //    cur = tmp;
            //}
            //Write("排序前：");
            //for (cur = head.next; cur != null; cur = cur.next)
            //{
            //    Write(cur.data + " ");
            //}
            //TestFindMiddleNode.Reorder(head);
            //Write("\n排序后：");
            //for (cur = head.next; cur != null; cur = cur.next)
            //{
            //    Write(cur.data + " ");
            //}

            #endregion

            #region 找出单链表中的倒数第K个元素

            //LNode.LNode head = Ahao.Algorithm.LNode.TestConstructListK.ConstructList();//链表头指针
            //LNode.LNode result = null;
            //Write("链表：");
            //TestConstructListK.PrintList(head);
            //result = TestConstructListK.FindLastK(head, 3);
            //if (result != null)
            //{
            //    Write("\n链表倒数第3个元素为：" + result.data);
            //}


            #endregion

            #region 将单链表向右旋转K个位置

            //LNode.LNode head = TestRotateK.ConstructList();
            //Write("旋转前：");
            //TestRotateK.PrintList(head);

            //TestRotateK.Rotate(head, 4);
            //Write("\n旋转后：");
            //TestRotateK.PrintList(head);


            #endregion

            #region 检查一个较大的单链表是否有环

            //LNode.LNode head = TestIsLoop.ConstructList();  //头结点
            //LNode.LNode meetNode = TestIsLoop.IsLoop(head);
            //LNode.LNode loopNode = null;
            //if(meetNode !=null )
            //{
            //    WriteLine("有环");
            //    loopNode = TestIsLoop.FindLoopNode(head, meetNode);
            //    WriteLine("环的入口点为：" + loopNode.data);
            //}
            //else
            //{
            //    WriteLine("无环");
            //}
            //ReadLine();

            #endregion

            #region 把链表相邻元素翻转

            //int i = 1;
            //LNode.LNode head = new LNode.LNode();
            //head.next = null;
            //LNode.LNode tmp = null;
            //LNode.LNode cur = head;
            //for (; i < 9; i++)
            //{
            //    tmp = new LNode.LNode();
            //    tmp.data = i;
            //    tmp.next = null;
            //    cur.next = tmp;
            //    cur = tmp;
            //}
            //Write("顺序输出：");
            //for (cur = head.next; cur != null; cur = cur.next)
            //{
            //    Write(cur.data + " ");
            //}
            //TestReverseN.Reverse(head);
            //Write("\n逆序输出：");
            //for (cur = head.next; cur != null; cur = cur.next)
            //{
            //    Write(cur.data + " ");
            //}
            //for (cur = head.next; cur != null;)
            //{
            //    tmp = cur;
            //    cur = cur.next;
            //}

            #endregion

            #region 把链表以K个结点为一组进行翻转

            //int i = 1;
            //LNode.LNode head = new LNode.LNode();
            //head.next = null;
            //LNode.LNode tmp = null;
            //LNode.LNode cur = head;
            //for (; i < 8; i++)
            //{
            //    tmp = new LNode.LNode();
            //    tmp.data = i;
            //    tmp.next = null;
            //    cur.next = tmp;
            //    cur = tmp;
            //}
            //Write("顺序输出：");
            //for (cur = head.next; cur != null; cur = cur.next)
            //{
            //    Write(cur.data + " ");
            //}
            //TestReverseByK.ReverseK(head, 3);
            //Write("\n逆序输出：");
            //for (cur = head.next; cur != null; cur = cur.next)
            //{
            //    Write(cur.data + " ");
            //}
            //for (cur = head.next; cur != null;)
            //{
            //    tmp = cur;
            //    cur = cur.next;
            //}



            #endregion

            #region 合并两个有序链表

            //LNode.LNode head1 = TestLNodeMerge.ConstructList(1);
            //LNode.LNode head2 = TestLNodeMerge.ConstructList(2);
            //Write("head1:");
            //TestLNodeMerge.PrintList(head1);
            //Write("\nhead2:");
            //TestLNodeMerge.PrintList(head2);
            //Write("\n合并后的链表：");
            //LNode.LNode head = TestLNodeMerge.Merge(head1, head2);
            //TestLNodeMerge.PrintList(head);

            #endregion

            #region 在只给定单链表中某个结点的指针的情况下删除该结点

            //int i = 1;
            //LNode.LNode head = new LNode.LNode();   //链表头结点
            //head.next = null;
            //LNode.LNode tmp = null;
            //LNode.LNode cur = head;
            //LNode.LNode p = null;
            ////构造链表
            //for(;i<10;i++)
            //{
            //    tmp = new LNode.LNode();
            //    tmp.data = i;
            //    tmp.next = null;
            //    cur.next = tmp;
            //    cur = tmp;
            //    if(i==5)
            //    {
            //        p = tmp;
            //    }
            //}
            //Write("删除节点" + p.data + "前链表：");
            //TestRemoveNode.PrintList(head);
            //bool result = TestRemoveNode.RemoveNode(p);
            //if(result)
            //{
            //    Write("\n删除该结点后链表：");
            //    TestRemoveNode.PrintList(head);
            //}


            #endregion

            #region 判断两个单链表(无环)是否相交

            //int i = 1;
            ////链表头结点
            //LNode.LNode head1 = new LNode.LNode();
            //head1.next = null;
            ////链表头结点
            //LNode.LNode head2 = new LNode.LNode();
            //head2.next = null;
            //LNode.LNode tmp = null;
            //LNode.LNode cur = head1;
            //LNode.LNode p = null;
            ////构造第一个链表
            //for (; i < 8; i++)
            //{
            //    tmp = new LNode.LNode();
            //    tmp.data = i;
            //    tmp.next = null;
            //    cur.next = tmp;
            //    cur = tmp;
            //    if (i == 5)
            //    {
            //        p = tmp;
            //    }
            //}
            //cur = head2;
            ////构造第二个链表
            //for (i = 1; i < 5; i++)
            //{
            //    tmp = new LNode.LNode();
            //    tmp.data = i;
            //    tmp.next = null;
            //    cur.next = tmp;
            //    cur = tmp;
            //}
            ////使它们相交与结点5
            //cur.next = p;
            //LNode.LNode interNode = TestIsIntersect.IsIntersect(head1, head2);
            //if (interNode == null)
            //{
            //    WriteLine("这两个链表不相交；");
            //}
            //else
            //{
            //    WriteLine("这两个链表相交点为：" + interNode.data);
            //}

            #endregion

            #region 用数组实现栈

            //TestStackByArray.MyStack<int> stack = new TestStackByArray.MyStack<int>();
            //stack.Push(1);
            //stack.Push(2);
            //WriteLine("栈顶元素为：" + stack.Top());
            //WriteLine("栈大小为：" + stack.Size());
            //stack.Pop();
            //WriteLine("弹栈成功");
            //stack.Pop();
            //Read();

            #endregion

            #region 用链表实现栈

            //TestStackByLink.MyStack<int> stack = new TestStackByLink.MyStack<int>();
            //for (var i = 1; i < 11; i+=2)
            //{
            //    stack.Push(i);
            //}
            //WriteLine("栈顶元素为：" + stack.Top());
            //WriteLine("栈的大小为：" + stack.Size());
            //stack.Pop();
            //WriteLine("出栈完成");
            //stack.Pop();
            //Read();

            #endregion

            #region 数组实现队列

            //TestQueueByArray.MyQueue<int> queue = new TestQueueByArray.MyQueue<int>(10);
            //queue.Enquene(1);
            //queue.Enquene(1);
            //WriteLine("对首元素为：" + queue.Dequene());
            //WriteLine("队列大小为：" + queue.Count());
            //queue.Peek();
            //WriteLine("取队首成功");
            //queue.Peek();
            //Read();

            #endregion








            ReadLine();
        }
    }
}
