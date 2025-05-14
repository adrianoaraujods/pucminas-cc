# Questão 1 - Experiências

Chegou a época do tradicional Festival da Mandioca de Monte Alegre, e os agricultores da região trouxeram N sacas de mandioca, cada uma com uma certa quantidade de quilos. Para organizar a distribuição entre os visitantes, os organizadores do festival seguiram algumas regras bastante curiosas:

1. Cada visitante, ao receber mandioca, escolhe a saca com a maior quantidade de quilos disponíveis.
2. O visitante coleta uma quantidade igual à quantidade de dígitos pares no número de quilos da saca. Por exemplo, se uma saca tem 832 kg, o visitante pegará 2 kg (pelos dígitos 8 e 2, que são pares).
3. Após a coleta, a saca é devolvida com a nova quantidade (original − coletado). Se a saca ficar com 0 kg, ela é descartada.
4. Cada visitante recebe uma única vez e sai da fila.

Você precisa ajudar Tainá, que está na K-ésima posição da fila, a descobrir quantos quilos de mandioca ela receberá no seu turno.

## Entrada

A primeira linha contém dois inteiros:

N (1 ≤ N ≤ 10⁶): número de sacas de mandioca
K (1 ≤ K ≤ 10⁹): posição de Tainá na fila
A segunda linha contém N inteiros Sᵢ (1 ≤ Sᵢ ≤ 10⁶), representando o peso inicial das sacas de mandioca.

## Saída

Imprima um único inteiro: a quantidade de quilos de mandioca que Tainá irá receber.

## Explicação

1ª pessoa: pega da saca 86 → 8 e 6 são pares → coleta 2 kg → sobra 84
2ª pessoa: pega da saca 84 → 8 e 4 são pares → coleta 2 kg → sobra 82
3ª pessoa: pega da saca 82 → 8 e 2 → coleta 2 kg → sobra 80
4ª (Tainá): pega da saca 80 → 8 e 0 → coleta 2 kg → Resposta: 2
