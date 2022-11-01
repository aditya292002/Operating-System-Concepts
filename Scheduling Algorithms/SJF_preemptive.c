#include<stdio.h>




void SJF(int n, int AT[], int BT[], int CT[]) {
	int time = 0;
	int NPS = 0;  // no. of process schedules
	int vis[50] = {0};

	while(NPS < n) {
		int LBI = -1; // least BT index
		for(int i = 0;i < n; i++) {
			if(AT[i] <= time && vis[i] == 0) {

				if(LBI != -1) {
					if(BT[LBI] > BT[i]) {
						LBI = i;
					}
				}
				else {
					LBI = i;
				}
			}
		}	

		if(LBI == -1) {
			time++;
		}
		else {
			vis[LBI] = 1;
			CT[LBI] = time + BT[LBI];
			time = CT[LBI];
			NPS++;
		}
	}
}



int main() {
	int n = 4;
	int AT[] = {0,1,2,3};
	int BT[] = {8,4,9,5};
	int CT[n];
	SJF(n,AT, BT, CT);

	// for(int i = 0; i < n; i++) {
	// 	printf("CT[%d] = %d\n",i,CT[i]);
	// }

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
