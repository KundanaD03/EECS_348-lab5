#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

// Function to calculate the average of an array of numbers
double calculateAverage(double array[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Function to print the sales report
void printSalesReport(char *months[], double sales[], int size) {
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }
}

// Function to print the sales summary
void printSalesSummary(char *months[], double sales[], int size) {
    printf("\nSales summary:\n");

    // Find the index of the minimum and maximum sales
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (sales[i] < sales[minIndex]) {
            minIndex = i;
        }
        if (sales[i] > sales[maxIndex]) {
            maxIndex = i;
        }
    }

    // Print minimum, maximum, and average sales
    printf("Minimum sales: $%.2f (%s)\n", sales[minIndex], months[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", sales[maxIndex], months[maxIndex]);
    printf("Average sales: $%.2f\n", calculateAverage(sales, size));
}

// Function to print the six-month moving average report
void printMovingAverage(char *months[], double sales[], int size) {
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= size - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        double average = sum / 6;
        printf("%s - %s $%.2f\n", months[i], months[i + 5], average);
    }
}

// Function to print the sales report from highest to lowest
void printSalesDescending(char *months[], double sales[], int size) {
    printf("\nSales Report (Highest to Lowest):\n");

    // Sort the sales array and rearrange months accordingly
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sales[j] < sales[j + 1]) {
                // Swap sales
                double tempSales = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = tempSales;

                // Swap months
                char *tempMonth = months[j];
                months[j] = months[j + 1];
                months[j + 1] = tempMonth;
            }
        }
    }

    // Print the sorted sales report
    printf("Month\tSales\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }
}

int main() {
    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};

    // Read monthly sales from sales file
    double sales[MONTHS];
    FILE *salesFile = fopen("sales.txt", "r");
    if (salesFile == NULL) {
        fprintf(stderr, "Error opening sales file.\n");
        return 1;
    }

    for (int i = 0; i < MONTHS; i++) {
        if (fscanf(salesFile, "%lf", &sales[i]) != 1) {
            fprintf(stderr, "Error reading from sales file.\n");
            fclose(salesFile);
            return 1;
        }
    }

    fclose(salesFile);

    // Print the sales report
    printSalesReport(months, sales, MONTHS);

    // Print the sales summary
    printSalesSummary(months, sales, MONTHS);

    // Print the six-month moving average report
    printMovingAverage(months, sales, MONTHS);

    // Print the sales report from highest to lowest
    printSalesDescending(months, sales, MONTHS);

    return 0;
}
