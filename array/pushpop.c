int main() {
    Stack stack;
    stack.top = -1;

    // Open input file
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Could not open input file.\n");
        return 1;
    }

    // Read numbers from input file
    int numbers[STACK_SIZE];
    int num_numbers = 0;
    int num_read;
    while (num_numbers < STACK_SIZE && fscanf(input_file, "%d", &numbers[num_numbers]) == 1) {
        num_numbers++;
    }
    fclose(input_file);

    // Initialize random number generator
    srand(time(NULL));

    // Perform stack operations using random numbers and input numbers
    for (int i = 0; i < STACK_SIZE; i++) {
        int randomNumber = rand() % 100;

        // Push operation
        if (rand() % 2 == 0) {
            if (num_numbers > 0) {
                int value = numbers[num_numbers - 1];
                push(&stack, value);
                num_numbers--;
                FILE* file = fopen("push_operations.txt", "a");
                if (file != NULL) {
                    fprintf(file, "Pushed %d onto the stack.\n", value);
                    fclose(file);
                }
            } else {
                push(&stack, randomNumber);
                FILE* file = fopen("push_operations.txt", "a");
                if (file != NULL) {
                    fprintf(file, "Pushed %d onto the stack.\n", randomNumber);
                    fclose(file);
                }
            }
        }
        // Pop operation
        else {
            int poppedValue = pop(&stack);
            FILE* file = fopen("pop_operations.txt", "a");
            if (file != NULL) {
                if (poppedValue != -1) {
                    fprintf(file, "Popped %d from the stack.\n", poppedValue);
                } else {
                    fprintf(file, "Failed to pop from the stack.\n");
                }
                fclose(file);
            }
        }
    }

    printf("\nPush Operations:\n");
    displayOperations("push_operations.txt");

    printf("\nPop Operations:\n");
    displayOperations("pop_operations.txt");

    return 0;
}
