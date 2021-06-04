# push_swap

## Score :
✅ 90/100 ✅

## Sujet :

Ecrire un programme en C nommé push_swap, qui calcule et affiche sur la sortie standard le plus petit programme dans le langage des instructions de Push_swap permettant de trier dans l'ordre croissant les entiers passés en paramètre.
Pour ce faire, on ne dispose que des opérations suivantes :
- sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
- sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
- ss : sa et sb en même temps.
- pa : push a - prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
- pb : push b - prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
- ra : rotate a - décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
- rb : rotate b - décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
- rr : ra et rb en même temps.
- rra : reverse rotate a - décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
- rrb : reverse rotate b - décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
- rrr : rra et rrb en même temps.

Utilisation de doubles listes chainées.

## Comment lancer :

Télécharger le repo :
```
git clone https://github.com/sarahlesc/push_swap.git
cd push_swap
```
Compiler et lancer le programme :
```
make
./push_swap < nombres entiers distincts (maximum 500 nombres) >
```
Pour verifier que les nombres sont bien triés dans l'ordre croissant :
```
./push_swap < nombres entiers distincts (maximum 500 nombres) > | ./checker_linux < même liste de nombres >
```

## Performances :
- moyenne de 714 sur 100 nombres
- moyenne de 6600 sur 500 nombres

## TUTO :
J'ai séparé le programme en quatre parties : very_small_sorting, small_sorting, medium_sorting et large_sorting.
- very_small_sorting trie les listes de 3 nombres maximum
- small_sorting trie les listes de 10 nombres maximum
- medium_sorting trie les listes de 100 nombres maximum
- large_sorting trie les listes de 500 nombres maximum

## SOURCES :
- https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a : très interessant pour les listes de 2 à 10 nombres.
