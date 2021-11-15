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
    for (; Lista[i].Id < Key; i++){
      continue;
    }
    if (i != n+1 and Lista[i].Id == Key) return 1;
  }
  return 0;
}
