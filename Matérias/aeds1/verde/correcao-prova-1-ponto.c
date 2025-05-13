#include <stdio.h>

#define MAX_QUESTIONS 100

void cadastrarRespostas(
  int n_alunos, int n_questoes, char respostas[][MAX_QUESTIONS]
) {
  for (int aluno = 0; aluno < n_alunos; aluno++) {
    for (int resposta = 0; resposta < n_questoes; resposta++) {
      scanf(" %c", &respostas[aluno][resposta]);
    }
  }
}

void cadastrarGabarito(int n_questoes, char gabarito[]) {
  for (int i = 0; i < n_questoes; i++) {
    scanf(" %c", &gabarito[i]);
  }
}

int calcularPontuacao(
  int aluno, int n_questoes, char respostas[][MAX_QUESTIONS], char gabarito[]
) {
  int pontuacao = 0;

  for (int resposta = 0; resposta < n_questoes; resposta++) {
    if (respostas[aluno][resposta] == gabarito[resposta]) {
      pontuacao++;
    }
  }

  return pontuacao;
}

int main() {
  int n_alunos;
  int n_questoes;

  scanf("%d %d", &n_alunos, &n_questoes);

  char respostas[n_alunos][MAX_QUESTIONS];
  char gabarito[n_questoes];

  cadastrarRespostas(n_alunos, n_questoes, respostas);
  cadastrarGabarito(n_questoes, gabarito);

  for (int aluno = 0; aluno < n_alunos; aluno++) {
    printf("%d ", calcularPontuacao(aluno, n_questoes, respostas, gabarito));
  }
}
