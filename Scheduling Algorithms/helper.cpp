#include<bits/stdc++.h>
#include<mutex>


using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define ff first
#define ss second
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl; ///////////////////////////////////////
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define vs vector<string>
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

#define un unordered_map
#define fr front
#define con continue
#define ins insert
#define all(x) x.begin(),x.end()


#define startClock() clock_t start_time = clock();
#define endClock()   clock_t end_time1 = clock(); clock_t result = end_time1 - start_time; cout << result/CLOCKS_PER_SEC <<"."<<result<<" s"<<endl;


int dir[2][2] = {{1, 0}, {0, 1}};
// vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T> void printt(vector<vector<vector<T>>> vec) { cout<<endl;for(auto it3 : vec){cout<<"[ "<<endl;for(auto it2 : it3) {for(auto it1 : it2) {     cout<<it1<<" ";}   cout<<endl;}cout<<"] "<<endl;cout<<endl;}cout<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
template<class T>void printt(queue<T> q) {while(!q.empty()) {cout<<q.front()<<" ";q.pop();}cout<<endl;}
template<class T>void printt(set<T> s) {for(auto it : s) {cout<<it<<" ";} cout<<endl;}
template<class T>void printt(multiset<T> s) {for(auto it : s) {cout<<it<<" ";} cout<<endl;}
template<class T>void printt(vector<pair<T,T>> vec) {cout<<"["<<endl;for(auto it : vec) {cout<<"{ "<<it.ff<<" "<<it.ss<<" }"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(stack<T> st) {while(!st.empty()) {cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<class X, class Y> void printt(set<pair<X,Y>> mySet) {cout<< "{ " <<endl;for(auto it : mySet) {cout << "{ " << it.first<<"," << it.second<< " }" << endl;}cout<<"}"<<endl;}
template<class X, class Y> void printt(vector<pair<X,Y>> vec) {cout<< "{ " <<endl;for(auto it : vec) {cout << "{ " << it.first<<"," << it.second<< " }" << endl;}cout<<"}"<<endl;}


void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}

unsigned countBits(unsigned int number) {    
    // log function in base 2
    // take only integer part
    return (int)log2(number)+1;
}

int convert_string_int(string s){  
    int ans = 0;
    int n = (int)(s.length());
    for(int i = 0; i < n;i++){if(s[i] == '0'){s.substr(1);}else{break;}}
        int tenth = 1;
    for(int i = n-1; i>=0; i--){ans = ans + (tenth*(s[i] - '0'));tenth*=10;}
        return ans;
}

// int mod =(int)1e9+7;
// factorial
ll fact(ll n){
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
// Combination
ll nCr(ll n, ll r) {return fact(n) / (fact(r) * fact(n - r));}

//print adjacency list
void print_adjList(vector<int> adjList[], int n) {
    for(int i = 0; i < n; i++) {
        debug(adjList[i]);
    }
}   

/*
{
    TC = O(n)
    SC = O(n)
*/
//----------------------------------------------------------------------------------------------------------------------------------------



void PS(int n, int AT[], int BT[], int P[], int CT[]) {
	int time = 0;
	int NPS = 0;  // no. of process schedules
	int vis[50] = {0};

	while(NPS < n) {
		int HPI = -1; // Highest Priority index
		for(int i = 0;i < n; i++) {
			if(vis[i] == 0 && AT[i] <= time) {

				if(HPI != -1) {
					if(P[i] > P[HPI]) {
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
	int AT[n] = {0,1,2,3,4,5,6};
	int BT[n] = {4,2,3,5,1,4,6};
	int priority[n] = {2,4,6,10,8,12,9};
	int CT[n];
	PS(n,AT, BT, priority, CT);

	for(int i = 0; i < n; i++) {
		printf("CT[%d] = %d\n",i,CT[i]);
	}

	int TAT[n], WT[n];
	int total_wait_time = 0;
	for(int i = 0; i < n; i++) {
		TAT[i] = CT[i] - AT[i];
		WT[i] = TAT[i] - BT[i];
		total_wait_time += WT[i];
	}
	
}