#include <iostream>

int getChute(int tentativas, int chute);

using namespace std;

int main() {
  cout << "\n*************************************" << endl;
  cout << "* Bem-vindos ao jogo de adivinhação *" << endl;
  cout << "*************************************" << endl;

  const int NUMERO_SECRETO = 42;

  bool nao_acertou = true;
  int tentativas = 0;
  double pontos = 1000;

  while (nao_acertou) {
    int chute = 0;
    tentativas++;
    chute = getChute(tentativas, chute);

    bool acertou = chute == NUMERO_SECRETO;
    bool chute_maior = chute > NUMERO_SECRETO;
    double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
    pontos = pontos - pontos_perdidos;

    if (acertou) {
      cout << endl << "Parabéns você acertou o número secreto!" << endl;
      nao_acertou = false;
    }
    else if (chute_maior)
      cout << endl << "Seu chute foi maior que o número secreto!" << endl;

    else
      cout << endl << "Seu chute foi menor que o número secreto!" << endl;
  }

  cout << endl << "--------------------- Fim do jogo ---------------------" << endl;
  cout << "Parabéns você acertou o número secreto em " << tentativas << " tentativas!" << endl;
  cout.precision(2);
  cout << fixed;
  cout << "Sua pontuação foi de " << pontos << " pontos.";
}

int getChute(int tentativas, int chute) {
  cout << endl << "Tentativa: " << tentativas << endl;
  cout << "\nQual o seu chute? ";
  cin >> chute;

  cout << endl << "O valor do seu chute é: " << chute << endl;
  return chute;
}