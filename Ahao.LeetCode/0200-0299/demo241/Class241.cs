﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo241
{
    public class Class241
    {
        const int ADDITION = -1;
        const int SUBTRACTION = -2;
        const int MULTIPLICATION = -3;

        public IList<int> DiffWaysToCompute(string expression)
        {
            IList<int> ops = new List<int>();
            for (int i = 0; i < expression.Length;)
            {
                if (!char.IsDigit(expression[i]))
                {
                    if (expression[i] == '+')
                    {
                        ops.Add(ADDITION);
                    }
                    else if (expression[i] == '-')
                    {
                        ops.Add(SUBTRACTION);
                    }
                    else
                    {
                        ops.Add(MULTIPLICATION);
                    }
                    i++;
                }
                else
                {
                    int t = 0;
                    while (i < expression.Length && char.IsDigit(expression[i]))
                    {
                        t = t * 10 + expression[i] - '0';
                        i++;
                    }
                    ops.Add(t);
                }
            }
            IList<int>[][] dp = new IList<int>[ops.Count][];
            for (int i = 0; i < ops.Count; i++)
            {
                dp[i] = new IList<int>[ops.Count];
            }
            for (int i = 0; i < ops.Count; i++)
            {
                for (int j = 0; j < ops.Count; j++)
                {
                    dp[i][j] = new List<int>();
                }
            }
            return DFS(dp, 0, ops.Count - 1, ops);
        }

        public IList<int> DFS(IList<int>[][] dp, int l, int r, IList<int> ops)
        {
            if (dp[l][r].Count == 0)
            {
                if (l == r)
                {
                    dp[l][r].Add(ops[l]);
                }
                else
                {
                    for (int i = l; i < r; i += 2)
                    {
                        IList<int> left = DFS(dp, l, i, ops);
                        IList<int> right = DFS(dp, i + 2, r, ops);
                        foreach (int lv in left)
                        {
                            foreach (int rv in right)
                            {
                                if (ops[i + 1] == ADDITION)
                                {
                                    dp[l][r].Add(lv + rv);
                                }
                                else if (ops[i + 1] == SUBTRACTION)
                                {
                                    dp[l][r].Add(lv - rv);
                                }
                                else
                                {
                                    dp[l][r].Add(lv * rv);
                                }
                            }
                        }
                    }
                }
            }
            return dp[l][r];
        }

    }
}
