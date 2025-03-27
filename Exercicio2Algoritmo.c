/*Isabella de Góes Santos; Kauã Azevedo Garcia*/

#define ex3
#include "stdio.h"

/*1. Escreva um programa que pergunte a velocidade de um
carro. Caso ultrapasse 80Km/h, exiba uma mensagem dizendo que o
usuário foi multado. O valor da multa é R$567 reais mais R$25,00 por
cada Km acima da velocidade permitida e exiba o valor da multa. Caso
contrário escreva uma mensagem informando que ele não cometeu
nenhuma infração.*/

/*
#include <stdio.h>

int main() {
    float velocidade, multa;

    do {
        printf("Digite a velocidade do seu veiculo: "); //Recebe a velocidade total percorrida
        scanf("%f", &velocidade);

        if (velocidade <= 0) {//Verifica a validade da velcoidade percorrida a partir do princípio de que o veículo só anda a partir de 0Km e mantem o usuário nessa verificação até o mesmo entrar com um valor > 0
            printf("Por favor, insira uma velocidade válida.\n");
        }
        else if (velocidade > 80) {
            multa = 567 + (velocidade - 80) * 25; //calcula a diferença da kilometragem máxima livre de multa e adiciona uma taxa de R$25 por Km excedido + a multa base
            printf("Voce foi multado!\n");
            printf("Sua multa: R$ %.2f\n", multa);
        }
        else {
            printf("Voce nao foi multado.\n");
        }
    } while (velocidade <= 0);

    return 0;
}

*/
#ifdef ex1
main()
{
    float velocidade, multa;

    do {
        printf("Digite a velocidade do seu veiculo: ");
        scanf("%f", &velocidade);

        if (velocidade <= 0)
        {
            printf("Por favor, insira uma velocidade valida.\n");
        }

        if (velocidade > 80)
        {
            multa = 567 + (velocidade - 80) * 25;
            printf("Voce foi multado!\n");
            printf("Sua multa: R$ %.2f\n", multa);
        }

        if (velocidade > 0 && velocidade <= 80)
        {
            printf("Voce nao foi multado.\n");
        }

    }
    while (velocidade <= 0);
}
#endif

/*2. Uma empresa de aluguel de carros precisa cobrar pelos
seus serviços. O aluguel de um carro custa R$90 por dia para carro
popular e R$150 por dia para carro de luxo. Além disso, o cliente paga por
Km percorrido. Receba via teclado o tipo de carro alugado (1=popular ou
2=luxo), quantos dias de aluguel e quantos Km foram percorridos. No final
mostre o preço a ser pago de acordo com a tabela a seguir:

a) Carros populares (aluguel de R$90 por dia)
Até 100Km percorridos: R$3,20 por Km
 Acima de 100Km percorridos: R$4,16 por Km

b) Carros de luxo (aluguel de R$150 por dia)
 Até 200Km percorridos: R$5,40 por Km
 Acima de 200Km percorridos: R$7,56 por KM.*/

#ifdef ex2
main()
{
    int carroAlugado, dia;
    float km, preco;

    do
    {
        printf("Digite o numero de dias de aluguel: ");
        scanf("%d", & dia);

        if (dia <= 0)
        {
            printf("Numero de dias invalido. Digite novamente.\n");
        }
    }
    while (dia <= 0);

    do
    {
        printf("Digite o numero de Km percorridos: ");
        scanf("%f", & km);

        if (km <= 0)
        {
            printf("Numero de Km invalido. Digite novamente.\n");
        }
    }
    while (km <= 0);

    do
    {
        printf("Digite o tipo de carro alugado (1 = Popular, 2 = Luxo): ");
        scanf("%d", & carroAlugado);

        if (carroAlugado != 1 && carroAlugado != 2)
        {
            printf("Tipo de carro invalido. Digite novamente.\n");
        }
    }
    while (carroAlugado != 1 && carroAlugado != 2);

    if (carroAlugado == 1)
    {

        preco = dia * 90;

        if (km <= 100)
        {
            preco = preco + km * 3.20;
        }
        else
        {
            preco = preco + (100 * 3.20) + ((km - 100) * 4.16);
        }
    }
    else
    {

        preco = dia * 150;

        if (km <= 200)
        {
            preco = preco + km * 5.40;
        }
        else
        {
            preco = preco + (200 * 5.40) + ((km - 200) * 7.56);
        }
    }

    printf("O valor total a ser pago: R$ %.2f\n", preco);

}
#endif



/* 3. Uma empresa precisa reajustar o salário dos seus funcionários,
dando um aumento de acordo com alguns fatores. Faça um programa que
leia o salário atual, o gênero do funcionário e há quantos anos esse
funcionário trabalha na empresa.
Observação: Para as mulheres você poderá atribuir m e M (tipo char) ou 1 e
para os homens você poderá atribuir h e H(tipo char) ou 2.
No final, mostre o seu novo salário, baseado na tabela a seguir:

a) Mulheres
menos de 15 anos de empresa: +5%
de 15 até 20 anos de empresa: +12%
mais de 20 anos de empresa: +23%

b) Homens
menos de 20 anos de empresa: +3%
de 20 até 30 anos de empresa: +13%
mais de 30 anos de empresa: +25%

VERSÃO COM FUNÇÃO:

#ifdef ex3
main() {
    float salario, salarioAjustado;
    int genero;
    int anos;

  //Recebe o salário e caso seja menor ou igual a 0, retorna para reinserção correta do dado até que a mesma seja efetuada
    do {
        printf("Digite o salário atual do funcionário (maior que 0): ");
        scanf("%f", &salario);
        if (salario <= 0) {
            printf("Valor inválido! O salário deve ser maior que 0.\n");
        }
    } while (salario <= 0);

  //Recebe o gênero e caso a entrada seja diferente de 1 ou 2, o usuário retorna até inserir um dado coerente com o solicitado
    do {
        printf("Digite o gênero do funcionário (1 para mulher, 2 para homem): ");
        scanf("%d", &genero);
        if (genero != 1 && genero != 2) {
            printf("Valor inválido! Insira 1 para mulher ou 2 para homem.\n");
        }
    } while (genero != 1 && genero != 2);

  //Recebe os anos de empresa e caso seja menor ou igual a 0, retorna para reinserção correta do dado
    do {
        printf("Digite há quantos anos o funcionário trabalha na empresa: ");
        scanf("%d", &anos);
        if (anos <= 0) {
            printf("Valor inválido! O número de anos deve ser maior que 0.\n");
        }
    } while (anos <= 0);

    if (genero == 1) {
        if (anos < 15) //Este é verificado primeiro pois é o menor intervalo de tempo e garante que a menor taxa de reajuste seja aplicada primeiro
            salarioAjustado = salario * 1.05;
        else if (anos <= 20) //Então avança-se para a maior possibilidade de ajuste pois assim a segunda possibilidade de ajuste informada na tabela só pode estar entre as duas possibilidades testadas, dispensando assim um cálculo próprio para a tal.
            salarioAjustado = salario * 1.12;
        else
            salarioAjustado = salario * 1.23;
    } else if (genero == 2) //Neste a mesma organização lógica do ajuste de salário feminino se repete com as devidas alterações de valores para o ajuste dos funcionários masculinos.
       {
        if (anos < 20)
            salarioAjustado = salario * 1.03;
        else if (anos <= 30)
            salarioAjustado = salario * 1.13;
        else
            salarioAjustado = salario * 1.25;
    }

    printf("O novo salário do funcionário será: R$ %.2f\n", salarioAjustado);

    return 0;
}
#endif
*/


#ifdef ex3
main() {
    float salario, salarioAjustado;
    int genero;
    int anos;

  //Recebe o salário e caso seja menor ou igual a 0, retorna para reinserção correta do dado até que a mesma seja efetuada
    do {
        printf("Digite o salario atual do funcionario (maior que 0): ");
        scanf("%f", &salario);
        if (salario <= 0) {
            printf("Valor invalido! O salario deve ser maior que 0.\n");
        }
    } while (salario <= 0);

  //Recebe o gênero e caso a entrada seja diferente de 1 ou 2, o usuário retorna até inserir um dado coerente com o solicitado
    do {
        printf("Digite o genero do funcionario (1 para mulher, 2 para homem): ");
        scanf("%d", &genero);
        if (genero != 1 && genero != 2) {
            printf("Valor invalido! Insira 1 para mulher ou 2 para homem.\n");
        }
    } while (genero != 1 && genero != 2);

  //Recebe os anos de empresa e caso seja menor ou igual a 0, retorna para reinserção correta do dado
    do {
        printf("Digite ha quantos anos o funcionario trabalha na empresa: ");
        scanf("%d", &anos);
        if (anos <= 0) {
            printf("Valor invalido! O número de anos deve ser maior que 0.\n");
        }
    } while (anos <= 0);

    if (genero == 1) {
        if (anos < 15) //Este é verificado primeiro pois é o menor intervalo de tempo e garante que a menor taxa de reajuste seja aplicada primeiro
            salarioAjustado = salario * 1.05;
        else if (anos <= 20) //Então avança-se para a maior possibilidade de ajuste pois assim a segunda possibilidade de ajuste informada na tabela só pode estar entre as duas possibilidades testadas, dispensando assim um cálculo próprio para a tal.
            salarioAjustado = salario * 1.12;
        else
            salarioAjustado = salario * 1.23;
    } else if (genero == 2) //Neste a mesma organização lógica do ajuste de salário feminino se repete com as devidas alterações de valores para o ajuste dos funcionários masculinos.
    {
        if (anos < 20)
            salarioAjustado = salario * 1.03;
        else if (anos <= 30)
            salarioAjustado = salario * 1.13;
        else
            salarioAjustado = salario * 1.25;
    }

    printf("O novo salario do funcionario sera: R$ %.2f\n", salarioAjustado);

    return 0;
}
#endif


