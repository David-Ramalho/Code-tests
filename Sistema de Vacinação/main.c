#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>


/* This program was made by David T. Ramalho.

Declaração da struct que irá armazenar os dados do paciente*/

 
struct InfoPaciente{
	char nome[50];
	char vacinaNome[50];
	char loteNum[10];
	char data[20];
	long int vetCPF;
	int cod;	
	
};

FILE * arq;
/* Declaração da da função que gera relatórios*/
void Relatorio(int  qtd, int j, struct InfoPaciente paciente[j]);

/* Declaração da da função que consulta pelo CPF*/
void CPFConsulta(int qtd, long int acharCPF, int j, struct InfoPaciente paciente[j]);

/* Declaração funções DEV*/
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
	
	
	/* laço while que controla o menu */	
	while(i!=4){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Controle de vacinação\\\\\\\\\\\\\\\\\\\\\\\\\n");
		printf("\nDigite para as seguintes opções:");
		printf("\n1-cadastrar Vacina\n2-Relatório geral\n3-consultar por CPF\n4-sair\n9-Modo de desenvolvimento**\n");
		scanf("%d", &i);
				
		/* Declaração dos IFs das opções do menu*/
		if(i==1){
			
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Cadastrando Paciente\\\\\\\\\\\\\\\\\\\\\\\\\n\n");	
					
		/* Abertura de Banco de dados*/
			arq=fopen("DataBase.dat","a+b");
			if(arq==NULL){
				system("cls");
				printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
				printf("\nO arquivo não foi aberto!\n***************************ERROR*************");
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
			
			/* looping para controlar quantos pacientes são cadastrados*/
			for(j=0;j<qtd;j++){		
			printf("\n*Cadastro pessoa número %d\n\n", j+1);			
			printf("\nDigite nome e sobrenome:\n\n");
			gets(paciente[j].nome);
			
			printf("Qual o CPF do paciente?\n");
			scanf("%lld", &paciente[j].vetCPF);
			fflush(stdin);
			
			printf("Qual o nome da vacina?\n");
			gets(paciente[j].vacinaNome);
			printf("Qual o número do lote da vacina?\n");
			gets(paciente[j].loteNum);
			
			printf("Data de aplicação:\n");
			gets(paciente[j].data);
			
			paciente[j].cod=j+1;
			system("cls");
			
		}
		
		/* Gravação de dados*/
		 fwrite(paciente, sizeof(struct InfoPaciente), qtd, arq);
		 if(arq==NULL){
		 	system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\nO arquivo não foi aberto!\n***************************ERROR*************");
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
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Relatório geral\\\\\\\\\\\\\\\\\\\\\\\\\n");				
		
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
		
		printf("\n***ESSA ÁREA É RESTRITA A DESENVOLVEDORES***.\nPRESSIONE QUALQUER TECLA PARA CONTINUAR\n\n");
		system("pause");
		Dev(d,qtd,j, paciente);
		system("pause");
		}
		
		else{
			system("cls");
			printf("Opção inválida!! Tente novamente\n");
			system("pause");
		}
			
		
	}	
	
	
	system("pause");
	return 0;
}



/* Escopo da função que gera relatórios */
void Relatorio(int  qtd, int j, struct InfoPaciente paciente[j]){ 	
 	if((arq=fopen("DataBase.dat", "r"))== NULL){
			printf("\nNão existem pacientes cadastrados\n\n");	
			fclose(arq);		
		}
		
		else{
			system("cls");
			arq=fopen("DataBase.dat","a+b");
			if(arq==NULL){
				system("cls");
				printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
				printf("\nO arquivo não foi aberto!\n***************************ERROR*************");
			}
			
			/* Leitura de banco de dados*/			
				int QTD;
				printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS WARNING\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
				printf("\n*************************Na atual versão não recomendamos mais que 5 por vez*************");
				printf("\n\nQuantos registros queres pesquisar?\n");
				scanf("%d",&QTD);
				printf("\n\n***Carregando Arquivos***\n:");
				sleep(3);
				system("cls");
				
				for(j=0;j<QTD;j++){																														
					if(fread(paciente, sizeof(struct InfoPaciente), QTD, arq)==QTD);
					printf("\nNome Paciente:\n%s\nCPF: \n%lld\nNome da Vacina:\n%s\nNúmero de Lote:\n%s", paciente[j].nome, paciente[j].vetCPF,paciente[j].vacinaNome,paciente[j].loteNum);
					printf("\nData da aplicação:\n%s \nCódigo de antendimento:\n%d \n",paciente[j].data,paciente[j].cod );
				}
				exit;				
				
				
				if(arq==NULL){
		 		system("cls");
				printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\BANCO DE DADOS\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
				printf("\nO arquivo não foi aberto!\n***************************ERROR*************");
		 }
			
			
		fclose(arq);
	}
 
 return;
 }
 
 
 
 /* Escopo da função que consulta pelo CPF */
 void CPFConsulta(int qtd, long int acharCPF, int j, struct InfoPaciente paciente[j]){
	long int cpf =0;
	int i;
	if(qtd==0){
			printf("\nNão existem pacientes cadastrados!\n\n");
		}
		else{
		
		printf("\nDigite o número do CPF do paciente:\n");
		scanf("%lld", &acharCPF);
		
		
			for(j=0;j<qtd;j++){			
				if(acharCPF == paciente[j].vetCPF){
				printf("\nCódigo: %d\n", paciente[j].cod);
				printf("\nNome: %s\n", paciente[j].nome);
				printf("\nCPF: %lld\n", paciente[j].vetCPF);
				printf("\nVacina: %s\n", paciente[j].vacinaNome);
				printf("\nLote: %s\n", paciente[j].loteNum);
				printf("\nData da aplicação:\n %s\n", paciente[j].data);
				acharCPF=-2;
											
				}
			}
				if(acharCPF!=-2){
					printf("\nPaciente não tem registro\n\n");
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
printf("\nEssa função contém informações para desenvolvedores.\n\n");
printf("Escolha as opções abaixo:\n");
printf("1-Teste de banco\n2-checagem de arquivos\n3-Funcionalidades sendo desenvolvidas\n4-Troca de Bios\n5-***\n\n");
scanf("%d", &d);
		
	if(d==1){
		arq=fopen("DataBase.dat","a+b");
		if(arq==NULL){
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\**DEV MODE**\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\**BANCO DE DADOS**\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\nO arquivo não foi aberto!\n***************************ERROR*************");
		}
		else{
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\**DEV MODE**\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\**BANCO DE DADOS**\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\nTestando Arquivos Binários do banco...\n\n");
			sleep(5);
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\**BANCO DE DADOS**\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			printf("\nGravando informações...!\n\n");
			sleep(5);
			system("cls");
			printf("\nBanco de dados sem erros!\n\n");
			}
			fclose(arq);
		}
		
		if(d==2){
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Developers' Mode!*'\\\\\\\\\\\\\\\\\\\\\\\\\n");
			printf("\nFuncionalidade não desenvolvida\n");
		}
		if(d==3){
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Developers' Mode!*'\\\\\\\\\\\\\\\\\\\\\\\\\n");
			printf("\nAtualmente o projeto está desenvolvendo as funções de banco\nMais novidades em breve!\n\n");
			printf("\n\nO ideal futuramente é mudar as funções do sistema antigo para .old\n\n");
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
			
			printf("\n\n***Escolha a opção abaixo\n:");
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

/* Declaração da struct que irá armazenar os dados do paciente */

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
	
	/* laço while que controla o menu */	
	while(i!=4){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\old system**careful/Controle de vacinação/old system**careful\\\\\\\\\\\\\\\\\\\\\\\\\n");
		printf("\nDigite para as seguintes opções:");
		printf("\n1-cadastrar Vacina\n2-Relatório geral\n3-consultar por CPF\n4-sair\n");
		scanf("%d", &i);
				
		/* Declaração dos IFs das opções do menu*/
		if(i==1){
			
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\old system**careful\Cadastrando Paciente\old system**careful\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			
			printf("Quantas Pessoas gostaria de cadastrar?\n");
			scanf("%d", &qtd);
			fflush(stdin);
			system("cls");
			printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\old system**careful\Cadastrando Paciente\old system**careful\\\\\\\\\\\\\\\\\\\\\\\\n\n");
			
			/* looping para controlar quantos pacientes são cadastrados*/
			for(j=0;j<qtd;j++){		
			printf("\n*Cadastro pessoa número %d\n\n", j+1);			
			printf("\nDigite nome e sobrenome:\n\n");
			gets(paciente[j].nome);
			
			printf("Qual o CPF do paciente?\n");
			scanf("%lld", &paciente[j].vetCPF);
			fflush(stdin);
			
			printf("Qual o nome da vacina?\n");
			gets(paciente[j].vacinaNome);
			printf("Qual o número do lote da vacina?\n");
			gets(paciente[j].loteNum);
			
			printf("Data de aplicação:\n");
			gets(paciente[j].data);
			
			paciente[j].cod=j+1;
			system("cls");
		}
			
			system("pause");			
		}	
	
		else if(i==2){
		system("cls");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\old system**careful\Relatório geral\old system**careful\\\\\\\\\\\\\\\\\\\\\\\\n");
		
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
			printf("Opção inválida!! Tente novamente\n");
			system("pause");
		}
			
		
	}	
	
	
	system("pause");
	
	return 0;
}


/* O ideal futuramente é mudar as funções do sistema antigo para .old*/
/* Escopo da função que gera relatórios */
void Relatorio_old(int  qtd, int j, struct InfoPaciente paciente[j]){
 	
 	if(qtd==0){
			printf("\nNão existem pacientes cadastrados\n\n");
		}
		
		else{
			system("cls");
			/* Laço for para pecorrer o array com as informações dos pacientes cadastrados*/
			for(j=0;j<qtd;j++){
				
				printf("\n\n     Paciente número %d\n", j+1);
				printf(" ==================================");
			
				printf("\nCódigo: %d\n", paciente[j].cod);
				printf("\nNome: %s\n", paciente[j].nome);
				printf("\nCPF: %lld\n", paciente[j].vetCPF);
				printf("\nVacina: %s\n", paciente[j].vacinaNome);
				printf("\nLote: %s\n", paciente[j].loteNum);
				printf("\nData da aplicação\n: %s\n", paciente[j].data);
			
		
		}
	}
 
 return;
 }
 
 
 
 /* Escopo da função que consulta pelo CPF */
 void CPFConsulta_old(int qtd, long int acharCPF, int j, struct InfoPaciente paciente[j]){
		int i,cpf =0;
	if(qtd==0){
			printf("\nNão existem pacientes cadastrados!\n\n");
		}
		else{
		
		printf("\nDigite o número do CPF do paciente:\n");
		scanf("%lld", &acharCPF);
		
		
			for(j=0;j<qtd;j++){			
				if(acharCPF == paciente[j].vetCPF){
				printf("\nCódigo: %d\n", paciente[j].cod);
				printf("\nNome: %s\n", paciente[j].nome);
				printf("\nCPF: %lld\n", paciente[j].vetCPF);
				printf("\nVacina: %s\n", paciente[j].vacinaNome);
				printf("\nLote: %s\n", paciente[j].loteNum);
				printf("\nData da aplicação:\n %s\n", paciente[j].data);
				acharCPF=-2;
											
				}
			}
				if(acharCPF!=-2){
					printf("\nPaciente não tem registro\n\n");
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
