#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>


/* This program was made by David T. Ramalho.

Declara��o da struct que ir� armazenar os dados do paciente*/

 
struct InfoPaciente{
	char nome[50];
	char vacinaNome[50];
	char loteNum[10];
	char data[20];
	long int vetCPF;
	int cod;	
	
};

FILE * arq;
/* Declara��o da da fun��o que gera relat�rios*/
void Relatorio(int  qtd, int j, struct InfoPaciente paciente[j]);

/* Declara��o da da fun��o que consulta pelo CPF*/
void CPFConsulta(int qtd, long int acharCPF, int j, struct InfoPaciente paciente[j]);

/* Declara��o fun��es DEV*/
void Dev();
void dev_fun();
void old_system();

	

int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, "Portuguese");
	printf("\nCarregando Arquivos do sistema\n:\n");
	sleep(2);
	printf("\nCarregando Arquivos de banco de dados\n:\n");
	sleep(2);
	printf("\nC Verificando criptografia\n:\n");
	sleep(3);
	
	int i,j=0;
	int qtd;
	struct InfoPaciente paciente[10000];
	long int acharCPF;	
	
	qtd=0;	
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
			if(qtd==0){
				qtd= qtd+1;
				printf("\nExiting\n");
			}
			else{
			
			/* looping para controlar quantos pacientes s�o cadastrados*/
			for(j=0;j<qtd;j++){		
			printf("\n*Cadastro pessoa n�mero %d\n\n", j+1);			
			printf("\nDigite nome e sobrenome:\n\n");
			gets(paciente[j].nome);
			
			printf("Qual o CPF do paciente?\n");
			scanf("%lld", &paciente[j].vetCPF);
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
		Dev(d,qtd,j, paciente);
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
				int QTD;
				printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS WARNING\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
				printf("\n*************************Na atual vers�o n�o recomendamos mais que 5 por vez*************");
				printf("\n\nQuantos registros queres pesquisar?\n");
				scanf("%d",&QTD);
				printf("\n\n***Carregando Arquivos***\n:");
				sleep(3);
				system("cls");
				
				for(j=0;j<QTD;j++){																														
					if(fread(paciente, sizeof(struct InfoPaciente), QTD, arq)==QTD);
					printf("\nNome Paciente:\n%s\nCPF: \n%lld\nNome da Vacina:\n%s\nN�mero de Lote:\n%s", paciente[j].nome, paciente[j].vetCPF,paciente[j].vacinaNome,paciente[j].loteNum);
					printf("\nData da aplica��o:\n%s \nC�digo de antendimento:\n%d \n",paciente[j].data,paciente[j].cod );
				}
				exit;				
				
				
				if(arq==NULL){
		 		system("cls");
				printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
				printf("\nO arquivo n�o foi aberto!\n***************************ERROR*************");
		 }
			
			
		fclose(arq);
	}
 
 return;
 }
 
 
 
 /* Escopo da fun��o que consulta pelo CPF */
 void CPFConsulta(int qtd, long int acharCPF, int j, struct InfoPaciente paciente[j]){
	long int cpf =0;
	int i;
	if(qtd==0){
			printf("\nN�o existem pacientes cadastrados!\n\n");
		}
		else{
		
		printf("\nDigite o n�mero do CPF do paciente:\n");
		scanf("%lld", &acharCPF);
		
		
			for(j=0;j<qtd;j++){			
				if(acharCPF == paciente[j].vetCPF){
				printf("\nC�digo: %d\n", paciente[j].cod);
				printf("\nNome: %s\n", paciente[j].nome);
				printf("\nCPF: %lld\n", paciente[j].vetCPF);
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
printf("1-Teste de banco\n2-checagem de arquivos\n3-Funcionalidades sendo desenvolvidas\n4-Troca de Bios\n5-***\n\n");
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
			printf("\nTestando Arquivos Bin�rios do banco...\n\n");
			sleep(5);
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\**BANCO DE DADOS**\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\nGravando informa��es...!\n\n");
			sleep(5);
			system("cls");
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
			printf("\n\nO ideal futuramente � mudar as fun��es do sistema antigo para .old\n\n");
		}			
		
		if(d==5){
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Developers' Mode(TEST BASE)!*'\\\\\\\\\\\\\\\\\\\\\\\\\n");
			printf("\nSendo desenvolvido\n");
			
			dev_fun();
		}
		
		if(d==4){
			int b;
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Developers' Mode(BIOS||BIOS||BIOS)!*'\\\\\\\\\\\\\\\\\\\\\\\\\n");
			
			printf("\n\n***Escolha a op��o abaixo\n:");
			printf("\n1-BaseProdAtual\n2-BaseProdAntiga\n");
			scanf("%d", &b);
			printf("\n\nCarregando Arquiv\n:");
			sleep(5);
			
			if(b==2){
				void old_system();
			}
			 old_system();
		}
		
		
}

void dev_fun(){	
int i;
	printf("\n\nDEV-FUN\nERROR**ERRO***ERROR**404\n\n\nEm desenvolvimento\n");
	printf("\n\nEnter this testing function at your own risk\n\nPress anything to\n");		
	system("pause");
	
	for(i=0;i<9000;i++){
		
		printf("\n***************This mode will have pre alpha functions***************\n");
		printf("\n***************EXITING INFINITE LOOPING ERROR8734BRF***************\n");
		
	}
}
	



//***old system**careful***	*****************************************
void old_system(){

/* Declara��o da struct que ir� armazenar os dados do paciente */

struct InfoPaciente1{
	char nome[50];
	char vacinaNome[50];
	char loteNum[10];
	char data[20];
	int long vetCPF;
	int cod;	
	
};
	
	int i,j;
	int qtd;
	struct InfoPaciente1 paciente[j];
	long int acharCPF;	
	
	qtd=0;
	
	/* la�o while que controla o menu */	
	while(i!=4){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\old system**careful/Controle de vacina��o/old system**careful\\\\\\\\\\\\\\\\\\\\\\\\\n");
		printf("\nDigite para as seguintes op��es:");
		printf("\n1-cadastrar Vacina\n2-Relat�rio geral\n3-consultar por CPF\n4-sair\n");
		scanf("%d", &i);
				
		/* Declara��o dos IFs das op��es do menu*/
		if(i==1){
			
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\old system**careful\Cadastrando Paciente\old system**careful\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			
			printf("Quantas Pessoas gostaria de cadastrar?\n");
			scanf("%d", &qtd);
			fflush(stdin);
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\old system**careful\Cadastrando Paciente\old system**careful\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			
			/* looping para controlar quantos pacientes s�o cadastrados*/
			for(j=0;j<qtd;j++){		
			printf("\n*Cadastro pessoa n�mero %d\n\n", j+1);			
			printf("\nDigite nome e sobrenome:\n\n");
			gets(paciente[j].nome);
			
			printf("Qual o CPF do paciente?\n");
			scanf("%lld", &paciente[j].vetCPF);
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
			
			system("pause");			
		}	
	
		else if(i==2){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\old system**careful\Relat�rio geral\old system**careful\\\\\\\\\\\\\\\\\\\\\\\\n");
		
		Relatorio_old(qtd,j,paciente);
		
		system("pause");			
		}
		
		else if(i==3){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\old system**careful\Consulta Por CPF\old system**careful\\\\\\\\\\\\\\\\\\\\\\\\n");
		
		CPFConsulta_old(qtd, acharCPF, j, paciente);
						
		system("pause");			
		}	
		
		else if(i==4){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\old system**careful\ exiting...\old system**careful\\\\\\\\\\\\\\\\\\\\\\\\n");
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


/* O ideal futuramente � mudar as fun��es do sistema antigo para .old*/
/* Escopo da fun��o que gera relat�rios */
void Relatorio_old(int  qtd, int j, struct InfoPaciente paciente[j]){
 	
 	if(qtd==0){
			printf("\nN�o existem pacientes cadastrados\n\n");
		}
		
		else{
			system("cls");
			/* La�o for para pecorrer o array com as informa��es dos pacientes cadastrados*/
			for(j=0;j<qtd;j++){
				
				printf("\n\n     Paciente n�mero %d\n", j+1);
				printf(" ==================================");
			
				printf("\nC�digo: %d\n", paciente[j].cod);
				printf("\nNome: %s\n", paciente[j].nome);
				printf("\nCPF: %lld\n", paciente[j].vetCPF);
				printf("\nVacina: %s\n", paciente[j].vacinaNome);
				printf("\nLote: %s\n", paciente[j].loteNum);
				printf("\nData da aplica��o\n: %s\n", paciente[j].data);
			
		
		}
	}
 
 return;
 }
 
 
 
 /* Escopo da fun��o que consulta pelo CPF */
 void CPFConsulta_old(int qtd, long int acharCPF, int j, struct InfoPaciente paciente[j]){
		int i,cpf =0;
	if(qtd==0){
			printf("\nN�o existem pacientes cadastrados!\n\n");
		}
		else{
		
		printf("\nDigite o n�mero do CPF do paciente:\n");
		scanf("%lld", &acharCPF);
		
		
			for(j=0;j<qtd;j++){			
				if(acharCPF == paciente[j].vetCPF){
				printf("\nC�digo: %d\n", paciente[j].cod);
				printf("\nNome: %s\n", paciente[j].nome);
				printf("\nCPF: %lld\n", paciente[j].vetCPF);
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
		
	


	


/*This program was made by David T. Ramalho.*/
