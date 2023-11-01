using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    public class Class2103
    {
        const int POLE_NUM = 10;
        const int COLOR_NUM = 3;

        public int CountPoints(string rings)
        {
            int[][] state = new int[POLE_NUM][];
            for (int i = 0; i < POLE_NUM; i++)
            {
                state[i] = new int[COLOR_NUM];
            }
            int n = rings.Length;
            for (int i = 0; i < n; i += 2)
            {
                char color = rings[i];
                int poleIndex = rings[i + 1] - '0';
                state[poleIndex][GetColorId(color)] = 1;
            }
            int res = 0;
            for (int i = 0; i < POLE_NUM; i++)
            {
                bool flag = true;
                for (int j = 0; j < COLOR_NUM; j++)
                {
                    if (state[i][j] == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    res++;
                }
            }
            return res;
        }

        public int GetColorId(char color)
        {
            if (color == 'R')
            {
                return 0;
            }
            else if (color == 'G')
            {
                return 1;
            }
            return 2;
        }




        const int POLE_NUM1 = 10;

        public int CountPoints2(string rings)
        {
            int[] state = new int[POLE_NUM1];
            int n = rings.Length;
            for (int i = 0; i < n; i += 2)
            {
                char color = rings[i];
                int poleIndex = rings[i + 1] - '0';
                if (color == 'R')
                {
                    state[poleIndex] |= 1;
                }
                else if (color == 'G')
                {
                    state[poleIndex] |= 2;
                }
                else
                {
                    state[poleIndex] |= 4;
                }
            }
            int res = 0;
            for (int i = 0; i < POLE_NUM; i++)
            {
                res += state[i] == 7 ? 1 : 0;
            }
            return res;
        }



        public int CountPoints3(string rings)
        {
            Dictionary<int, int[]> dic = new Dictionary<int, int[]>();//杆编号+rgb(0,0,0)
            for (int i = 0; i < rings.Length; i += 2)
            {
                char color = rings[i];
                int key = int.Parse(rings[i + 1].ToString());
                if (dic.ContainsKey(key))
                {
                    if (color == 'R') dic[key][0]++;
                    else if (color == 'G') dic[key][1]++;
                    else if (color == 'B') dic[key][2]++;
                }
                else
                {
                    if (color == 'R') dic.Add(key, new int[3] { 1, 0, 0 });
                    else if (color == 'G') dic.Add(key, new int[3] { 0, 1, 0 });
                    else if (color == 'B') dic.Add(key, new int[3] { 0, 0, 1 });
                }
            }

            int res = 0;
            foreach (var d in dic)
            {
                int[] rgb = d.Value;
                if (rgb[0] > 0 && rgb[1] > 0 && rgb[2] > 0)
                    res++;//rgb每个都有，就满足了含3种颜色的圈圈
            }
            return res;
        }


        public int CountPoints4(string rings)
        {

            int res = 0;
            int[,] bucket = new int[10, 3];
            for (int i = 0; i < rings.Length; i += 2)
            {
                if (rings[i] == 'B')
                {
                    bucket[rings[i + 1] - '0', 0]++;
                }
                else if (rings[i] == 'R')
                {
                    bucket[rings[i + 1] - '0', 1]++;
                }
                else if (rings[i] == 'G')
                {
                    bucket[rings[i + 1] - '0', 2]++;
                }
            }
            for (int i = 0; i < 10; i++)
            {
                bool flage = true;
                for (int j = 0; j < 3; j++)
                {
                    if (bucket[i, j] == 0)
                    {
                        flage = false;
                        break;
                    }
                }
                if (flage == true) res++;
            }
            return res;
        }

    }
}
