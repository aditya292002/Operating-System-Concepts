
#include<stdio.h>

#define INT_MIN -1*(1e9 + 7)
#define INT_MAX 1e9 + 7

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int FIFO_page_replacement_algo(int ref_string[], int n, int frames) {
    int mem[frames];
    for(int i = 0; i < frames; i++) {
        mem[i] = -1;
    }
        
    int maxi = -1*(1e9 + 7); // getting max page number
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, ref_string[i]);
    }

    int vis[maxi + 1];
    for(int i  = 0; i <= maxi; i++) {
        vis[i] = 0;
    }


    int count_page_fault = 0;

    int pages_ind = 0;

    for(int i = 0; i < n; i++) {
        int ind_of_oldest_pg = pages_ind % frames;

        // debug(i)
        // debug(first_come_ind)
        // debug(ref_string[i])

        if(vis[ref_string[i]] == 0) {
            // page miss
            if(mem[ind_of_oldest_pg] != -1) {
                int ele = mem[ind_of_oldest_pg];
                vis[ele] = 0;
            }
            mem[ind_of_oldest_pg] = ref_string[i];
            vis[ref_string[i]] = 1;

            count_page_fault++;

            // printArray(vis,maxi + 1);
            // printArray(mem, frames);
            // debug(count_page_fault)
            pages_ind++;
        }
    }

    return count_page_fault;
}


int main() {
    int ref_string[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int n = sizeof(ref_string)/4;
    int frames_cnt = 3;
    printf("%d \n", FIFO_page_replacement_algo(ref_string,n,frames_cnt)); 
}