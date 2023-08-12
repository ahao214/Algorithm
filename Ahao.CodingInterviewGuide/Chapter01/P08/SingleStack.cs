using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.CodingInterviewGuide.Chapter01.P08
{
    public class SingleStack
    {
        public int[][] RightWay(int[] arr)
        {
            int n = arr.Length;
            int[][] res = new int[n][];
            for (int i = 0; i < n; i++)
            {
                res[i] = new int[2];
            }

            for (int i = 0; i < n; i++)
            {
                int leftLessIndex = -1;
                int rightLessIndex = -1;
                int cur = i - 1;
                while (cur >= 0)
                {
                    if (arr[cur] < arr[i])
                    {
                        leftLessIndex = cur;
                        break;
                    }
                    cur--;
                }
                cur = i + 1;
                while (cur < n)
                {
                    if (arr[cur] < arr[i])
                    {
                        rightLessIndex = cur;
                        break;
                    }
                    cur++;
                }
                res[i][0] = leftLessIndex;
                res[i][1] = rightLessIndex;
            }
            return res;
        }


        public int[][] GetNearLessNoRepeat(int[] arr)
        {
            int n = arr.Length;
            int[][] res = new int[n][];
            for (int i = 0; i < n; i++)
            {
                res[i] = new int[2];
            }

            Stack<int> stk = new Stack<int>();
            for (int i = 0; i < n; i++)
            {
                while (stk.Count != 0 && arr[stk.Peek()] > arr[i])
                {
                    int popIndex = stk.Pop();
                    int leftLessIndex = stk.Count == 0 ? -1 : stk.Peek();
                    res[popIndex][0] = leftLessIndex;
                    res[popIndex][1] = i;
                }
                stk.Push(i);
            }

            while (stk.Count != 0)
            {
                int popIndex = stk.Pop();
                int leftLessIndex = stk.Count == 0 ? -1 : stk.Peek();
                res[popIndex][0] = leftLessIndex;
                res[popIndex][1] = -1;
            }
            return res;

        }



    }
}
