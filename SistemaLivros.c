#include <stdio.h>
#include <string.h>

int main() {
	int codigo[20];
	int ano[20];
	char autor[20][50];
	char titulo[20][50];

	int total = 0;

	int opcao;

	do {
		printf("\n===== SISTEMA DE LIVROS =====\n");
		printf("1 - Cadastrar livro\n");
		printf("2 - Consultar livro\n");
		printf("3 - Listar livros\n");
		printf("4 - Alterar livro\n");
		printf("5 - Excluir livro\n");
		printf("0 - Sair\n");
		printf("==============================\n");

		printf("Escolha uma destas opcoes: ");
		scanf("%d", &opcao);


		switch (opcao) {
		case 1:
			if (total < 20) {
				printf("\n--- CADASTRAR LIVRO ---\n");

				printf("Digite o codigo do livro: ");
				scanf("%d", &codigo[total]);

				printf("Digite o titulo do livro: ");
				scanf(" %49[^\n]", titulo[total]);

				printf("Digite o autor do livro: ");
				scanf(" %49[^\n]", autor[total]);

				printf("Digite o ano de publicacao: ");
				scanf("%d", &ano[total]);

				total++;

				printf("\nLivro cadastrado com sucesso!\n");
			} else {
				printf("\nLimite maximo de livros atingido!\n");
			}
			break;


		case 2: {
			int busca;
			int encontrado = 0;

			printf("\n--- CONSULTAR LIVRO ---\n");
			printf("Digite o codigo do livro: ");
			scanf("%d", &busca);

			for (int i = 0; i < total; i++) {
				if (codigo[i] == busca) {
					printf("\nLivro encontrado!\n");
					printf("Codigo: %d\n", codigo[i]);
					printf("Titulo: %s\n", titulo[i]);
					printf("Autor: %s\n", autor[i]);
					printf("Ano: %d\n", ano[i]);

					encontrado = 1;
					break;
				}
			}

			if (encontrado == 0) {
				printf("\nLivro nao encontrado!\n");
			}
			break;
		}

		case 3:
			printf("\n--- LISTA DE LIVROS ---\n");

			if (total == 0) {
				printf("Nenhum livro cadastrado.\n");
			} else {
				for (int i = 0; i < total; i++) {
					printf("\nLivro %d\n", i + 1);
					printf("Codigo: %d\n", codigo[i]);
					printf("Titulo: %s\n", titulo[i]);
					printf("Autor: %s\n", autor[i]);
					printf("Ano: %d\n", ano[i]);
				}
			}
			break;

		case 4: {
			int busca;
			int encontrado = 0;

			printf("\n--- ALTERAR LIVRO ---\n");
			printf("Digite o codigo do livro que deseja alterar: ");
			scanf("%d", &busca);

			for (int i = 0; i < total; i++) {
				if (codigo[i] == busca) {
					printf("\nLivro encontrado!\n");

					printf("Novo titulo: ");
					scanf(" %49[^\n]", titulo[i]);

					printf("Novo autor: ");
					scanf(" %49[^\n]", autor[i]);

					printf("Novo ano de publicacao: ");
					scanf("%d", &ano[i]);

					encontrado = 1;

					printf("\nLivro alterado com sucesso!\n");
					break;
				}
			}

			if (encontrado == 0) {
				printf("\nLivro nao encontrado!\n");
			}
			break;
		}

		case 5: {
			int busca;
			int encontrado = 0;

			printf("\n--- EXCLUIR LIVRO ---\n");
			printf("Digite o codigo do livro que deseja excluir: ");
			scanf("%d", &busca);

			for (int i = 0; i < total; i++) {
				if (codigo[i] == busca) {

					for (int j = i; j < total - 1; j++) {
						codigo[j] = codigo[j + 1];
						ano[j] = ano[j + 1];

						strcpy(titulo[j], titulo[j + 1]);
						strcpy(autor[j], autor[j + 1]);
					}

					total--;
					encontrado = 1;

					printf("\nLivro excluido com sucesso!\n");
					break;
				}
			}

			if (encontrado == 0) {
				printf("\nLivro nao encontrado!\n");
			}

			break;
		}

		case 0:
			printf("\nEncerrando o sistema...\n");
			break;

		default:
			printf("\nOpcao invalida! Tente novamente.\n");
		}

	} while (opcao != 0);


	return 0;
}