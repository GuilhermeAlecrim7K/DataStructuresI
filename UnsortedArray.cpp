#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <stdlib.h>
using namespace std;

struct Dados{
  int Id;
  string Nome;
};

struct Dados Lista[12];
int n = 0, m = 10;
enum ErrorTypes {NotFound, RegistroJaExiste, ListaCheia, ListaVazia};
const string headerline = "=============================";
const string OpSuccess = "Operação realizada com sucesso.";

void ReportError(ErrorTypes Erro){
  switch (Erro){
    case RegistroJaExiste:
      cout << "Já existe um registro com essa Id. Tente novamente." << endl;
      break;
    case NotFound:
      cout << "Chave de registro não encontrada" << endl;
      break;
    case ListaCheia:
      cout << "Operação não realizada. Lista cheia" << endl;
      break;
    case ListaVazia:
      cout << "Operação não realizada. Lista Vazia" << endl;
  }

}

int Read(int Key){
  int i = 1;
  Lista[n+1].Id = Key;
  for (; Lista[i].Id != Key; i++){
    continue;
  }
  if (i != n+1)   return i;
  else            return 0;
}

void Create(int Key, string Input){
  if (n < m){
    if (Read(Key) == NotFound){
      Lista[n+1].Id = Key;
      Lista[n+1].Nome = Input;
      n++;
      cout << OpSuccess << endl;
    }
    else ReportError(RegistroJaExiste);
  }
  else ReportError(ListaCheia);
}

void Update(int Key, string Input){
  int Id = Read(Key);
  if (n>0){
    if (Read(Key) != NotFound){
    Lista[Id].Nome = Input;
    cout << OpSuccess << endl;
    }
    else ReportError(NotFound);
  }
  else ReportError(ListaVazia);
}

void Delete(int Key){
  int Id = Read(Key);
  if (n > 0){
    if (Read(Key) != NotFound){
      for (int i = Read(Key); i<n ; i++){
        Lista[i] = Lista[i+1];
      }
      n--;
      cout << OpSuccess << endl;
    }
    else
      ReportError(NotFound);
  }
  else ReportError(ListaVazia);
}

bool Menu(){
  int opCrud;
  int chaveUsuario; string nomeUsuario;
  enum opcoes {Buscar = 1, Inserir, Excluir, Atualizar, Abandonar}; 
  string MSG = "";
  const string MENU_OPTIONS = "Listas Lineares Não Ordenadas\n\nEscolha sua opção: \n1.Buscar\n2.Inserir\n3.Excluir\n4.Atualizar\n5.Deixar programa\n\nDigite aqui: ";
  cout << MENU_OPTIONS;
  cin >> opCrud;
  switch (opCrud){
    case Buscar:
      cout << headerline << endl << "MENU BUSCAR\nQual o número da chave do registro? " ; 
      cin >> chaveUsuario;
      if (Read(chaveUsuario) != NotFound){
        cout << "ID do Registro: " << chaveUsuario << "\nNome: " << Lista[Read(chaveUsuario)].Nome << endl;
      }
      else ReportError(NotFound);
      break;
    case Inserir:
      cout << headerline << endl << "MENU INSERIR\nCrie uma chave para o novo dado: ";
      cin >> chaveUsuario;
      cout << "Qual o dado a ser inserido nessa chave? ";
      cin >> nomeUsuario;
      Create(chaveUsuario, nomeUsuario);
      break; 
    case Excluir:
      cout << headerline << endl << "MENU EXCLUIR\nQual a chave do dado que deve ser excluído? ";
      cin >> chaveUsuario;
      Delete(chaveUsuario);
      break;
    case Atualizar:
      cout << headerline << endl << "MENU ATUALIZAR\nQual a chave do dado a ser atualizado? ";
      cin >> chaveUsuario;
      cout << "Qual o novo valor a ser inserido? ";
      cin >> nomeUsuario;
      Update(chaveUsuario, nomeUsuario);
      break;
    case Abandonar:
      system("clear");
      cout << "Fim de execução." << endl;
      return true;
    default:
      system("clear");
      cout << "Operação não reconhecida. Tente novamente.\n" << endl;
  }
  sleep(2);
  system("clear");
  return false;
}

int main() {
  bool finishProgram = false;
  cout << "Bem-vindo ao algoritmo de Listas Lineares Sequenciais Não Ordenadas com chave identificadora.\n " << endl;
  do{
    finishProgram = Menu();
  }
  while (!finishProgram);
} 
