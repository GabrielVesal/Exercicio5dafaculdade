# Exercicio de Repetição

O programa solicitado é uma calculadora de isolamento térmico de tubulações. Segue uma análise do que o programa faz:

A calculadora é feita para trabalhar com três parâmetros: transferência de calor máxima admissível, resistência térmica necessária e a espessura recomendada para o isolamento.

Ao iniciar o programa, um menu é apresentado ao usuário. As opções deste menu variam de acordo com os cálculos que foram feitos anteriormente. Por exemplo, a resistência térmica só pode ser calculada se a transferência de calor máxima admissível já tiver sido calculada, e a espessura do isolamento só pode ser calculada se a resistência térmica necessária já tiver sido calculada.

A transferência de calor máxima admissível é calculada com base na vazão mássica, no comprimento da tubulação e no aumento máximo de temperatura permitido.

A resistência térmica necessária é calculada a partir das temperaturas ambiente e do fluido, desde que a transferência de calor máxima admissível já tenha sido calculada.

A espessura recomendada do isolamento é calculada a partir da resistência térmica necessária (que deve ter sido calculada em uma iteração anterior do programa) e a condutividade térmica do material isolante e o diâmetro externo da tubulação.

As variações do menu e os cálculos são realizados através de um loop while que fica em execução até que o usuário decida sair.

Ao final de cada cálculo, os resultados são exibidos e os valores de transferência de calor máxima admissível, resistência térmica e espessura do isolamento são redefinidos para 0. Isso significa que, na próxima vez que o menu for exibido, apenas as opções que podem ser calculadas com base nos cálculos anteriores serão exibidas.

Os programas são escritos em C e Python e, embora a estrutura básica seja a mesma, há algumas diferenças sutis na implementação devido às diferenças nas linguagens.

Por exemplo, o Python usa a declaração match (introduzida no Python 3.10) para lidar com a entrada do usuário, enquanto C usa a declaração switch. Além disso, o C usa getchar() para lidar com a entrada do usuário, enquanto o Python usa input().

Como as equações específicas para calcular a transferência de calor máxima admissível, a resistência térmica necessária e a espessura recomendada para o isolamento não foram fornecidas, as fórmulas exatas usadas nos programas são suposições.

<div>
    <img height='50em' src="https://cdn.worldvectorlogo.com/logos/c-1.svg"svg">
    <img height='50em' src="https://cdn.worldvectorlogo.com/logos/python-5.svg">                                                                                                                                         

   




