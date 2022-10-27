
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
        counter[ref_string[i]] = 1;
    }



    int count_page_fault = frames;

    // printArray(counter, maxi + 1);    
    // debug(i)

    while(i < n) {
        if(vis[ref_string[i]] == 0) {   


            // debug(i)

            count_page_fault++;

            int min_cnt_ele_ind = -1;
            int min_cnt = INT_MAX;   

            // printArray(counter, maxi + 1);         
            
            for(int j = 0; j < frames; j++) {
                int element = mem[j];
                // debug(element)
                if(counter[element] < min_cnt) {
                    // debug(counter[element])
                    // debug(min_cnt)
                    min_cnt = counter[element];
                    min_cnt_ele_ind = j; 
                }
            }

            // debug(min_cnt_ele_ind)
            // debug(min_cnt)

            int prev_ele = mem[min_cnt_ele_ind];
            vis[prev_ele] = 0;

            
            mem[min_cnt_ele_ind] = ref_string[i];
            vis[ref_string[i]] = 1;
            counter[ref_string[i]]++;

            // printArray(mem, frames);
            // printArray(counter, maxi + 1);
        }
        else {
            counter[ref_string[i]]++;
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