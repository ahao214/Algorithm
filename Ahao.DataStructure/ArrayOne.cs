using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.DataStructure
{
    /// <summary>
    /// 动态数组
    /// </summary>
    class ArrayOne
    {
        private int[] data;
        private int N;

        public ArrayOne(int capacity)
        {
            data = new int[capacity];
            N = 0;
        }

        public ArrayOne() : this(10) { }

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
        public void Add(int index, int ele)
        {
            if (index < 0 || index > N)
                throw new ArgumentException("数组索引越界");
            if (N == data.Length)
                throw new ArgumentException("数组已满");
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
        public void AddLast(int ele)
        {
            Add(N, ele);
        }

        /// <summary>
        /// 向数组头部添加数据
        /// </summary>
        /// <param name="ele"></param>
        public void AddFirst(int ele)
        {
            Add(0, ele);
        }

        //获取某个位置的元素
        public int Get(int index)
        {
            if (index < 0 || index >= N)
                throw new ArgumentException("数组索引越界");
            return data[index];
        }

        //获取第一个元素
        public int GetFirst()
        {
            return Get(0);
        }

        //获取最后一个元素
        public int GetLast()
        {
            return Get(N - 1);
        }

        //设置某个位置的元素
        public void Set(int index, int newEle)
        {
            if (index < 0 || index >= N)
                throw new ArgumentException("数组索引越界");
            data[index] = newEle;
        }


        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(string.Format($"ArrayOne: Count={N}, Capacity={data.Length }"));
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
