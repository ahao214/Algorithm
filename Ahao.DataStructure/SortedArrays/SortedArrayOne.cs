﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 有序数组
    /// </summary>
    class SortedArrayOne<Key> where Key : IComparable<Key>
    {
        private Key[] keys;
        private int N;
        public SortedArrayOne(int capacity)
        {
            keys = new Key[capacity];
        }

        public SortedArrayOne() : this(10) { }

        public int Count { get { return N; } }
        public bool IsEmpty { get { return N == 0; } }

        //查询元素的索引
        public int Rank(Key key)
        {
            int left = 0;
            int right = N - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (key.CompareTo(keys[mid]) < 0)
                    right = mid - 1;
                else if (key.CompareTo(keys[mid]) > 0)
                    left = mid + 1;
                else
                    return mid;
            }
            return left;
        }

        //添加
        public void Add(Key key)
        {
            int index = Rank(key);
            if (index < N && keys[index].CompareTo(key) == 0)
                return;
            for (int j = N - 1; j >= index; j--)
                keys[j + 1] = keys[j];
            keys[index] = key;
            N++;
        }

        //删除
        public void Remove(Key key)
        {
            if (IsEmpty)
                return;
            int i = Rank(key);
            if (i == N || keys[i].CompareTo(key) != 0)
                return;
            for (int j = i + 1; j <= N - 1; j++)
                keys[j - 1] = keys[j];
            N--;
            keys[N] = default(Key);
        }


    }
}
