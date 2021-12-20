using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Ahao.LeetCode.Hard.demo85
{
    /// <summary>
    /// 85. 最大矩形
    /// </summary>
    public class Class85
    {
        public int MaximalRectangle(char[][] matrix)
        {
            if (matrix == null || matrix.Length == 0)
            {
                return 0;
            }
            var rowCount = matrix.Length;
            var colCount = matrix[0].Length;
            var hcount = new int[rowCount, colCount];
            var vcount = new int[rowCount, colCount];

            for (int i = 0; i < colCount; i++)
            {
                vcount[rowCount - 1, i] = 0;
            }

            for (int i = 0; i < rowCount; i++)
            {
                hcount[i, colCount - 1] = 0;
            }

            for (int i = rowCount - 1; i >= 0; i--)
            {
                for (int j = colCount - 1; j >= 0; j--)
                {
                    if (matrix[i][j] == '0')
                    {
                        hcount[i, j] = 0;
                        vcount[i, j] = 0;
                    }
                    else
                    {
                        hcount[i, j] = j + 1 == colCount ? 0 : hcount[i, j + 1] + 1;
                        vcount[i, j] = i + 1 == rowCount ? 0 : vcount[i + 1, j] + 1;
                    }
                }
            }
            
            var heap = new MinHeap<Item>(new List<Item>(rowCount * colCount), 0, (x, y) => Comparer<int>.Default.Compare(x.Value, y.Value));

            

            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < colCount; j++)
                {
                    if (matrix[i][j] != '0')
                    {
                        heap.Insert(new Item(i * colCount + j, i, j, 1, 1));
                    }
                }
            }

            var maxValue = 0;
            while (heap.Count > 0)
            {
                var item = heap.PopRoot();
                var row = item.Row;
                var col = item.Col;

                if (hcount[row, col] * vcount[row, col] <= maxValue)
                {
                    maxValue = Math.Max(maxValue, item.Area);
                }

                if (item.HAble)
                {
                    if (item.NextCol < colCount && vcount[row, item.NextCol] >= item.Height)
                    {
                        heap.Insert(new Item(item.Value, row, col, item.Width + 1, item.Height, true));
                    }
                }

                if (item.NextRow < rowCount && hcount[item.NextRow, col] >= item.Width)
                {
                    heap.Insert(new Item(item.Value, row, col, item.Width, item.Height + 1, true));
                }
            }
            return maxValue;
        }

        struct Item
        {
            public readonly int Value;
            public readonly int Row;
            public readonly int Col;
            public readonly int Height;
            public readonly int Width;
            public readonly bool HAble;

            public int NextRow => Row + Width;
            public int NextCol => Col + Width;
            public int Area => Width * Height;

            public Item(int value, int row, int col, int height, int width, bool hAble = true)
            {
                this.Value = value;
                this.Row = row;
                this.Col = col;
                this.Height = height;
                this.Width = width;
                this.HAble = hAble;
            }
        }
    }
}
