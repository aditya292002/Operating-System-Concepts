

#include<stdio.h>

#define INT_MIN -1*(1e9 + 7)
#define INT_MAX 1e9 + 7

int max(int a, int b) {
    if(a > b) return a;
    return b;
}


int optimal_page_replacement(int ref_string[], int n, int frames) {
    int mem[frames];

    int maxi = -1*(1e9 + 7); // getting max page number
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, ref_string[i]);
    }

    int vis[maxi + 1];
    for(int i  = 0; i <= maxi; i++) {
        vis[i] = 0;
    }



    int i = 0;
    for(; i < frames; i++) {
        mem[i] = ref_string[i];
        vis[ref_string[i]] = 1;
    }


    // printArray(mem, frames);
    // debug(i)

    // printArray(vis,maxi + 1);


    int count_page_fault = frames;


    while(i < n) {

        if(vis[ref_string[i]] == 0) {

            count_page_fault++;

            int last_ind[frames];
            for(int j = 0; j < frames; j++) {
                int element = mem[j];

                // debug(element)

                int flag = 1;
                for(int k = i; k < n; k++) {
                    if(ref_string[k] == element) {
                        last_ind[j] = k; 
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    last_ind[j] = INT_MAX;
                }
            }

            // printArray(last_ind,frames);

            int farthest_ele = INT_MIN;
            int farthest_ele_ind = -1;
            for(int j = 0; j < frames; j++) {
                if(last_ind[j] > farthest_ele) {
                    farthest_ele = last_ind[j];
                    farthest_ele_ind = j;
                }
            }

            // debug(farthest_ele)
            // debug(farthest_ele_ind)


            int prev_ele = mem[farthest_ele_ind];
            vis[prev_ele] = 0;

            mem[farthest_ele_ind] = ref_string[i];
            vis[ref_string[i]] = 1;

            // printArray(mem,frames);
            // printArray(vis, maxi + 1);   
        }
        i++;
    }

    return count_page_fault;
}

int main() {
    int ref_string[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int n = sizeof(ref_string)/4;
    int frames_cnt = 3;
    printf("%d \n", optimal_page_replacement(ref_string,n,frames_cnt)); 
}