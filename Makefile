all: compila executa

compila:
	gcc -c $(FOLDER)/main.c -Wall
	gcc $(FOLDER)/main.c -o executavel 
 
executa:
	$(FOLDER)/executavel
