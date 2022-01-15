using Ahao.LeetCode.Medium;
using Ahao.LeetCode.Medium.demo334;
using Ahao.LeetCode.Medium.demo825;
using Ahao.LeetCode.Medium.demo846;
using Ahao.LeetCode.Simple.demo1716;
using Ahao.LeetCode.Simple;
using System;
using static System.Console;

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

            ReadLine();
        }
    }
}
