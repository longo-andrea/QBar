# QBar
Progetto sviluppato per il Corso di Programmazione ad Oggetti.

![Logo](https://github.com/longo-andrea/QBar/blob/master/Graphic/logo.svg)

## Composizione
Vengono sviluppati: 
- Qontainer: template di un contenitore, senza l'utilizzo della stl
- Gerarchia: una gerarchia di tipi con almeno un passo di derivazione virtuale e 3 sotto-tipi
- GUI: sviluppo di un'interfaccia grafica 

### Qontainer
Il Qontainer è stato implementato come un vector, e fornisce dei metodi per:
- Inserimento
- Rimozione
- Ricerca
- Accesso
- Iterazione

### Gerarchia
La gerarchia implementata:

 | PRODOTTO | - | - | - |
 |---|---|---|---|
 | CIBO | BRISOCHE | PANINO | PIADINA
| BEVANDE | ANALCOLICO | COKCTAIL | VINO 

Si ha una classe base:
- Prodotto: classe base astratta che descrive un generico prodotto
Due classi astratte derivate da Prodotto:
- Bevanda: che rappresenta una generica bevanda
- Cibo: che rappresenta un cibo generico
Abbiamo poi 3 classi concrete derivate da Cibo:
- Briosche: rappresenta una briosche
- Panino: rappresenta un panino
- Piadina: rappresenta una piadina
Anche Bevanda possiede 3 classi derivate concrete:
- Analcolico: rappresenta una bevanda analcolica
- Cocktail: rappresenta un cocktail
- Vino: rappresenta un vino


