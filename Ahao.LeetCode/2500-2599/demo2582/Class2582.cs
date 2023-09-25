using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2500_2599.demo2582
{
    internal class Class2582
    {

        public int PassThePillow(int n, int time)
        {
            time %= (n - 1) * 2;
            return time < n ? time + 1 : n * 2 - time - 1;
        }

    }
}
