Algoritmo "EX06"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Vitor Costa
// Data atual  : 15/03/2025
Var
// Seção de Declarações das variáveis 
horas_trabalhadas_mes: real
valor_por_hora: real
dep: real
bruto: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreval(">>> Digite a quantidade de horas mensais do funcionário: ")
leia(horas_trabalhadas_mes)
escreval(">>> Digite o valor que ele recebe por hora: ")
leia(valor_por_hora)

bruto <- horas_trabalhadas_mes * valor_por_hora
dep <- bruto * 0.1
bruto <- bruto + dep

escreva(bruto)

Fimalgoritmo