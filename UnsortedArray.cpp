#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Dados{
  int Id;
  int Info;
};

struct Dados Lista[7];
int n = 0, m = 5;
enum OpConclusions {NotFound, RegistroJaExiste, ListaCheia, ListaVazia, Success};
const string headerline = "=============================";

string ReportConclusion(OpConclusions Conclusion){
  switch (Conclusion){
    case NotFound:
      return "Chave de registro não encontrada.";
      break;    
    case RegistroJaExiste:
      return "Já existe um registro com essa Id. Tente novamente.";
      break;
    case ListaCheia:
      return "Operação não realizada. Lista cheia.";
      break;
    case ListaVazia:
      return "Operação não realizada. Lista Vazia.";
      break;
    case Success:
      return "Operação realizada com sucesso.";
  }
}

int Read(int Key){
  if (n>0){
    int i = 1;
    Lista[n+1].Id = Key;
    for (; Lista[i].Id != Key; i++){
      continue;
    }
    if (i != n+1) return i;
  }
  return 0;
}

OpConclusions Create(int Key, int Input){
  if (n < m){
    if (Read(Key) == NotFound){
      Lista[n+1].Id = Key;
      Lista[n+1].Info = Input;
      n++;
      return Success;
    }
    else return RegistroJaExiste;
  }
  else return ListaCheia;
}

OpConclusions Update(int Key, int Input){
  int Id = Read(Key);
  if (n>0){
    if (Read(Key) != NotFound){
    Lista[Id].Info = Input;
    return Success;
    }
    else return NotFound;
  }
  else return ListaVazia;
}

OpConclusions Delete(int Key){
  int Id = Read(Key);
  if (n > 0){
    if (Read(Key) != NotFound){
      for (int i = Read(Key); i<n ; i++){
        Lista[i] = Lista[i+1];
      }
      n--;
      return Success;
    }
    else return NotFound;
  }
  else return ListaVazia;
}

OpConclusions Listagem(){
  if (n>0){
    for (int i=1; i<=n; i++){
      cout << "ID do Registro: " << Lista[i].Id << "\nInfo: " << Lista[i].Info << endl;
    }
    return Success;
  }
  else return ListaVazia;
  sleep(n*3); 
}

bool Menu(){
  enum opcoes {Buscar = 1, Inserir, Excluir, Atualizar, Listar, Abandonar};
  int temp;
  int opCrud;
  int chaveUsuario, InfoUsuario; 
  string MSG = "";
  const string MENU_OPTIONS = "Listas Lineares Não Ordenadas\n\nEscolha sua opção: \n1.Buscar\n2.Inserir\n3.Excluir\n4.Atualizar\n5.Listar Registros\n6.Deixar programa\n\nDigite aqui: ";
  cout << MENU_OPTIONS;
  cin >> opCrud;
  switch (opCrud){
    case Buscar:
      cout << headerline << endl << "MENU BUSCAR\nQual o número da chave do registro? " ; 
      cin >> chaveUsuario;
      if (Read(chaveUsuario) != NotFound){
        cout << "ID do Registro: " << chaveUsuario << "\nInfo: " << Lista[Read(chaveUsuario)].Info << endl;
      }
      else cout << ReportConclusion(NotFound) << endl;
      break;
    case Inserir:
      cout << headerline << endl << "MENU INSERIR\nCrie uma chave para o novo dado: ";
      cin >> chaveUsuario;
      cout << "Qual o dado a ser inserido nessa chave? ";
      cin >> InfoUsuario;
      cout << ReportConclusion(Create(chaveUsuario, InfoUsuario)) << endl;
      break;
    case Excluir:
      cout << headerline << endl << "MENU EXCLUIR\nQual a chave do dado que deve ser excluído? ";
      cin >> chaveUsuario;
      cout << ReportConclusion(Delete(chaveUsuario)) << endl;
      break;
    case Atualizar:
      cout << headerline << endl << "MENU ATUALIZAR\nQual a chave do dado a ser atualizado? ";
      cin >> chaveUsuario;
      cout << "Qual o novo valor a ser inserido? ";
      cin >> InfoUsuario;
      cout << ReportConclusion(Update(chaveUsuario, InfoUsuario)) << endl;
      break;
    case Listar:
      cout << headerline << endl << "MENU LISTAR\n" << endl;
      cout << ReportConclusion(Listagem()) << endl;
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
