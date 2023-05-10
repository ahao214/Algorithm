using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1015
{
    public class Class1015
    {

        public int SmallestRepunitDivByK(int k)
        {
            int resid = 1 % k, len = 1; // resid为余数，len为数字长度，初始值为1
            ISet<int> set = new HashSet<int>(); // 创建一个无序集合，用于存储余数
            set.Add(resid); // 插入余数1
            while (resid != 0)
            { // 当余数为0时退出循环
                resid = (resid * 10 + 1) % k; // 计算下一个余数
                len++; // 数字长度+1
                if (set.Contains(resid))
                { // 如果余数重复出现，则无解
                    return -1;
                }
                set.Add(resid); // 将余数插入集合
            }
            return len; // 返回数字长度
        }


    }
}
