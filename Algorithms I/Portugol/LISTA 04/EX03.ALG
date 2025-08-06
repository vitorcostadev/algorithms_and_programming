Algoritmo "EX03"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Calcular média de números pares
// Autor(a)    : Vitor Costa
// Data atual  : 19/05/2025
Var
numerosDigitados, contador, numero: INTEIRO
Inicio
numerosDigitados <- 0
contador <- 0
numero <- 0
REPITA
      escreval(">>> Digite um número: ")
      leia(numero)
      se ((numero mod 2 = 0) e (numero > 0)) entao
         numerosDigitados <- numerosDigitados + numero
         contador <- contador + 1
      fimse
      
ATE (numero = 0)

escreval("No fim, tivemos ", contador, " números pares.")
escreval("E a média desses números é de: ", numerosDigitados DIV contador)

Fimalgoritmo