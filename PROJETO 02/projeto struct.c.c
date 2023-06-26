#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 1000
#define MAX_LENGTH 100

struct Usuario {
    char nome[MAX_LENGTH];
    char email[MAX_LENGTH];
    char sexo[MAX_LENGTH];
    int vacina;
    char endereco[MAX_LENGTH];
    float altura;
    int id;
};

struct Usuario usuarios[MAX_USERS];
int totalUsuarios = 0;

void incluirUsuario() {
    if (totalUsuarios >= MAX_USERS) {
        printf("Limite de usuarios alcancado.\n");
        return;
    }

    struct Usuario novoUsuario;

    printf("Digite o nome do usuario: ");
    fgets(novoUsuario.nome, MAX_LENGTH, stdin);

    printf("Digite o e-mail do usuario: ");
    fgets(novoUsuario.email, MAX_LENGTH, stdin);
    
    printf("Digite o sexo do usuario: ");
    fgets(novoUsuario.sexo, MAX_LENGTH, stdin);
    
    printf("Digite o endereco do usuario: ");
    fgets(novoUsuario.endereco, MAX_LENGTH, stdin);

    printf("Digite a altura do usuario: ");
    scanf("%f", &novoUsuario.altura);
    
    printf("Digite (1) se tomou a vacina ou (2) se nao tomou : ");
    scanf("%d", &novoUsuario.vacina);

    novoUsuario.id = rand();

    getchar(); // Limpar o buffer de entrada

    usuarios[totalUsuarios++] = novoUsuario;

    printf("Usuario cadastrado com sucesso!\n");
}

void editarUsuario() {
    char emailBusca[MAX_LENGTH];
    printf("Digite o e-mail do usuario que deseja editar: ");
    fgets(emailBusca, MAX_LENGTH, stdin);

    int encontrado = 0;
    int i = 0;

    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].email, emailBusca) == 0) {
            printf("Digite o novo nome do usuario: ");
            fgets(usuarios[i].nome, MAX_LENGTH, stdin);

            printf("Digite o novo e-mail do usuario: ");
            fgets(usuarios[i].email, MAX_LENGTH, stdin);
            
            printf("Digite o novo endereco do usuario: ");
            fgets(usuarios[i].endereco, MAX_LENGTH, stdin);
            
            printf("Digite o novo sexo do usuario: ");
            fgets(usuarios[i].sexo, MAX_LENGTH, stdin);
            
			printf("Digite (1) se tomou a vacina ou (2) se nao tomou : ");
			scanf("%d", &usuarios[i].vacina);
            

            printf("Digite a nova altura do usuario: ");
            scanf("%f", &usuarios[i].altura);

            getchar(); 

            printf("Usuario editado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario nao encontrado.\n");
    }
}

void excluirUsuario() {
    char emailBusca[MAX_LENGTH];
    printf("Digite o e-mail do usuario que deseja excluir: ");
    fgets(emailBusca, MAX_LENGTH, stdin);

    int encontrado = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].email, emailBusca) == 0) {
            for (j = i; j < totalUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }

            totalUsuarios--;
            printf("Usuario excluido com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario nao encontrado.\n");
    }
}

void buscarUsuarioPorEmail() {
    char emailBusca[MAX_LENGTH];
    printf("Digite o e-mail do usuario que deseja buscar: ");
    fgets(emailBusca, MAX_LENGTH, stdin);

    int encontrado = 0;
    int i = 0;

    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].email, emailBusca) == 0) {
            printf("Usuario encontrado:\n");
            printf("Nome: %s", usuarios[i].nome);
            printf("E-mail: %s", usuarios[i].email);
            printf("Endereco: %s", usuarios[i].endereco);
            printf("Sexo: %s", usuarios[i].sexo);
            
            if(usuarios[i].vacina == 1){
				printf("Esse usuario foi vacinado!");
			} else{
				printf("Esse usuario nao foi vacinado!");
			}
			
            printf("Altura: %.2f\n", usuarios[i].altura);
            printf("ID: %d\n", usuarios[i].id);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuario nao encontrado.\n");
    }
}

void imprimirUsuariosCadastrados() {
	int i = 0;
	
    printf("Usuarios cadastrados:\n");

    for (i = 0; i < totalUsuarios; i++) {
        printf("Usuario %d:\n", i + 1);
        printf("Nome: %s", usuarios[i].nome);
        printf("E-mail: %s", usuarios[i].email);
        printf("Endereco: %s", usuarios[i].endereco);
        printf("E-mail: %s", usuarios[i].sexo);
        printf("Altura: %.2f\n", usuarios[i].altura);
        if(usuarios[i].vacina == 1){
				printf("Esse usuario foi vacinado!\n");
			} else{
				printf("Esse usuario nao foi vacinado!\n");
			}
        printf("ID: %d\n\n", usuarios[i].id);
    }
}

int main() {
    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Incluir usuario\n");
        printf("2. Editar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario por e-mail\n");
        printf("5. Imprimir usuarios cadastrados\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                incluirUsuario();
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
                imprimirUsuariosCadastrados();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}
