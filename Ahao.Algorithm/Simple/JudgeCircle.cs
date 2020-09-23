using System;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 657.机器人能否返回原点
    /// </summary>
    public class JudgeCircle
    {
        public bool Method(string moves)
        {
            bool IsTrue = false;
            char[] charStr = moves.ToCharArray();
            int lCount = 0;
            int rCount = 0;
            int uCount = 0;
            int dCount = 0;

            if (Convert.ToInt32(charStr.Length) % 2 != 0)
            {
                return IsTrue;
            }
            else
            {
                for (int i = 0; i < charStr.Length; i++)
                {
                    if (charStr[i].ToString().ToUpper() == "L")
                    {
                        lCount += 1;
                    }
                    if (charStr[i].ToString().ToUpper() == "R")
                    {
                        rCount += 1;
                    }
                    if (charStr[i].ToString().ToUpper() == "D")
                    {
                        dCount += 1;
                    }
                    if (charStr[i].ToString().ToUpper() == "U")
                    {
                        uCount += 1;
                    }
                }
                if (lCount == rCount && uCount == dCount)
                {
                    IsTrue = true;
                }
                return IsTrue;
            }


        }
    }
}
