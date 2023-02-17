#ifndef __CORE_H
#define __CORE_H

export int gcd(int a, int b){
    while(a != b){
        if(a > b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}

export int fac (int n){
    for(int i = n - 1, 0, -1){
        n = n * i;
    }
    return n;
}

export int fib (int n){
    int fib_1 = 0;
    int fib_2 = 1;
    int fib_res;

    if (n <= 2){
        if (n == 1){
            fib_res = fib_1;
        }
        else{
            fib_res = fib_2;
        }
    }
    else{
        for(int i = n, 2, -1){
            fib_res = fib_1 + fib_2;
            fib_1 = fib_2;
            fib_2 = fib_res;
        }
    }
    return fib_res;
}

export bool isprime (int n){
    bool is_prime = true;
    for(int i = 2, n){
        if (n % i == 0) {
        is_prime = false;
        }
    }
    return is_prime;
}

#endif