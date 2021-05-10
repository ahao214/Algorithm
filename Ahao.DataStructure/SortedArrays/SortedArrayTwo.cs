using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    class SortedArrayTwo<Key, Value> where Key : IComparable<Key>
    {
        private Key[] keys;
        private Value[] values;
        private int N;

        public SortedArrayTwo(int capacity)
        {
            keys = new Key[capacity];
            values = new Value[capacity];
        }

        public SortedArrayTwo() : this(10) { }

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


        public Value Get(Key key)
        {
            if (IsEmpty)
                throw new ArgumentException("数组为空");
            int i = Rank(key);
            if (i < N && keys[i].CompareTo(key) == 0)
                return values[i];
            else
                throw new ArgumentException("键" + key + "不存在");
        }


        //添加
        public void Add(Key key, Value value)
        {
            int index = Rank(key);
            if (N == keys.Length)
                N = keys.Length * 2;

            if (index < N && keys[index].CompareTo(key) == 0)
            {
                values[index] = value;
                return;
            }
            for (int j = N - 1; j >= index; j--)
            {
                keys[j + 1] = keys[j];
                values[j + 1] = values[j];
            }
            keys[index] = key;
            values[index] = value;
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
            {
                keys[j - 1] = keys[j];
                values[j - 1] = values[j];
            }
            N--;
            keys[N] = default(Key);
            values[N] = default(Value);
            if (N == keys.Length / 4)
                N = keys.Length / 2;
        }

        //数组最小值
        public Key Min()
        {
            if (IsEmpty)
                throw new ArgumentException("数组为空");
            return keys[0];
        }

        //数组最大值
        public Key Max()
        {
            if (IsEmpty)
                throw new ArgumentException("数组为空");

            return keys[N - 1];
        }

        public Key Select(int k)
        {
            if (k < 0 || k >= N)
                throw new ArgumentException("索引越界");

            return keys[k];
        }

        public bool Contains(Key key)
        {
            int i = Rank(key);
            if (i < N && keys[i].CompareTo(key) == 0)
                return true;
            return false;
        }

        //找出小于或等于key的最大值
        public Key Floor(Key key)
        {
            int i = Rank(key);
            if (i < N && keys[i].CompareTo(key) == 0)
                return keys[i];
            if (i == 0)
                throw new ArgumentException("没有找打小于或等于" + key + "的最大值");
            else
                return keys[i - 1];
        }

        //找出大于或等于key的最小值
        public Key Ceiling(Key key)
        {
            int i = Rank(key);
            if (i == N)
                throw new ArgumentException("没有找打大于或等于" + key + "的最小值");
            else
                return keys[i];
        }

        //数组容量的修改
        private void ResetCapacity(int newCapacity)
        {
            Key[] newKeys = new Key[newCapacity];
            Value[] newValues = new Value[newCapacity];

            for (int i = 0; i < N; i++)
            {
                newKeys[i] = keys[i];
                newValues[i] = values[i];
            }
            keys = newKeys;
            values = newValues;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("[");
            for (int i = 0; i < N; i++)
            {
                sb.Append("{" + keys[i] + "," + values[i] + "}");
                if (i != N - 1)
                    sb.Append(", ");
            }
            sb.Append("]");
            return sb.ToString();
        }
    }
}
