#include "Common.h"
class LongestIncreasingPath {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        const unsigned int XDim = matrix.size();
        mXDim = XDim;
        if (XDim == 0) return 0;
        const unsigned int YDim = matrix[0].size();
        mYDim = YDim;
        int *longestPaths = new int[XDim * YDim];
        memset(longestPaths, 0, sizeof(int)* XDim * YDim);
        int result = 0;

        for (int i = 0; i < XDim; i++)
        {
            for (int j = 0; j < YDim; j++)
            {
                longestPaths[Tran(i, j)] = check(longestPaths, matrix, i, j);
                result = max(result, longestPaths[Tran(i, j)]);
            }
        }
        return result;
    }
    int check(int *longestPaths, vector<vector<int>> &matrix, int i, int j)
    {
        if (longestPaths[Tran(i, j)] == 0)
        {
            int len = 1;
            if (i > 0 && matrix[i][j] < matrix[i - 1][j])
            {
                len = max(len, 1 + check(longestPaths, matrix, i - 1, j));
            }            
            if (i + 1 < mXDim && matrix[i][j] < matrix[i + 1][j])
            {
                len = max(len, 1 + check(longestPaths, matrix, i + 1, j));
            }
            if (j > 0 && matrix[i][j] < matrix[i][j - 1])
            {
                len = max(len, 1 + check(longestPaths, matrix, i, j - 1));
            }
            if (j + 1 < mYDim && matrix[i][j] < matrix[i][j + 1])
            {
                len = max(len, 1 + check(longestPaths, matrix, i, j + 1));
            }
            longestPaths[Tran(i, j)] = len;
            return len;
        }
        return longestPaths[Tran(i, j)];
    }
    //// DP
    //function longestIncreasingPath(matrix) {
    //    var longestCount = [];
    //    var max = 0,
    //        k, x, y, tmp, dimX = matrix.length,
    //        dimY = dimX ? matrix[0].length : 0;
    //    for (x = 0; x < dimX; x++) {
    //        longestCount[x] = [];
    //        for (y = 0; y < dimY; y++)
    //            longestCount[x][y] = 1;
    //    }

    //    for (k = 0; k < dimX * dimY; k++) {
    //        tmp = 0;
    //        for (x = 0; x < dimX; x++) {
    //            for (y = 0; y < dimY; y++) {
    //                if (matrix[x - 1] && matrix[x - 1][y] && matrix[x - 1][y] > matrix[x][y])
    //                    longestCount[x][y] = Math.max(longestCount[x][y], longestCount[x - 1][y] + 1);
    //                if (matrix[x + 1] && matrix[x + 1][y] && matrix[x + 1][y] > matrix[x][y])
    //                    longestCount[x][y] = Math.max(longestCount[x][y], longestCount[x + 1][y] + 1);
    //                if (matrix[x][y - 1] && matrix[x][y - 1] > matrix[x][y])
    //                    longestCount[x][y] = Math.max(longestCount[x][y], longestCount[x][y - 1] + 1);
    //                if (matrix[x][y + 1] && matrix[x][y + 1] > matrix[x][y])
    //                    longestCount[x][y] = Math.max(longestCount[x][y], longestCount[x][y + 1] + 1);
    //                tmp = Math.max(tmp, longestCount[x][y]);
    //            }
    //        }
    //        if (tmp == = max && k >= tmp) return max;
    //        max = Math.max(tmp, max);
    //    }
    //    return max;
    //}
private:
    int mXDim;
    int mYDim;
    inline int Tran(int i, int j)
    {
        return (i * mYDim + j);
    }
    /*old alog
    public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		mXDim = matrix.size();
		if (mXDim == 0) return 0;
		mYDim = matrix[0].size();
		vector<list<int>> grap(mXDim * mYDim);

		for (int i = 0; i < mXDim; i++)
		{
			for (int j = 0; j < mYDim; j++)
			{
				int cur = matrix[i][j];
				if (i > 0 && cur < matrix[i - 1][j])
				{
					grap[Tran(i, j)].push_back(Tran(i - 1, j));
				}
				if (j > 0 && cur < matrix[i][j - 1])
				{
					grap[Tran(i, j)].push_back(Tran(i, j - 1));
				}
				if (i + 1 < mXDim && cur < matrix[i + 1][j])
				{
					grap[Tran(i, j)].push_back(Tran(i + 1, j));
				}
				if (j + 1 < mYDim && cur < matrix[i][j + 1])
				{
					grap[Tran(i, j)].push_back(Tran(i, j + 1));
				}
			}
		}
		result = 0;
		for (int i = 0; i < grap.size(); i++)
		{
			vector<bool> levelTags(grap.size(), false);
			queue<int> node;
			node.push(i);
			levelTags[i] = true;
			int levelTag = i;
			int temRes = 0;
			while (!node.empty())
			{
				int cur = node.front();
				node.pop();
				if (levelTags[cur]) temRes++;
				if (!grap[cur].empty())
				{
					for (list<int>::iterator iter = grap[cur].begin(); iter != grap[cur].end(); iter++)
					{
							node.push(*(iter));
							levelTag = *(iter);
					}
				}
				if (levelTags[cur]) levelTags[levelTag] = true;
			}
			if (temRes > result)
			{
				result = temRes;
			}
		}
		return result;
	}
private:
	int result;
	int mXDim;
	int mYDim;
	inline int Tran(int i, int j)
	{
		return (i * mYDim + j);
	}
    */
};