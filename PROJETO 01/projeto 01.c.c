#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_SEXO_LENGTH 20
#define MAX_ENDERECO_LENGTH 50

char names[MAX_USERS][MAX_NAME_LENGTH];
char emails[MAX_USERS][MAX_EMAIL_LENGTH];
char endereco[MAX_USERS][MAX_ENDERECO_LENGTH];
char sexo[MAX_USERS][MAX_SEXO_LENGTH];
float altura[MAX_USERS];
int id[MAX_USERS];
int vacina[MAX_USERS];
int count = 0;

void cadastrarUsuario() {
    if (count < MAX_USERS) {
        printf("===== CADASTRO DE USUARIO =====\n");
        
        while (getchar() != '\n') {
        	continue;
    	}
        
        printf("Digite o nome do usuario: ");
		scanf("%[^\n]",&names[count]);
		
		while (getchar() != '\n') {
        	continue;
    	}
		
        printf("Digite o e-mail do usuario: ");
        scanf("%s", &emails[count]);
        
        while (getchar() != '\n') {
        	continue;
    	}
    	
    	printf("Digite o Sexo do usuario: ");
        scanf("%s", &sexo[count]);
        
        while (getchar() != '\n') {
        	continue;
    	}
    	
    	printf("Digite o Endereco do usuario: ");
        scanf("%[^\n]",&endereco[count]);
        
        while (getchar() != '\n') {
        	continue;
    	}
        
        printf("Digite (1) se tomou vacina e (2) se nao tomou: ");
        scanf("%d", &vacina[count]);
    	
    	printf("Digite a Altura do usuario: ");
        scanf("%f", &altura[count]);
        
        id[count] = rand();
        
        count++;
        printf("Usuario cadastrado com sucesso.\n");
    } else {
        printf("Numero maximo de usuarios cadastrados atingido.\n");
    }
}

void editarUsuario() {
    char email[MAX_EMAIL_LENGTH];
    int encontrado = 0;
    int i;

    printf("===== EDIÇAO DE USUARIO =====\n");
    printf("Digite o e-mail do usuario que deseja editar: ");
    scanf("%s", email);

    for (i = 0; i < count; i++) {
        if (strcmp(emails[i], email) == 0) {
        	
        	while (getchar() != '\n') {
        		continue;
    		}
            printf("Digite o novo nome do usuario: ");
            scanf("%[^\n]",&names[count]);
            
            while (getchar() != '\n') {
        		continue;
    		}
    		
    		printf("Digite o novo Sexo do usuario: ");
        	scanf("%s", &sexo[count]);
        
        	while (getchar() != '\n') {
        		continue;
 			}
    	
    		printf("Digite o novo Endereco do usuario: ");
  			scanf("%[^\n]",&endereco[count]);
        
   			while (getchar() != '\n') {
        		continue;
    		}
    	
    		printf("Digite a nova Altura do usuario: ");
        	scanf("%f", &altura[count]);
        
        	printf("Digite (1)se tomou vacina e (2) se nao tomou: ");
        	scanf("%d", &vacina[count]);
            
            
            
            printf("Usuário editado com sucesso.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado.\n");
    }
}

void excluirUsuario() {
    char email[MAX_EMAIL_LENGTH];
    int encontrado = 0;
    int i;
    int j;

    printf("===== EXCLUSAO DE USUARIO =====\n");
    printf("Digite o e-mail do usuario que deseja excluir: ");
    scanf("%s", email);

    for (i = 0; i < count; i++) {
        if (strcmp(emails[i], email) == 0) {
            for (j = i; j < count - 1; j++) {
                strcpy(names[j], names[j + 1]);
                strcpy(emails[j], emails[j + 1]);
                strcpy(sexo[j], sexo[j + 1]);
                strcpy(endereco[j], endereco[j + 1]);
                altura[j] = altura[j + 1];
                vacina[j] = vacina[j + 1];
                id[j] = id[j + 1];
            }
            count--;
            printf("Usuario excluido com sucesso.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario nao encontrado.\n");
    }
}

void buscarUsuarioPorEmail() {
    char email[MAX_EMAIL_LENGTH];
    int encontrado = 0;
    int i;

    printf("===== BUSCA DE USUARIO POR E-MAIL =====\n");
    printf("Digite o e-mail do usuario que deseja buscar: ");
    scanf("%s", email);

    for (i = 0; i < count; i++) {
        if (strcmp(emails[i], email) == 0) {
            printf("Usuario encontrado:\n");
            printf("Nome: %s\n", names[i]);
            printf("E-mail: %s\n", emails[i]);
            printf("Sexo: %s\n", sexo[i]);
            printf("Endereco: %s\n", endereco[i]);
            printf("Altura: %.2f\n", altura[i]);
            printf("ID: %d\n", id[i]);
            
            if(vacina[i] == 1){
				printf("Esse usuario tomou a vacina!");
			} else{
				printf("Esse usuario nao tomou a vacina!");
			}
            
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario nao encontrado.\n");
    }
}

void imprimirUsuarios() {
	int i;
	
    if (count > 0) {
        printf("===== USUARIOS CADASTRADOS =====\n");
        for (i = 0; i < count; i++) {
            printf("Usuario %d:\n", i + 1);
            printf("Nome: %s\n", names[i]);
            printf("E-mail: %s\n", emails[i]);
            printf("Sexo: %s\n", sexo[i]);
            printf("Endereco: %s\n", endereco[i]);
            printf("Altura: %.2f\n", altura[i]);
            printf("ID: %d\n", id[i]);
            
            printf("\n");
        }
    } else {
        printf("Nenhum usuario cadastrado.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("===== MENU =====\n");
        printf("1. Cadastrar usuario\n");
        printf("2. Editar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario por e-mail\n");
        printf("5. Imprimir todos os usuarios cadastrados\n");
        printf("6. Sair\n");
        printf("Digite a opçao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                editarUsuario();
                break;
            case 3:
                excluirUsuario();
                break;
            case 4:
                buscarUsuarioPorEmail();
                break;
            case 5:
                imprimirUsuarios();
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opçao invalida. Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 6);

    return 0;
}
