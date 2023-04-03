#include <string.h>
#include <stdio.h>
/*RUI YU LEI WU, CÓDIGO:8978227*/
/*La complejidad en la solucion(funcion traduccion) es constante O(1), 
en el peor casos el while itera un total de 54 veces. */
char simbolos[53]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                   'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                   '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', '?', '\'',
                   '!', '/', '(', ')', '&', ':', ';', '=', '+', '-', '_', '\"','@'};
char enMorse[53][10]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--","-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-",".-..-.",".--.-."};
int traduccion(char morse){
    int i=0;
    int bandera=0;
    while(i<53 && bandera==0){
        if (!(strcmp(&enMorse[i][0],morse))){
            bandera=1;
        }
        i++;
    }
    return (i-1);
}

int main() {
    char oracion[8];
    int casos;
    char nada[10];
    int i;
    char letra1[2000];
    scanf("%d",&casos);
    scanf("%c",&nada);
    for(i=1;i<=casos;i++){
        char n='n';
        printf("Message #%d\n",i);
        while(n!='\n') {
            scanf("%c",oracion);
            int j=0;
            int num;
            while(oracion[j]!='\n' && oracion[j]!=' ') {
                j++;
                scanf("%c",&oracion[j]);
            }
            if(j==0 && oracion[j]==' '){
                printf("%c",' ');
            }
            else{
                n=oracion[j];
                oracion[j]='\0';
                num=traduccion(oracion);
                printf("%c", simbolos[num]);
            }
        }
        if(i<casos){
            printf("\n\n");
        }
    }


    return 0;
}