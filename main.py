def ordernarVetor(inicio: int, fim: int, vetor: list):
    if(inicio >= fim): return;
    else:
        min_idx = inicio
        for _ in range(inicio+1, fim+1):
            if(vetor[_] < vetor[min_idx]):
                min_idx = _ 
        
        vetor[inicio], vetor[min_idx] = vetor[min_idx], vetor[inicio]
        ordernarVetor(inicio+1, fim, vetor)

def procuraNum(inicio: int, fim: int, num: int, vetor: list):
    
    if inicio > fim: return False
    if vetor[inicio] > num: return False
    if vetor[inicio] == num: return True 
    return procuraNum(inicio+1, fim, num, vetor)

from time import time 

vetor = [1,2,3,4,5,6,7,8,9,10]
print("Antes: ", vetor)
ordernarVetor(0, len(vetor)-1, vetor)
print("Depois: ", vetor)
if procuraNum(0, len(vetor)-1, 4, vetor): print("O numero esta inserido.")
else: print("Nao esta.")
