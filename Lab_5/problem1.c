#include <stdio.h>

#define MONTHS 12

// Function to calculate the average of an array of floats
float calculateAverage(float arr[], int n)
{
    float sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

// Function to generate the sales report
void generateSalesReport(float sales[], char *months[])
{
    printf("Monthly sales report for 20xx:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++)
    {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

// Function to find the month with the minimum sales
int findMinSales(float sales[])
{
    float min = sales[0];
    int minIndex = 0;
    for (int i = 1; i < MONTHS; i++)
    {
        if (sales[i] < min)
        {
            min = sales[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to find the month with the maximum sales
int findMaxSales(float sales[])
{
    float max = sales[0];
    int maxIndex = 0;
    for (int i = 1; i < MONTHS; i++)
    {
        if (sales[i] > max)
        {
            max = sales[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to generate the sales summary report
void generateSummaryReport(float sales[], char *months[])
{
    int minIndex = findMinSales(sales);
    int maxIndex = findMaxSales(sales);
    float average = calculateAverage(sales, MONTHS);

    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", sales[minIndex], months[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", sales[maxIndex], months[maxIndex]);
    printf("Average sales: $%.2f\n\n", average);
}

// Function to generate the six-month moving average report
void generateMovingAverage(float sales[], char *months[])
{
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i <= MONTHS - 6; i++)
    {
        float sum = 0.0;
        for (int j = i; j < i + 6; j++)
        {
            sum += sales[j];
        }
        printf("%s - %s $%.2f\n", months[i], months[i + 5], sum / 6);
    }
    printf("\n");
}

// Function to sort sales in descending order
void sortSalesDescending(float sales[], char *months[])
{
    int i, j;
    float temp;
    char *tempMonth;

    for (i = 0; i < MONTHS - 1; i++)
    {
        for (j = i + 1; j < MONTHS; j++)
        {
            if (sales[i] < sales[j])
            {
                // Swap sales
                temp = sales[i];
                sales[i] = sales[j];
                sales[j] = temp;
                // Swap months
                tempMonth = months[i];
                months[i] = months[j];
                months[j] = tempMonth;
            }
        }
    }
}

// Function to generate the sales report in descending order
void generateDescendingSalesReport(float sales[], char *months[])
{
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++)
    {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

int main()
{
    FILE *file;
    float sales[MONTHS];

    // Open and read data from the file 'sales_data.txt' and store it in an array
    file = fopen("sales_data.txt", "r");
    if (file == NULL)
    {
        printf("Error in opening file!\n");
    }

    for (int i = 0; i < MONTHS; i++)
    {
        if (fscanf(file, "%f", &sales[i]) != 1)
        {
            printf("Error reading data from file!\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};

    generateSalesReport(sales, months);

    generateSummaryReport(sales, months);

    generateMovingAverage(sales, months);

    sortSalesDescending(sales, months);

    generateDescendingSalesReport(sales, months);

    return 0;
}
