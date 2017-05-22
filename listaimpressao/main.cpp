/*
  ATENÇÃO, ESSA DESGRAÇA USA THREAD, EU FIZ ISSO AQUI SÒ PRA ALIMENTAR MEU EGO
  PRA COMPILAR ISSO DAQUI EU TIVE QUE USAR UBUNTU COM A ULTIMA VERSÃO DO GCC
  INSTALADA, SE VOCÊ QUISER TENTAR VOCÊ PODE FAZER:

  Pra instalar o gcc:
  sudo apt-get install GCC

  Pra compilar:
  g++ -std=c++11 main.cpp -o main -pthread

  Pra executar:
  ./main

  Não consegui fazer o compilador compilar certinho no windows, mas você talvez
  consiga, boa sorte

  O programa pode parecer que travou as vezes, principalmente após apertar
  enter, caso aconteca aperte enter mais uma vez e aguarde
*/

#include <iostream>
#include <thread>
#include <stdio.h>
#define limite 10

using namespace std;

struct impressao {
  string maquina = "";
  string arquivo = "";
};

struct impressao filaDeImpressao[limite];
int topo = -1;
string ultimaMensagem = "Nenhuma mensagem";

char selecao = '0';

unsigned long ultimaRemocao =
    std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count();
/*
  Printa o menu
*/
void printMenu(){
  if (selecao == '1'){
    cout << "Siga as instrucoes:" << endl;
    cout << "Digite a maquina responsavel pela impressao e aperte enter" << endl;
    cout << "Depois digite o nome do arquivo e aperte enter" << endl;
    return;
  }
  else if (selecao == '2'){
    cout << "Siga as instrucoes:" << endl;
    cout << "Digite o a posicao que quer excluir" << endl;
    return;
  }

  cout << "+--------------------------------------+" << endl;
  cout << "| * Menu Trabalho de Impressão *       |" << endl;
  cout << "| 1 - Inserir trabalho de impressão    |" << endl;
  cout << "| 2 - Remover trabalho de impressão    |" << endl;
  cout << "| 3 - É automatico                     |" << endl;
  cout << "| 4 - Sair                             |" << endl;
  cout << "| Item >                               |" << endl;
  cout << "+--------------------------------------+" << endl;
}

/*
Insere um trabalho na fila (push)
*/
void inserirTrabalhoImpressao(string maquina, string arquivo) {
  if (topo >= limite) {
    topo = limite;
    ultimaMensagem = "Erro ao inserir na lista: LISTA CHEIA";
    return;
  }
  topo++;
  filaDeImpressao[topo].maquina = maquina;
  filaDeImpressao[topo].arquivo = arquivo;
  ultimaMensagem = "Item colocado na lista com sucesso";
  return;
}

/*
  Insere valores padrões na lista antes do programa se iniciar
*/
void adicionarListaDefault() {
  inserirTrabalhoImpressao("HP1", "TRABALHO.DOC");
  inserirTrabalhoImpressao("HP2", "IMAGEM.JPG");
  inserirTrabalhoImpressao("HP3", "DOCUMENTO.PDF");
}

/*
  Retira o primeiro item da lista (shift)
*/
struct impressao removerPrimeiroItem() {
  if (topo < 0) {
    ultimaMensagem = "Erro ao retirar item da lista: Lista vazia";
    return filaDeImpressao[0];
  }
  struct impressao temp = filaDeImpressao[0];
  for (int i = 1; i < topo + 1; i++) {
    filaDeImpressao[i - 1] = filaDeImpressao[i];
  }
  topo--;
  return temp;
}

/*
  Retira um documento especifico
*/
struct impressao removerElemento(int pos){
  if (pos < 0 && pos > topo){
    ultimaMensagem = "Erro ao retirar item especifico: Fora da lista";
    return filaDeImpressao[0];
  }
  if (pos == topo) {
    topo--;
    return filaDeImpressao[topo + 1];
  }
  struct impressao temp = filaDeImpressao[pos];
  for (int i = pos + 1; i < topo + 1; i++) {
    filaDeImpressao[i - 1] = filaDeImpressao[i];
  }
  return temp;
}

void printStruct(){
  cout << endl << "Lista de impressoes" << endl;
  for (int i = 0; i < topo + 1; i++) {
    cout << i << " " << filaDeImpressao[i].maquina
      << " " << filaDeImpressao[i].arquivo << endl;
  }
}

void listaThread(){
  while (selecao != '4'){
    unsigned long agora =
    std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count();
    if (agora - ultimaRemocao > 3000) {
      ultimaRemocao =
        std::chrono::duration_cast<std::chrono::milliseconds>
          (std::chrono::system_clock::now().time_since_epoch()).count();
      if (selecao != '1' && selecao != '2'){
        cout << "\033[2J\033[1;1H";
        cout << ultimaMensagem;
        printStruct();
        printMenu();
      }
      removerPrimeiroItem();
    }
  }
}

void inserirTrabalhoUsuario(){
  cout << "\033[2J\033[1;1H";
  cout << ultimaMensagem;
  printStruct();
  printMenu();
  string arquivo = "";
  string maquina = "";
  cin >> maquina;
  cin >> arquivo;
  inserirTrabalhoImpressao(maquina, arquivo);
  if (topo < 0) {
    ultimaRemocao =
      std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count();
  }
  selecao = '0';
}

void removerElementoUsuario(){
  cout << "\033[2J\033[1;1H";
  cout << ultimaMensagem;
  printStruct();
  printMenu();
  int remocao = 0;
  cin >> remocao;
  removerElemento(remocao);
  selecao = '0';
}

int main() {
  adicionarListaDefault();
  thread t1(listaThread);
  while (selecao != '4'){
    selecao = getchar();
    if (selecao == '1') {
      inserirTrabalhoUsuario();
    } else if (selecao == '2') {
      removerElementoUsuario();
    } else {
      continue;
    }
  }
  t1.join();
  cout << "\033[2J\033[1;1H";
  cout << "bye :>" << endl;
  return 0;
}
