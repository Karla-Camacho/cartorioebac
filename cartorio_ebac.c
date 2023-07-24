#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Alocação de espaços na memória
#include <locale.h> //Alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings


int registro ()
{
	
	setlocale (LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf ("Digite o CPF a ser cadatrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salvo a variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta ()
{
	
	setlocale (LC_ALL, "Portuguese");
	
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo. Não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);	
		printf("\n\n");
	}
	
	system("pause");
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado do sistema: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
		if(file == NULL);
	{
		printf("Usuário não encontrado no sistema!\n");
		system("pause");
	}
	
}


int main () 
{
	
	int opcao=0; //Definição de variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");

		setlocale (LC_ALL, "Portuguese");
	
	
		printf("### Cartório da EBAC ### \n\n"); //Início do Menu
		printf("Escolha a opção desejada no menu: \n\n");
		printf("\t 1 - Registrar Nomes\n");
		printf("\t 2 - Consultar Nomes\n");
		printf("\t 3 - Deletar Nomes\n"); //Fim do Menu
		printf("\t 4 - Sair do sistema\n\n");
		printf("Opção: ");
	
	
		scanf ("%d", &opcao); //Armazenamento de escolhas do usuários
	
		system("cls"); //limpar
		
		switch (opcao)
		{
			case 1:
				registro();
				break;
			
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
			
			case 4:
				printf("Obrigado por usar o sistema!\n");
				return 0;
				break;
					
				
				
			default:
				printf("Essa opção não está disponível! Escolha novamente!\n");
				system("pause");
				break;
				
		} //Fim da seleção
	
	}
	
	
}
