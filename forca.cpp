#include <string>
#include <iostream>

using namespace std;

bool letra_existe(string palavra_secreta, char chute);

int main() {

  const string PALAVRA_SECRETA = "LARANJA";
  cout << PALAVRA_SECRETA << endl;

  bool nao_acertou = true;
  bool nao_enforcou = true;

  while (nao_acertou && nao_enforcou) {
    char chute;
    cin >> chute;

    if (letra_existe(PALAVRA_SECRETA, chute)) {
      cout << endl << "Você acertou!" << endl;
    }
    else {
      cout << endl << "Você errou! Tente novamente!" << endl;
    }
  }
}

bool letra_existe(string PALAVRA_SECRETA, char chute) {

  for (char letra: PALAVRA_SECRETA) {
    if (chute == letra) {
      return true;
    }
  }
  return false;
}
