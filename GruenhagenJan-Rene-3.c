/*************************************************
Filename:       GruenhagenJan-Rene-3.c ; GruenhagenJan-Rene-3.pdf
Beschreibung:   Einen Start und einen Zielpunkt auf einem 7x7 Feld setzen und ausgeben.
Autor/in:       Jan-René Grünhagen
Historie:       Datum           Ereignis
                09.05 2016      erzeugt

Zusammengearbeitet mit: Nicoleta Constantin
**************************************************/

#include <stdio.h> //IO include für die Ein und Ausgabe.
#define N 7 //Ersetzen des N durch eine 7

struct punkt{ //Punkt in der Matrix als Struct realisiert.
    int x;
    int y;
}s,z; // Start (s) oder Ziel (z)

char matrix[N][N]; //Zweidimensionales Array mit N Feldern, welche oben durch 7 ersetzt wird für die Dynamik.
void matrixausgabe(void); //Funktionsdeklaration für die Ausgabe der Matrix
void matrixfuellen(void); //Funktionsdeklaration für die Füllung der Matrix
int einlesen(void); //Funktionsdeklaration für das einlesen der Punkte.

//Main Funktion
int main(void)
{
    matrixfuellen();
    do {
        printf("Gib mir s.x ");
        s.x=einlesen(); //einlesen von s.x
        printf("Gib mir s.y ");
        s.y=einlesen(); //einlesen von s.y
        printf("Gib mir z.x ");
        z.x=einlesen(); //einlesen von z.x
        printf("Gib mir z.y ");
        z.y=einlesen(); //einlesen von z.y
    } while ( (s.x == z.x) && (s.y == z.y) ); //s muss ungleich z sein!
    matrix[s.y][s.x]='s'; //Eintragen von s in die Matrix
    matrix[z.y][z.x]='z'; //Eintragen von z in die Matrix
    matrixausgabe(); //Ausgeben der Matrix
    return 0;
}

//Füllt das Array mit 0 erst vertikal, dann horizontal
void matrixfuellen(void)
{
    int i;
    int j;
    for (i=0;i<7;i++){
            for (j=0;j<7;j++){
                matrix[i][j] = '0';
        }
    }
}

//Gibt den Inhalt des Array aus, erst vertikal, dann horizontal.
void matrixausgabe(void)
{
    int i;
    int j;
    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            printf("%c ",matrix[i][j]);
        }
        printf("\n");
    }
}

/*Funktion für das einlesen der Werte,
solange kein valider Wert eingegeben wird,
läuft die Schleife.*/
int einlesen(void)
{
    int i;
    do {
        printf("(Zahl zwischen 0 & 6): ");
        scanf("%d",&i);
    } while (i < 0 || i > 6);
    return(i);
}
