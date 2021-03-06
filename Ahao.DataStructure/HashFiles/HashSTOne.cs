﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    class HashSTOne<Key>
    {
        private LinkedListOne<Key>[] hashtable;
        private int N;
        private int M;
        public HashSTOne(int M)
        {
            this.M = M;
            N = 0;
            hashtable = new LinkedListOne<Key>[M];
            for (int i = 0; i < M; i++)
            {
                hashtable[i] = new LinkedListOne<Key>();
            }
        }

        public HashSTOne() : this(97) { }

        public int Count { get { return N; } }
        public bool IsEmpty { get { return N == 0; } }
        private int Hash(Key key)
        {
            return (key.GetHashCode() & 0x7fffffff) % M;
        }

        public void Add(Key key)
        {
            LinkedListOne<Key> lst = hashtable[Hash(key)];
            if (lst.Contains(key))
            {
                return;
            }
            else
            {
                lst.AddFirst(key);
                N++;
            }
        }

        public void Remove(Key key)
        {
            LinkedListOne<Key> lst = hashtable[Hash(key)];
            if (lst.Contains(key))
            {
                lst.RemoveEle(key);
                N--;
            }
        }

        public bool Contains(Key key)
        {
            LinkedListOne<Key> lst = hashtable[Hash(key)];
            return lst.Contains(key);
        }






    }
}
