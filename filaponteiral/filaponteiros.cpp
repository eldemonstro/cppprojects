#include "iostream"
#include "stdio.h"
#define MAX 10

using namespace std;

int topo = -1;
struct pilha {
  int posicao;
  int valor;
};

bool cheia(){
  return (topo + 1) > (MAX - 1);
}

bool vazia(){
  return topo < 0;
}

int empilhar(int valor, struct pilha *mP){
  if (cheia()) return MAX;
  topo++;
  mP[topo].posicao = topo;
  mP[topo].valor = valor;
  return topo;
}

int desempilhar(struct pilha *mP) {
  if (vazia()) return -1;
  topo--;
  return mP[topo+1].valor;
}

void mostrarPilha(struct pilha *mP){
  if (vazia()) return;
  for (int i = 0; i < (topo + 1); i++) {
    cout << mP[i].valor << endl;
  }
}



int main() {
  struct pilha *mP;
  mP = new struct pilha[MAX];
  empilhar(5, mP);
  empilhar(6, mP);
  mostrarPilha(mP);
  cout << desempilhar(mP) << endl;
  mostrarPilha(mP);
  desempilhar(mP);
  cout << topo;
  return 0;
}
