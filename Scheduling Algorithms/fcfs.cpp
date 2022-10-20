#include<bits/stdc++.h>
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
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
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

// complete time for non_preemptive-fcfs
void calc_complete_time(vector<int> &at, vector<int> &bt, vector<int> &complete_time) { 
    // arrive time is sorted
    int time_pointer = 0;
    for(int i = 0; i < at.size(); i++) {
        complete_time[i] = time_pointer + bt[i];
        time_pointer = complete_time[i];
    }
}

// complete-time for pre-emptive-fcfs
void calc_complete_time_pre(vector<int> &at, vector<int> bt, vector<int> &complete_time, int tq) {
    int n = at.size();
    int time_pointer = 0;
    queue<int> q; // q represents ready queue
    q.push(0);

    while(!q.empty()) {
        int curr_job = q.front();  q.pop();
        int last_time_pointer = time_pointer;
        bool complete = true;

        if(bt[curr_job] > tq) {
            time_pointer += tq;
            bt[curr_job] -= tq;
            complete = false;
        }
        else {
            time_pointer += bt[curr_job];
            bt[curr_job] = 0;
            complete_time[curr_job] = time_pointer;
        }

        // check for new arrived jobs  
        if(last_time_pointer < at[n-1])  {  // if all haven't arrived
            for(int i = curr_job + 1; i < n; i++) {
                if(at[i] <= time_pointer) {
                    q.push(i);
                }
                else break;
            }
        }

        if(!complete) {
            q.push(curr_job);
        }   
    }
}

// calculating turn-around time
void calc_TAT(vector<int> &at, vector<int> &turn_around_time, vector<int> &complete_time) {
    int n = at.size();
    for(int i = 0; i < n; i++) {
        turn_around_time[i] = complete_time[i] - at[i];
    }
}

// calculating wait-time time
void calc_WT(vector<int> &turn_around_time, vector<int> &bt, vector<int> &wait_time) {
    int n = bt.size();
    for(int i = 0; i < n; i++) {
        wait_time[i] = turn_around_time[i] - bt[i];
    }
}


int main() {
    vector<int> arrival_time = {0, 1, 2}; 
    vector<int> burst_time = {20, 2, 2};
    int n = arrival_time.size();
    vector<int> complete_time(n,0), turn_around_time(n,0), wt(n,0);

    int time_quantum = 2; // for preemptive scheduling

    calc_complete_time(arrival_time, burst_time, complete_time);
    // calc_complete_time_pre(arrival_time, burst_time, complete_time, time_quantum);
    calc_TAT(arrival_time, turn_around_time, complete_time);
    calc_WT(turn_around_time, burst_time, wt);

    cout << "Process   Arrival-Time    Burst-Time    Complete-Time    Turn-around-time    Wait-Time" << endl;  
    for(int i = 0; i < n; i++) {
        cout<<i<<"         "<<arrival_time[i]<<"                "<<burst_time[i]<<"              "<<complete_time[i]<<"               "<<turn_around_time[i]<<"                 "<<wt[i]<<endl;          
    }
    int total_wait_time = 0;
    for(int i = 0; i < n; i++) {
        total_wait_time += wt[i];
    }
    cout<< "Average wait time : " << (double)((double)total_wait_time/(double)n) << endl; 
}

