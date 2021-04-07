using Ahao.Algorithm.ArrayNums;
using Ahao.Algorithm.CharacterString;
using Ahao.Algorithm.Secondary;
using Ahao.Algorithm.Simple;
using System;
using System.Collections.Generic;
using System.IO.Pipes;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using static System.Console;

namespace Ahao.Algorithm
{
    class Program
    {
        public int getBegin() { return this.begin; }
        public int getEnd() { return this.end; }
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

            //FourSum fourSum = new FourSum();
            //int[] num = { 1, 0, -1, 0, -2, 2 };
            //int target = 0;
            //fourSum.Method(num, target);

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

            #region 485.最大连续1的个数

            //FindMaxConsecutiveOnes findMaxConsecutiveOnes = new FindMaxConsecutiveOnes();
            //int[] nums = { 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 ,1,0,1};
            //WriteLine(findMaxConsecutiveOnes.Method(nums));

            #endregion

            #region 1227. 飞机座位分配概率

            //NthPersonGetsNthSeat nthPersonGetsNthSeat = new NthPersonGetsNthSeat();
            //WriteLine(nthPersonGetsNthSeat.Method(4));

            #endregion

            #region 881.救生艇

            //NumRescueBoats numRescueBoats = new NumRescueBoats();
            //int[] people = { 1, 2 };
            //int limit = 3;
            //WriteLine(numRescueBoats.Method(people, limit));

            #endregion

            #region 896. 单调数列

            //int[] arr = { 3, 3, 3 };
            //IsMonotonic isMonotonic = new IsMonotonic();
            //WriteLine(isMonotonic.Method(arr));

            #endregion

            #region 16. 最接近的三数之和

            //ThreeSumClosest threeSumClosest = new ThreeSumClosest();
            //int[] nums = { -1, 2, 1, -4 };
            //int tar = 1;
            //WriteLine(threeSumClosest.Method(nums, tar));

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

            #region 链表实现队列

            //TestQueueByLink.MyQueue<int> queue = new TestQueueByLink.MyQueue<int>();
            //queue.Enqueue(1);
            //queue.Enqueue(1);
            //WriteLine("队首元素为：" + queue.Dequeue());
            //WriteLine("队列大小为：" + queue.Count());
            //queue.Peek();
            //WriteLine("取队首成功！");
            //queue.Peek();
            //Read();

            #endregion

            #region 翻转栈的所有元素

            //Stack<int> s = new Stack<int>();
            //for (var i = 5; i > 0; i--)
            //{
            //    s.Push(i);
            //}
            //TestMoveBottomToTop.Reverse(s);
            //WriteLine("翻转后出栈顺序后：");
            //while(s.Count>0)
            //{
            //    Write(s.Peek() + " ");
            //    s.Pop();
            //}
            //Read();

            #endregion

            #region 给栈排序

            //Stack<int> s = new Stack<int>();
            //s.Push(1);
            //s.Push(3);
            //s.Push(2);
            //s.Push(90);
            //s.Push(11);
            //TestSortStack.SortStack(s);
            //Write("排序后出栈顺序为：");
            //while(s.Count >0)
            //{
            //    Write(s.Peek() + " ");
            //    s.Pop();
            //}

            #endregion

            #region 根据入栈序列判断可能的出栈序列

            //String push = "12345";
            //String pop = "53412";
            //if (TestIsPopSerial.IsPopSerial(push, pop))
            //{
            //    WriteLine(pop + "是" + push + "的一个pop序列");
            //}
            //else
            //{
            //    WriteLine(pop + "不是" + push + "的一个pop序列");
            //}

            #endregion

            #region 求栈中最小元素

            //TestMinEleInStack.MyStack stack = new TestMinEleInStack.MyStack();
            //stack.Push(5);
            //WriteLine("栈中最小值为：" + stack.Min());
            //stack.Push(6);
            //WriteLine("栈中最小值为：" + stack.Min());
            //stack.Push(2);
            //WriteLine("栈中最小值为：" + stack.Min());
            //stack.Pop();
            //WriteLine("栈中最小值为：" + stack.Min());
            //stack.Push(4);
            //WriteLine("栈中最小值为：" + stack.Min());
            //Read();

            #endregion

            #region 用两个栈模拟队列操作

            //TestTwoStack.MyStack<int> stack = new TestTwoStack.MyStack<int>();
            //stack.push(1);
            //stack.push(2);
            //WriteLine("队列首元素为：" + stack.pop());                        
            //WriteLine("队列首元素为：" + stack.pop());
            //Read();


            #endregion

            #region 设计一个排序系统

            //TestUser u1 = new TestUser(1, "战三");
            //TestUser u2 = new TestUser(2, "大刀");
            //TestUser u3 = new TestUser(3, "玄剑");
            //TestUser u4 = new TestUser(4, "战斧");
            //MyQueue queue = new MyQueue();
            //queue.EnQueue(u1);
            //queue.EnQueue(u2);
            //queue.EnQueue(u3);
            //queue.EnQueue(u4);
            //queue.DeQueue();    //对首元素u1出队列
            //queue.DeQueue(u3);  //队列中间的元素u3出队列
            //queue.PrintList();


            #endregion

            #region 实现LRU缓存方案

            ////假设缓存大小为3
            //TestLRU lru = new TestLRU(3);
            ////访问page
            //lru.AccessPage(1);
            //lru.AccessPage(2);
            //lru.AccessPage(5);
            //lru.AccessPage(1);
            //lru.AccessPage(6);
            //lru.AccessPage(7);

            ////通过上面的访问序列后，缓存的信息为
            //lru.PrintQueue();

            #endregion

            #region 从给定的车票中找出旅程的路线

            //Dictionary<String, String> input = new Dictionary<String, String>();
            //input.Add("西安","成都");
            //input.Add("北京", "上海");
            //input.Add("大连", "西安");
            //input.Add("上海", "大连");
            //input.Add("成都", "武汉");

            //Itinerary.PrintResult(input);

            #endregion

            #region 从数组中找出满足a+b=c+d的两个数对

            //int[] arr = { 3, 4, 7, 10, 20, 9, 8 };
            //ArrayElements a = new ArrayElements();
            //a.findPairs(arr);

            #endregion

            #region 把一个有序整数数组放到二叉树中

            //int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            //Write("数组：");
            //for(int i=0;i<arr.Length;i++)
            //{
            //    Write(arr[i] + " ");
            //}
            //WriteLine();
            //BiTNode root;
            //root = TestArraytotree.Arraytotree(arr, 0, arr.Length - 1);
            //WriteLine("转换成树的中序遍历为：");
            //TestArraytotree.PrintTreeMidOrders(root);
            //WriteLine();

            #endregion

            #region 从顶部开始逐层遍历二叉树结点数据

            //int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            //BiTNode root = TestArraytotree.Arraytotree(arr, 0, arr.Length - 1);
            //Write("树的层序遍历结果为：");
            //TestPrintTreeLayer.PrintTreeLayer(root);

            #endregion

            #region 求一颗二叉树的最大子树的和

            //构造二叉树
            //BiTNode root = TestFindMaxSubTree.constructTree();
            //BiTNode maxRoot = new BiTNode();    //最大子树的根结点
            //int maxSum = TestFindMaxSubTree.FindMaxSubTree(root, maxRoot);
            //WriteLine("最大子树和为：" + maxSum);
            //WriteLine("对应子树的根结点为：" + maxRoot.Data);

            #endregion

            #region 判断两颗二叉树是否相等

            //BiTNode root1 = TestIsEqualTree.constructTree(5, 3, 0, 9);
            //BiTNode root2 = TestIsEqualTree.constructTree(3, 4, 9, 0);
            //bool equal = TestIsEqualTree.IsEqual(root1, root2);
            //if (equal)
            //{
            //    WriteLine("这两颗二叉树相等");
            //}
            //else
            //{
            //    WriteLine("这两颗二叉树不相等");
            //}

            #endregion

            #region 把二叉树转换为双向链表

            //int[] arr = { 1, 2, 3, 4, 5, 6, 7 };
            //BiTNode root;
            //root = TestArraytotree.Arraytotree(arr, 0, arr.Length - 1);
            //TestInOrderBSTree.InOrderBSTree(root);
            //BiTNode cur;
            //Write("转换后双向链表正向遍历：");
            //for (cur = TestInOrderBSTree.pHead; cur != null; cur = cur.Rchild)
            //{
            //    Write(cur.Data + " ");
            //}
            //WriteLine();
            //Write("转换后双向链表逆向遍历：");
            //for (cur = TestInOrderBSTree.pEnd; cur != null; cur = cur.Lchild)
            //{
            //    Write(cur.Data + " ");
            //}


            #endregion

            #region 如何判断一个数组是否是二元查找树后序遍历的序列

            //int[] arr = { 1, 3, 2, 5, 7, 6, 4 };
            //bool result = TestIsAfterOrder.IsAfterOrder(arr, 0, arr.Length - 1);
            //for (int i = 0; i < arr.Length; i++)
            //{
            //    Write(arr[i] + " ");
            //}
            //if (result)
            //{
            //    WriteLine("是某一个二元查找树的后续遍历序列");
            //}
            //else
            //{
            //    WriteLine("不是某一个二元查找树的后续遍历序列");
            //}

            #endregion

            #region 找出排序二叉树上任意两个结点的最近共同父结点

            //int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            //BiTNode root;
            //root = TestArraytotree.Arraytotree(arr, 0, arr.Length - 1);
            //BiTNode node1 = root.Lchild.Lchild.Lchild;
            //BiTNode node2 = root.Lchild.Rchild;
            //BiTNode res = null;
            //res = TestGetPathFromRoot.FindParentNode(root, node1, node2);
            //if (res != null)
            //{
            //    Write(node1.Data + "与" + node2.Data + "的最近公共父结点为：" + res.Data);
            //}
            //else
            //{
            //    WriteLine("没有公共父结点");
            //}

            #endregion

            #region 复制二叉树

            //BiTNode root1 = TestCopyTree.constructTree();
            //BiTNode root2 = TestCopyTree.createDupTree(root1);
            //Write("原始二叉树中序遍历：");
            //TestCopyTree.printTreeMidOrder(root1);
            //WriteLine();
            //Write("新的二叉树中序遍历：");
            //TestCopyTree.printTreeMidOrder(root2);

            #endregion

            #region 在二叉树中找出与输入整数相等的所有路径

            //BiTNode root = TestFindRoad.constructTree();
            //List<int> s = new List<int>();
            //Write("满足路径结点和等于8的路径为：");
            //TestFindRoad.FindRoad(root, 8, 0, s);

            #endregion

            #region 如何对二叉树进行镜像翻转

            //int[] arr = { 1, 2, 3, 4, 5, 6, 7 };
            //BiTNode root;
            //root = TestReverseTree.arraytotree(arr, 0, arr.Length - 1);
            //Write("二叉树层序遍历结果为：");
            //TestReverseTree.PrintTreeLayer(root);
            //WriteLine();
            //TestReverseTree.ReverseTree(root);
            //Write("反转后的二叉树层序遍历结果为：");
            //TestReverseTree.PrintTreeLayer(root);

            #endregion

            #region 在二叉排序树中找出第一个大于中间值的结点

            //int[] arr = { 1, 2, 3, 4, 5, 6, 7 };
            //BiTNode root;
            //root = TestGetNode.arraytoTree(arr, 0, arr.Length - 1);
            //WriteLine(TestGetNode.GetNode(root).Data);

            #endregion

            #region 在二叉树中找出路径最大的和

            //Ahao.Algorithm.Tree.TreeNode root = new Ahao.Algorithm.Tree.TreeNode(2);
            //Ahao.Algorithm.Tree.TreeNode left = new Ahao.Algorithm.Tree.TreeNode(3);
            //Ahao.Algorithm.Tree.TreeNode right = new Ahao.Algorithm.Tree.TreeNode(5);
            //root.Left  = left;
            //root.Right = right;
            //TestFindMaxPath t = new TestFindMaxPath();
            //WriteLine(t.FindMaxPath(root));

            #endregion

            #region 如何实现反向DNS查找缓存

            //String[] ipAdds = { "10.57.11.127", "121.57.61.129", "66.125.100.103" };
            //String[] url = { "www.samsung.com", "www.samsung.net", "www.google.in" };

            //int n = ipAdds.Length;
            //DNSCache cache = new DNSCache();

            ////把IP地址和对应的URL插入到Trie树中
            //for(int i=0;i<n;i++)
            //{
            //    cache.insert(ipAdds[i], url[i]);
            //}

            //String ip = "121.57.61.129";
            //String res_url = cache.searchDNSCache(ip);
            //if(res_url !=null )
            //{
            //    WriteLine("找到了IP对应的URL:\n" + ip + "--->" + res_url);
            //}
            //else
            //{
            //    WriteLine("没有找到对应的URL\n");
            //}


            #endregion

            #region 找出数组中唯一的重复元素

            //int[] nums = { 1, 3, 4, 2, 5, 3 };
            //int result = TestFindDup.FindDupHuan(nums);
            //WriteLine(result);
            //Read();

            //int[] array = { 1, 2, 3, 3, 3, 4, 5, 5, 5, 5, 6 };
            //int length = array.Length;
            //int nums = 6;
            //HashSet<int> s = TestFindDup.FindRepeat(array, length, nums);
            //foreach (var item in s)
            //{
            //    WriteLine(item);
            //}
            //Read();

            #endregion

            #region 查找数组中元素的最大值和最小值

            //int[] array = { 7, 3, 19, 40, 4, 7, 1 };
            //TestMaxMin.MaxMin m = TestMaxMin.GetmaxAndMin(array);
            //WriteLine("max=" + m.Max);
            //WriteLine("min=" + m.Min);
            //Read();

            //TestMaxMin testMaxMin = new TestMaxMin();
            //List<int> result = testMaxMin.GetMaxAndMin(array, 0, array.Length - 1);
            //WriteLine("max=" + result[1]);
            //WriteLine("min=" + result[0]);


            #endregion

            #region 找出旋转数组的最小元素

            //int[] arrone = { 5, 6, 1, 2, 3, 4 };
            //int min = TestGetMin.GetMin(arrone);
            //WriteLine(min);
            //int[] arrtwo = { 1, 1, 0, 1 };
            //min = TestGetMin.GetMin(arrtwo);
            //WriteLine(min);

            #endregion

            #region 实现数组旋转

            //int[] arr = { 1, 2, 3, 4, 5 };
            //TestSwap.rotatearr(arr, 2);
            //for (int i = 0; i < arr.Length; i++)
            //{
            //    WriteLine(arr[i] + " ");
            //}

            #endregion

            #region 如何找出数组总出现奇数次的数

            //int[] arr = { 3, 5, 6, 6, 5, 7, 2, 2 };
            //TestGetOddNumberHash.GetOddNumberHash(arr);
            //Read();

            //int[] arr = { 3, 5, 6, 6, 5, 7, 2, 2 };
            //TestGetOddNumberHash.GetOddNumberYH(arr);

            #endregion

            #region 找出数组中第K小的数

            //int k = 3;
            //int[] arr = { 4, 6, 1, 5, 2, 3 };
            //WriteLine("第" + k + "小的值为：");
            //WriteLine(TestFindSmallK.FindSmallK(arr, 0, arr.Length - 1, k));

            #endregion

            #region 在数组中找出前K大的值

            //int[] arr = { 4, 7, 1, 2, 3, 8, 9, 5 };
            //TestFindTopK.FindTopK(arr);

            #endregion

            #region 求数组中两个元素的最小距离

            //int[] arr = { 4, 5, 6, 4, 7, 4, 6, 4, 7, 8, 5, 6, 4, 3, 10, 8 };
            //int one = 4;
            //int two = 8;
            //WriteLine(TestMinDistance.MinDistance(arr, one, two));
            //WriteLine(TestMinDistance.MinDistance(arr, one, two));

            #endregion

            #region 求解最小三元组距离

            //int[] a = { 3, 4, 5, 7, 15 };
            //int[] b = { 10, 12, 14, 16, 17 };
            //int[] c = { 20, 21, 23, 24, 37, 30 };
            //WriteLine("最小距离为：" + TestThreeMinDistance.MinDistance(a, b, c));
            //WriteLine("最小距离为：" + TestThreeMinDistance.MinDistanceLow(a, b, c));
            //WriteLine("最小距离为：" + TestThreeMinDistance.MinDistanceA(a, b, c));

            #endregion

            #region 求数组中绝对值最小的数

            //int[] arr = { -10, -5, -2, 7, 15, 50 };
            //WriteLine("绝对值最小的数是:" + TestFindMin.FindMin(arr));
            //WriteLine("绝对值最小的数是:" + TestFindMin.FindMinT(arr));

            #endregion

            #region 求数组连续最大和

            //int[] arr = { 1, -2, 4, 8, -4, 7, -1, -5 };
            //WriteLine("连续最大和为：" + TestMaxSubArray.MaxSubArray(arr));
            //WriteLine("连续最大和为：" + TestMaxSubArray.MaxSubArr(arr));
            //WriteLine("连续最大和为：" + TestMaxSubArray.MaxSubArrayDT(arr));
            //WriteLine("连续最大和为：" + TestMaxSubArray.MaxSubArrayDTT(arr));
            //Program p = new Program();
            //WriteLine("连续最大和为：" + p.MaxSubArrayOne(arr));
            //WriteLine("最大和对应的数组起始与结束坐标分别为：" + p.getBegin() + "," + p.getEnd());

            #endregion

            #region 找出数组中出现1次的数

            //int[] arr = { 6, 3, 4, 5, 9, 4, 3 };
            //TestFindSingle testFindSingle = new TestFindSingle();
            //int result = testFindSingle.FindSingle(arr);
            //if (result != -1)
            //{
            //    WriteLine(result);
            //}
            //else
            //{
            //    WriteLine("没找到");
            //}

            #endregion

            #region 在不排序的情况下求数组中的中位数

            //int[] arr = { 7, 5, 3, 1, 11, 9 };
            //TestGetMid testGetMid = new TestGetMid();
            //WriteLine(testGetMid.GetMid(arr));

            #endregion

            #region 求集合的所有子集

            //char[] array = { 'a', 'b', 'c' };
            //int[] mask = { 0, 0, 0 };
            //TestGetAllSubset.GetAllSubset(array, mask, 0);

            //List<string> result = TestGetAllSubset.GetAllSubSet("abc");
            //for (int i=0;i<result .Count;i++)
            //{
            //    WriteLine(result[i]);
            //}

            #endregion

            #region 对数组进行循环移位

            //int i;
            //int k = 3;
            //int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8 };
            //TestRightShift.RightShiftThree(arr, k);
            //for (i = 0; i < arr.Length; i++)
            //{
            //    Write(arr[i] + " ");
            //}

            #endregion

            #region 求解迷宫问题

            //TestMaze testMaze = new TestMaze();
            //int[][] maze = { new int[] { 1, 0, 0, 0 }, new int[] { 1, 1, 0, 1 }, new int[] { 0, 1, 0, 0 }, new int[] { 1, 1, 1, 1 } };
            //int[][] sol = { new int []{ 0, 0, 0, 0 }, new int []{ 0, 0, 0, 0 }, new int[] { 0, 0, 0, 0 }, new int[] { 0, 0, 0, 0 } };
            //if(testMaze.GetPath(maze,0,0,sol)==false)
            //{
            //    Write("不存在可达的路径");
            //}
            //else
            //{
            //    testMaze.PrintSolution(sol);
            //}

            #endregion

            #region 求解数组分为和相等的m份后m最大值问题

            //int[] arr = { 3, 2, 4, 3, 6 };
            //TestGetMMax.GetMax(arr);

            #endregion

            #region 求一个数组的最长递减子序列

            //int[] arr = { 9, 4, 3, 2, 5, 4, 3, 2 };
            //TestLIS.LIS(arr);

            #endregion

            #region 求解和为n的连续正数序列

            //int number = 15;
            //TestFind.Find(number);

            #endregion

            #region 寻找丑数

            //int number = 10;
            //TestIsUgly isUgly = new TestIsUgly();
            //int result = isUgly.FindUgly(number);
            //WriteLine(result);

            //Write(TestIsUgly.ExcellenceFindUgly(number));

            #endregion

            #region 找到数组元素连接起来排成的所有数字中最小的一个

            //int[] arr = { 4, 3, 2, 3, 1 };
            //TestComArrayMin.ComArrayMin(arr);

            #endregion

            #region 找出数组中出现次数超过了一半的那个数字

            //int[] arr = { 1, 3, 3, 3, 1 };
            //int res = TestMoreHalf.MoreHalf(arr);
            //WriteLine(res);

            #endregion

            #region 找出数组中左边的数都小于等于它，右边的数都大于等于它的数

            //int[] arr = { 7, 10, 2, 6, 19, 22, 32 };
            //TestSmallLarge.SmallLarge(arr);

            #endregion

            #region 进行大整数相乘

            //TestMulti.Multi("1234", "5678");

            #endregion

            #region 求集合的所有子集

            //TestRecurse.SubSet("1234");           

            #endregion

            #region 如何知道拿走了哪个数

            //int[] arr = new int[10000];
            //for (int i = 1; i <= 10000; i++)
            //{
            //    //模拟把999拿走
            //    if (i != 999)
            //    {
            //        arr[i - 1] = i;
            //    }
            //}
            //TestFindLoseNumber.FindLoseNumber(arr);


            #endregion

            #region 求解n-m问题

            //int m = 2;
            //int n = 3;
            //int[] arr = { 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3 };
            //Write(TestFindSingleNumber.FindSingleNumber(arr, m, n));

            #endregion

            #region 求2个有序数组合并后的中位数

            //int[] a = new int[] { 1, 2, 3, 4 };
            //int[] b = new int[] { 5, 6, 7, 8, 9 };
            //Write(TestFindMedian.FindMedian(a, a.Length, b, b.Length));

            #endregion

            #region 找出n个整数中最小的K个数

            //int[] arr = new int[] { 4, 5, 1, 6, 2, 7, 3, 8 };
            //int k = 4;
            //TestGetLeastNumbers.GetLeastNumbers(arr, k);

            #endregion

            #region 求解数组中逆序对的个数

            //int[] arr = { 4, 5, 1, 6, 2, 7, 3, 8 };
            //WriteLine(TestReversePairs.ReversePairs(arr));

            #endregion

            #region 找出数组的峰值

            //int[] arr = { 1, 2, 1, 3, 4, 5, 7, 6 };
            //WriteLine(TestFindPeakElement.FindPeakElement(arr));

            #endregion

            #region 找出数组中的乘积最大子序列

            //int[] array = { 1, 2, 1, 3, 4, 5, 7, 6 };
            //WriteLine(TestMaxSubProduct.MaxSubProduct(array));

            #endregion

            #region 对数组进行旋转

            //int[][] matrix = new int[][] { new int[] { 1, 2, 3 }, new int[] { 4, 5, 6 }, new int[] { 7, 8, 9 } };
            //TestRotate testRotate = new TestRotate();
            //testRotate.Rotate2(matrix);
            //for (int i = 0; i < matrix.Length; i++)
            //{
            //    for (int j = 0; j < matrix[i].Length; j++)
            //    {
            //        Write(matrix[i][j] + " ");
            //    }
            //    WriteLine("");
            //}

            #endregion

            #region 求数组的最大子数组差

            //int[] arr = { 1, 2, -3, 1 };
            //WriteLine(TestMaxDiffSubArrays.MaxDiffSubArrays(arr));

            #endregion

            #region 如何统计比给定整数小的数的个数

            //int[] a = { 1, 2, 7, 8, 5 };
            //int[] b = { 1, 8, 5 };
            //WriteLine(string.Join(",", TestCountOfSmallerNumber.CountOfSmallerNumber(a, b)));

            #endregion

            #region 如何进行摇摆排序

            //var arr = new int[] { 3, 5, 2, 1, 6, 4 };
            //TestWiggleSort.WiggleSort(arr);
            //for (int i = 0; i < arr.Length; i++)
            //{
            //    Write(arr[i] + " ");
            //}

            #endregion

            #region 求解数组排序前后最大的间隔

            //var arr = new int[] { 1, 9, 2, 5 };
            //WriteLine(TestMaxGap.MaxGap(arr));

            #endregion

            #region 找出和最接近0的子数组

            //var array = new int[] { -3, 1, 1, -3, 5 };
            //Console.WriteLine(String.Join("", TestSubarraySumClosest.SubarraySumClosest(array)));

            #endregion

            #region 找出数组中和为指定值的四元组

            //var array = new int[] { 1, 0, -1, 0, -2, 2 };
            //var list = TestFourNum.FourNum(array,0);
            //foreach(var item in list )
            //{
            //    Console.WriteLine(string.Join(" ", item));
            //}

            #endregion

            #region 计算买股票的最佳时间

            //int[] prices = { 3, 2, 3, 1, 2 };
            //WriteLine(TestMaxProfit.MaxProfit(prices));

            #endregion

            #region 确定出发加油站问题

            //int[] gas = { 1, 1, 3, 1 };
            //int[] cost = { 2, 2, 1, 1 };
            //WriteLine(TestCanComplete.CanComplete(gas, cost));

            #endregion

            #region 求一个字符串的所有排列

            //String s = "abc";
            //TestPermutation.Permutation(s);

            //TestPermutationT.Permutation(s);
            //TestPermutationThree.Permutation(s);

            #endregion

            #region 求两个字符串的最长公共子串

            //String str1 = "abccade";
            //String str2 = "dgcadde";
            //Console.WriteLine(TestGetMaxSubStr.GetMaxSubStr(str1, str2));
            //Console.WriteLine(TestGetMaxSubStr.GetMaxSubStrHD(str1, str2));

            #endregion

            #region 判断两个字符串是否为换位字符串

            //String strone = "aaaabbc";
            //String strtwo = "abcbaaa";
            //Console.WriteLine(strone + "和" + strtwo);
            //if(TextCompare .Compare (strone ,strtwo ))
            //{
            //    Console.WriteLine("是换位字符");
            //}
            //else
            //{
            //    Console.WriteLine("不是换位字符");
            //}


            #endregion

            #region 判断两个字符串的包含关系

            //String str1 = "abcdef";
            //String str2 = "acf";
            //bool isContain = TestIsContain.IsContain(str1, str2);
            ////时间换空间方法
            //isContain = TestIsContain.IsContainT(str1, str2);
            //Console.Write(str1 + "和" + str2);
            //if (isContain)
            //{
            //    Console.WriteLine("有包含关系");
            //}
            //else
            //{
            //    Console.WriteLine("没有包含关系");
            //}

            #endregion

            #region 对由大小写字母组成的字符数组排序

            //char[] ch = "AbcDef".ToCharArray();
            //TestReverseArray.ReverseArray(ch);
            //for (int i = 0; i < ch.Length; i++)
            //{
            //    Console.Write(ch[i]);
            //}

            #endregion

            #region 88. 合并两个有序数组

            //Merge merge = new Merge();
            //int[] nums1 = { 1, 2, 3, 0, 0, 0 };
            //int m = 3;
            //int[] nums2 = { 2, 5, 6 };
            //int n = 3;
            //merge.Method(nums1, m, nums2, n);

            #endregion

            #region 去掉字符串中嵌套的括号

            //string str = "(1,(2,3),(4,(5,6),7))";
            //Console.WriteLine(str + "去除嵌套括号后是：" + TestRemoveNestedPare.RemoveNestedPare(str));

            #endregion

            #region 判断字符串是否是整数

            //TestIsNumber testIsNumber = new TestIsNumber();
            //String s = "-543";
            //Console.WriteLine(testIsNumber.strToint(s));

            //s = "543";
            //Console.WriteLine(testIsNumber.strToint(s));

            //s = "+543";
            //Console.WriteLine(testIsNumber.strToint(s));

            //s = "++43";
            //int result = testIsNumber.strToint(s);
            //Console.WriteLine(result);

            #endregion

            #region 实现字符串的匹配

            //String s = "xyzabcd";
            //String p = "abc";
            //Console.WriteLine(TestMatch.match(s, p));

            //------------------------------

            //String s = "abababaabcbab";
            //String p = "ababac";
            //int len = p.Length;
            //int[] next = new int[len + 1];
            //TestMatchT.GetNext(p, next);
            //Console.Write("next数组为：" + next[0]);
            //for(int i=1;i<len -1;i++)
            //{
            //    Console.Write("," + next[i]);
            //}
            //Console.WriteLine();
            //Console.WriteLine("匹配结果为：" + TestMatchT.Match(s, p, next));


            #endregion

            #region 求字符串的编辑距离

            //String s1 = "bciln";
            //String s2 = "fciling";
            //TestEditDistance testEditDistance = new TestEditDistance();
            //WriteLine("第一问：");
            //WriteLine("编辑距离：" + testEditDistance.edit(s1, s2, 1));
            //WriteLine("第二问：");
            //WriteLine("编辑距离：" + testEditDistance.edit(s1, s2, 2));

            #endregion

            #region 查找到达目标词的最短链长度

            //TestIsAdjacent testIsAdjacent = new TestIsAdjacent();
            //List<String> D = new List<string>();
            //D.Add("pooN");
            //D.Add("pbcc");
            //D.Add("azmc");
            //D.Add("poIc");
            //D.Add("pbca");
            //D.Add("pbIc");
            //D.Add("poIN");
            //String start = "TooN";
            //String target = "pbca";
            //Console.WriteLine("最短的链条的长度为：" + testIsAdjacent.shortestChainLen(start, target, D));

            #endregion

















            ReadLine();
        }

        #region 求数组连续最大和

        private int begin = 0;  //记录最大子数组起始位置
        private int end = 0;    //记录最大子数组结束位置

        public int MaxSubArrayOne(int[] arr)
        {
            int n = arr.Length;
            int maxSum = int.MinValue;  //子数组最大值
            int nSum = 0;   //包含子数组最后一位的最大值
            int nStart = 0;
            for (int i = 0; i < n; i++)
            {
                if (nSum < 0)
                {
                    nSum = arr[i];
                    nStart = i;
                }
                else
                {
                    nSum += arr[i];
                }
                if (nSum > maxSum)
                {
                    maxSum = nSum;
                    begin = end;
                    end = i;
                }
            }
            return maxSum;
        }

        #endregion
    }
}
