﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1333
{
    public class Class1333
    {

        public IList<int> FilterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance)
        {
            int n = restaurants.Length;
            IList<int[]> filtered = new List<int[]>();
            for (int i = 0; i < n; i++)
            {
                if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance && !(veganFriendly == 1 && restaurants[i][2] == 0))
                {
                    filtered.Add(restaurants[i]);
                }
            }
            ((List<int[]>)filtered).Sort((a, b) => {
                if (a[1] != b[1])
                {
                    return b[1] - a[1];
                }
                else
                {
                    return b[0] - a[0];
                }
            });
            IList<int> res = new List<int>();
            foreach (int[] v in filtered)
            {
                res.Add(v[0]);
            }
            return res;
        }


    }
}
