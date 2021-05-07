using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    class ArrayE<E>
    {
        private E[] data;
        private int N;

        public ArrayE(int capacity)
        {
            data = new E[capacity];
            N = 0;
        }

        public ArrayE() : this(10) { }

        /// <summary>
        /// 数组的容量
        /// </summary>
        public int Capacity
        {
            get { return data.Length; }
        }

        /// <summary>
        /// 数组中元素的个数
        /// </summary>
        public int Count
        {
            get { return N; }
        }

        /// <summary>
        /// 判断数组是否为空
        /// </summary>
        public bool IsEmpty
        {
            get { return N == 0; }
        }

        /// <summary>
        /// 向数组中添加元素
        /// </summary>
        /// <param name="index">添加的位置</param>
        /// <param name="ele">添加的元素</param>
        public void Add(int index, E ele)
        {
            if (index < 0 || index > N)
                throw new ArgumentException("数组索引越界");
            if (N == data.Length)
                ResetCapacity(2 * data.Length);     //数组扩大容量

            for (int i = N - 1; i >= index; i--)
            {
                //把前面一个元素赋值给后面
                data[i + 1] = data[i];
            }
            //把元素ele赋值到index位置
            data[index] = ele;
            //数组个数加1
            N++;
        }

        /// <summary>
        /// 向数组末尾添加数据
        /// </summary>
        /// <param name="ele"></param>
        public void AddLast(E ele)
        {
            Add(N, ele);
        }

        /// <summary>
        /// 向数组头部添加数据
        /// </summary>
        /// <param name="ele"></param>
        public void AddFirst(E ele)
        {
            Add(0, ele);
        }

        //获取某个位置的元素
        public E Get(int index)
        {
            if (index < 0 || index >= N)
                throw new ArgumentException("数组索引越界");
            return data[index];
        }

        //获取第一个元素
        public E GetFirst()
        {
            return Get(0);
        }

        //获取最后一个元素
        public E GetLast()
        {
            return Get(N - 1);
        }

        //设置某个位置的元素
        public void Set(int index, E newEle)
        {
            if (index < 0 || index >= N)
                throw new ArgumentException("数组索引越界");
            data[index] = newEle;
        }

        /// <summary>
        /// 是否包含某个元素
        /// </summary>
        /// <returns></returns>
        public bool Contains(int ele)
        {
            for (int i = 0; i < N; i++)
            {
                if (data[i].Equals(ele))
                    return true;
            }
            return false;
        }

        /// <summary>
        /// 元素的位置
        /// </summary>
        /// <param name="ele"></param>
        /// <returns></returns>
        public int IndexOf(int ele)
        {
            for (int i = 0; i < N; i++)
            {
                if (data[i].Equals(ele))
                    return i;
            }
            return -1;
        }

        /// <summary>
        /// 删除
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public E RemoveAt(int index)
        {
            if (index < 0 || index >= N)
                throw new ArgumentException("数组索引越界");
            E del = data[index];
            for (int i = index + 1; i <= N - 1; i++)
            {
                data[i - 1] = data[i];
            }
            N--;
            data[N] = default(E);

            //数组减小容量
            if (N == data.Length / 4)
                ResetCapacity(data.Length / 2);

            return del;
        }

        public E RemoveFirst()
        {
            return RemoveAt(0);
        }

        public E RemoveLast()
        {
            return RemoveAt(N - 1);
        }

        /// <summary>
        /// 删除某个元素
        /// </summary>
        /// <param name="ele"></param>
        public void Remove(int ele)
        {
            int index = IndexOf(ele);
            if (index != -1)
                RemoveAt(index);
        }

        /// <summary>
        /// 对数组进行扩容
        /// </summary>
        /// <param name="newCapacity"></param>
        private void ResetCapacity(int newCapacity)
        {
            E[] newData = new E[newCapacity];
            for (int i = 0; i < N; i++)
                newData[i] = data[i];
            data = newData;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(string.Format($"ArrayOne: Count={N}, Capacity={data.Length }\n"));
            sb.Append("[");
            for (int i = 0; i < N; i++)
            {
                sb.Append(data[i]);
                if (i != N - 1)
                    sb.Append(", ");
            }
            sb.Append("]");
            return sb.ToString();
        }
    }
}
