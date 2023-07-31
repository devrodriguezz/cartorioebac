#include <stdio.h> // Biblioteca de comunica��o com o usario
#include <stdlib.h> // Biblioteca de Aloca��o de Espa�o em Memoria
#include <locale.h> // Biblioteca de Aloca��o de Texto por regi�o
#include <string.h> //Biblioteca responsavel de cuidar das strings
int registro()
{
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o cpf a ser cadastrado: ");
    scanf("%s" ,cpf);
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //Cria o arquivo
    fprintf(file,cpf); //Salvo o valor da variavel
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s" ,nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
	system("pause");
    
    
    
}

int consulta()
{
    setlocale(LC_ALL, "portuguese");//Definindo a linguagem
	
	char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf);
    
    system("cls");
   
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    printf("N�o foi possivel abrir o arquivo,n�o localizado! \n");
	}
	system("pause");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas s�o as informa�oes do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
		
	system("pause");
	}
}

int deletar()
{
	
	int laco=1;
	char cpf[40];
	
	for(laco=1;laco=1;)
{

    printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s" ,cpf);
		
	remove(cpf);
	system("cls");
	
	FILE*file;
	file = fopen(cpf,"r");
	printf("Usuario j� deletado do banco de dados!\n");
	
	system("pause");
	system("cls");
	
	int opcao=0;
	
	printf("\t 1. Deseja deletar mais nomes?\n");
	printf("\t 2. Deseja voltar ao menu?\n");
	printf("Op��o: ");
	scanf("%d", &opcao);
	system("cls");
	
	switch(opcao)
	{
		
		case 1:
		printf("Voc� escolheu deletar mais nomes!\n");
		system("pause");
		system("cls");
		break;
		
		case 2:
		printf("Voc� escolheu voltar para o menu!\n");
		system("pause");
		system("cls");
		return 0;
		break;
		
		default:
		printf("Est� op��o n�o est� disponivel!\n");
		system("pause");
		system("cls");
		break;
		}	
}
}
int main()
{
	int opcao=0;//Definindo Variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		setlocale(LC_ALL, "portuguese");//Definindo a linguagem
			
	printf("###Banco de dados EBAC###\n\n");//Incio do menu
	printf("Deseja a op��o desejada no menu\n\n"); 
	printf("\t1 - Registrar nomes.\n");
	printf("\t2 - Consultar nomes.\n");
	printf("\t3 - Deletar nomes.\n");
	printf("\t4 - Sair do sistema.\n");
	printf("Op��o: ");//final do menu		
    
	scanf("%d" ,&opcao);//Armazenamento de escolha do usuario
	
	system("cls");
	
	switch(opcao)//inicio da sele��o
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
    printf("Agradecemos por ultilizar nosso sistema!\n");
    system("pause");
    return 0;
    break;
    
    default:
    printf("Esta op��o n�o esta disponivel!\n");
    system("pause");
    break;
	}//fim da sele��o
		
	}
}

