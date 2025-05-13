#include <iostream>

using namespace std;

/*
  Nesta  quinta-feira  tivemos  a  oportunidade  de  introduzir  os  conceitos  de  Orientação  por  Objetos  (OO). Esta atividade tem unicamente o objetivo de prover o exercício da abstração (sobre a figura  do quadrado) e o encapsulamento (o objeto deverá manter encapsulado seu atributo).

  Considere o tipo Quadrado descrito pelo seguinte atributo (dado-membro):
  - Lado, um atributo do tipo real

  E as seguintes operações:
  - Atribuir um valor parametrizado ao atributo Lado - rejeitar valor negativo;
  - Recuperar o valor do atributo Lado;
  - Gerar o perímetro do quadrado;
  - Gerar a área do quadrado;
  - Ler um valor do teclado e guardá-lo no atributo Lado;
  - Escreva na tela do monitor de vídeo o valor atribuído ao atributo Lado.

  Na função principal:
  Criar uma coleção de instâncias de quadrado (de tamanho MAX) e:
  - para cada instância, guardar o valor do lado fornecido pelo usuário;
  - para cada instância, escrever na tela:
  - a sequência do quadrado (1, 2, 3 etc.);
  - o valor do lado daquele quadrado;
  - o perímetro daquele quadrado;
  - a área daquele quadrado
*/

class Square {
private:
  float side;

public:
  void setSide(float side) {}
  float getSide() {
    return this->side;
  }

  float area() {
    return this->side * this->side;
  }

  float perimeter() {
    return this->side * 4;
  }

  void readSide() {
    float input;
    bool valid;

    do {
      cout << "Enter the side: " << endl;
      cin >> input;

      valid = input > 0;
    } while (!valid);

    this->setSide(input);
  }

  void printSide() {
    cout << "Square side: " << this->side << endl;
  }
};