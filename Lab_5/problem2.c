#include <stdio.h>

#define TD 6
#define TD1 7
#define TD2 8
#define FG 3
#define SAFETY 2

void CombinationCalc(int score)
{
    int td, td1, td2, fg, safety;
    for (td2 = 0; score >= (td2 * TD2); ++td2)
    {
        for (td1 = 0; score >= (td1 * TD1); ++td1)
        {
            for (td = 0; score >= (td * TD); ++td)
            {
                for (fg = 0; score >= (fg * FG); ++fg)
                {
                    for (safety = 0; score >= (safety * SAFETY); ++safety)
                    {
                        if ((td2 * TD2) + (td1 * TD1) + (td * TD) + (fg * FG) + (safety * SAFETY) == score)
                        {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int score;
    while (1)
    {
        printf("\nEnter 0 or 1 to STOP\nEnter a score to find the combinations: \n");
        scanf("%d", &score);

        if (score <= 1)
        {
            break;
        }
        printf("\n\nPossible combinations of scoring plays:\n");
        CombinationCalc(score);
    }
}