using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.ArrayNums
{
    /// <summary>
    /// 找到数组元素连接起来排成的所有数字中最小的一个
    /// </summary>
    public class TestComArrayMin
    {
        //自定义数字比较排序规则
        public class CustomComparer:System.Collections.IComparer
        {
            public int Compare(object x,object y)
            {
                string one = x.ToString();
                string two = y.ToString();
                //将两个字符拼接后进行排序
                one = one + two;
                two = two + one;
                return String.Compare(one, two);
            }
        }

        public static void ComArrayMin(int [] arr )
        {
            //根据自定义排序规则进行排序
            Array.Sort(arr, new CustomComparer());
            //输出集合
            Console.WriteLine(String.Join("", arr));
        }


    }
}
