using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.UI.WebControls;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 37.解数独
    /// </summary>
    public class SolveSudoku
    {
        //九列
        List<Dictionary<int, bool>> listCol = new List<Dictionary<int, bool>>();
        //九行
        List<Dictionary<int, bool>> listRow = new List<Dictionary<int, bool>>();
        //3*3格子 九个
        List<Dictionary<int, bool>> listBox = new List<Dictionary<int, bool>>();
        char[][] boardAll = null;
        public void Method(char[][] board)
        {
            //判断一共有多少个数字
            int hasNumCount = 0;
            Dictionary<int, bool> dicAllTemp = new Dictionary<int, bool>();
            //创建一个键值对集合存储数字是否出现过 
            for (int i = 1; i <= 9; i++)
            {
                dicAllTemp.Add(i, false);
            }
            for (int i = 0; i < 9; i++)
            {
                //存储对应的九列
                listCol.Add(new Dictionary<int, bool>(dicAllTemp));
                //存储对应的九行
                listRow.Add(new Dictionary<int, bool>(dicAllTemp));
                //存储对应的九个3*3格子
                listBox.Add(new Dictionary<int, bool>(dicAllTemp));
            }
            //遍历整个集合 将已出现的数字赋值为true 
            for (int i = 0; i < board.Length; i++)
            {
                for (int j = 0; j < board[0].Length; j++)
                {
                    if (board[i][j] != '.')
                    {
                        int temp = board[i][j] - 48;
                        listRow[i][temp] = true;
                        listCol[j][temp] = true;
                        int count = (i / 3) * 3 + j / 3;
                        listBox[count][temp] = true;
                        hasNumCount++;
                    }
                }
            }
            Recursive(board, hasNumCount, 0, 0);
            board = boardAll;
        }

        public bool Recursive(char[][] board, int hasNumCount, int i, int j)
        {
            //81个数字表示表格填满了 直接返回结果
            if (hasNumCount == 81)
            {
                boardAll = board;
                return true;
            }
            for (; i < board.Length; i++)
            {
                for (j = 0; j < board[0].Length; j++)
                {
                    if (board[i][j] == '.')
                    {
                        //查出该行对应的所有未使用的数字 一次遍历填入
                        List<int> liRes = listRow[i].Where(e => e.Value == false).Select(e => e.Key).ToList();
                        foreach (var item in liRes)
                        {
                            //判读位于那个格子 
                            int count = (i / 3) * 3 + j / 3;
                            if (listCol[j][item] == false && listBox[count][item] == false && listRow[i][item] == false)
                            {
                                //总数+1 对应的位置赋值为true
                                hasNumCount++;
                                listRow[i][item] = true;
                                listCol[j][item] = true;
                                listBox[count][item] = true;
                                //之所以加48为了将数字转为char类型存进去
                                board[i][j] = (char)(item + 48);
                                //递归 存在不符合就返回 结果为true只有一种情况 那就是81个空格已经填满数字
                                if (Recursive(board, hasNumCount, i, 0))
                                {
                                    return true;
                                }
                                //不符合 将操作撤回到之前 
                                hasNumCount--;
                                board[i][j] = '.';
                                listRow[i][item] = false;
                                listCol[j][item] = false;
                                listBox[count][item] = false;
                            }
                        }
                        return false;
                    }
                }
            }
            return false;
        }
    }
}
