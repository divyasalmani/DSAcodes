#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMS 1000

int main() {
    int p,q, num;
    printf("Enter the start of the range: ");
    scanf("%d", &p);
    printf("Enter the end of the range: ");
    scanf("%d", &q);
    printf("Enter the number of random integers to generate: ");
    scanf("%d", &num);
    FILE *input_file, *output_file;
    int nums[MAX_NUMS], i, n;

    // Initialize random number generator
    srand(time(NULL));

    // Generate random integers within the specified range
    int random_ints[num];
    for (i = 0; i < num; i++) {
        random_ints[i] = rand() % (q - p + 1) + p;
    }

    // Get user input for file name to save the list of random integers
    char file_name[50];
    printf("Enter the name of the file to save: ");
    scanf("%s", file_name);

    // Save the list of random integers to the specified file
    FILE *f = fopen(file_name, "w");
    if (f == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    for (i = 0; i < num; i++)
    {
        fprintf(f, "%d\n", random_ints[i]);
    }
    fclose(f);

    printf("%d random integers have been generated and saved to %s.\n", num, file_name);
    return 0;

    // Open input file for reading
    input_file = fopen("abc.txt", "r");
    if (input_file == NULL)
    {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Read in numbers from file
    n = 0;
    while (fscanf(input_file, "%d", &nums[n]) == 1)
    {
        n++;
    }
    fclose(input_file);

    // stack operations


    // Open output file for writing
    output_file = fopen("output.txt", "w");
    if (output_file == NULL)
    {
        printf("Error: Unable to open output file.\n");
        return 1;
    }
    // Write sorted numbers to file
    for (i = 0; i < n; i++)
    {
        fprintf(output_file, "%d\n", nums[i]);
    }
    fclose(output_file);

    return 0;
}


