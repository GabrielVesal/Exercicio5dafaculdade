import math  #Gabriel Alves Teixeira
    
transfcalormaxadmissivel = 0
resistenciacalculada = 0
resistenciatermicanecessaria = 0
calor_especifico = 4190

while True:
        print("\n-Calculadora de isolamento térmico-\n")

        if transfcalormaxadmissivel == 0:
            print("[1] Calcular a transferência de calor máxima admissível")
        
        elif  resistenciatermicanecessaria == 0:
            print(f"Transferência de Calor Máxima Admissível: {transfcalormaxadmissivel:.2f} (W/m)")
            print("\n[1] Calcular a transferência de calor máxima admissível")
            print("[2] Calcular a resistência térmica necessária")
        
        elif resistenciacalculada == 0:
            print(f"Transferência de Calor Máxima Admissível: {transfcalormaxadmissivel:.2f} (W/m)")
            print(f"Resistência Térmica Necessária: {resistenciatermicanecessaria:.2f} (K.m/W)")
            print("\n[1] Calcular a transferência de calor máxima admissível")
            print("[2] Calcular a resistência térmica necessária")
            print("[3] Calcular a espessura recomendada para o isolamento")

        else:
            print(f"Transferência de Calor Máxima Admissível: {transfcalormaxadmissivel:.2f} (W/m)")
            print(f"Resistência Térmica Necessária: {resistenciatermicanecessaria:.2f} (K.m/W)")
            print(f"Espessura Recomendada para o Isolamento: {resistenciacalculada:.2f} (m)")
            print("\n[1] Calcular a transferência de calor máxima admissível");
            print("[2] Calcular a resistência térmica necessária");
            print("[3] Calcular a espessura recomendada para o isolamento");
            #👇Redefinir as variáveis para 0, desta forma, cada vez que a opção 1 é selecionada, todos os cálculos são redefinidos e você pode começar a inserir novos dados para cada uma das opções novamente.
            transfcalormaxadmissivel = 0
            resistenciacalculada = 0
            resistenciatermicanecessaria = 0
    
        print("[4] Sair\n")
        op = input("Escolha uma opção: ")
        print("---------------------------\n\n")
        
        match op:
            case '1':
                vazaomassica = float(input("Informe a vazão mássica (kg/s): "))
                comprimentodatubulacao = float(input("Informe o comprimento da tubulação (m): "))
                tempmaximaadmissivel = float(input("Informe a temperatura maxima admissivel (°C): "))
                transfcalormaxadmissivel = vazaomassica * calor_especifico * tempmaximaadmissivel / comprimentodatubulacao
                print(f"\nTransferência de Calor Máxima Admissível: {transfcalormaxadmissivel:.2f} (W/m)")
            case '2':
                if transfcalormaxadmissivel != 0:#👈A condição do if é que verifica se o valor da variável "transfcalormaxadmissivel" é diferente de 0 se for, isso indica que a variável transfcalormaxadmissivel já foi calculada e o código dentro das chaves {} após a instrução if é executado, o mesmo acontece com o outro if e a variavel que esta nele.
                    tempdoarambiente = float(input("Informe a temperatura do ar ambiente (°C): "))
                    temperatfluido = float(input("Informe a temperatura do fluido (°C): "))
                    resistenciatermicanecessaria = (tempdoarambiente - temperatfluido) / transfcalormaxadmissivel
                    print(f"\nResistência Térmica Necessária: {resistenciatermicanecessaria:.2f} (K.m/W)") 
                else:
                    print("Opção inválida!\n")
            case '3':
                if resistenciatermicanecessaria != 0:
                    condtermicaK = float(input("Informe a condutividade térmica do material isolante (W/m.K): "))
                    diametroexterno = float(input("Informe o diâmetro externo da tubulação (m): "))
                    f = 2 * math.pi * condtermicaK * resistenciatermicanecessaria
                    resistenciacalculada = diametroexterno / 2 * (pow(2.7183, f) - 1)
                    print(f"\nEspessura Recomendada para o Isolamento: {resistenciacalculada:.2f} (m)")  
                else:
                    print("Opção inválida!\n")
            case '4':
                exit(0)
            case _:
                print("Opção inválida!\n")
            