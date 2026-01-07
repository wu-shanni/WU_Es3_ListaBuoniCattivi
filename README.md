ESERCIZIO 3 - La Lista dei Buoni e dei Cattivi
Babbo Natale ha bisogno di sapere quanti regali e quanto carbone preparare!
Il processo padre (Babbo Natale) legge N (numero di bambini) da tastiera
Crea due processi figli (due elfi aiutanti) usando fork()
Babbo Natale invia N a entrambi gli elfi tramite pipe
Elfo 1 conta i bambini buoni (numeri dispari da 1 a N) e rimanda il conteggio al padre
Elfo 2 conta i bambini cattivi (numeri pari da 1 a N) e rimanda il conteggio al padre
Babbo Natale riceve entrambi i risultati e stampa: "Quest'anno consegnerò X regali e Y pezzi di carbone!"
