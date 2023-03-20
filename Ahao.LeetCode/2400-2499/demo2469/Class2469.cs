using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2469
{
    public class Class2469
    {
        public double[] ConvertTemperature(double celsius)
        {
            double[] res = new double[2];
            res[0] = celsius + 273.15;
            res[1] = celsius * 1.80 + 32.00;
            return res;
        }


        public double[] ConvertTemperature2(double celsius)
        {
            return new double[] { celsius + 273.15, celsius * 1.80 + 32.00 };
        }

    }
}
