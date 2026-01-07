#include <stdio.h>

void change_digits(int *number, int digit) {
    int result = 0;

    while(*number){
        result = result * 10 + digit;
        *number /= 10;
    }

    *number = result;
}

void encr_num(int *num){
    int digit = 0, max_digit = 0, temp = *num;

    max_digit = temp % 10;  // Let a digit be extracted and be a max digit.
    temp = temp / 10;

    while(temp){
        digit = temp % 10;

        if(digit > max_digit)
            max_digit = digit;
        
        temp = temp / 10;
    }

    change_digits(num, max_digit);
    
}

int sum_encr(int numbers[], int size){
    int sum = 0;
    
    for(size_t i = 0; i < size; i++){
        encr_num(&numbers[i]);
        sum += numbers[i];
    }

    return sum;
}


int main(){
    int size = 0;

    printf("\nEnter the size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("\nEnter the %d numbers: ", size);
    for(size_t i = 0; i < size; i++)
        scanf("%d", &arr[i]);


    printf("\nThe sum of encrypted numbers is: %d", sum_encr(arr, size));

    return 0;
}