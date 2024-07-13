#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço na memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca de gerenciamento de strings

int registrar()
{
	setlocale (LC_ALL, "Portuguese"); // definição da língua aplicada no programa
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	system("cls");
	printf("\t\t\t\t--- NOVO CADASTRO DE USUÁRIO ---\n\n");
	printf("DIGITE O CPF DO NOVO USUÁRIO: ");
	scanf ("%s",cpf);
	
	strcpy (arquivo, cpf); //função para copiar o nome do cpf para o arquivo
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("DIGITE O NOME DO NOVO USUÁRIO: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("DIGITE O SOBRENOME DO NOVO USUÁRIO: ");
	scanf("%s", sobrenome);
	
	fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("DIGITE O CARGO DO NOVO USUÁRIO: ");
	scanf("%s", cargo);
	
	fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("cls");
	printf("USUÁRIO CADASTRADO COM SUCESSO!\n");
	system ("pause");
	
}
int consultar()
{
	setlocale (LC_ALL, "Portuguese"); // definição da língua aplicada no programa
	char cpf[40];
	char conteudo[200];
	
	printf("DIGITE O CPF A SER CONSULTADO: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\nCPF NÃO LOCALIZADO OU NÃO EXISTENTE!\n");
	}
	
	while (fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nESSAS SÃO AS INFORMAÇÕES DO USUÁRIO SOLICITADAS: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");
}
int deletar()
{
	char cpf[40];
	char escolha;
	
	printf ("\nDIGITE O CPF DO USUÁRIO A SER DELETADO: \n\n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\nCPF NÃO LOCALIZADO OU NÃO EXISTENTE!\n");
		system("pause");
	}
/*	
	else 
	{
		printf("\n VOCÊ TEM CERTEZA QUE QUER DELETAR O CPF: ");
		printf("%s",cpf);
		printf("? \n [s/n]: ");
		scanf("%s", &escolha);
		
		switch (escolha)
	{
		
		
			case 's':
			remove(cpf);
			printf("\nO USUÁRIO FOI REMOVIDO COM SUCESSO!\n\n");
			system("pause");
			break;
		
		    case 'n':
			printf("\nO USUÁRIO NÃO FOI REMOVIDO!\n\n");
			system("pause");
			break;
		
			default:
			printf("\nESCOLHA UMA OPÇÃO VÁLIDA!\n\n");
			system ("pause");
			break;
			
	}
			
			
		} */
		
	}
	
	



int main()
{
	int opcao=0; // variável de escolha do usuário
	int i=1; // iteração para o laço de repetição do menu
	setlocale (LC_ALL, "Portuguese"); // definição da língua aplicada no programa
	
	for (i=1;i=1;)
	{
		system ("cls"); 
	
		printf ("\n\t\t\t\t----- CARTÓRIO EBAC ------ \n\n"); //Menu principal
		printf ("ESCOLHA A OPÇÃO DESEJADA: \n\n");
		printf ("\t1 - REGISTRAR NOMES");
		printf ("\t2 - CONSULTAR NOMES");
		printf ("\t3 - DELETAR NOMES");
		printf ("\t4 - FINALIZAR O PROGRAMA\n\n");
		printf ("\nOPÇÃO: "); //fim do menu principal
	
		scanf ("%d", &opcao); //armazenamento da escolha do usuário
		system ("cls");
	
			switch (opcao) //tratamento da opção escolhida pelo usuário
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
				printf("\nESCOLHA UMA OPÇÃO VÁLIDA\n\n");
				system ("pause");
				break;
	}
	

	

}
}
