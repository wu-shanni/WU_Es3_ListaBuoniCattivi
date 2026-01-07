#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int numero;

    // Lettura del numero di bambini
    printf("Inserisci il numero di bambini: ");
    scanf("%d", &numero);

    // Pipe
    int p1[2]; // babbo natale -> elfo 1
    int p2[2]; // babbo natale -> elfo 2
    int r1[2]; // elfo 1 -> babbo natale
    int r2[2]; // elfo 2 -> babbo natale

    pipe(p1);
    pipe(p2);
    pipe(r1);
    pipe(r2);

    // elfo 1:
    if (fork() == 0) {
        int n, buoni = 0;

        close(p1[1]); // legge solo
        close(r1[0]); // scrive solo

        // riceve N da babbo natale
        read(p1[0], &n, sizeof(int));

        // conta i numeri dispari
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0)
                buoni++;
        }

        // manda il risultato a babbo natale
        write(r1[1], &buoni, sizeof(int));

        exit(0);
    }

    // elfo 2:
    if (fork() == 0) {
        int n, cattivi = 0;

        close(p2[1]); // legge solo
        close(r2[0]); // scrive solo

        read(p2[0], &n, sizeof(int));

        // conta i numeri pari
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0)
                cattivi++;
        }

        // manda il risultato a babbo natale
        write(r2[1], &cattivi, sizeof(int));

        exit(0);
    }


    // babbo natale:

    // invia N ai due elfi
    write(p1[1], &numero, sizeof(int));
    write(p2[1], &numero, sizeof(int));

    int regali, carbone;

    read(r1[0], &regali, sizeof(int));
    read(r2[0], &carbone, sizeof(int));

    wait(NULL);
    wait(NULL);

    // stampa
    printf("Quest'anno consegnerò %d regali e %d pezzi di carbone!\n",
           regali, carbone);

    return 0;
}