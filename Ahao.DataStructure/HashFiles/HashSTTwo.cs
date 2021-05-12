using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 哈希表
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    class HashSTTwo<Key, Value>
    {
        private LinkedListThree<Key, Value>[] hashtable;
        private int N;
        private int M;
        public HashSTTwo(int M)
        {
            this.M = M;
            N = 0;
            hashtable = new LinkedListThree<Key, Value>[M];
            for (int i = 0; i < M; i++)
            {
                hashtable[i] = new LinkedListThree<Key, Value>();
            }
        }

        public HashSTTwo() : this(97) { }

        public int Count { get { return N; } }
        public bool IsEmpty { get { return N == 0; } }
        private int Hash(Key key)
        {
            return (key.GetHashCode() & 0x7fffffff) % M;
        }

        public void Add(Key key, Value value)
        {
            LinkedListThree<Key, Value> lst = hashtable[Hash(key)];
            if (lst.Contains(key))
            {
                lst.Set(key, value);
            }
            else
            {
                lst.Add(key, value);
                N++;
            }
        }

        public void Remove(Key key)
        {
            LinkedListThree<Key, Value> lst = hashtable[Hash(key)];
            if (lst.Contains(key))
            {
                lst.RemoveEle(key);
                N--;
            }
        }

        public bool Contains(Key key)
        {
            LinkedListThree<Key, Value> lst = hashtable[Hash(key)];
            return lst.Contains(key);
        }

        public Value Get(Key key)
        {
            LinkedListThree<Key, Value> lst = hashtable[Hash(key)];
            return lst.Get(key);
        }

        public void Set(Key key, Value newValue)
        {
            LinkedListThree<Key, Value> lst = hashtable[Hash(key)];
            lst.Set(key, newValue);
        }


    }
}
