import os
os.system("cls")

# declaração de VARS.
livros=[]
op=1;
j=0

# declaração do DIC com as informações da obra.
ObraInfo={
    'cod':0,
    'nomeAutor': "",
    'obraNome': "",
    'editoraNome': "",
  }

def Cadastro(j,op,livros):
    print("\nQuantos livros queres cadastrar?\n")
    j=int(input())
    os.system("cls")

    if j>4:
        os.system("cls")
        print("\\\\\\\\\\\\\\\\\\\\\\\\LIMITE EXCEDIDO\\\\\\\\\\\\\\\\\\\\\\\\")
        print("\nQuantidade não suportada na atual versão do sistema!\n")
        os.system("pause")
        os.system("cls")
       
    else:

        for i in range(0,j): 

            print("\nCadastrando a obra de número: ",i+1)           
            ObraInfo['cod']= i+1            
            ObraInfo['nomeAutor']= input("\nQual o nome do autor da obra?\n")
            ObraInfo['obraNome']= input("\nQual o nome da Obra?\n")
            ObraInfo['editoraNome']= input("\nQual o nome da Editora?\n")
            livros.append(ObraInfo)
            os.system("cls")
    return(j,op, livros)



print("\\\\\\\\\\\\\\\\\\\\\\\\Menú Principal\\\\\\\\\\\\\\\\\\\\\\\\")
print("\nBem vindos ao sistema de gestão de biblioteca.\n")

#laço While que forma as opções de menú
while op!=0:         
    print("\nDigite a opção de escolha:\n")
    print("1-Inserir um novo cadastro\n")
    print("2-Listar todos os cadastros\n")
    print("0-Sair\n")    
    op=int(input()) 
    os.system("cls")   

#Lógica das opções de menú
    if op==1:
       os.system("cls")        
       print("\\\\\\\\\\\\\\\\\\\\\\\\Cadastrando Obra\\\\\\\\\\\\\\\\\\\\\\\\")
       
       Cadastro(j,op,livros)
       

    elif op==2:
        os.system("cls")                
        print("\\\\\\\\\\\\\\\\\\\\\\\\Listando obras\\\\\\\\\\\\\\\\\\\\\\\\")
        for i in range(0,j):
            print("\n\nInformações da obra de N°", i+1,":\n")            
            print("Nome da Obra:\n", livros[i]['obraNome'])
            print("Nome do Autor:\n", livros[i]['nomeAutor'])
            print("Nome da editora:\n", livros[i]['editoraNome'])
            print("Código:\n", livros[i]['cod'])
            
        os.system("pause")
        os.system("cls")
    elif op==0:
        os.system("cls")       
        print("\\\\\\\\\\\\\\\\\\\\\\\\Exiting\\\\\\\\\\\\\\\\\\\\\\\\")

    else:        
        print("\\\\\\\\\\\\\\\\\\\\\\\\ERROR\\\\\\\\\\\\\\\\\\\\\\\\")
        print("\nOpção inválida! Tente novamente.")
        os.system("pause")
        os.system("cls")

os.system("pause")