using System;

/// <summary>
/// Summary description for Class1
/// </summary>
public class Class794
{
    public Class794()
    {
        //
        // TODO: Add constructor logic here
        //
    }

    /// <summary>
    /// 794. 有效的井字游戏
    /// </summary>
    /// <param name="board"></param>
    /// <returns></returns>
    public bool ValidTicTacToe(string[] board)
    {
        int xCount = 0, oCount = 0;
        foreach (string row in board)
        {
            foreach (char c in row)
            {
                if (c == 'X')
                {
                    xCount++;
                }
                if (c == 'O')
                {
                    oCount++;
                }
            }
        }
        if (oCount != xCount && oCount != xCount - 1)
        {
            return false;
        }
        if (win(board, 'X') && oCount != xCount - 1)
        {
            return false;
        }
        if (win(board, 'O') && oCount != xCount)
        {
            return false;
        }
        return true;
    }

    public bool win(string[] board, char p)
    {
        for (int i = 0; i < 3; ++i)
        {
            if ((p == board[i][0] && p == board[i][1] && p == board[i][2]) || (p == board[0][i] && p == board[1][i] && p == board[2][i]))
            {
                return true;
            }
        }
        if ((p == board[0][0] && p == board[1][1] && p == board[2][2]) || (p == board[0][2] && p == board[1][1] && p == board[2][0]))
        {
            return true;
        }
        return false;
    }

}
