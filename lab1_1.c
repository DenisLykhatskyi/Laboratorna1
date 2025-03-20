#include <stdio.h>
#include <math.h>

#define MAX_ARRAY_SIZE 100

int main() {
    int size;
    printf("Введіть кількість чисел (1-%d): ", MAX_ARRAY_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_ARRAY_SIZE) {
        printf("Помилка: Розмір має бути від 1 до %d\n", MAX_ARRAY_SIZE);
        return 1;
    }

    int numbers[MAX_ARRAY_SIZE];
    int sum_even = 0, count_even = 0;
    long long product_odd = 1;  // Using long long to handle larger products
    int count_odd = 0;
    int max_value, max_index = 0;

    printf("Введіть числа:\n");
    for (int i = 0; i < size; i++) {

        if (scanf("%d", &numbers[i]) != 1) {
            printf("Помилка: Неправильний формат числа\n");
            return 1;
        }

        if (i == 0 || numbers[i] > max_value) {
            max_value = numbers[i];
            max_index = i;
        }

        if (numbers[i] % 2 == 0) {
            sum_even += numbers[i];
            count_even++;
        } else {
            product_odd *= numbers[i];
            count_odd++;
        }
    }

    double avg_even = count_even > 0 ? (double)sum_even / count_even : 0;
    double geo_mean_odd = count_odd > 0 ? pow(product_odd, 1.0 / count_odd) : 0;

    printf("Сума парних: %d, середнє арифм.: %.2lf\n", sum_even, avg_even);
    printf("Добуток непарних: %lld, середнє геом.: %.2lf\n", product_odd, geo_mean_odd);
    printf("Максимальне: %d, індекс: %d\n", max_value, max_index);

    return 0;
}