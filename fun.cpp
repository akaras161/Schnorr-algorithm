#include "fun.h"

int generate_random_number(int min_value, int max_value){
    return rand() % (max_value-min_value+1) + min_value;
}

int generate_prime_number(int min_value, int max_value){
    bool is_primary = false;
    int rand_number;
    do{
        rand_number = rand() % (max_value-min_value+1) + min_value;
        for(int i=2; i<=rand_number-1; i++){
            if(rand_number%i==0) {
                is_primary = false;
                break;
            }else{
                is_primary = true;
            }
        }
    }while(!is_primary);
    return rand_number;
}