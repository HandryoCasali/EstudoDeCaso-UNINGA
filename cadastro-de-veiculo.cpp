#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

main ()
{
	typedef struct
	{
		char placa[10];
		char modelo[30];
		int anoFab;
		char potenciaMotor[5];
	} Veiculo; 
	
	int tamanhoVetor = 1;
	Veiculo veic[tamanhoVetor];
	
	int proximo = 0;
	
	int opcao;
	do
	{
		Sleep(2000);
		printf("Menu de opcoes: \n");
		printf("1 - Incluir novo veiculo.\n");
		printf("2 - Pesquisar veiculo.\n");
		printf("3 - Listar veiculos cadastrados. \n");
		printf("4 - Encerrar programa.\n\n");
		printf("Digite uma opcao: ");
		
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:	
				if(proximo >= tamanhoVetor)
				{
					printf("\nNao eh possivel efetuar mais cadastro\n");
					printf("Limite de cadastro atingido\n");
					break;
				}
				
				char placaDigitada[10];
				char modeloDigitado[30];
				int anoDigitado;
				char potenciaDigitada[5];
				
				int saoiguais;
				
				system("cls");
				
				printf("Para efetuar o CADASTRO\n\n");
				
				printf("Digite o modelo do veiculo: ");
				fflush(stdin);
				gets(modeloDigitado);
				
				printf("Digite a placa do veiculo: ");
				scanf("%s", &placaDigitada);
				strupr(placaDigitada);
				
				for(int i = 0; i < proximo; i++)
				{
					saoiguais = strcmp(veic[i].placa, placaDigitada);
					
					if(saoiguais == 0)
					{
						printf("Placa já existe no cadastro!!!\n");
						printf("Cadastro cancelado!\n\n");
						break;
					}
				}
				
				if(saoiguais == 0) break;
								
				printf("Digite o ano do veiculo: ");
				scanf("%d", &anoDigitado);
		
				printf("Digite a potencia do motor do veiculo: ");
				scanf("%s", &potenciaDigitada );
				
				veic[proximo].anoFab = anoDigitado;
				strcpy(veic[proximo].modelo, modeloDigitado);
				strcpy(veic[proximo].placa, placaDigitada);
				strcpy(veic[proximo].potenciaMotor, potenciaDigitada);
				
				proximo += 1;
				
				printf("Cadastro concluido com sucesso!\n");
				break;
				
			case 2:
				//pesquisar
				printf("Digite a placa do veiculo para pesquisar: ");
				scanf("%s", &placaDigitada);
				strupr(placaDigitada);
				
				for(int i = 0; i < proximo; i++)
				{
					saoiguais = strcmp(veic[i].placa, placaDigitada);
					
					if(saoiguais == 0)
					{
						printf("%Veiculo encontrado.\n");
						printf(" Modelo: %s, ", veic[i].modelo);
						printf(" Placa: %s, ", veic[i].placa);
						printf(" Ano: %d, ", veic[i].anoFab);
						printf(" Potencia: %s\n", veic[i].potenciaMotor);
						
						break;
					}
					else
					{
						printf("Nao foi encontrado nenhum veiculo cadastrado com esta placa.");
						break;
					}
				}
				printf("\n\n");
				break;
			case 3:
				//listar veiculos cadastrados
				if(proximo == 0)
				{
					printf("\nNao ha nenhum veiculo cadastrado.");
				}
				else
				{
					for(int i = 0; i < proximo; i++)
					{
						printf("%d° Veiculo cadastrado.\n", i+1);
						printf(" Modelo: %s, ", veic[i].modelo);
						printf(" Placa: %s, ", veic[i].placa);
						printf(" Ano: %d, ", veic[i].anoFab);
						printf(" Potencia: %s\n", veic[i].potenciaMotor);
					}
				}
				printf("\n\n");
				break;
			case 4:
				//sair
				printf("\nEncerrando o programa!");
				break;
			default:
				//opcao invalida
				system("cls");
				printf("\nOpcao invalida, digite a opcao novamente!\n\n");
				break;
		}
	} while(opcao != 4);
	return 0;
}





