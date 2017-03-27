#include "iostream"
#include "cstdlib"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define tam 15

using namespace std;

int lastPos = -1;

struct pessoa
{
    int id;
    int idade;
    string nome;
};

struct pessoa bancoDeDados[tam];

string pegarNome()
{
    string nome;
    cout << "Digite o nome da pessoa: ";
    cin >> nome;
    return nome;
}

int pegarIdade()
{
    int idade;
    cout << "Digite a idade da pessoa: ";
    cin >> idade;
    return idade;
}

int inserirPessoa()
{
    system("cls");
    lastPos++;
    if (lastPos >= tam)
    {
        lastPos = tam - 1;
        cout << "Numero maximo de pessoas inseridas" << endl;
        system("pause");
        return 0;
    }
    string nome = pegarNome();
    int idade = pegarIdade();
    bancoDeDados[lastPos].nome = nome;
    bancoDeDados[lastPos].idade = idade;
    bancoDeDados[lastPos].id = lastPos;
    cout << "\nPessoa inserida com sucesso na posição: " << lastPos << endl;
    system("pause");
    return 0;
}

int mostrarBanco()
{
    system("cls");
    for (int i = 0; i < (lastPos >= (tam - 1) ? tam : (lastPos + 1)); i++)
    {
        cout << "Nome: " << bancoDeDados[i].nome << endl;
        cout << "Idade: " << bancoDeDados[i].idade << endl;
        cout << "Id: " << bancoDeDados[i].id << endl;
        cout << "-------" << endl;
    }
    system("pause");
    return 0;
}

int trocar(int i, int prox)
{
    struct pessoa tempPessoa;
    tempPessoa = bancoDeDados[i];
    bancoDeDados[i] = bancoDeDados[prox];
    bancoDeDados[prox] = tempPessoa;
}

int ordenarIdade()
{
    system("cls");
    bool trocando = false;
    do
    {
        trocando = false;
        for (int i = 0; i < lastPos; i++)
        {
            if (bancoDeDados[i].idade > bancoDeDados[i + 1].idade)
            {
                trocando = true;
                trocar(i, i + 1);
            }
        }
    }
    while (trocando == true);
    cout << "Banco ordenado por idade com sucesso" << endl;
    system("pause");
    return 0;
}

int ordenarNome()
{
    bool trocando = false;
    do
    {

    }
    while (trocando);
}

int buscaIdadeSequencial()
{
    system("cls");
    int idade = 0;
    idade = pegarIdade();
    bool encontrado = false;
    for (int i = 0; i < (lastPos >= (tam - 1) ? tam : (lastPos + 1)); i++)
    {
        if (bancoDeDados[i].idade == idade)
        {
            if (!encontrado)
            {
                cout << "Pessoa(s) encontrada(s) na(s) posição(ões): " << endl;
                encontrado = true;
            }
            cout << "Posição: " << i << endl;
            cout << "Nome: " << bancoDeDados[i].nome << endl;
            cout << "Idade: " << bancoDeDados[i].idade << endl;
            cout << "Id: " << bancoDeDados[i].id << endl;
            cout << "-------" << endl;
        }
    }
    if (!encontrado)
    {
        cout << "Nenhum registro encontrado" << endl;
    }
    system("pause");
    return 0;
}

int limparLista()
{
    system("cls");
    lastPos = -1;
    cout << "Lista limpa" << endl;
    system("pause");
    return 0;
}

int inserirPessoaAuto()
{
    lastPos = 4;
    string nomes[lastPos + 1] = {"Gizs", "Yoz", "Multax", "Klovkx", "Induvente"};
    int idades[lastPos + 1] = {15, 3, 69, 45, 99};
    for (int i = 0; i < (lastPos + 1); i++)
    {
        bancoDeDados[i].nome = nomes[i];
        bancoDeDados[i].idade = idades[i];
        bancoDeDados[i].id = i;
    }
    return 0;
}

char tela ()
{
    char tecla = '2';
    system("cls");
    cout << "\n** Simulação de banco de dados **";
    cout << "\n\n1 - Inserir pessoa";
    cout << "\n2 - Exibir Banco de dados";
    cout << "\n3 - Ordernar por idade";
    cout << "\n4 - Ordernar por nome *não implementado*";
    cout << "\n5 - Busca por idade (sequencial)";
    cout << "\n6 - Busca por idade (binaria) (executa ordenar por idade) *não implementado*";
    cout << "\n7 - Busca por nome *não implementado*";
    cout << "\n8 - Limpar Banco";
    cout << "\n9 - Inserir pessoas pré definidas (executa limpar banco)";
    cout << "\nEsc - Sair";
    cout << "\n\n\nItem>";
    tecla = getch();
    cout << endl;
    return tecla;
}

void menu()
{
    char escolha = '2';
    while (escolha != 27)
    {
        escolha = tela();
        switch (escolha)
        {
        case '1':
            inserirPessoa();
            break;
        case '2':
            mostrarBanco();
            break;
        case '3':
            ordenarIdade();
            break;
        case '4':
            ordenarNome();
            break;
        case '5':
            buscaIdadeSequencial();
            break;
        case '8':
            limparLista();
            break;
        case '9':
            inserirPessoaAuto();
            break;
        default:
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}
