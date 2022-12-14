#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool letra_existe(string palavra_secreta, char chute);

bool nao_acertou(const string PALAVRA_SECRETA, map<char, bool> chutou);

bool nao_enforcou(vector<char> chutes_errados);

void imprime_cabecalho();

void imprime_erros(vector<char> &chutes_errados);

void imprime_palavra(const string &PALAVRA_SECRETA, map<char, bool> &chutou);

char chuta(const string &PALAVRA_SECRETA, vector<char> &chutes_errados);

int main() {

  imprime_cabecalho();

  const string PALAVRA_SECRETA = "LARANJA";
  map<char, bool> chutou;
  vector<char> chutes_errados;

  while (nao_acertou(PALAVRA_SECRETA, chutou) && nao_enforcou(chutes_errados)) {
    imprime_erros(chutes_errados);

    imprime_palavra(PALAVRA_SECRETA, chutou);

    char chute = chuta(PALAVRA_SECRETA, chutes_errados);

    chutou[chute] = true;
  }

  cout << endl << "Fim de jogo!" << endl;
  cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl << endl;

  if (nao_acertou(PALAVRA_SECRETA, chutou)) {
    cout << "Você perdeu! Tente novamente!" << endl;
  }
  else {
    cout << "Parabéns! Você acertou a palavra secreta!" << endl;
  }
}

char chuta(const string &PALAVRA_SECRETA, vector<char> &chutes_errados) {

  cout << endl << "Seu chute é: ";
  char chute;
  cin >> chute;

  if (letra_existe(PALAVRA_SECRETA, chute)) {
    cout << endl << "Você acertou!" << endl;
  }
  else {
    cout << endl << "Você errou! Tente novamente!" << endl;
    chutes_errados.push_back(chute);
  }
  return chute;
}

void imprime_palavra(const string &PALAVRA_SECRETA, map<char, bool> &chutou) {

  for (char letra: PALAVRA_SECRETA) {
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

bool nao_acertou(const string PALAVRA_SECRETA, map<char, bool> chutou) {

  for (char letra: PALAVRA_SECRETA) {
    if (!chutou[letra]) {
      return true;
    }
  }
  return false;
}

bool letra_existe(string PALAVRA_SECRETA, char chute) {

  for (char letra: PALAVRA_SECRETA) {
    if (chute == letra) {
      return true;
    }
  }
  return false;
}
