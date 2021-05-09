using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 无序链表实现映射
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    class LinkedListThreeDictionary<Key, Value> : Ahao.DataStructure.DictionaryFiles.IDictionary<Key, Value>
    {
        private LinkedListThree<Key, Value> list;
        public LinkedListThreeDictionary()
        {
            list = new LinkedListThree<Key, Value>();
        }

        public int Count
        {
            get
            {
                return list.Count;
            }
        }

        public bool IsEmpty
        {
            get
            {
                return list.IsEmpty;
            }
        }

        public void Add(Key key, Value value)
        {
            list.Add(key, value);
        }

        public bool ContainsKey(Key key)
        {
            return list.Contains(key);
        }

        public Value Get(Key key)
        {
            return list.Get(key);
        }

        public void Remove(Key key)
        {
            list.RemoveEle(key);
        }

        public void Set(Key key, Value newValue)
        {
            list.Set(key, newValue);
        }
    }
}
