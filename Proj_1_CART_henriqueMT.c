#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca de gerenciamento de strings

int registrar()
{
	setlocale (LC_ALL, "Portuguese"); // defini��o da l�ngua aplicada no programa
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	system("cls");
	printf("\t\t\t\t--- NOVO CADASTRO DE USU�RIO ---\n\n");
	printf("DIGITE O CPF DO NOVO USU�RIO: ");
	scanf ("%s",cpf);
	
	strcpy (arquivo, cpf); //fun��o para copiar o nome do cpf para o arquivo
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("DIGITE O NOME DO NOVO USU�RIO: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("DIGITE O SOBRENOME DO NOVO USU�RIO: ");
	scanf("%s", sobrenome);
	
	fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("DIGITE O CARGO DO NOVO USU�RIO: ");
	scanf("%s", cargo);
	
	fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("cls");
	printf("USU�RIO CADASTRADO COM SUCESSO!\n");
	system ("pause");
	
}
int consultar()
{
	setlocale (LC_ALL, "Portuguese"); // defini��o da l�ngua aplicada no programa
	char cpf[40];
	char conteudo[200];
	
	printf("DIGITE O CPF A SER CONSULTADO: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\nCPF N�O LOCALIZADO OU N�O EXISTENTE!\n");
	}
	
	while (fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nESSAS S�O AS INFORMA��ES DO USU�RIO SOLICITADAS: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");
}
int deletar()
{
	char cpf[40];
	char escolha;
	
	printf ("\nDIGITE O CPF DO USU�RIO A SER DELETADO: \n\n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\nCPF N�O LOCALIZADO OU N�O EXISTENTE!\n");
		system("pause");
	}
/*	
	else 
	{
		printf("\n VOC� TEM CERTEZA QUE QUER DELETAR O CPF: ");
		printf("%s",cpf);
		printf("? \n [s/n]: ");
		scanf("%s", &escolha);
		
		switch (escolha)
	{
		
		
			case 's':
			remove(cpf);
			printf("\nO USU�RIO FOI REMOVIDO COM SUCESSO!\n\n");
			system("pause");
			break;
		
		    case 'n':
			printf("\nO USU�RIO N�O FOI REMOVIDO!\n\n");
			system("pause");
			break;
		
			default:
			printf("\nESCOLHA UMA OP��O V�LIDA!\n\n");
			system ("pause");
			break;
			
	}
			
			
		} */
		
	}
	
	



int main()
{
	int opcao=0; // vari�vel de escolha do usu�rio
	int i=1; // itera��o para o la�o de repeti��o do menu
	setlocale (LC_ALL, "Portuguese"); // defini��o da l�ngua aplicada no programa
	
	for (i=1;i=1;)
	{
		system ("cls"); 
	
		printf ("\n\t\t\t\t----- CART�RIO EBAC ------ \n\n"); //Menu principal
		printf ("ESCOLHA A OP��O DESEJADA: \n\n");
		printf ("\t1 - REGISTRAR NOMES");
		printf ("\t2 - CONSULTAR NOMES");
		printf ("\t3 - DELETAR NOMES");
		printf ("\t4 - FINALIZAR O PROGRAMA\n\n");
		printf ("\nOP��O: "); //fim do menu principal
	
		scanf ("%d", &opcao); //armazenamento da escolha do usu�rio
		system ("cls");
	
			switch (opcao) //tratamento da op��o escolhida pelo usu�rio
	{
				case 1:
				registrar();
				break;
			
				case 2:
				consultar();
				break;
		
				case 3:
				deletar();
				break;
				
				case 4:
				printf("MUITO OBRIGADO POR UTILIZAR NOSSO PROGRAMA EM DESENVOLVIMENTO!");
				return(0);
				break;
			
				default:
				printf("\nESCOLHA UMA OP��O V�LIDA\n\n");
				system ("pause");
				break;
	}
	

	

}
}
