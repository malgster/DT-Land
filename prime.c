#include "prime.h"

//  compile with -lm option at the end  //


/**
 * @brief check whether the int in parameter is prime or not 
 * 
 * @return 
 * 1 -> prime
 * 0 -> not prime
 * -1 - undefined (aka x <= 1)
 */

int is_prime(const int x){
    if (x <= 1) return -1;
    if (x <= 3) return 1;
    if ((x%2) == 0) return 0;
    int i = 0;
    for (i = 3; i <= floor(sqrt((double) x)); i+=2){
        if ((x % i) == 0){
            return 0;
        }
    }
    return 1;
}

/**
 * @brief return x if it's a prime number, or the next prime number if it isn't
 * 
 */

int next_prime(int x){
    while (is_prime(x) != 1){
        x++;
    }
    return x;
}

int main(void){
    return 0;
}