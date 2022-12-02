#include <stdio.h>
int iszero(int wiersze, int kolumny, float T[wiersze][kolumny]);
int issymetric(int wiersze, int kolumny, float T[wiersze][kolumny]);
float sre(int wiersze, int kolumny, int kol, float T[wiersze][kolumny]);
void zamiana(int wiersze, int kolumny, float T[wiersze][kolumny]);

int main() {
    int wiersze, kolumny, i, j, kol, bool, bool2, wybor;
    printf("Podaj ile chcesz wierszy: ");
    scanf("%d", &wiersze);
    printf("Podaj ile chcesz kolumn: ");
    scanf("%d", &kolumny);
    float T[wiersze][kolumny], dane,r, sredniak;
    for(i=0;i<wiersze;i++){
        for(j=0;j<kolumny;j++){
            printf("Podaj dane: ");
            scanf("%f", &dane);
            T[i][j]=dane;
        }
    }
    for(i=0;i<wiersze;i++){
        for(j=0;j<kolumny;j++){
            printf("%4.1f \t", T[i][j]);
        }
        printf("\n");
    }
    printf("Podaj co chcesz zrobic: 1- policzyc srednia dla wybranej kolumny, 2- Sprawdzic czy w tablicy jest 0\n3- Sprawdzic czy tablica jest symetryczna, 4 - zamienic miejscami brzeowe kolumny, 0- Wyjsc z aplikacji: ");
    scanf("%d", &wybor);
    while(wybor!=0){
        if(wybor<0 || wybor>4){
            printf("Podales niepoprawna liczbe, podaj jeszcze raz: ");
            scanf("%f", &wybor);
        }
        if(wybor==1){
            printf("Podaj dla ktorej kolumny chcesz policzyc srednia: ");
            scanf("%d", &kol);
            sredniak= sre(wiersze,kolumny,kol-1,T);
            printf("Srednia dla kolumny %d wynosi: %f\n", kol, sredniak);
        }
        if(wybor==2){
            bool=iszero(wiersze,kolumny,T);
            if(bool){
                printf("Jest zero!\n");
            }
            else{
                printf("Nie ma zera\n");
            }
        }
        if(wybor==3){
            bool2= issymetric(wiersze,kolumny,T);
            if(bool2){
                printf("Jest Symetryczna!\n");
            }
            else{
                printf("Nie jest symetryczna\n");
            }
        }
        if(wybor==4){
            zamiana(wiersze,kolumny,T);
            printf("Po zamianie: \n");
            for(i=0;i<wiersze;i++){
                for(j=0;j<kolumny;j++){
                    printf("%4.1f \t", T[i][j]);
                }
                printf("\n");
            }
        }
        printf("Podaj co chcesz zrobic: 1- policzyc srednia dla wybranej kolumny, 2- Sprawdzic czy w tablicy jest 0\n3- Sprawdzic czy tablica jest symetryczna, 4 - zamienic miejscami brzeowe kolumny, 0- Wyjsc z aplikacji: ");
        scanf("%d", &wybor);
    }
    printf("Dziekuje za skorzystanie z aplikacji!");
    return 0;
}

int iszero(int wiersze, int kolumny, float T[wiersze][kolumny]){
    int i,j;
    for(i=0;i<wiersze;i++){
        for(j=0;j<kolumny;j++){
            if(T[i][j]==0){
                return 1;
            }
        }
    }
    return 0;
}
int issymetric(int wiersze, int kolumny, float T[wiersze][kolumny]){
    int i,j;
    for(i=0;i<wiersze;i++){
        for(j=0;j<kolumny/2;j++){
            if(T[i][j]!=T[i][kolumny-j-1]){
                return 0;
            }
        }
    }
    return 1;
}
float sre(int wiersze, int kolumny, int kol, float T[wiersze][kolumny]){
    int i,j;
    float sredniaa=0;
    if(kol>=0 && kol<=kolumny) {
        for (i = 0; i < wiersze; i++) {
            sredniaa += T[i][kol];
        }
        sredniaa=sredniaa/wiersze;
        return sredniaa;
    }
    else{
        return 0;
    }
}
void zamiana(int wiersze, int kolumny, float T[wiersze][kolumny]){
    int i,j;
    float r;
    for(j=0;j<kolumny;j++){
        if(j==0 || j==kolumny-1) {
            r = T[0][j];
            T[0][j] = T[wiersze - 1][j];
            T[wiersze - 1][j] = r;
        }
    }
}