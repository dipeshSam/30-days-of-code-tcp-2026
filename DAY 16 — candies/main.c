#include <stdio.h>

int get_min_candy(int ratings[], int size) {
    int candies[size];
    int sum = 0;

    // Step 1: everyone gets 1 candy
    for (int i = 0; i < size; i++)
        candies[i] = 1;

    // Step 2: left to right
    for (int i = 1; i < size; i++) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    // Step 3: right to left
    for (int i = size - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;

    }

    // Step 4: sum
    for (int i = 0; i < size; i++)
        sum += candies[i];

    return sum;
}

int main(){
    int ratings[] = {1, 6, 10, 8, 7, 3, 2};
    int size = sizeof(ratings)/sizeof(ratings[0]);

    printf("%d", get_min_candy(ratings, size));

    return 0;
}