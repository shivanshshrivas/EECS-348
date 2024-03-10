#include <stdio.h>

void findCombinations(int score, int td, int fg, int td_1, int td_2, int safety)
{
    if (score == 0)
    {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2, td_1, td, fg, safety);
    }
    else if (score <= 1)
    {
        return 0;
    }
    else
    {
        if (score >= 8)
        {
            findCombinations(score - 8, td_2 + 1, td_1, td, fg, safety);
        }
        if (score >= 7)
        {
            findCombinations(score - 7, td_2, td_1 + 1, td, fg, safety);
        }
        if (score >= 6)
        {
            findCombinations(score - 6, td_2, td_1, td + 1, fg, safety);
        }
        if (score >= 3)
        {
            findCombinations(score - 3, td_2, td_1, td, fg + 1, safety);
        }
        if (score >= 2)
        {
            findCombinations(score - 2, td_2, td_1, td, fg, safety + 1);
        }
    }
}

int main()
{
    int score;

    while (1)
    {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1)
        {
            printf("Program terminated.\n");
            break;
        }

        printf("Possible combinations of scoring plays:\n");
        findCombinations(score, 0, 0, 0, 0, 0);
    }

    return 0;
}