    #include <stdio.h>

    int make_triangle(int size, int curr);
    int number_palindrome(int n);
    int get_first(int num);
    int count_digit(int n);
    int exponent(int base, int expo);

    int main() {
        int size;

        printf("Check number palindrome: "); scanf("%d", &size);

        printf("%d\n", number_palindrome(size));
    }

    int make_triangle(int size, int curr) {
        if (curr == size){
            return 0;
        } else {
            for (int i = 0; i < size - curr; i++){ // loop for spaces, decreasing
                printf(" ");
            }
            for (int i = 0; i < curr + 1; i++){ // loop for *, increasing
                printf(" *");
            } printf("\n");
            curr++;
            make_triangle(size, curr);
        }
    }

    int number_palindrome(int n){
        if (n == 0){
            return 1;
        }
        int last_digit = n % 10;
        int first_digit = get_first(n);
        if (last_digit == first_digit){
            n = n - first_digit * exponent(10, count_digit(n) - 1);
            n = n / 10;
            return number_palindrome(n);
        } else {
            return 0;
        }
    }

    int get_first(int num){
        if ((num / 10) == 0){
            return num;
        } else {
           return get_first(num / 10);
        }
    }

    int count_digit(int n){
        int count = 0;
        while(1){
            n = n / 10;
            count++;
            if (n == 0){
                return count;
            }
        }
    }

    int exponent(int base, int expo){
        if (expo == 0){
            return 1;
        }

        int result = 1;
        for (int i = 0;i < expo; i++){
            result *= base;
        }
        return result;
    }