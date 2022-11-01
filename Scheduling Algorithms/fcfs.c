#include<stdio.h>

// non-preemptive
void fcfs(int n, int AT[], int BT[], int CT[]) {
	int time = 0;
	for(int i = 0; i < n; i++) {
		if(time >= AT[i]) {
			CT[i] = time + BT[i];
			time = CT[i];
		}
		else {
			time++;
		}
	}
}



int main() {
	int n = 3;
	int AT[] = {0,1,2};
	int BT[] = {20,2,2};
	int CT[n];
	fcfs(n,AT,BT,CT);
	int TAT[n], WT[n];


	int total_wait_time = 0;
	for(int i = 0; i < n; i++) {
		TAT[i] = CT[i] - AT[i];
		WT[i] = TAT[i] - BT[i];
		total_wait_time += WT[i];
	}

	printf("Process   Arrival-Time    Burst-Time    Complete-Time    Turn-around-time    Wait-Time\n"); 
    for(int i = 0; i < n; i++) {
        printf("%d          %d                %d              %d                   %d             %d\n",i, AT[i], BT[i], CT[i], TAT[i], WT[i]);    
    }

    printf("Average wait time : %d",(double)((double)total_wait_time/(double)n)); 
}
