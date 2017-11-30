#include <bits/stdc++.h>
#define MAX 1500

using namespace std;
using tiii = tuple<int, int, int>;

void menu();
void show_edges(map<int, tiii>& edges, bool fixed[]);
bool in_range(int c, int low, int high);
bool edge_exists(int src, int dst, map<int, tiii>& edges);
bool any_fixed(int number_of_edges, bool fixed[]);

int main(){
    vector<tiii> adj[MAX];
    map<int, tiii> edges;
    bool fixed[MAX];

    int number_of_nodes;
    do {
        cout << "How many nodes? (Up to 1000) ";
        cin >> number_of_nodes;
    } while(number_of_nodes < 0 or number_of_nodes > 1000);
    cout << endl;

    int option;
    int node_id = 0;

    do {
        menu();

        cout << endl;
        cin >> option;

        if(option == 1){
            int src, dst, w;
            cout << "Insert a edge in the format (first node, second node, weight): ";
            cin >> src >> dst >> w;

            while(!in_range(src, 1, number_of_nodes) or !in_range(dst, 1, number_of_nodes) or edge_exists(src, dst, edges)){
                cout << "Source or destiny nodes are invalids" << endl;
                cout << "Insert a edge in the format (first node, second node, weight): ";
                cin >> src >> dst >> w;
            }

            edges[node_id] = make_tuple(src, dst, w);
            adj[src].push_back(make_tuple(node_id++, dst, w));

            edges[node_id] = make_tuple(dst, src, w);
            adj[dst].push_back(make_tuple(node_id++, src, w));
        }
        if(option == 2){
            show_edges(edges, fixed);

            int id;
            cout << "Add edge id to fix: ";
            cin >> id;

            while(edges.find(id) == edges.end() or (id >= 1 and id <= number_of_nodes and fixed[id])){
                cout << "Edge with this id is already fixed or does not exist. Add edge to fix: ";
                cin >> id;
            }

            fixed[id] = true;
        }
        if(option == 3){
            // TODO choose root node
            if(any_fixed(edges.size(), fixed)){
                cout << "As there are fixed edges, the result may not be a tree and," << endl;
                cout << "even if it's a tree, may not be a minimum spanning tree." << endl;
                cout << "Keep that in mind." << endl;
            }
        }
        if(option == 4){
            // TODO choose root node
            if(any_fixed(number_of_nodes, fixed)){
                cout << "As there are fixed edges, the result may not be a tree and," << endl;
                cout << "even if it's a tree, may not be a maximum spanning tree." << endl;
                cout << "Keep that in mind." << endl;
            }
        }
        if(option == 5){
            cout << "Clearing fixed edges.." << endl;
            memset(fixed, false, sizeof fixed);
            cout << "Done." << endl;
        }
        if(option == 6){
            show_edges(edges, fixed);
        }
        if(option == 7){
            system("clear");
        }

        cout << endl;
    } while(option != 0);

    cout << "So long and thanks for all the fish!" << endl; 

    return 0;
}

void menu(){
    cout << "What do you want to do?" << endl;
    cout << "1 - add edge" << endl;
    cout << "2 - fix edge" << endl;
    // FIXME minimum spanning subgraph
    cout << "3 - get minimum spanning tree" << endl;
    cout << "4 - get maximum spanning tree" << endl;
    cout << "5 - clear fixed edges" << endl;
    cout << "6 - show edges" << endl;
    cout << "7 - clear console" << endl;
    cout << "0 - quit" << endl;
}

void show_edges(map<int, tiii>& edges, bool fixed[]){
    for(auto e : edges) {
        printf("id: %d, src: %d, dst: %d, weight: %d %s\n",
                e.first, get<0>(e.second), get<1>(e.second), get<2>(e.second), (fixed[e.first] ? "(fixed)" : ""));
    }
}

bool in_range(int c, int low, int high){
    return c >= low and c <= high;
}

bool edge_exists(int src, int dst, map<int, tiii>& edges){
    for(auto e : edges){
        if((get<0>(e.second) == src and get<1>(e.second) == dst) or
            (get<0>(e.second) == src and get<1>(e.second) == dst)){
            return true;
        }
    }
    return false;
}

bool any_fixed(int number_of_edges, bool fixed[]){
    for(int i=1;i<=number_of_edges;i++)
        if(fixed[i])
            return true;
    return false;
}
