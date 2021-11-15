using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 860.柠檬水找零
    /// </summary>
    public class LemonadeChange
    {
        public bool Method(int[] bills)
        {
            bool result = true;
            int count = bills.Length;
            if (count == 0)
            {
                result = true;
            }
            else
            {
                if (bills[0] > 5)
                {
                    result = false;
                }
                else
                {
                    Dictionary<int, int> dic = new Dictionary<int, int>();
                    dic.Add(5, 0);
                    dic.Add(10, 0);
                    for (int i = 0; i < count; i++)
                    {
                        if (bills[i] == 5)
                        {
                            dic[5]++;
                        }
                        else if (bills[i] == 10)
                        {
                            if (dic[5] > 0)
                            {
                                dic[5]--;
                                dic[10]++;
                            }
                            else
                            {
                                result = false;
                            }
                        }
                        else if (bills[i] == 20)
                        {
                            if (dic[10] > 0 && dic[5] > 0)
                            {
                                dic[5]--;
                                dic[10]--;
                            }
                            else if (dic[5] > 3)
                            {
                                dic[5] -= 3;
                            }
                            else
                            {
                                result = false;
                            }
                        }
                    }
                }
            }
          
            return result;
        }
    }
}
