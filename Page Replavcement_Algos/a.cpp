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

    // printArray(counter, maxi + 1);    
    // debug(i)

    while(i < n) {
        if(vis[ref_string[i]] == 0) {   


            // debug(i)

            count_page_fault++;

            int min_ind = INT_MAX;
            int min_ele = -1;   

            printArray(counter, maxi + 1);         
            
            for(int j = 0; j < frames; j++) {
                int element = mem[j];
                // debug(element)
                if(counter[element] < min_ind) {
                    // debug(counter[element])
                    // debug(min_cnt)
                    min_ind = counter[element];
                    min_ele = j; 
                }
            }

            // debug(min_cnt_ele_ind)
            // debug(min_ind)
            // debug(min_ele)

            int prev_ele = mem[min_ele];
            // debug(prev_ele)
            vis[prev_ele] = 0;


            
            mem[min_ele] = ref_string[i];
            vis[ref_string[i]] = 1;
            counter[ref_string[i]] = i + 1;

            // printArray(mem, frames);
            // printArray(counter, maxi + 1);
        }
        else {
            counter[ref_string[i]] = i + 1;
        }
        i++;
    }
    return count_page_fault;
}


int main() { 
    startClock();

    int ref_string[] = {7,0,1,2,0,3,0,4,2,3};   
    int n = sizeof(ref_string)/4;
    int frames_cnt = 3;
    cout << LRU(ref_string,n,frames_cnt) << endl;

    endClock();
    // cout << optimal_page_replacement(ref_string,n,frames_cnt) << endl;
    // cout << FIFO_page_replacement_algo(ref_string,n,frames_cnt) << endl;
}


