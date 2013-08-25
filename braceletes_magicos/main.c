#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int ForcaBruta(char* T, long n, char* P, long m)
{ long i , j , k;
for ( i = 1; i <= (n - m + 1); i++)
{ k = i ; j = 1;
while (T[k-1] == P[ j -1] && j <= m) { j ++; k++; }
if ( j > m) return 1;
}
return 0;
} 
void reverse(char s[])
{
      int length = strlen(s) ;
      int c, i, j;

      for (i = 0, j = length - 1; i < j; i++, j--)
     {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
      }
}

int main(){
    int repeticoes;
    int tam_seg , tam_brac; 
    scanf("%d",&repeticoes);
 
    char segredo[100], bracelete[10000],*nova ; 
    while(repeticoes > 0){ 
        nova = (char*)malloc(sizeof(char*) * 20000);
        scanf("%s %s",segredo,bracelete);

        tam_seg = strlen(segredo); 
        tam_brac = strlen(bracelete);  

        strcpy(nova,bracelete); 
        strncat(nova,bracelete,tam_brac);

        tam_brac = strlen(nova);   

        if(ForcaBruta(nova,tam_brac,segredo,tam_seg)){
            printf("S\n");
        }else{ 
            reverse(nova);
            if(ForcaBruta(nova,tam_brac,segredo,tam_seg))
                printf("S\n");
            else
                printf("N\n"); 
        }

        repeticoes--;
        free(nova);
    } 
    
    return 0;    
}