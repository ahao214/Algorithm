using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo1610
{
    /// <summary>
    /// 1610. 可见点的最大数目
    /// </summary>
    public class Class1610
    {
        //二分查找
        public int VisiblePoints(IList<IList<int>> points, int angle, IList<int> location)
        {
            int sameCnt = 0;
            List<double> polarDegrees = new List<double>();
            int locationX = location[0];
            int locationY = location[1];
            //在一条直线上的点
            for (int i = 0; i < points.Count; ++i)
            {
                int x = points[i][0];
                int y = points[i][1];
                if (x == locationX && y == locationY)
                {
                    sameCnt++;
                    continue;
                }
                double degree = Math.Atan2(y - locationY, x - locationX);
                polarDegrees.Add(degree);
            }
            polarDegrees.Sort();

            int m = polarDegrees.Count;
            for (int i = 0; i < m; ++i)
            {
                polarDegrees.Add(polarDegrees[i] + 2 * Math.PI);
            }

            int maxCnt = 0;
            double toDegree = angle * Math.PI / 180.0;
            for (int i = 0; i < m; ++i)
            {
                int iteration = BinarySearch(polarDegrees, polarDegrees[i] + toDegree, false);
                maxCnt = Math.Max(maxCnt, iteration - i);
            }
            return maxCnt + sameCnt;
        }

        public int BinarySearch(List<double> nums, double target, bool lower)
        {
            int left = 0, right = nums.Count - 1;
            int ans = nums.Count;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (nums[mid] > target || (lower && nums[mid] >= target))
                {
                    right = mid - 1;
                    ans = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return ans;
        }



        //滑动窗口
        public int VisiblePoints2(IList<IList<int>> points, int angle, IList<int> location)
        {
            int sameCnt = 0;
            List<double> polarDegrees = new List<double>();
            int locationX = location[0];
            int locationY = location[1];
            //在一条直线上的点
            for (int i = 0; i < points.Count; ++i)
            {
                int x = points[i][0];
                int y = points[i][1];
                if (x == locationX && y == locationY)
                {
                    sameCnt++;
                    continue;
                }
                double degree = Math.Atan2(y - locationY, x - locationX);
                polarDegrees.Add(degree);
            }
            polarDegrees.Sort();

            int m = polarDegrees.Count;
            for (int i = 0; i < m; ++i)
            {
                polarDegrees.Add(polarDegrees[i] + 2 * Math.PI);
            }

            int maxCnt = 0;
            int right = 0;
            double toDegree = angle * Math.PI / 180;
            for (int i = 0; i < m; ++i)
            {
                double curr = polarDegrees[i] + toDegree;
                while (right < polarDegrees.Count && polarDegrees[right] <= curr)
                {
                    right++;
                }
                maxCnt = Math.Max(maxCnt, right - i);
            }
            return maxCnt + sameCnt;
        }
    }
}
