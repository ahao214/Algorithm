using Ahao.LeetCode.Medium;
using Ahao.LeetCode.Medium.demo334;
using Ahao.LeetCode.Medium.demo825;
using Ahao.LeetCode.Medium.demo846;
using Ahao.LeetCode.Simple.demo1716;
using Ahao.LeetCode.Simple.demo5908;
using Ahao.LeetCode.Medium.demo5194;
using Ahao.LeetCode.Simple;
using Ahao.LeetCode.Medium.demo5990;
using Ahao.LeetCode.Medium.demo5981;
using System;
using static System.Console;
using Ahao.LeetCode.Hard;
using Ahao.LeetCode._5200_5299.demo5236;
using Ahao.LeetCode._0900_0999.demo954;

namespace Ahao.LeetCode
{
    class Program
    {
        static void Main(string[] args)
        {
            #region 33. 搜索旋转排序数组

            //Class33 class33 = new Class33();
            //int[] arr = { 4, 5, 6, 7, 0, 1, 2 };
            //int target = 0;
            //WriteLine(class33.Search(arr, target));


            #endregion

            #region 1005. K 次取反后最大化的数组和

            //Class1005 class1005 = new Class1005();
            //int[] arr = { 2, -3, -1, 5, -4 };
            //int k = 2;
            //WriteLine(class1005.LargestSumAfterKNegations(arr, k));

            #endregion

            #region 825. 适龄的朋友

            //int[] ages = { 20, 30, 100, 110, 120 };

            //Class825 class825 = new Class825();
            //WriteLine(class825.NumFriendRequests2(ages));

            #endregion

            #region

            int[] hand = { 1, 2, 3, 6, 2, 3, 4, 7, 8 };
            int groupSize = 3;
            Class846 class846 = new Class846();
            WriteLine(class846.IsNStraightHand(hand, groupSize));

            #endregion

            #region


            #endregion

            #region


            #endregion

            #region 334. 递增的三元子序列

            //Class334 class334 = new Class334();
            //int[] arr = { 20, 100, 10, 12, 5, 13 };
            //WriteLine(class334.IncreasingTriplet(arr));

            #endregion

            #region 1716. 计算力扣银行的钱

            //Class1716 class1716 = new Class1716();
            //WriteLine(class1716.TotalMoney(10));

            #endregion

            #region 5980. 将字符串拆分为若干长度为 k 的组

            //Class5908 class5908 = new Class5908();
            //string s = "ctoyjrwtngqwt";
            //int k = 8;
            //char c = 'n';
            //class5908.DivideString(s, k, c);

            #endregion

            #region 5194. 得到目标值的最少行动次数

            //Class5194 class5194 = new Class5194();
            //int target = 10;
            //int maxDoubles = 4;
            //WriteLine(class5194.MinMoves(target, maxDoubles));

            #endregion

            #region 5990.找出数组中的所有孤独数字

            //Class5990 class5990 = new Class5990();
            //int[] nums = { 1, 3, 3, 5 };
            //class5990.FindLonely(nums);

            #endregion

            #region 5991. 按符号重排数组

            //Class5991 class5991 = new Class5991();
            //int[] nums = { 3, 1, -2, -5, 2, -4 };
            //class5991.RearrangeArray(nums);

            #endregion

            #region 5981. 分组得分最高的所有下标

            //Class5981 class5981 = new Class5981();
            //int[] nums = { 0, 0, 1, 0 };
            //class5981.MaxScoreIndices(nums);

            #endregion

            #region 1984. 学生分数的最小差值

            //Class1984 class1984 = new Class1984();
            //int[] nums = { 9, 4, 1, 7 };
            //int k = 2;
            //class1984.MinimumDifference(nums, k);

            #endregion



            Class954 class954 = new Class954();
            int[] ar = { 1, 2, 4, 16, 8, 4 };
            class954.CanReorderDoubled(ar);






            ReadLine();
        }
    }
}
