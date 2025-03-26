#include <stdio.h>
#include <stdbool.h>

#define EXTRA_POINTS 30

int main() {
    int rounds;

    while (scanf("%d", &rounds) != EOF) {
        int score1 = 0;
        int score2 = 0;
        bool extra = false; 

        int player1[rounds];
        int player2[rounds];

        for(int i = 0; i < rounds; i++) {
          scanf(" %d", &player1[i]);
        }

        for(int i = 0; i < rounds; i++) {
          scanf(" %d", &player2[i]);
        }

        for(int i = 0; i < rounds; i++) {
            score1 += player1[i];
            score2 += player2[i];

            if (!extra && (rounds - i) >= 3) {
                extra = true;

                if (player1[i] == player1[i+1] && player1[i] == player1[i+2]) {
                    score1 += EXTRA_POINTS;
                } else if (player2[i] == player2[i+1] && player2[i] == player2[i+2]) {
                    score2 += EXTRA_POINTS;
                }
            }
        }

        if (rounds > 0) {
            printf("%c\n", 
                score1 == score2 ? 'T' :
                    score1 > score2 ? 'M' : 'L'
            );
        }
    }

    return 0;
}
