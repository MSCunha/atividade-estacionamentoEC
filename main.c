#include <stdio.h>

int main() {
    char placaCarro[8];
    char tipoVeiculo[12];

    float tempo, desconto, multa;
    int op, tempoInt;

    //definicoes de valores
    float horaMoto = 3.00;
    float horaCarro = 5.00;
    float horacaminhonete = 8.00;

    float subtotal;

    inicio:
    tempo = 0;
    desconto = 0;
    multa = 0;

    printf("Digite a placa do veiculo (apenas letras e numeros): ");
    scanf("%s", placaCarro);

    if (placaCarro[7] != '\0' || placaCarro[6] == '\0' || placaCarro[3] == '-') {
        printf("\nERRO: Formato de placa invalido!\n");
        printf("Certifique-se de digitar apenas 7 caracteres alfanumericos.\n");
        goto inicio;
    }

    tempo:
    printf("insira o tempo de uso em horas: "); // seguindo os requisitos deve-se usar horas
    //printf("insira o tempo de uso em minutos: "); 
    if (scanf("%f", &tempo)!=1 || tempo < 0) {
        printf("ERRO: Entrada invalida para o tempo de uso. Por favor, insira um numero valido.\n");
        goto tempo;
    }
    //tempo = tempo / 60; // se em minutos converte para horas considerando a inviabilidade de horas em decimais.

    // arredondamento para cima
    tempoInt = (int)tempo;
    if (tempo - tempoInt > 0) {
        tempoInt++;
    }
   
    tipo:
    printf("1 - Moto \n2 - Carro \n3 - Caminhonete\nDigite o tipo do veiculo:");
    scanf("%d", &op);

    switch (op){
    case 1:
        sprintf(tipoVeiculo, "Moto");
        if (tempo<=1 && tempo>0.25){
            subtotal = horaMoto;
        }else  if (tempoInt > 1 && tempoInt <= 5) {
            subtotal = tempoInt * horaMoto;
        }else if (tempoInt>5){
            desconto = 0.10 * (tempoInt * horaMoto);
            subtotal = (tempoInt * horaMoto);
        }else{
            subtotal = 0;
        }
        break;
    case 2:
        sprintf(tipoVeiculo, "Carro");
        if (tempo<=1 && tempo>0.25){
            subtotal = horaCarro;
        }else  if (tempoInt > 1 && tempoInt <= 5) {
            subtotal = tempoInt * horaCarro;
        }else if (tempoInt>5){
            desconto = 0.10 * (tempoInt * horaCarro);
            subtotal = (tempoInt * horaCarro);
        }else{
            subtotal = 0;
        }
        break;
    case 3:
        sprintf(tipoVeiculo, "Caminhonete");
        if (tempo<=1 && tempo>0.25){
            subtotal = horacaminhonete;
        }else  if (tempoInt > 1 && tempoInt <= 5) {
            subtotal = tempoInt * horacaminhonete;
        }else if (tempoInt>5){
            desconto = 0.10 * (tempoInt * horacaminhonete);
            subtotal = (tempoInt * horacaminhonete);
        }else{
            subtotal = 0;
        }
        break;
    default:
        printf("ERRO: Tipo de veiculo invalido. Por favor, escolha uma opcao valida.\n");
        goto tipo;
    }

    if (tempo > 10) {
        multa = 20;
    }

    printf("\n==========================================\n");
    printf("\nVeiculo: %s - %s\nPermanencia: %.1f Horas\nSubtotal: R$ %.2f\nDescontos: R$ %.2f\nMulta: R$ %.2f\n", placaCarro, tipoVeiculo, tempo, subtotal, desconto, multa);
    printf("\n------------------------------------------\n");
    printf("\nTotal: R$ %.2f\n", (subtotal - desconto + multa));
    printf("\n==========================================\n");
 return 0;
}