using Ahao.Algorithm.Tree;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.UI.WebControls;

namespace Ahao.Algorithm.Combinations
{
    /// <summary>
    /// 求数字的组合
    /// </summary>
    public class TestCombination
    {
        private int[] numbers = { 1, 2, 2, 3, 4, 5 };
        private int n = 6;
        //用来标记图中结点是否被遍历过
        private bool[] visited;
        //图的二维数组表示
        private int[,] graph;
        //数字的组合
        private StringBuilder combination = new StringBuilder();
        //存放所有的组合
        private HashSet<String> s = new HashSet<string>();

        public TestCombination(int[] arr)
        {
            numbers = arr;
            visited = new bool[numbers.Length];
            graph = new int[numbers.Length, numbers.Length];
        }

        /// <summary>
        /// 对图从结点start位置开始进行深度遍历
        /// </summary>
        /// <param name="start">遍历的起始位置</param>
        private void DepthFirstSearch(int start)
        {
            visited[start] = true;
            combination.Append(numbers[start]);
            if (combination.Length == n)
            {
                //数字4不出现在第三个位置
                if (combination.ToString().IndexOf("4") != 2)
                    s.Add(combination.ToString());
            }
            for (int j = 0; j < n; j++)
            {
                if (graph[start, j] == 1 && !visited[j])
                    DepthFirstSearch(j);
            }

            combination.Remove(combination.Length - 1, combination.Length);
            visited[start] = false;
        }

        /// <summary>
        /// 获取1/2/2/3/4/5的左右组合，使得"4"不能在第三位，"3"与"5"不能相连
        /// </summary>
        public void GetAllCombination()
        {
            int i;
            //构造图
            for (i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        graph[i, j] = 0;
                    }
                    else
                    {
                        graph[i, j] = 1;
                    }
                }
            }
            //确保在遍历的时候3与5是不可达的
            graph[3, 5] = 0;
            graph[5, 3] = 0;

            //分别从不同的结点出发深度遍历图
            for (i = 0; i < n; i++)
            {
                DepthFirstSearch(i);
            }
        }

        public void PrintAllCombinations()
        {
            foreach (var item in s)
            {
                Console.WriteLine(item);
            }
        }

    }
}
