#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

bool letra_existe(string palavra_secreta, char chute);

bool nao_acertou(string palavra_secreta, map<char, bool> chutou);

bool nao_enforcou(vector<char> chutes_errados);

void imprime_cabecalho();

void imprime_erros(vector<char> &chutes_errados);

void imprime_palavra(string &palavra_secreta, map<char, bool> &chutou);

char chuta(string &palavra_secreta, vector<char> &chutes_errados);

vector<string> le_arquivo();

void sorteia_palavra();

string palavra_secreta = "MELAO";


int main() {

    map<char, bool> chutou;

    vector<char> chutes_errados;

    imprime_cabecalho();

    le_arquivo();

    sorteia_palavra();


    while (nao_acertou(palavra_secreta, chutou) && nao_enforcou(chutes_errados)) {

        imprime_erros(chutes_errados);

        imprime_palavra(palavra_secreta, chutou);

        char chute = chuta(palavra_secreta, chutes_errados);

        chutou[chute] = true;

    }

    cout << endl << "Fim de jogo!" << endl;

    cout << "A palavra secreta era: " << palavra_secreta << endl << endl;

    if (nao_acertou(palavra_secreta, chutou)) {

        cout << "Você perdeu! Tente novamente!" << endl;

    }
    else {

        cout << "Parabéns! Você acertou a palavra secreta!" << endl;

    }

}


vector<string> le_arquivo() {

    ifstream arquivo;

    arquivo.open("palavras.txt");

    int quantidade_palavras;

    arquivo >> quantidade_palavras;

    vector<string> palavras_arquivo;

    for (int i = 0; i < quantidade_palavras; i++) {

        string palavra_lida;

        arquivo >> palavra_lida;

        palavras_arquivo.push_back(palavra_lida);

    }

    return palavras_arquivo;

}


void sorteia_palavra() {

    vector<string> palavras = le_arquivo();

    srand(time(nullptr));

    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];

}


char chuta(string &palavra_secreta, vector<char> &chutes_errados) {

    cout << endl << "Seu chute é: ";

    char chute;

    cin >> chute;

    if (letra_existe(palavra_secreta, chute)) {

        cout << endl << "Você acertou!" << endl;

    }
    else {

        cout << endl << "Você errou! Tente novamente!" << endl;

        chutes_errados.push_back(chute);

    }

    return chute;

}


void imprime_palavra(string &palavra_secreta, map<char, bool> &chutou) {

    for (char letra: palavra_secreta) {

        if (chutou[letra]) {

            cout << letra << " ";

        }
        else {

            cout << "_ ";

        }

    }

    cout << endl;

}


void imprime_erros(vector<char> &chutes_errados) {

    cout << "Chutes errados: ";

    for (char letra: chutes_errados) {

        cout << letra << " ";

    }

    cout << endl << endl;

}


void imprime_cabecalho() {

    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl << endl;

}


bool nao_enforcou(vector<char> chutes_errados) {

    return chutes_errados.size() < 5;
}


bool nao_acertou(string palavra_secreta, map<char, bool> chutou) {

    for (char letra: palavra_secreta) {

        if (!chutou[letra]) {

            return true;

        }

    }

    return false;

}

bool letra_existe(string palavra_secreta, char chute) {

    for (char letra: palavra_secreta) {

        if (chute == letra) {

            return true;

        }

    }

    return false;

}
