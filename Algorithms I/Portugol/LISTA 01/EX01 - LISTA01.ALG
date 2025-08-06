Algoritmo "EX01 - LISTA01"
//1. Fa�a um algoritmo que leia o raio de uma circunfer�ncia e calcule o comprimento e a �rea da
//circunfer�ncia.
//F�RMULAS: �rea = p * raio2
//comprimento = 2 * p * raio
Var
// Se��o de Declara��es das vari�veis 
area, comprimento, raio: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreval("Digite o raio da circuferência: ")
leia(raio)
area <- pi * raio ^ 2
comprimento <- 2 * pi * raio

escreval("A area da circuferencia é: ", area)
escreval("O comprimento da circuferencia é de: ", comprimento)

Fimalgoritmo