#ifndef __ARRAY_H
#define __ARRAY_H

void printIntVec(int[n] vec){
    for (int i = 0, n){
        printInt(vec[i]);
        printSpaces(1);
    }
}

void printFloatVec(float[n] vec){
    for (int i = 0, n){
        printFloat(vec[i]);
        printSpaces(1);
    }
}


void scanIntVec(int[n] vec){
    for (int i = 0, n){
        vec[i] = scanInt();
    }
}

void scanFloatVec(float[n] vec){
    for (int i = 0, n){
        vec[i] = scanFloat();
    }
}

void printIntMat(int[m,n] mat){
    for (int i = 0, m){
        for(int j = 0, n){
            printInt(mat[i,j]);
            printSpaces(1);
        }
        printNewlines(1);
    }
}

void printFloatMat(float[m,n] mat){
    for (int i = 0, m){
        for(int j = 0, n){
            printFloat(mat[i,j]);
            printSpaces(1);
        }
        printNewlines(1);
    }
}

void scanIntMat(int[m,n] mat){
    for (int i = 0, m){
        for(int j = 0, n){
            mat[i,j] = scanInt();
        }
    }
}

void scanFloatMat(float[m,n] mat){
    for (int i = 0, m){
        for(int j = 0, n){
            mat[i,j] = scanFloat();
        }
    }
}

void matMul( float[m,n] a, float[o,p] b, float[q,l] c){
    if (n == o){
        for(int i = 0, q)
        {
            for(int j = 0, l)
            {
                for(int k = 0, n)
                {
                    c[i,j] = c[i,j] + a[i,k]*b[k,j];
                }
            }
        }
    }
}

#endif
