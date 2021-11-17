#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Dados{
  struct Dados *Next;
  int Info;
};

struct Dados *Top = NULL;
int StackLimit = 10;
int StackCounter = 0;

enum OpConclusions {PilhaVazia, Success};
const string headerline = "=============================";

string ReportConclusion(OpConclusions Conclusion){
  switch (Conclusion){
    case PilhaVazia:
      return "Operação não realizada. Pilha Vazia.";
      break;
    case Success:
      return "Operação realizada com sucesso.";
  }
}

void PopLast(){
  struct Dados *pt = Top;
  while((pt->Next)->Next != NULL){
    pt = pt->Next;
  }
  delete(pt->Next);
  pt->Next = NULL;
}

OpConclusions Push(int Input){
  struct Dados *AuxPointer = new struct Dados;
  if (StackCounter == StackLimit){
    PopLast();
    StackCounter--;
  }
  AuxPointer->Info = Input;
  AuxPointer->Next = Top;
  Top = AuxPointer;
  StackCounter++;
  return Success;
}

OpConclusions Pop(){
  struct Dados *AuxPointer;
  if (Top != NULL){
    AuxPointer = Top;
    Top = Top->Next;
    delete(AuxPointer);
    StackCounter--;
    return Success;
  }
  else return PilhaVazia;
}

OpConclusions List(){
  struct Dados *AuxPointer = Top;
  int SleepCounter = 0;
  if (Top != NULL){
    while(AuxPointer != NULL){
      cout << AuxPointer->Info << endl;
      AuxPointer = AuxPointer->Next;
      SleepCounter++;
    }
    sleep(SleepCounter/2);
    return Success;
  }
  else return PilhaVazia;
}

bool Menu(){
  enum opcoes {Inserir = 1, Excluir, Listar, Abandonar};
  int opCrud;
  int InfoUsuario;
  OpConclusions result; 
  const string MENU_OPTIONS = "Pilhas\n\nEscolha sua opção:\n1.Inserir\n2.Excluir\n3.Listar Registros\n4.Deixar programa\n\nDigite aqui: ";
  cout << MENU_OPTIONS;
  cin >> opCrud;
  switch (opCrud){
    case Inserir:
      cout << "Qual o dado a ser inserido no topo da pilha? ";
      cin >> InfoUsuario;
      cout << ReportConclusion(Push(InfoUsuario)) << endl;
      break;
    case Excluir:
      cout << ReportConclusion(Pop()) << endl;
      break;
    case Listar:
      cout << headerline << endl << "MENU LISTAR\n" << endl;
      result = List();
      if (result != Success){
        cout << ReportConclusion(result) << endl;
      }
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
  cout << "Bem-vindo ao algoritmo de manipulação de Pilhas.\n " << endl;
  do{
    finishProgram = Menu();
  }
  while (!finishProgram);
} 
