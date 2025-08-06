Algoritmo "EXM1 - Questão 05"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Calcular qnts latas de tinta para pintar um tanque
// Autor(a)    : Vitor Kawã P. da Costa
// Data atual  : 08/04/2025
Var
area_base, area_lateral, raio, altura, area_total: real
quantidade_latas: real


Inicio
escreva(">>> Digite o raio da lata de cilindro: ")
leia(raio)
escreva(">>> Agora, digite a altura da lata de cilindro: ")
leia(altura)

area_base <- pi * raio^2
area_lateral <- pi * raio * altura
area_total <- area_lateral + area_base

// Cada litro da lata pinta cerca de 3m², e como cada uma
// possui 5 litros, seria 5x3 = 15m².

quantidade_latas <- area_total mod 15 // não existe fraçao em lata de tinta hehe
escreval("Você iria precisar de",quantidade_latas, " latas de tinta para pintar o tanque.")


Fimalgoritmo