#include<stdio.h>




void PS(int n, int AT[], int BT[], int P[], int CT[]) {
	int time = 0;
	int NPS = 0;  // no. of process schedules
	int vis[50] = {0};


	while(NPS < n) {
		int HPI = -1; // Highest Priority index
		for(int i = 0;i < n; i++) {
			if(AT[i] <= time && vis[i] == 0) {

				if(HPI != -1) {
					if(P[HPI] < P[i]) {
						HPI = i;
					}
				}
				else {
					HPI = i;
				}
			}
		}	

		if(HPI == -1) {
			time++;
		}
		else {
			vis[HPI] = 1;
			CT[HPI] = time + BT[HPI];
			time = CT[HPI];
			NPS++;
		}
	}
}



int main() {
	int n = 7;
	int AT[] = {0,1,2,3,4,5,6};
	int BT[] = {4,2,3,5,1,4,6};
	int P[] = {2,4,6,10,8,12,9};
	int CT[n];
	PS(n,AT, BT, CT,P);

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
