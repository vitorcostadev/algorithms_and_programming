Algoritmo "EX04"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Verificação de multíplos.
// Autor(a)    : Vitor Costa
// Data atual  : 24/03/2025
Var
// Seção de Declarações das variáveis 

a,b: inteiro
Inicio
// 4. Escreva um algoritmo que leia 2 valores inteiros, a e b, e escreve-os juntamente com a mensagem ‘são múltiplos’
// ou ‘não são múltiplos’, conforme o caso.

escreval(">>> Digite dois valores: ")
leia(a,b)

se (a mod b) = 0 entao
   escreval("Os valores ", a, " e ", b, "  são multiplos.")
senao
     escreval("Os valores ", a, " e ", b, "  não são multiplos.")
fimse

Fimalgoritmo