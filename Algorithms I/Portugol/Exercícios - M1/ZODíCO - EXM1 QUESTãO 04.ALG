Algoritmo "Zodíco - EXM1 Questão 04"
// Disciplina   : [Algoritimos e Progamação]
// Professor   : Fernanda Cunha 
// Descrição   : Signo baseado na data do nascimento.
// Autor(a)    : Vitor Kawa P. Da Costa
// Data atual  : 08/04/2025
Var
signo, mes: caractere
dia: inteiro


Inicio
escreval(">>> Primeiramente, informe a sua data de nascimento a seguir: (dia/mes)")
escreval("OBS: A primeira entrada é o dia, e o segundo é o mês (por extenso).")
leia(dia,mes)

mes <- minusc(mes)

se ((dia >= 21) e (dia <= 31) e (mes = "janeiro") ou (dia <= 19) e (mes = "fevereiro")) entao
   signo <- "Aquário"
senao
     se ((dia > 19) e (mes = "fevereiro") ou (dia <= 20) e (mes = "março")) entao
        signo <- "Peixes"
     senao
          se ((dia >= 21) e (dia <= 31) e (mes = "março") ou (dia <= 30) e (mes = "abril")) entao
             signo <- "Áries"
          senao
               se ((dia >= 21) e (dia <= 30) e (mes = "abril") ou (dia <= 20) e (mes = "maio")) entao
                  signo <- "Touro"
               senao
                    se ((dia >= 21) e (dia <= 31) e (mes = "maio") ou (dia <= 20) e (mes = "junho")) entao
                       signo <- "Gêmeos"
                    senao
                         se ((dia >= 21) e (dia <= 30) e (mes = "junho") ou (dia <= 21) e (mes = "julho")) entao
                            signo <- "Câncer"
                         senao
                              se ((dia >= 22) e (dia <= 31) e (mes = "julho") ou (dia <= 22) e (mes = "agosto")) entao
                                 signo <- "Leão"
                              senao
                                   se ((dia >= 23) e (dia <= 31) e (mes = "agosto") ou (dia <= 22) e (mes = "setembro")) entao
                                      signo <- "Virgem"
                                   senao
                                        se ((dia >= 23) e (dia <= 30) e (mes = "setembro") ou (dia <= 22) e (mes = "outubro")) entao
                                           signo <- "Libra"
                                        senao
                                             se ((dia >= 23) e (dia <= 31) e (mes = "outubro") ou (dia <= 21) e (mes = "novembro")) entao
                                                signo <- "Escorpião"
                                             senao
                                                  se ((dia >= 22) e (dia <= 30) e (mes = "novembro") ou (dia <= 21) e (mes = "dezembro")) entao
                                                     signo <- "Sagitário"
                                                  senao
                                                       se ((dia >= 22) e (dia <= 31) ou (dia <= 20) e (mes = "janeiro")) entao
                                                          signo <- "Capricório"
                                                       fimse
                                                  fimse
                                             fimse
                                        fimse
                                   fimse
                              fimse
                         fimse
                    fimse
               fimse
          fimse
     fimse
fimse
escreva("Você é do signo: ", signo, "!")


Fimalgoritmo