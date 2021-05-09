using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 循环数组
    /// </summary>
    /// <typeparam name="E"></typeparam>
    class ArrayTwo<E>
    {
        private E[] data;
        private int first;
        private int last;
        private int N;

        public ArrayTwo(int capacity)
        {
            data = new E[capacity];
            first = 0;
            last = 0;
            N = 0;
        }

        public ArrayTwo() : this(10) { }

        public int Count { get { return N; } }
        public bool IsEmpty { get { return N == 0; } }

        //添加
        public void Add(E e)
        {
            if (N == data.Length)
                ResetCapacity(2 * data.Length);

            data[last] = e;
            last = (last + 1) % data.Length;
            N++;
        }


        //删除
        public E RemoveFirst()
        {
            if (IsEmpty)
                throw new InvalidOperationException("数组为空");

            E res = data[first];
            data[first] = default(E);
            first = (first + 1) % data.Length;
            N--;

            if (N == data.Length / 4)
                ResetCapacity(data.Length / 2);

            return res;
        }


        public E GetFirst()
        {
            if (IsEmpty)
                throw new InvalidOperationException("数组为空");
            return data[first];
        }

        //扩充容量大小
        public void ResetCapacity(int newCapacity)
        {
            E[] newData = new E[newCapacity];
            for (int i = 0; i < N; i++)
                newData[i] = data[(first + 1) % data.Length];
            data = newData;
            first = 0;
            last = N;
        }


        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("[");

            for (int i = 0; i < N; i++)
            {
                sb.Append(data[(first + i) % data.Length]);
                if ((first + i + 1) % data.Length != last)
                    sb.Append(",");
            }

            sb.Append("]");
            return sb.ToString();
        }


    }
}
