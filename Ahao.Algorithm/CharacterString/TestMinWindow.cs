using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.CharacterString
{
    /// <summary>
    /// 进行子串查询
    /// </summary>
    public class TestMinWindow
    {
        public void MinWindow(string s, string t)
        {
            int slen = s.Length;
            int tlen = t.Length;
            //开始位置
            int startWin = 0;
            //结束位置
            int endWin = 0;

            if (slen <= 0 || tlen <= 0)
                return;
            //存储T中不同字符的总数2的8次方
            int[] needFind = new int[256];
            for (int i = 0; i < tlen; i++)
            {
                ++needFind[t[i]];
            }

            //存储到目前为止遇到过的不同字符的总数
            int[] hasFound = new int[256];
            //存储到目前为止遇到过的T中字符总数
            int count = 0;
            int minWin = int.MaxValue;
            int endEle;
            for (int start = 0, end = 0; end < slen; end++)
            {
                endEle = s[end];
                //减枝无用字符(T中字符为有用字符)
                if (needFind[endEle] == 0)
                    continue;
                ++hasFound[endEle];
                if (hasFound[endEle] <= needFind[endEle])
                    ++count;

                //找到一个有效窗口
                if (count == tlen)
                {
                    int begEle = s[start];
                    //满足：字符为无用字符，当begEle元素找多了时start指针才向右移动
                    while (needFind[begEle] == 0 || hasFound[begEle] > needFind[begEle])
                    {
                        if (hasFound[begEle] > needFind[begEle])
                        {
                            --hasFound[begEle];
                        }
                        ++start;
                        begEle = s[start];
                    }
                    //更新最小窗口
                    int curWin = end - start + 1;
                    if (curWin < minWin)
                    {
                        minWin = curWin;
                        startWin = start;
                        endWin = end;
                    }
                }
            }
            if (count == tlen)
            {
                Console.WriteLine(s.Substring(startWin, endWin - startWin + 1));
            }
            else
            {
                Console.WriteLine("未找到");
            }


        }
    }
