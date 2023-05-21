#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdio.h>
using namespace std;
int N[10] = { 0, };
int k = 0;
int maxnum = 0;
int countforp;
int swap(int i, int j)
{
    int temp;
    if (i == j) return 0;
    temp = N[i];
    N[i] = N[j];
    N[j] = temp;
    return 0;
}

int Permutation(int TotalN, int NUM)
{
    int count = 0;
    int i;
    if (NUM == 1) {
        for (int j = 0; j < k; j++) {

            if (j == k - 1) {
                if (sqrt(N[j] + N[0]) - int((sqrt(N[j] + N[0]))) == 0) {
                    count = count + 1;
                  
                }

            }
            else {
                if (sqrt(N[j] + N[j + 1]) - int((sqrt(N[j] + N[j + 1]))) == 0) {
                    count = count + 1;
           
                }

            }
        }
        if (count > maxnum) {
            maxnum = count;
        }
        else if (count == maxnum) {

        }
        return 0;
    }

    for (i = 1; i < NUM; i++) {
        swap(i, NUM - 1);
        Permutation(TotalN, NUM - 1);
        swap(i, NUM - 1);
    }
    return 0;
}
int main() {
    int n = 0;
    int l = 0;

    char input1[10];
    ifstream fin;
    fin.open("sample_input.txt");

    fin >> input1;
    n = stoi(input1);


    for (int m = 0; m < n; m++) {
        fin >> input1;
        k = stoi(input1);
        printf("#%d ", m + 1);
        for (int j = 0; j < k; j++) {
            fin >> input1;
            l = stoi(input1);
            N[j] = l;
        }
        Permutation(k, k);
   
        printf("%d\n", maxnum);
    
        maxnum = 0;

    }
}
