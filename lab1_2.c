#include <stdio.h>

void process_array(double arr[], int n, int *min_index, double *sum_between_negatives) {
    *min_index = -1;
    double min_value = arr[0];  
    *min_index = 0;  

    for (int i = 1; i < n; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
            *min_index = i;
        }
    }

    int first_neg = -1, second_neg = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (first_neg == -1) {
                first_neg = i;
            } else {
                second_neg = i;
                break;
            }
        }
    }

    *sum_between_negatives = 0;
    if (first_neg != -1 && second_neg != -1) {
        for (int i = first_neg + 1; i < second_neg; i++) {
            *sum_between_negatives += arr[i];
        }
    }
}

int main() {
    int n;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);

    double arr[n];
    printf("Введіть %d елементів масиву:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    int min_index;
    double sum_between_negatives;

    process_array(arr, n, &min_index, &sum_between_negatives);

    printf("Номер мінімального елемента: %d\n", min_index + 1); 
    printf("Сума елементів між першим і другим від'ємними елементами: %.2f\n", sum_between_negatives);

    return 0;
}