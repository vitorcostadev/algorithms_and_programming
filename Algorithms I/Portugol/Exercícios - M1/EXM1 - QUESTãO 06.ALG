Algoritmo "EXM1 - Questão 06"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Jogo de advinhação
// Autor(a)    : Vitor Kawa P. Da Costa
// Data atual  : 08/04/2025
Var
palpite, bot: inteiro


Inicio
bot <- randi(50) + 1
escreval(">>> Tente advinhar o número (está entre 1-50): ")
leia(palpite)

// Vou definir que, se o palpite do usuario for menor do que 10 numeros
// do palpite do bot, ele chegou perto, ou se for 10 acima, um "Quase la!"
// e caso for acima disso, passou longe!

se ( ((palpite-bot) < 0) e ((palpite-bot) >= -10) ) entao
   escreval("Você chegou quase lá! O número que eu gerei foi, ",bot,".")
senao
     se ( ((palpite-bot) > 0) e ((palpite-bot) <= 10) ) entao
        escreval("Você passou um pouco do número que eu gerei, que foi o ",bot,"!")
     senao
          escreval("Passou longe pô! vishe... kkkk o número que eu gerei foi o ",bot,"!")
     fimse
fimse


Fimalgoritmo