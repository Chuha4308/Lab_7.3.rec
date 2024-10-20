#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < K - 1)
        CreateRows(a, K, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int K, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < K - 1)
        PrintRows(a, K, N, rowNo + 1);
    else
        cout << endl;
}


bool hasNoNegativeElements(int* row, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (row[i] < 0)
            return false;
    }
    return true;
}


int SumPositiveRows(int** a, const int size)
{
    int totalSum = 0;
    for (int i = 0; i < size; i++)
    {
        if (hasNoNegativeElements(a[i], size))
        {
            for (int j = 0; j < size; j++)
                totalSum += a[i][j];
        }
    }
    return totalSum;
}

void MinSumParallelDiagonals(int** a, const int size)
{
    int minSum = INT_MAX;

    for (int start = 1; start < size; start++)
    {
        int sum = 0;
        for (int i = 0, j = start; j < size; i++, j++)
            sum += a[i][j];
        if (sum < minSum)
            minSum = sum;
    }

    for (int start = 1; start < size; start++)
    {
        int sum = 0;
        for (int i = start, j = 0; i < size; i++, j++)
            sum += a[i][j];
        if (sum < minSum)
            minSum = sum;
    }

    cout << "MinSumParallelDiagonals: " << minSum << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int Low = -10;
    int High = 10;
    int size;

    cout << " n: ";
    cin >> size;

    int** a = new int* [size];
    for (int i = 0; i < size; i++)
        a[i] = new int[size];

    CreateRows(a, size, size, Low, High, 0);

    PrintRows(a, size, size, 0);

    int sumPositiveRows = SumPositiveRows(a, size);
    cout << "SumPositiveRows: " << sumPositiveRows << endl;

    MinSumParallelDiagonals(a, size);

    for (int i = 0; i < size; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
