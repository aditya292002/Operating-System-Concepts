
#include<stdio.h>

#define INT_MIN -1*(1e9 + 7)
#define INT_MAX 1e9 + 7

int max(int a, int b) {
    if(a > b) return a;
    return b;
}




int LRU(int ref_string[], int n, int frames) {

    
    int mem[frames];

    int maxi = -1*(1e9 + 7); // getting max page number
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, ref_string[i]);
    }

    int vis[maxi + 1];
    int counter[maxi + 1];
    for(int i  = 0; i <= maxi; i++) {
        vis[i] = 0;
        counter[i] = 0;
    }

    int i = 0;
    for(; i < frames; i++) {
        mem[i] = ref_string[i];
        vis[ref_string[i]] = 1;
        counter[ref_string[i]] = i + 1;
    }



    int count_page_fault = frames;

    while(i < n) {
        if(vis[ref_string[i]] == 0) {   

            count_page_fault++;

            int min_ind = INT_MAX;
            int min_ele = -1;   

            printArray(counter, maxi + 1);         
            
            for(int j = 0; j < frames; j++) {
                int element = mem[j];
                if(counter[element] < min_ind) {
                    min_ind = counter[element];
                    min_ele = j; 
                }
            }


            int prev_ele = mem[min_ele];
            vis[prev_ele] = 0;


            
            mem[min_ele] = ref_string[i];
            vis[ref_string[i]] = 1;
            counter[ref_string[i]] = i + 1;

        }
        else {
            counter[ref_string[i]] = i + 1;
        }
        i++;
    }
    return count_page_fault;
}



int main() {
    int ref_string[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int n = sizeof(ref_string)/4;
    int frames_cnt = 3;
    printf("%d \n", LRU(ref_string,n,frames_cnt)); 
}