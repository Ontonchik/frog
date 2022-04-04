#include <iostream>
#include <string>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

class Frog {
public:
    double res;
    string way;
    Frog() {}

    void set_res(double a) {
        res = a;
    }
    
    void function(int* arr, int size) {
        double* f = new double[4];
        int* ways = new int[size+1];
        f[1] = (double)arr[0]; ways[1] = -1;
        f[2] = -std::numeric_limits<double>::infinity(); ways[2] = -1;
        f[0] = f[2]; ways[0] = -1;
        f[3] = f[1] + arr[2]; ways[3] = 1;
        for (int i = 4; i <= size; i++) {
            bool option = (f[(i - 2) % 4] > f[(i - 3) % 4]);
            f[i%4] =(option?f[(i-2)%4]:f[(i-3)%4]) + arr[i - 1];
            ways[i] = (option ? (i - 2) : (i - 3));
        }
        int i = size;
        int j = -1;
        int* tmp = new int[size];
        while (i != -1) {
            j++;
            tmp[j] = i;
            i = ways[i];
        }
        way = to_string(tmp[j]);
        for (int k = j-1; k >= 0; k--) {
            way += " " + to_string(tmp[k]);
        }
        res = f[size%4];
        delete[] ways;
        delete[] f;
    }
};

void main() {
    Frog Test = Frog();
    int length = 0;
    scanf("%i", &length);
    if(length>=3){
        int* array = new int[length];
        for (int i = 0; i < length; i++) {
            scanf("%i", &array[i]);
        }
        Test.function(array,length);
        delete[] array;
        int r = Test.res;
        printf("%d", r);//result);
        printf("%s", "\n");
        printf("%s", Test.way.c_str());
    }
    else if (length == 2 || length == 0) {
        printf("%i", -1);
    }
    else if (length == 1) {
        int a = 0;
        scanf("%d", &a);
        printf("%d%s", a, "\n");
        printf("%i", 1);
    }
}
