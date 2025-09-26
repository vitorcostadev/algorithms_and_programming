def ordernarVetor(inicio: int, fim: int, vetor: list):
    if(inicio >= fim): return;
    else:
        min_idx = inicio
        for _ in range(inicio+1, fim+1):
            if(vetor[_] < vetor[min_idx]):
                min_idx = _ 
        
        vetor[inicio], vetor[min_idx] = vetor[min_idx], vetor[inicio]
        ordernarVetor(inicio+1, fim, vetor)

from random import randint
vetor = [randint(1,999) for _ in range(5)]
print("Antes: ", vetor)
ordernarVetor(0, len(vetor)-1, vetor)
print("Depois: ", vetor)