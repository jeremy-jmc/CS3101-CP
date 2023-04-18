
/// 8 queen chess problem
#include <bits/stdc++.h>
using namespace std;
int a, b, canti;
int row[8];

void imprimir()
{
    if (canti > 0)
        printf("\n");
    canti++;
    printf("%2d      %d", canti, row[0] + 1);
    for (int i = 1; i < 8; i++)
        printf(" %d", row[i] + 1);
}

bool isvalid(int fila, int nq)
{   // check if the queen can be in the row 'fila' for the column 'nq'
    // for each column
    for (int i = 0; i < nq; i++)
    {
        if (row[i] == fila ||       // check it the row of the queen in the column 'i' is the same as the proposal
            abs(row[i] - fila) == abs(i - nq)       // check if the difference of the rows is the same as the difference of the columns
            )
            return false;
    }
    return true;
}

void backtrack(int nq)
{   
    // explore all the solutions
    if (nq == 8 && row[b] == a)
        imprimir();
    
    // for each row
    for (int i = 0; i < 8; i++)
    {   // try setting the row of the column 'nq'
        if (isvalid(i, nq))
        {
            row[nq] = i;            // put the row of the queen in the column 'nq'
            backtrack(nq + 1);      // explore the next column
        }
    }
}

void solve()
{
    scanf("%d%d", &a, &b);
    a--;
    b--;
    canti = 0;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtrack(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    scanf("%d", &t);
    while (t--)
    {
        /// reset values of diags
        for (int i = 0; i < 8; i++)
            row[i] = 0;
            // the row of the queen in the column i
        /// solve

        solve();
        if (t > 0)
            printf("\n\n");
        else
            printf("\n");
    }
    return 0;
}
