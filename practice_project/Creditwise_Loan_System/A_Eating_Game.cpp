#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int simulateGame(int &n)
{
    vector<int> table(n);
    vector<int> canWin(n, 0);
    int totalDishes = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> table[i];
        totalDishes += table[i];
    }
    int i = 0;
    while (i < n)
    {
        int eaten = 0;
        int currPlayer = i - 1;
        vector<int> mockTable(table);
        while (eaten != totalDishes)
        {
            currPlayer = (currPlayer + 1) % n;
            if (mockTable[currPlayer] != 0)
            {
                eaten++;
                mockTable[currPlayer]--;
            }
        }
        canWin[currPlayer] = 1;
        i++;
    }

    int winners = accumulate(canWin.begin(), canWin.end(), 0);

    return winners;
}

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << simulateGame(n) << endl;
    }
}