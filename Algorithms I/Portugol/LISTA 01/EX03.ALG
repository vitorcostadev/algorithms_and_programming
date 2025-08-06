Algoritmo "EX03"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Vitor Costa
// Data atual  : 15/03/2025
Var
// Seção de Declarações das variáveis 

a,b,c, area, P: real
Inicio
// área = v P (P - a) (P - b) (P - c)

escreval(">>> Digite o valor do primeiro lado do triangulo (A): ")
leia(a)
escreval(">>> Digite o valor do segundo lado do triangulo (B): ")
leia(b)
escreval(">>> Digite o valor do último lado do triangulo (C): ")
leia(c)

P <- (a+b+c) / 2
area <- raizq ( P * (P-a) * (P-b) * (P-c) )
escreval(">>> O valor da aréa do triangulo é de: ". area)




Fimalgoritmo