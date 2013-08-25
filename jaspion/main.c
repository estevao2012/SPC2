#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream> 
#include <algorithm> 

using namespace std; 

string str_replace(const string& search, const string& replace, const string& subject);

int main(){
    int repeticoes,palavras,linhas_musica,i,j;  
    cin >> repeticoes;
    string *traducao;
    string *japones; 
    string frase;
    string traduzido;
    string nada;

    while(repeticoes > 0){    
        cin >> palavras;
        cin >> linhas_musica;
        
        japones = new string[palavras];
        traducao = new string[palavras]; 

        getline (cin ,nada); //corrige problema de captura da primeira linha

        for(i=0;i<palavras;i++){
           getline (cin ,japones[i]); 
           getline (cin ,traducao[i]); 
        }

        for(i=0;i<linhas_musica;i++){

          getline (cin ,frase);

          traduzido = str_replace(japones[0],traducao[0],frase);

          for(j=1;j<palavras;j++)
            traduzido = str_replace(japones[j],traducao[j],traduzido);
          
          cout << traduzido << endl;
        }
          cout << endl;

        repeticoes--; 
    } 
    
    return 0;    
 
}

std::string str_replace(const std::string& search, const std::string& replace, const std::string& subject)
{
    std::string str = subject;
    size_t pos = 0;
    while((pos = str.find(search, pos)) != std::string::npos)
    {
        str.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return str;
}
