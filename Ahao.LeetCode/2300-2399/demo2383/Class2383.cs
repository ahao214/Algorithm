using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2300_2399.demo2383
{
    public class Class2383
    {

        public int MinNumberOfHours(int initialEnergy, int initialExperience, int[] energy, int[] experience)
        {
            int sum = 0;
            foreach (int e in energy)
            {
                sum += e;
            }
            int trainingHours = initialEnergy > sum ? 0 : sum + 1 - initialEnergy;
            foreach (int e in experience)
            {
                if (initialExperience <= e)
                {
                    trainingHours += 1 + (e - initialExperience);
                    initialExperience = 2 * e + 1;
                }
                else
                {
                    initialExperience += e;
                }
            }
            return trainingHours;
        }


        public int MinNumberOfHours2(int initialEnergy, int initialExperience, int[] energy, int[] experience)
        {
            int res = 0;
            int sumEnergy = energy.Sum();
            if (sumEnergy >= initialEnergy)
            {
                res = sumEnergy - initialEnergy + 1;
            }
            foreach (var item in experience)
            {
                if (item >= initialExperience)
                {
                    res += item - initialExperience + 1;
                    initialExperience = 2 * item + 1;
                }
                else
                {
                    initialExperience += item;
                }
            }
            return res;
        }
    }
}
