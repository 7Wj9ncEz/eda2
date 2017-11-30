#include <bits/stdc++.h>
#define MAX 1000

using namespace std;
using ii = pair<int, int>;

void menu(){
    cout << "What do you want to do?" << endl;
    cout << "1 - add connection" << endl;
    cout << "2 - fix connection" << endl;
    // FIXME minimum spanning subgraph
    cout << "3 - get minimum spanning tree" << endl;
    cout << "4 - get maximum spanning tree" << endl;
    cout << "5 - clear fixed connections" << endl;
    cout << "6 - Show fixed edges" << endl;
    cout << "0 - quit" << endl;
}

void show_edges(map<int, tuple<int, int, int> >& edges) {
    for(auto e : edges) {
        printf("id: %d, src: %d, dst: %d, weight: %d\n", e.first, get<0>(e.second), get<1>(e.second), get<2>(e.second));
    }
}

void show_fixed_edges(map<int, tuple<int, int, int>>& edges, bool fixed[]){
    for(auto e : edges){
        if(fixed[e.first]){
            printf("id: %d, src: %d, dst: %d, weight: %d\n", e.first, get<0>(e.second), get<1>(e.second), get<2>(e.second));
        }
    }
}

int main(){
    // FIXME make dynamic
    vector< tuple<int, int, int> > adj[MAX];
    map<int, tuple<int, int, int> > edges;
    bool fixed[MAX];

    int number_of_nodes;
    do {
        cout << "How many nodes? (Up to 1000) ";
        cin >> number_of_nodes;
    } while(number_of_nodes < 0 or number_of_nodes > 1000);

    int option;
    int node_id = 0;

    do {
        menu();

        cout << endl;
        cin >> option;

        if(option == 1){
            // TODO block if there is already an edge between A and B

            int fn, sn, w;
            cout << "Insert a connection in the format (first node, second node, weight): ";
            cin >> fn >> sn >> w;

            while(fn < 1 or fn > number_of_nodes or sn < 1 or sn > number_of_nodes){
                cout << "Source or destiny nodes are invalids" << endl;
                cout << "Insert a connection in the format (first node, second node, weight): ";
                cin >> fn >> sn >> w;
            }

            edges[node_id] = make_tuple(fn, sn, w);
            adj[fn].push_back(make_tuple(node_id++, sn, w));

            edges[node_id] = make_tuple(sn, fn, w);
            adj[sn].push_back(make_tuple(node_id++, fn, w));
        }
        if(option == 2){
            show_edges(edges);

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
            // choose root node
            // check fixed edges (fixed edges should be in the result tree)
        }
        if(option == 4){
            // choose root node
            // check fixed edges (fixed edges should be in the result tree)
        }
        if(option == 5){
            cout << "Clearing fixed connections.." << endl;
            memset(fixed, false, sizeof fixed);
            cout << "Done." << endl;
        }
        if(option == 6){
            show_fixed_edges(edges, fixed);
        }

        cout << endl;
    } while(option != 0);

    cout << "So long and thanks for all the fish!" << endl; 

    return 0;
}
