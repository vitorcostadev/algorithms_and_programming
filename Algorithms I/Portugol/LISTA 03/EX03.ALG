Algoritmo "EX03"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Média Ponderada
// Autor(a)    : Vitor Costa
// Data atual  : 24/03/2025
Var
// Seção de Declarações das variáveis 

a,b,c,media, max: real
Inicio
// Escreva um algoritmo que leia três valores a, b e c, e calcule e escreva a média ponderada com pesos de 5 para
// o maior dos 3 valores e 2.5 para os outros 2 valores.

escreval(">>> Digite três valores: ")
leia(a,b,c)

se (a > b) e (a > c) entao
   max <- a
   a <- a * 5
   b <- b * 2.5
   c <- c * 2.5
   
fimse

se (b > a) e (b > c) entao
   max <- b
   a <- a * 2.5
   b <- b * 5
   c <- c * 2.5
   
fimse

se (c > a) e (c > b) entao
   max <- c
   a <- a * 2.5
   b <- b * 2.5
   c <- c * 5
   
fimse

media <- (a + b + c) / (5 + 2.5 + 2.5)

escreval(">>> O resultado da média ponderada ficou: ")
escreval("A: ",a)
escreval("B: ",b)
escreval("C: ",c)
escreval("Média final: ", media)
escreval("O maior valor inserido é: ", max)


Fimalgoritmo