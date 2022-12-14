#include <stdio.h>
#include <stdbool.h>

// function prototypes
void printCell(int ar[][4], int n);
int isWin(int ar[][4], int n);
void printWinner1(int ar[][4], int n);
void printWinner2(int ar[][4], int n);

// driver code
int main () {

    int n = 3;
    int ar[4][4];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ar[i][j] = -1;
        }
    }

    int player1 = true;
    int player2 = false;

    while(true) {

        printCell(ar, n);

        int r, c; // we have to take entries by row and column

        // taking entry from player-1 (X)
        if (player1) {
            flag1:
            printf("Player 1 Turn (X), Enter row and column: ");
            scanf("%d %d", &r, &c);

            if (ar[r][c] != -1) {
                printf("Already Entered by Player 2! Please Enter Again.\n");
                goto flag1;
            }

            ar[r][c] = 1;

            player1 = false;
            player2 = true;
        }

        // taking entry from player-2 (O)
        else {
            flag2:
            printf("Player 2 Turn (O), Enter row and column: ");
            scanf("%d %d", &r, &c);

            if (ar[r][c] != -1) {
                printf("Already Entered by Player 1! Please Enter Again.\n");
                goto flag2;
            }

            ar[r][c] = 2;

            player2 = false;
            player1 = true;
        }

        // finding who is the winner
        if (isWin(ar, n) == 1) {
            printWinner1(ar, n);
            printf("Player 1 Won!\n");
            break;
        }
        else if (isWin(ar, n) == 2) {
            printWinner2(ar, n);
            printf("Player 2 Won!\n");
            break;
        }
    }

    return 0;
}

// function to print the cells with available entries
void printCell(int ar[][4], int n) {
        printf("___________________________________");
        for (int i = 1; i <= n; i++) {
        printf("\n\n");
        for (int j = 1; j <= n; j++) {
            if (ar[i][j] == -1) printf(" ");
            if (ar[i][j] == 1) printf("X");
            if (ar[i][j] == 2) printf("O");
            if (j < n) printf("\t|\t");
        }
        printf("\n");
        printf("___________________________________");
    }

    printf("\n\n");
}

// function to determine the winner
int isWin(int ar[][4], int n) {
    for (int i = 1; i <= n; i++) {
        if (ar[i][1] == ar[i][2] && ar[i][1] == ar[i][3] && ar[i][1] != -1) {
            return ar[i][1];
        }
    }

    for (int j = 1; j <= n; j++) {
        if (ar[1][j] == ar[2][j] && ar[1][j] == ar[3][j] && ar[1][j] != -1) {
            return ar[1][j];
        }
    }

    if (ar[1][1] == ar[2][2] && ar[1][1] == ar[3][3] && ar[1][1] != -1) {
        return ar[1][1];
    }

    if (ar[3][1] == ar[2][2] && ar[3][1] == ar[1][3] && ar[3][1] != -1) {
        return ar[3][1];
    }

    return -1;
}

// function to print the entries of winner-1 (X)
void printWinner1(int ar[][4], int n) {
        printf("___________________________________");
        for (int i = 1; i <= n; i++) {
        printf("\n\n");
        for (int j = 1; j <= n; j++) {
            if (ar[i][j] == -1) printf(" ");
            if (ar[i][j] == 1) printf("<X>");
            if (ar[i][j] == 2) printf("O");
            if (j < n) printf("\t|\t");
        }
        printf("\n");
        printf("___________________________________");
    }

    printf("\n\n");
}

// function to print the entries of winner-2 (O)
void printWinner2(int ar[][4], int n) {
        printf("___________________________________");
        for (int i = 1; i <= n; i++) {
        printf("\n\n");
        for (int j = 1; j <= n; j++) {
            if (ar[i][j] == -1) printf(" ");
            if (ar[i][j] == 1) printf("X");
            if (ar[i][j] == 2) printf("<O>");
            if (j < n) printf("\t|\t");
        }
        printf("\n");
        printf("___________________________________");
    }

    printf("\n\n");
}
