#include <iostream>

int getChute(int tentativas, int chute);

using namespace std;

int main() {

  cout << "\n*************************************" << endl;
  cout << "* Bem-vindos ao jogo de adivinhação *" << endl;
  cout << "*************************************" << endl;

  char dificuldade = ' ';

  cout << endl << "Escolha o nível de dificuldade:" << endl;
  cout << "Fácil (F), Médio (M), Difícil (D)" << endl;
  cout << "Nível de dificuldade: ";

  dificuldade = tolower(dificuldade);
  cin >> dificuldade;

  int numero_tentativas;

  if (dificuldade == 'f')
    numero_tentativas = 15;
  else if (dificuldade == 'm')
    numero_tentativas = 10;
  else
    numero_tentativas = 5;


  srand(time(nullptr));
  const int NUMERO_SECRETO = rand() % 100;
  bool nao_acertou = true;
  int tentativas;
  double pontos = 1000;

  for (tentativas = 1; tentativas <= numero_tentativas; tentativas++) {
    int chute = 0;
    chute = getChute(tentativas, chute);

    bool acertou = chute == NUMERO_SECRETO;
    bool chute_maior = chute > NUMERO_SECRETO;
    double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
    pontos = pontos - pontos_perdidos;

    if (acertou) {
      cout << endl << "Parabéns você acertou o número secreto!" << endl;
      nao_acertou = false;
      break;
    }
    else if (chute_maior)
      cout << endl << "Seu chute foi maior que o número secreto!" << endl;
    else
      cout << endl << "Seu chute foi menor que o número secreto!" << endl;
  }

  cout << endl << "--------------------- Fim do jogo ---------------------" << endl;
  if (nao_acertou)
    cout << "Você perdeu! Tente novamente!" << endl;
  else {
    cout << "Parabéns você acertou o número secreto em " << tentativas << " tentativas!" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
  }
}

int getChute(int tentativas, int chute) {

  cout << endl << "Tentativa: " << tentativas << endl;
  cout << "\nQual o seu chute? ";
  cin >> chute;

  cout << endl << "O valor do seu chute é: " << chute << endl;
  return chute;
}