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

OpConclusions Create(int Key, int Input){
  int i;
  if (n < m){
    if (Read(Key) == NotFound){
      for (i = n; i>0 and Lista[i].Id>Key; i--){
        Lista[i+1] = Lista[i];  
      }
      Lista[i+1].Id = Key;
      Lista[i+1].Info = Input;
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
      for (int i = Id; i<n ; i++){
        Lista[i] = Lista[i+1];
      }
      n--;
      return Success;
    }
    else return NotFound;
  }
  else return ListaVazia;
}
