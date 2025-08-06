Algoritmo "EX06"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Maior ou Menor
// Autor(a)    : Vitor Costa
// Data atual  : 24/03/2025
Var
// Seção de Declarações das variáveis 

a,b,c: real
option: inteiro
Inicio
//6. Escreva um algoritmo que leia 4 valores (opção, a, b, c), onde opção é um valor inteiro e positivo e a, b, c são
//quaisquer valores reais. Escreva os valores lidos da seguinte maneira:
 //se opção = 1 ? escreva os 3 valores a, b, c em ordem crescente
 //se opção = 2 ? escreva os 3 valores a, b, c em ordem decrescente
 //se opção = 3 ? escreva os 3 valores de forma que o maior valor entre a, b, c fica entre os outros 2.
 
 escreval(">>> Digite uma opção [1,2,3]: ")
 leia(option)
 escreval(">>> Agora, digite três numeros quaisquer: ")
 leia(a,b,c)
 
 escolha option
 
         caso 1
              se (a > b) e (b > c) entao
                 escreval("CRESCENTE [1.a] : ", c,b,a)
              senao
                   se (a > c) e (c > b) entao
                      escreval("CRESCENTE [1.1a] : ", b,c,a)
                   senao
                        se (b > a) e (a > c) entao
                           escreval("CRESCENTE [1.2a] : ", c,a,b)
                        senao
                             se (b > c) e (c > a) entao
                                escreval("CRESCENTE [1.3a] : ", a,c,b)
                             senao
                                  se (c > a) e (a > b) entao
                                     escreval("CRESCENTE [1.4a] : ", b,a,c)
                                  senao
                                       escreval("CRESCENTE [1.5a] : ", a,b,c)
                                  fimse
                             fimse
                        fimse
                   fimse
              fimse
              
         caso 2
              se (a > b) e (b > c) entao
                 escreval("DECRESCENTE [1.a] : ", a,b,c)
              senao
                   se (a > c) e (c > b) entao
                      escreval("DECRESCENTE [1.1a] : ", a,c,b)
                   senao
                        se (b > a) e (a > c) entao
                           escreval("DECRESCENTE [1.2a] : ", b,a,c)
                        senao
                             se (b > c) e (c > a) entao
                                escreval("DECRESCENTE [1.3a] : ", a,c,b)
                             senao
                                  se (c > a) e (a > b) entao
                                     escreval("DECRESCENTE [1.4a] : ", c,a,b)
                                  senao
                                       escreval("CRESCENTE [1.5a] : ", c,b,a)
                                  fimse
                             fimse
                        fimse
                   fimse
              fimse
         
         caso 3
              se (a > b) e (b > c) entao
                 escreval("NUM MAIOR NO MEIO [1.a] : ", c,a,b)
              senao
                   se (a > c) e (c > b) entao
                      escreval("NUM MAIOR NO MEIO [1.1a] : ", b,a,c)
                   senao
                        se (b > a) e (a > c) entao
                           escreval("CRESCENTE [1.2a] : ", c,b,c)
                        senao
                             se (b > c) e (c > a) entao
                                escreval("NUM MAIOR NO MEIO [1.3a] : ", a,b,c)
                             senao
                                  se (c > a) e (a > b) entao
                                     escreval("NUM MAIOR NO MEIO [1.4a] : ", b,c,a)
                                  senao
                                       escreval("NUM MAIOR NO MEIO [1.5a] : ", a,c,b)
                                  fimse
                             fimse
                        fimse
                   fimse
              fimse
         fimescolha


Fimalgoritmo