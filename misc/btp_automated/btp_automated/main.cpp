#include "/Users/manishkumar/Work/stdc++.h"
#include <chrono>
using namespace std::chrono;
using namespace std;
#define ll long long int

long long int min_cost = LLONG_MAX;
vector<vector<pair<int,int>>> adj ;
vector<unordered_map<string, long long int>> shortest_cost_path_base;

vector<int> cost_of_build;

int COST_OF_BUILD_WEIGHT_FACTOR = 50;
int EDGE_WEIGHT_FACTOR = 30;
double RANDOM_HOTSPOT_FACTOR = 0.25 ;


unordered_map<int, int> brute_force_trace_parent;

void buildMSF(vector<int> &key, vector<vector<pair<int,int>>> adj, vector<int> &parent, unordered_set<int> hotspot) {
    
    int n_size = (int)key.size();
    vector<bool> inMst(n_size, false);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(int i=0;i<n_size;++i) {
        pair<int,int> temp = {key[i], i};
        pq.push(temp);
    }
    
    while(!pq.empty()) {
        
        pair<int,int> node = pq.top(); pq.pop();
        
        if(!inMst[node.second]){
            inMst[node.second] = true;
            
            int u = node.second ;
            
            if(parent[node.second] == -1) {
                
                for(auto v:adj[u]) {
                    
                    if(!inMst[v.first] &&
                       (hotspot.find(v.first) != hotspot.end()) &&
                       (key[v.first] > ( v.second)) ) {
                        
                        parent[v.first] = u;
                        key[v.first] = v.second;
                        pair<int,int> temp_pr = {key[v.first], v.first};
                        pq.push(temp_pr);
                        
                    }
                }
            }
            
        }
    }
    
}


unordered_map<string, long long int> dijkstra(int src) {
    
    int n = adj.size();
    
    vector<long long int> key(n,LLONG_MAX);
    vector<bool> isVis(n,false);
    key[src] = 0;
    
    priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int,int>>> pq;
    pq.push(make_pair(key[src], src));
    
    while(!pq.empty()) {
        pair<long long int, int> temp = pq.top(); pq.pop();
        
        int u = temp.second;
        isVis[u] = true;
        
        for(pair<int,int> v_ed : adj[u]) {
            if( !isVis[v_ed.first] && key[v_ed.first] > key[u]+v_ed.second) {
                key[v_ed.first] = key[u]+v_ed.second;
                pq.push(make_pair(key[v_ed.first], v_ed.first));
            }
        }
    }
    
    
    unordered_map<string, long long int> umap;
    
    for(int i=0;i<n;++i) {
        const string map_key = to_string(src)+":"+to_string(i);
        umap[map_key] = key[i];
    }
    
//    for(auto it=umap.begin();it!=umap.end();++it) {
//        cout<<it->first<<" "<<it->second<<"\n";
//    }
    
    
    return umap;
}


void brute_force(vector<int> hspot, vector<int>avaiable_option,
                 unordered_map<int, bool> &isVis,
                 int i, int j,
                 long long int cost, unordered_map<int, int> &bf_parent) {
    
    
    if(i>=0 and j<0) {
        return ;
    }
    
    if(i<0) {
        if(cost > 0 && cost < min_cost) {
            min_cost = cost;
            brute_force_trace_parent = bf_parent;
        }
    } else {
        
        // j chooses i and repeats itself
        // the same point chose itself
        
        ll cost_of_building = (isVis[avaiable_option[j]])?0:cost_of_build[avaiable_option[j]];
        
        /*TODO: inmprovement of shortest path*/
        
        ll cost_of_path ;
        if(hspot[i] == avaiable_option[j]) {
            cost_of_path = 0 ;
        } else {
            string key1 = to_string(hspot[i])+":"+to_string(avaiable_option[j]);
            string key2 = to_string(avaiable_option[j])+":"+to_string(hspot[i]);
            
            //cout<<key1<<" "<<key2<<" "<<shortest_cost_path_base[hspot[i]][key1]<<" "<<shortest_cost_path_base[avaiable_option[j]][key2]<<"\n";
            
            if(shortest_cost_path_base[hspot[i]].find(key1) == shortest_cost_path_base[hspot[i]].end()) {
                brute_force(hspot, avaiable_option, isVis,
                i, j-1, cost, bf_parent);
                return;
            }
            
            
            cost_of_path = min(shortest_cost_path_base[hspot[i]][key1], shortest_cost_path_base[avaiable_option[j]][key2]);
            
        }
        
        if(cost+ cost_of_path+ cost_of_building < 0) return;
        
        bool isCheckedAtThisLevel = (!isVis[avaiable_option[j]]);
        
        isVis[avaiable_option[j]] = true;
        bf_parent[hspot[i]] = avaiable_option[j];
        // selecting and repeating
        brute_force(hspot, avaiable_option, isVis,
                    i-1, j, cost+cost_of_building+cost_of_path, bf_parent);
        
        
        //not selecting
        if(isCheckedAtThisLevel)isVis[avaiable_option[j]] = false;
        bf_parent[hspot[i]] = -1;
        brute_force(hspot, avaiable_option, isVis,
        i, j-1, cost, bf_parent);
                
    }
    
}

// 100604239
void brute_force_driver(vector<int> hspot, vector<int>avaiable_option ) {
    
   // sort(hspot.begin(), hspot.end());
    
    
    
     do {
        
//        for(int x:hspot) {
//            cout<<x<<" ";
//        }
//        cout<<"\n";
        
        min_cost = LLONG_MAX;
        unordered_map<int, bool> umap;
        unordered_map<int, int> bf_parent;
        
        brute_force(hspot, avaiable_option, umap,
                   (int) hspot.size()-1, (int)avaiable_option.size()-1, 0, bf_parent);
     //   cout<<min_cost<<"\n";
        
     } while(next_permutation(hspot.begin(), hspot.end()));
    
}


long long int compute_cost(vector<int> parent, unordered_set<int> hotspot) {
    
    long long int res = 0 ;
    
    unordered_set<int> new_buildings ;
    
    for(int u:hotspot) {
        if(parent[u] == -1) {
            new_buildings.insert(u);
        } else {
            new_buildings.insert(parent[u]);
        }
    }
    
    long long int cost_new_building = 0;
    long long int cost_of_path = 0;
    
    for (int u:new_buildings) {
        cost_new_building+=cost_of_build[u];
    }
    
    for(int u:hotspot) {
        if(parent[u]!=-1) {
            
            /*TODO: inmprovement of shortest path*/
            string key1 = to_string(u)+":"+to_string(parent[u]);
            string key2 = to_string(parent[u])+":"+to_string(u);
            
            long long int cst = min(shortest_cost_path_base[u][key1], shortest_cost_path_base[parent[u]][key2]);
            cost_of_path+=cst;
        }
    }
    
    res = cost_new_building+cost_of_path;
    return res;
}




int main() {
    int number_of_nodes;
    int number_of_edges;
    
   
    for(int i=1;i<=15;++i) {
 
        
        const string input_file = "/Users/manishkumar/Work/Git-Projects/competitive/misc/btp_automated/btp_automated/tt_15_95/test_case"+to_string(i)+"_15_95_1.txt" ;
        const string output_file = "/Users/manishkumar/Work/Git-Projects/competitive/misc/btp_automated/btp_automated/tt_15_95/output3.txt";
        
        freopen(input_file.c_str(),"r",stdin);
        freopen(output_file.c_str(),"a",stdout);
    
            int T;
            cin>>T;
   
        
            cin>>number_of_nodes;
            cin>>number_of_edges;
            adj = vector<vector<pair<int,int>>>(number_of_nodes);
            shortest_cost_path_base = vector<unordered_map<string, long long int>>(number_of_nodes);
        
            cost_of_build = vector<int>(number_of_nodes);
            vector<int> parent(number_of_nodes, -1);
            vector<int> key;
            
            bool isDirected = false;
            
            vector<set<int>> adj_copy(number_of_nodes);
                
            // Graph initialised
            for(int i=0;i<number_of_edges;++i) {
                int u,v,w;
                cin>>u>>v>>w ;
                
                
                if(!isDirected) {
                    
                    adj[u].push_back(make_pair(v, w));
                    adj[v].push_back(make_pair(u, w));
                    
                } else {
                    adj[u].push_back(make_pair(v, w));
                }
            }
            
            
            for(int i=0;i<number_of_nodes;++i) {
                unordered_map<string, ll> res = dijkstra(i);
                shortest_cost_path_base[i] = res;
            }
        

            // Cost of build initialised
            srand(time(0));
            for(int i=0;i<number_of_nodes;++i) {
                cost_of_build[i] = (rand()%COST_OF_BUILD_WEIGHT_FACTOR) +1;
            }
            
            key = cost_of_build;
            
            
            // Initialise random hotspot
            unordered_set<int> hotspot;
            int hostspot_size = number_of_nodes*RANDOM_HOTSPOT_FACTOR;
            
            for(int i=0;i<hostspot_size;++i) {
                int val = rand()%number_of_nodes;
                hotspot.insert(val);
            }
            
            
            auto start = high_resolution_clock::now();
            buildMSF(key, adj, parent, hotspot);
            auto stop = high_resolution_clock::now();
            
            auto duration_msf_execution_time = duration_cast<microseconds>(stop - start);
            

            long long int msf_cost_res = compute_cost(parent, hotspot);

                        
            vector<int> hspot;
            
            for(int r_hspot:hotspot) {
                hspot.push_back(r_hspot);
            }
            
            vector<int> avail(number_of_nodes);
            iota(avail.begin(), avail.end(), 0);
            
            start = high_resolution_clock::now();
            brute_force_driver(hspot, avail);
            stop = high_resolution_clock::now();
            
            auto duration_brute_force_execution_time  = duration_cast<microseconds>(stop - start);
            long long int brute_force_cost_res = min_cost;
          
            cout<<msf_cost_res<<","<<duration_msf_execution_time.count()<<","<<brute_force_cost_res<<","<<duration_brute_force_execution_time.count()<<"\n";
    
    
    }
    
    cout<<"-------------------------------\n";
    return 0;
}
