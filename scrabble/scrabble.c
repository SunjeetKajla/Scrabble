#include <stdio.h>
#include <string.h>
#include <ctype.h>

void scan(char *x,int size, char *y){
        fgets(x, size, stdin);
        x[strcspn(x, "\n")] = '\0';
        sscanf(x, "%s", y);
}

void strlower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void game(char player[7], int* score){
	int a[26];
    
    a[0] = 1; a[1] = 3; a[2] = 3; a[3] = 2; a[4] = 1;
    a[5] = 4; a[6] = 2; a[7] = 4; a[8] = 1; a[9] = 8;
    a[10] = 5; a[11] = 1; a[12] = 3; a[13] = 1;
    a[14] = 1; a[15] = 3; a[16] = 10; a[17] = 1;
    a[18] = 1; a[19] = 1; a[20] = 1; a[21] = 4;
    a[22] = 4; a[23] = 8; a[24] = 4; a[25] = 10;
    char input[69];
    printf("(Enter Only one word, the word after Space will not be counted)\n %s Word: ",player);
    //scanf("%s",input);
    scan(input, sizeof(input), input);
    strlower(input);

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            *score += a[input[i] - 'a'];
        }
    }

    printf("Score of %s is: %d\n", player, *score);
}

int main() {
    int score1 = 0;
	int score2=0;
    game("Player1",&score1);
    game("Player2",&score2);
    if (score1>score2){
    	printf("Player1 Wins!!");
    }
    else if (score1<score2){
    	printf("Player2 Wins!!");
    }
    else {
    	printf("This is a Tie!!");
    }
    return 0;
}
