 /*************************************************************************
	> File Name: 27_queen.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年07月26日 星期二 16时24分34秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

int queens(int n);
void permutation(int *ColumnIndex, int start, int n, int &solutionNumber);
bool satisfyQueenRequirements(int *, int);

int queens(int n)           //n皇后问题
{
    int solutionN = 0;
    int *ColumnIndex = new int[n];
    for(int i = 0; i < n; i++)
        ColumnIndex[i] = i;
    
    permutation(ColumnIndex, 0, n, solutionN);
    
    return solutionN;
}

//全排列
void permutation(int *ColumnIndex, int start, int n, int &solutionNumber)
{        
    if(ColumnIndex == NULL) return;

    if(start == n-1)
    {
        //检查输出
        if(satisfyQueenRequirements(ColumnIndex, n))
        {
            solutionNumber++;
            for(int k = 0; k < n; k++)
                cout<< ColumnIndex[k] << ' ';
            cout << endl;
        }
        return;
    }

    for(int i = start; i<n; i++)
    {
        int temp = ColumnIndex[start];
        ColumnIndex[start] = ColumnIndex[i];
        ColumnIndex[i] = temp;

        permutation(ColumnIndex, start+1, n, solutionNumber);

        temp = ColumnIndex[start];
        ColumnIndex[start] = ColumnIndex[i];
        ColumnIndex[i] = temp;
    }
}

bool satisfyQueenRequirements(int *ColumnIndex, int n)
{
    bool result = true;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            if( i!=j && abs(i-j) == abs(ColumnIndex[i]-ColumnIndex[j]))
            {
                result = false;
                return result;
            }
        }
    }
    return result;
}

int main()
{
    cout<< queens(8) <<endl;
    return 0;
}
