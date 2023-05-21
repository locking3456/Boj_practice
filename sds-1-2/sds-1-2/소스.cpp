#include <iostream>
#include <fstream>
#include <deque>
#include <string>
int k = 0;
int maxnum = 0;
using namespace std;
int main() {
    int n = 0;
    int l = 0;
    deque<int> dq;
    deque<int> N;
    deque<int> waitf;
    char input1[10];
    ifstream fin;
    fin.open("sample_input.txt");
    int count = 0;
    fin >> input1;
    n = stoi(input1);


    for (int m = 0; m < n; m++) {
        count = 0;
        int checkn = 0;
        fin >> input1;
        k = stoi(input1);
        printf("#%d ", m + 1);
        for (int j = 0; j < k; j++) {
            fin >> input1;
            l = stoi(input1);
            N.push_back(l);
        }
        while(dq.size()!=k) {
            if(dq.empty()){
                dq.push_front(N.front());
                N.pop_front();
            }
            else if(!N.empty()){
                if (sqrt(N.front() + dq.back()) - int((sqrt(N.front() + dq.back()))) == 0) {
                    dq.push_back(N.front());
                    N.pop_front();
                    count = count + 1;
                    if (N.empty()) {
                        checkn = 1;
                        continue;
                    }
              
                }
                else if (sqrt(N.front() + dq.front()) - int((sqrt(N.front() + dq.front()))) == 0) {
                    dq.push_front(N.front());
                    N.pop_front();
                    count = count + 1;
                    if (N.empty()) {
                        checkn = 1;
                        continue;
                    }
                }
                else{
                    if (!N.empty()) {
                        waitf.push_back(N.front());
                        N.pop_front();
                    }
              
                } 
            }
            if (N.empty()) {           
                if (checkn == 1) {
                    while (!waitf.empty()) {
                        N.push_front(waitf.front());
                        waitf.pop_front();
                        checkn=0;
                    }
                }
                else if (checkn == 0) {
                    dq.push_front(waitf.front());
                    waitf.pop_front();
                    while (!waitf.empty()) {
                        N.push_front(waitf.front());
                        waitf.pop_front();
                    }
                }
            }

        }
        if (sqrt(dq.back() + dq.front()) - int((sqrt(dq.back() + dq.front()))) == 0) {
            count = count + 1;
        }
        printf("%d \n",count);
        dq.clear();
        N.clear();
    }
}
