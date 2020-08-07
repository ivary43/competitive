#include "/Users/manishkumar/Work/stdc++.h"
using namespace std;

long long int min_cost = LLONG_MAX;
vector<vector<pair<int,int>>> adj ;
vector<int> cost_of_build;

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
            
            if(parent[u] == -1) {
                
                for(auto v:adj[u]) {
                    
                    if(!inMst[v.first] &&
                       (hotspot.find(v.first) != hotspot.end()) &&
                       (key[v.first] > (v.second)) ) {
                        
                        parent[v.first] = u;
                        key[v.first] =  v.second;
                        pair<int,int> temp_pr = {key[v.second], v.first};
                        pq.push(temp_pr);
                        
                    }
                }
            }
            
        }
    }
    
}


void brute_force(vector<int> hspot, vector<int>avaiable_option,
                 unordered_map<int, int> &isVis,
                 int i, int j,
                 long long int cost, unordered_map<int, int> &bf_parent) {
    
    
    
    if( (i>=0 and j<0)) {
        return ;
    }
    
    //cout<<i<<" ff "<<j<<endl;
    if(i<0) {
        
//        unordered_map<int, int>::iterator it;
//        for(it = bf_parent.begin();it!=bf_parent.end();++it) {
//            cout<<it->first<<"<---"<<it->second<<"  ";
//        }
//        cout<<"\n";
        
        if(cost< min_cost) {
            min_cost = cost;
            brute_force_trace_parent = bf_parent;
        }
    } else {
        
        // j chooses i and repeats itself
        // the same point chose itself
        
        int cost_of_building = (isVis[avaiable_option[j]]>=1)?0:cost_of_build[avaiable_option[j]];
        int cost_of_path = (hspot[i] == avaiable_option[j])?0:adj[hspot[i]][avaiable_option[j]].second;
        
        isVis[avaiable_option[j]]++;
    
        bf_parent[hspot[i]] = avaiable_option[j];
        // selecting and repeating
        brute_force(hspot, avaiable_option, isVis,
                    i-1, j, cost+cost_of_building+cost_of_path, bf_parent);
         
        isVis[avaiable_option[j]]--;
        //not selecting
        bf_parent[hspot[i]] = -1;
        brute_force(hspot, avaiable_option, isVis,
        i, j-1, cost, bf_parent);
                
    }
    
}

long long int brute_force_driver(vector<int> hspot, vector<int>avaiable_option ) {
    
    long long int bf_cost_res = LLONG_MAX;
    
   do {
        min_cost = LLONG_MAX;
        unordered_map<int, int> isvis;
        unordered_map<int, int> bf_parent;
        
        brute_force(hspot, avaiable_option, isvis,
                   (int) hspot.size()-1, avaiable_option.size()-1, 0, bf_parent);
        
        if(bf_cost_res> min_cost) {
            bf_cost_res = min_cost;
        }
        
        cout<<min_cost<<"\n";
        
   } while(next_permutation(hspot.begin(), hspot.end()));
 
    return bf_cost_res;
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
            cost_of_path+=adj[u][parent[u]].second;
        }
    }
    
    res = cost_new_building+cost_of_path;
    return res;
}




int main() {
    int number_nodes = 9;
    //int number_edge = 3;
    
    map<int, pair<int,int>> mp;
    
    int count = 0;
    
    for(int i=0;i<3;++i) {
        for(int j=0;j<3;++j) {
            pair<int,int> pr = {i,j};
            mp[count] = pr;
            count++;
        }
    }
    
    adj = vector<vector<pair<int,int>>>(number_nodes);
    
    for(int i=0;i<number_nodes;++i) {
        for(int j=0;j<number_nodes;++j) {
            if(i != j) {
                
                pair<int,int> pos_u = mp[i];
                pair<int,int> pos_v = mp[j];
                
                int dist = abs(pos_u.first-pos_v.first) + abs(pos_u.second - pos_v.second);
                adj[i].push_back(make_pair(j,dist));
            }
        }
    }
    
    adj[0][8].second = 10;
    adj[2][8].second = 8;
    adj[3][8].second = 9;
    adj[8][0].second = 10;
    adj[8][2].second = 8;
    adj[8][3].second = 9;
    
    vector<int> parent(number_nodes, -1);
    cost_of_build = vector<int>(number_nodes);
    
    
    cost_of_build[0] = 5;
    cost_of_build[1] = 6;
    cost_of_build[2] = 6;
    cost_of_build[3] = 9;
    cost_of_build[4] = 3;
    cost_of_build[5] = 9;
    cost_of_build[6] = 3;
    cost_of_build[7] = 8;
    cost_of_build[8] = 1;
    
    
    vector<int> key;
    key = cost_of_build;
    
    unordered_set<int> hotspot;
    
    hotspot.insert(0);
    hotspot.insert(2);
    hotspot.insert(3);
    
    
    buildMSF(key, adj, parent, hotspot);


    cout<<"Parent of nodes\n\n";

    for(int i=0;i<number_nodes;++i) {
        cout<<i<<"<---->"<<parent[i]<<"\n";
    }

    long long int cost_res = compute_cost(parent, hotspot);

    cout<<"Total cost is -- "<<cost_res<<"\n";
    
    
    
    vector<int> hspot;
    hspot.push_back(0);hspot.push_back(2);hspot.push_back(3);
    
    vector<int> avail;
    avail.push_back(0);avail.push_back(1);avail.push_back(2);avail.push_back(3);
    avail.push_back(4);avail.push_back(4);avail.push_back(6);avail.push_back(7);avail.push_back(8);
    
    long long int bf_res = brute_force_driver(hspot, avail);
    
    cout<<"Total cost by brute force is -- "<<bf_res<<"\n";
    
    
    unordered_map<int, int> :: iterator it ;
    
    cout<<"Parent--\n";
    for(it = brute_force_trace_parent.begin();it!=brute_force_trace_parent.end();++it) {
        cout<<it->first<<"-->"<<it->second<<"\n";
    }
    
    return 0;
}
