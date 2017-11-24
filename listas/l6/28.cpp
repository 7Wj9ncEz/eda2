#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;


// Matriz que guarda o resultado máximo de jobs
int M[1000][1000];
vector<ii> job_time_deadline;


void select_tasks(int n, int D){
// Inicializando com 0 se não houver nenhum job ou com 0 se não houver nenhum tempo
  for(int i=0; i<=D; i++){
    M[0][i] = 0;
  }
  for(int i=0; i<=n; i++){
    M[i][0] = 0;
  }

// Para cada elemento da matriz, verificar se o job está no conjunto ótimo
// Se estiver, passar para o job acima com a contagem incrementada e o tempo decrementado.
// Este algoritmo é muito similiar ao Knapsack.
  for(int m=1; m<=n; m++){
    for(int d=0; d<=D; d++){
      if(M[m-1][d] > M[m-1][d-job_time_deadline[m].second+1]){
        M[m][d] = M[m-1][d];
      }else{
        M[m][d] = M[m-1][d-job_time_deadline[m].second]+1;
      }
    }
  }
}


int main(){
// Obtenção de dados. Para facilitar, usou-se um arquivo de entrada.
  int D, deadl, jobs, tj;
  cout << "Insert number of jobs" << endl;
  cin >> jobs;
  cout << "Insert general deadline" << endl;
  cin >> D;
  cout << "Insert deadlines and time to do the job" << endl;
// Inserção de um elemento inválido no vetor de jobs para que a contagem seja inicializada em 1.
  job_time_deadline.push_back(ii(-10, -10));
  for(int i=1; i<= jobs; i++){
    cin >> deadl >> tj;
    job_time_deadline.push_back(ii(deadl, tj));
  }

  sort(job_time_deadline.begin(), job_time_deadline.end());
  select_tasks(jobs, D);
  for(int k=0; k<=jobs; k++){
    for(int l=0; l<D; l++){
      cout << M[k][l] << " ";
    }
    cout << endl;
  }
  return 0;
}
