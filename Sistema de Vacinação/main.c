#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>


/* Declara��o da struct que ir� armazenar os dados do paciente */

struct InfoPaciente{
	char nome[50];
	char vacinaNome[50];
	char loteNum[10];
	char data[20];
	int vetCPF;
	int cod;	
	
};

FILE * arq;
/* Declara��o da da fun��o que gera relat�rios*/
void Relatorio(int  qtd, int j, struct InfoPaciente paciente[j]);

/* Declara��o da da fun��o que consulta pelo CPF*/
void CPFConsulta(int qtd, int acharCPF, int j, struct InfoPaciente paciente[j]);

void Dev();
void dev_fun();

	

int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, "Portuguese");
	
	int i,j=0;
	int qtd;
	struct InfoPaciente paciente[j];
	int acharCPF;	
	
	qtd=0;
	Relatorio(qtd,j,paciente);
	system("cls");
	
	/* la�o while que controla o menu */	
	while(i!=4){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Controle de vacina��o\\\\\\\\\\\\\\\\\\\\\\\\\n");
		printf("\nDigite para as seguintes op��es:");
		printf("\n1-cadastrar Vacina\n2-Relat�rio geral\n3-consultar por CPF\n4-sair\n9-Modo de desenvolvimento**\n");
		scanf("%d", &i);
				
		/* Declara��o dos IFs das op��es do menu*/
		if(i==1){
			
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Cadastrando Paciente\\\\\\\\\\\\\\\\\\\\\\\\\n\n");	
					
		/* Abertura de Banco de dados*/
			arq=fopen("DataBase.dat","a+b");
			if(arq==NULL){
				system("cls");
				printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
				printf("\nO arquivo n�o foi aberto!\n***************************ERROR*************");
			}
			
			else{	
			j=0;			
			printf("Quantas Pessoas gostaria de cadastrar?\n");
			scanf("%d", &qtd);
			fflush(stdin);
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Cadastrando Paciente\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			
			/* looping para controlar quantos pacientes s�o cadastrados*/
			for(j=0;j<qtd;j++){		
			printf("\n*Cadastro pessoa n�mero %d\n\n", j+1);			
			printf("\nDigite nome e sobrenome:\n\n");
			gets(paciente[j].nome);
			
			printf("Qual o CPF do paciente?\n");
			scanf("%d", &paciente[j].vetCPF);
			fflush(stdin);
			
			printf("Qual o nome da vacina?\n");
			gets(paciente[j].vacinaNome);
			printf("Qual o n�mero do lote da vacina?\n");
			gets(paciente[j].loteNum);
			
			printf("Data de aplica��o:\n");
			gets(paciente[j].data);
			
			paciente[j].cod=j+1;
			system("cls");
			
		}
		
		/* Grava��o de dados*/
		 fwrite(paciente, sizeof(struct InfoPaciente), qtd, arq);
		 if(arq==NULL){
		 	system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\nO arquivo n�o foi aberto!\n***************************ERROR*************");
		 }
		 else{
		 	system("cls");
		 	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
		 	printf("\n***Dados armazenados***\n");
		 }
			
			system("pause");			
		}
		fclose(arq);	
	}
	
		else if(i==2){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Relat�rio geral\\\\\\\\\\\\\\\\\\\\\\\\\n");
		
		Relatorio(qtd,j,paciente);
		
		system("pause");			
		}
		
		else if(i==3){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Consulta Por CPF\\\\\\\\\\\\\\\\\\\\\\\\\n");
		
		CPFConsulta(qtd, acharCPF, j, paciente);
						
		system("pause");			
		}	
		
		else if(i==4){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ exiting...\\\\\\\\\\\\\\\\\\\\\\\\\n");							
		}	
		
		
		else if(i==9){
		int d;
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Developers' Mode!'\\\\\\\\\\\\\\\\\\\\\\\\\n");
		
		printf("\n***ESSA �REA � RESTRITA A DESENVOLVEDORES***.\nPRESSIONE QUALQUER TECLA PARA CONTINUAR\n\n");
		system("pause");
		Dev(d);
		system("pause");
		}
		
		else{
			system("cls");
			printf("Op��o inv�lida!! Tente novamente\n");
			system("pause");
		}
			
		
	}	
	
	
	system("pause");
	return 0;
}



/* Escopo da fun��o que gera relat�rios */
void Relatorio(int  qtd, int j, struct InfoPaciente paciente[j]){ 	
 	if((arq=fopen("DataBase.dat", "r"))== NULL){
			printf("\nN�o existem pacientes cadastrados\n\n");	
			fclose(arq);		
		}
		
		else{
			system("cls");
			arq=fopen("DataBase.dat","a+b");
			if(arq==NULL){
				system("cls");
				printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
				printf("\nO arquivo n�o foi aberto!\n***************************ERROR*************");
			}
			
			/* Leitura de banco de dados*/
			while(!feof(arq)){																					
					if(fread(paciente, sizeof(struct InfoPaciente), 1, arq)==1);
					printf("\nNome Paciente:\n%s\nNome da Vacina:\n%s\nN�mero de Lote:\n%s", paciente[1].nome, paciente[j].vacinaNome,paciente[j].loteNum);
					printf("\nData da aplica��o:\n%s \nC�digo de antendimento:\n%d \n",paciente[j].data,paciente[j].cod );
		
		}
				
				
				if(arq==qtd){
		 		system("cls");
				printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
				printf("\nO arquivo n�o foi aberto!\n***************************ERROR*************");
		 }
			
			
		fclose(arq);
	}
 
 return;
 }
 
 
 
 /* Escopo da fun��o que consulta pelo CPF */
 void CPFConsulta(int qtd, int acharCPF, int j, struct InfoPaciente paciente[j]){
	int i,cpf =0;
	if(qtd==0){
			printf("\nN�o existem pacientes cadastrados!\n\n");
		}
		else{
		
		printf("\nDigite o n�mero do CPF do paciente:\n");
		scanf("%d", &acharCPF);
		
		
			for(j=0;j<qtd;j++){			
				if(acharCPF == paciente[j].vetCPF){
				printf("\nC�digo: %d\n", paciente[j].cod);
				printf("\nNome: %s\n", paciente[j].nome);
				printf("\nCPF: %d\n", paciente[j].vetCPF);
				printf("\nVacina: %s\n", paciente[j].vacinaNome);
				printf("\nLote: %s\n", paciente[j].loteNum);
				printf("\nData da aplica��o:\n %s\n", paciente[j].data);
				acharCPF=-2;
											
				}
			}
				if(acharCPF!=-2){
					printf("\nPaciente n�o tem registro\n\n");
				}
				if(acharCPF==-1){
					system("cls");
					printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\System Failure\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
					printf("\n\n***Algum erro desconhecido ocorreu***\n\nContate seu T.I\n");
				}
			}
				
			 return;
			}
		
			
		
void Dev(int d){
system("cls");
printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Developers' Mode!*'\\\\\\\\\\\\\\\\\\\\\\\\\n");
printf("\nEssa fun��o cont�m informa��es para desenvolvedores.\n\n");
printf("Escolha as op��es abaixo:\n");
printf("1-Teste de banco\n2-checagem de arquivos\n3-Funcionalidades sendo desenvolvidas\n4-***\n\n");
scanf("%d", &d);
		
	if(d==1){
		arq=fopen("DataBase.dat","a+b");
		if(arq==NULL){
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\**DEV MODE**\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\**BANCO DE DADOS**\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\nO arquivo n�o foi aberto!\n***************************ERROR*************");
		}
		else{
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\**DEV MODE**\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\**BANCO DE DADOS**\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\nBanco de dados sem erros!\n\n");
			}
			fclose(arq);
		}
		
		if(d==2){
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Developers' Mode!*'\\\\\\\\\\\\\\\\\\\\\\\\\n");
			printf("\nFuncionalidade n�o desenvolvida\n");
		}
		if(d==3){
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Developers' Mode!*'\\\\\\\\\\\\\\\\\\\\\\\\\n");
			printf("\nAtualmente o projeto est� desenvolvendo as fun��es de banco\nMais novidades em breve!\n\n");
		}
		
		if(d==4){
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Developers' Mode(TEST BASE)!*'\\\\\\\\\\\\\\\\\\\\\\\\\n");
			printf("\nSendo desenvolvido\n");
			
			dev_fun();
		}
		
		
}

void dev_fun(){	
int i;
	printf("\n\nDEV-FUN\nERROR**ERRO***ERROR**404\N\n\nEm desenvolvimento\n");
	printf("\n\nEnter this testing function at your own risk\n\nPress anything to\n");		
	system("pause");
	
	for(i=0;i<9000;i++){
		
		printf("\n***************This mode will have pre alpha functions***************\n");
		printf("\n***************EXITING INFINITE LOOPING ERROR8734BRF***************\n");
	}
}
	



