#include "iostream"
#include "cstdlib"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#define tam 100

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
    return 0;
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

bool maiorNome(int i, int prox)
{
    char c1 = bancoDeDados[i].nome[0];
    char c2 = bancoDeDados[prox].nome[0];
    int nomePos = 0;
    bool retorno = false;
    if (bancoDeDados[i].nome == bancoDeDados[prox].nome)
    {
        if (bancoDeDados[i].id > bancoDeDados[prox].id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    while (c1 != '\0' || c2 != '\0')
    {
        if (c1 < c2)
        {
            retorno = false;
            break;
        }
        else if (c1 > c2)
        {
            retorno = true;
            break;
        }
        else
        {
            nomePos++;
            c1 = bancoDeDados[i].nome[nomePos];
            c2 = bancoDeDados[prox].nome[nomePos];
        }
    }
    return retorno;
}

int ordenarNome()
{
    system("cls");
    bool trocando = false;
    do
    {
        trocando = false;
        for (int i = 0; i < lastPos; i++)
        {
            if (maiorNome(i, i+1))
            {
                trocar(i, i+1);
                trocando = true;
            }
        }
    }
    while (trocando);
    cout << "Banco ordenado por nome com sucesso" << endl;
    system("pause");
    return 0;
}

int ordenarId()
{
    system("cls");
    bool trocando = false;
    do
    {
        trocando = false;
        for (int i = 0; i < lastPos; i++)
        {
            if (bancoDeDados[i].id > bancoDeDados[i + 1].id)
            {
                trocando = true;
                trocar(i, i + 1);
            }
        }
    }
    while (trocando == true);
    cout << "Banco ordenado por ID com sucesso" << endl;
    system("pause");
    return 0;
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

int buscaIdadeBinario()
{
    system("cls");
    ordenarIdade();
    int comeco = 0;
    int fim = lastPos;
    int buscaPos = 0;
    int idade = 0;
    idade = pegarIdade();
    bool encontrado = false;

    while (!encontrado)
    {
        buscaPos = (comeco + fim) / 2;
        if (fim < comeco)
        {
            encontrado = false;
            break;
        }
        if (idade == bancoDeDados[buscaPos].idade)
        {
            encontrado = true;
            cout << "Pessoa encontrada na posição: " << endl;
            cout << "Posição: " << buscaPos << endl;
            cout << "Nome: " << bancoDeDados[buscaPos].nome << endl;
            cout << "Idade: " << bancoDeDados[buscaPos].idade << endl;
            cout << "Id: " << bancoDeDados[buscaPos].id << endl;
            cout << "-------" << endl;
            break;
        }
        else if (idade < bancoDeDados[buscaPos].idade)
        {
            fim = buscaPos - 1;
        }
        else
        {
            comeco = buscaPos + 1;
        }
    }

    if (!encontrado)
    {
        cout << "Nenhum registro encontrado" << endl;
    }
    system("pause");
    return 0;
}

bool contemString(string str, string pesquisa)
{
    int tamanhoStr = str.length();
    int tamanhoPesquisa = pesquisa.length();
    string tempStr = str;
    string tempPesquisa = pesquisa;
    if (str == pesquisa)
    {
        return true;
    }
    if (tamanhoStr > tamanhoPesquisa)
    {
        tamanhoStr = tamanhoPesquisa;
        tempStr = str.substr(0, tamanhoStr);
        if (tempStr != pesquisa)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        for (int i = 0; i < (tamanhoPesquisa - tamanhoStr); i++)
        {
            tempPesquisa = pesquisa.substr(i, tamanhoStr);
            if (tempPesquisa == str)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}

int buscaNome()
{
    system("cls");
    cout << "Alguns valores podem ser aproximados" << endl;
    string nome = "";
    nome = pegarNome();
    bool encontrado = false;
    for (int i = 0; i < (lastPos >= (tam - 1) ? tam : (lastPos + 1)); i++)
    {
        if (contemString(nome, bancoDeDados[i].nome))
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
    lastPos = 9;
    string nomes[] = {"Gizs", "Yoz", "Multax", "Klovkx", "Induvente", "Mantrz", "Wyxxyz", "Zaac", "Halesh", "Sahah"};
    int idades[] = {15, 3, 69, 45, 99, 47, 52, 37, 48, 14};
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
    cout << "\n4 - Ordernar por nome";
    cout << "\n5 - Ordenar por ID";
    cout << "\n6 - Busca por idade (sequencial)";
    cout << "\n7 - Busca por idade (binaria) (executa ordenar por idade)";
    cout << "\n8 - Busca por nome";
    cout << "\n9 - Limpar Banco";
    cout << "\n0 - Inserir pessoas pré definidas (executa limpar banco)";
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
            ordenarId();
            break;
        case '6':
            buscaIdadeSequencial();
            break;
        case '7':
            buscaIdadeBinario();
            break;
        case '8':
            buscaNome();
            break;
        case '9':
            limparLista();
            break;
        case '0':
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
