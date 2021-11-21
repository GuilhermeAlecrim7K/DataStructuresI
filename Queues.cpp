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

struct Dados *First = NULL;
struct Dados *Last = NULL;
int QueueLimit = 5;
int QueueCounter = 0;

enum OpConclusions {EmptyQueue, FullQueue, Success};
const string headerline = "=============================";

string ReportConclusion(OpConclusions Conclusion){
  switch (Conclusion){
    case EmptyQueue:
      return "Operação não realizada. Pilha Vazia.";
      break;
    case FullQueue:
      return "Não foi possível incluir um novo item na lista, pois seu limite foi atingido. Remova um item e tente novamente.";
      break;
    case Success:
      return "Operação realizada com sucesso.";
  }
}

OpConclusions Enqueue(int Input){
  struct Dados *AuxPointer = new struct Dados;
  if (QueueCounter == QueueLimit) 
    return FullQueue;
  AuxPointer->Info = Input;
  AuxPointer->Next = NULL;
  if (First != NULL){
    Last->Next = AuxPointer;
    Last = AuxPointer;
  }
  else{
    First = AuxPointer;
    Last = AuxPointer;
  }
  QueueCounter++;
  return Success;
}

OpConclusions Dequeue(){
  struct Dados *AuxPointer;
  if (First != NULL){
    AuxPointer = First;
    First = First->Next;
    delete(AuxPointer);
    QueueCounter--;
    return Success;
  }
  else return EmptyQueue;
}

OpConclusions List(){
  struct Dados *AuxPointer = First;
  int SleepCounter = 0;
  if (First != NULL){
    while(AuxPointer != NULL){
      cout << AuxPointer->Info << endl;
      AuxPointer = AuxPointer->Next;
      SleepCounter++;
    }
    sleep(SleepCounter/2);
    return Success;
  }
  else return EmptyQueue;
}

bool Menu(){
  enum opcoes {Inserir = 1, Excluir, Listar, Abandonar};
  int opCrud;
  int InfoUsuario;
  OpConclusions result; 
  const string MENU_OPTIONS = "Filas\n\nEscolha sua opção:\n1.Inserir\n2.Excluir\n3.Listar Registros\n4.Deixar programa\n\nDigite aqui: ";
  cout << MENU_OPTIONS;
  cin >> opCrud;
  switch (opCrud){
    case Inserir:
      cout << "Qual o dado a ser inserido no início da fila? ";
      cin >> InfoUsuario;
      cout << ReportConclusion(Enqueue(InfoUsuario)) << endl;
      break;
    case Excluir:
      cout << ReportConclusion(Dequeue()) << endl;
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
  cout << "Bem-vindo ao algoritmo de manipulação de Filas.\n " << endl;
  do{
    finishProgram = Menu();
  }
  while (!finishProgram);
} 
