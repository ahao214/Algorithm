using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1629
{
    /// <summary>
    /// 1629. 按键持续时间最长的键
    /// </summary>
    public class Class1629
    {
        public char SlowestKey(int[] releaseTimes, string keysPressed)
        {
            int longestTime = releaseTimes[0];
            char res = keysPressed[0];
            for (int i = 1; i < releaseTimes.Length; i++)
            {
                int time = releaseTimes[i] - releaseTimes[i - 1];
                char key = keysPressed[i];
                if (time > longestTime || (time == longestTime && key > res))
                {
                    res = key;
                    longestTime = time;
                }
            }
            return res;
        }
    }
}
