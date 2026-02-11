
ALGORITHME DE RECHERCHE DANS DICTIONNAIRE  
la recherche choisie est la recherche dichotomique, j'ai 
choisis cette recherche car elle était plus rapide et 
applicable car le dictionnaire est trié dans le fichier, j'ai
choisi la recherche dichotomique simple et non petit car 
chaque tuile a un nom différent donc l’indice trouvé est 
forcément le premier .


COORDONNÉES 
les coordonnées pour le chargement du niveau et les collisions 
avec les tuiles sont les coordonnées des cases à l'écran et 
celles de l’affichage et la position des personnages sont en 
coordonnées de pixels ( la conversions est faite avec 
TAILLE_CASE ) 
j'ai stocké les position pour les personnages en pixel 
pour simplifier une possible animation ( si on voulait 
déplacer le personnage en glissant et non en passant d’une 
case à une autre directement )   
Pour les tests de collision ( caseEstLibre , les paramètres 
sont en cases mais les coordonnées sont en pixels ) le choix a 
été fait de faire la comparaison avec les coordonnées en cases 
.  


COLLISION ET VÉRIFICATION DES DÉPLACEMENTS  
Parcours chaque objet du niveau et regarde grâce à une boucle 
while si c’est la case ou on veut aller et si elle est solide 
ou non 
Cette fonction a ensuite été implémenté dans peutBougerVers, 
cette fonction vérifie dans un premier temps que le personnage 
ne sorte pas de l'écran puis que le personnage n’aille pas 
dans une case solide ( dans un mur par exemple ) 
