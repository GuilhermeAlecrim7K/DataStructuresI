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
  struct Dados* Next;
  int Info;
};

struct Dados* HeadPointer, PreviousPointer, ResultPointer;

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

}

OpConclusions Create(int Key, int Input){

}

OpConclusions Update(int Key, int Input){

}

OpConclusions Delete(int Key){

}

OpConclusions Listagem(){

}

bool Menu(){
  enum opcoes {Buscar = 1, Inserir, Excluir, Atualizar, Listar, Abandonar};
  int opCrud;
  int chaveUsuario, InfoUsuario; 
  const string MENU_OPTIONS = "Listas Lineares Não Ordenadas\n\nEscolha sua opção: \n1.Buscar\n2.Inserir\n3.Excluir\n4.Atualizar\n5.Listar Registros\n6.Deixar programa\n\nDigite aqui: ";
  cout << MENU_OPTIONS;
  cin >> opCrud;
  switch (opCrud){
    case Buscar:
      cout << headerline << endl << "MENU BUSCAR\nQual o número da chave do registro? " ; 
      cin >> chaveUsuario;
      if (Read(chaveUsuario) != NotFound){
        cout << "ID do Registro: " << chaveUsuario << "\nInfo: " << ResultPointer.Info << endl;
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
  HeadPointer = new struct Dados;
  HeadPointer->Next = NULL;
  bool finishProgram = false;
  cout << "Bem-vindo ao algoritmo de Listas Lineares Sequenciais Ordenadas com chave identificadora.\n " << endl;
  do{
    finishProgram = Menu();
  }
  while (!finishProgram);
} 
