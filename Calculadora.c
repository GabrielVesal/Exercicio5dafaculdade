#include <stdio.h> /*Gabriel Alves Teixeira*/
#include <math.h>
#include <stdbool.h>

int main()
{
    char op;
    float transfcalormaxadmissivel = 0, resistenciacalculada = 0, resistenciatermicanecessaria = 0, tempdoarambiente;
    float vazaomassica, comprimentodatubulacao, condtermicaK, diametroexterno, tempmaximaadmissivel, f, temperatfluido;
    const float calor_especifico = 4190;

    while (true)
    {
        printf("\n-Calculadora de isolamento térmico-\n");
        if (transfcalormaxadmissivel == 0)
        {
            printf("\n[1] Calcular a transferência de calor máxima admissível\n");
        }
        else if (resistenciatermicanecessaria == 0)
        {
            printf("\nTransferência de Calor Máxima Admissível: %.2f (W/m)\n", transfcalormaxadmissivel);
            printf("\n[1] Calcular a transferência de calor máxima admissível\n");
            printf("[2] Calcular a resistência térmica necessária\n");
        }
        else if (resistenciacalculada == 0)
        {
            printf("\nTransferência de Calor Máxima Admissível: %.2f (W/m)\n", transfcalormaxadmissivel);
            printf("Resistência Térmica Necessária: %.2f (K.m/W)\n", resistenciatermicanecessaria);
            printf("\n[1] Calcular a transferência de calor máxima admissível\n");
            printf("[2] Calcular a resistência térmica necessária\n");
            printf("[3] Calcular a espessura recomendada para o isolamento\n");
        }
        else
        {
            printf("\nTransferência de Calor Máxima Admissível: %.2f (W/m)\n", transfcalormaxadmissivel);
            printf("Resistência Térmica Necessária: %.2f (K.m/W)\n", resistenciatermicanecessaria);
            printf("Espessura Recomendada para o Isolamento: %.2f (m)\n", resistenciacalculada);
            printf("\n[1] Calcular a transferência de calor máxima admissível\n");
            printf("[2] Calcular a resistência térmica necessária\n");
            printf("[3] Calcular a espessura recomendada para o isolamento\n");
            // 👇Redefini as variáveis para 0, desta forma, cada vez que a opção 1 é selecionada, todos os cálculos são redefinidos e você pode começar a inserir novos dados para cada uma das opções novamente.
            transfcalormaxadmissivel = 0;
            resistenciatermicanecessaria = 0;
            resistenciacalculada = 0;
        }
        printf("[4] Sair\n");
        printf("\nEscolha uma opção: ");
        op = getchar();
        getchar();
        printf("---------------------------\n\n");
        switch (op)
        {
        case '1':
            printf("Informe a vazão mássica (kg/s): ");
            scanf("%f", &vazaomassica);
            printf("Informe o comprimento da tubulação (m): ");
            scanf("%f", &comprimentodatubulacao);
            printf("Informe a temperatura maxima admissivel (°C): ");
            scanf("%f", &tempmaximaadmissivel);
            transfcalormaxadmissivel = vazaomassica * calor_especifico * tempmaximaadmissivel / comprimentodatubulacao;
            printf("\nTransferência de Calor Máxima Admissível: %.2f (W/m)\n", transfcalormaxadmissivel);
            break;
        case '2':
            if (transfcalormaxadmissivel != 0) // 👈A condição do if é que verifica se o valor da variável "transfcalormaxadmissivel" é diferente de 0 se for, isso indica que a variável transfcalormaxadmissivel já foi calculada e o código dentro das chaves {} após a instrução if é executado, o mesmo acontece com o outro if e a variavel que esta nele.
            {
                printf("Informe a temperatura do ar ambiente (°C): ");
                scanf("%f", &tempdoarambiente);
                printf("Informe a temperatura do fluido (°C): ");
                scanf("%f", &temperatfluido);
                resistenciatermicanecessaria = (tempdoarambiente - temperatfluido) / transfcalormaxadmissivel;
                printf("\nResistência Térmica Necessária: %.2f (K.m/W)\n", resistenciatermicanecessaria);
            }
            else
            {
                printf("Opção inválida!\n");
            }
            break;
        case '3':
            if (resistenciatermicanecessaria != 0)
            {
                printf("Informe a condutividade térmica do material isolante (W/m.K): ");
                scanf("%f", &condtermicaK);
                printf("Informe o diâmetro externo da tubulação (m): ");
                scanf("%f", &diametroexterno);
                f = 2 * M_PI * condtermicaK * resistenciatermicanecessaria;
                resistenciacalculada = diametroexterno / 2 * (pow(2.7183, f) - 1);
                printf("\nEspessura Recomendada para o Isolamento: %.2f (m)\n", resistenciacalculada);
            }
            else
            {
                printf("Opção inválida!\n");
            }
            break;
        case '4':
            return 0;
        default:
            printf("Opção inválida!\n");
        }
        if (op != '\n')
            getchar();
    }
}
