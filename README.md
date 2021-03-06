# Euj Escape Game - EEG🚪💠🌟🏃👾👾👾

Projet C++ 2019/2020 - Langage à Objets Avancé - Université de Paris - Double Master Mathématiques, Informatique parcours Data Science (MIDS).

Tuteur : Jean-Baptiste Yunès.

Réalisé par : Mohamed Boudokhane et Mohamed-Amine Bousahih.

## Description du projet

Ce projet propose la création d'un ensemble de deux applications écrites en langage C++ : une application de conception de plateaux de jeu et une application permettant de jouer sur un ensemble de plateaux.

Le jeu est à temps discret, directement piloté par l'utilisateur. Celui-ci déplace à l'aide du clavier un personnage afin d'aller récupérer un maximum de trésors tandis que des personnages hostiles, automatisés, tentent de l'en empêcher.

Votre mission est la suivante : réussir à traverser tous les plateaux.

Attention : les streumons 👾 deviennent de plus en plus intelligents au fil des niveaux.

## Concepts de bases

Un oueurj 🏃 : symbolisé par le caractère J et qui peut se déplacer, à chaque tour, dans l'une des huits adjacentes (si possible), rester sur place ou se téléporter.

Des streumons 👾: symbolisés par '0', '1' ou '2' (leur symbole indique le type déplacement) et qui peuvent se déplacer, à chaque tour, dans l'une des huits cases adjacentes (si possible). Un streumon n'a qu'un but dans la vie : dévorer le oueurj.

Des reumus : symbolisés par 'X'. Un reumu est un obstacle inamovible et aucun élément ne peut le traverser. Ils délimitent le plateau et peuvent former des barrières à l'intérieur du plateau.

Des diams 💠: symbolisés par '\$' qui peuvent être rammassés par le oueurj. Celui-ci doit d'ailleurs en ramasser au moins un avant qu'une porte de sortie ne s'ouvre et qu'il puisse tenter de s'y engouffrer. Les diams sont ignorés par les streumons.

Des geurchars 🌟: symbolisés par '\*' et qui permettent d'obtenir, pour le oueurj, la possibilité de téléportation infinie dans le niveau actuel.

Des teupors 🚪: symbolisés par '+' si elles sont ouvertes et '-' si fermées. A chaque fois que le oueurj ramasse un diam, une nouvelle teupor s'ouvre à travers laquelle le oueurj peut sortir du plateau.

## Représentation d'un plateau

![Sauvegarde](./images/plateauu.png)

## Commandes de bases

En tant qu'utilisateur, vous déplacez le oueurj:

- z : haut
- x : bas
- d : droite
- q : gauche
- a : haut diagonale gauche
- e : haut diagonale droite
- c : bas diagonale droite
- w : bas diagonale gauche
- o : arrêter le jeu et éventuellement sauvgarder.

A chaque début de partie, vous avez une téléportation. Dès lors que vous réussissez à traverser un niveau, vous obtenez une téléportation supplémentaire.

Attention : vous n'avez qu'un nombre fini de téléportations. Par exemple, supposons qu'au niveau n°2 vous aviez cinq téléportations. Si vous utilisez toutes vos téléportations "par défaut" pour échapper aux streumons 👾 , alors au niveau n°3 il ne vous restera qu'une téléportation.

Lorsque vous récupérez des geuchars 🌟 , vous avez la possibilité de vous téléporter, de manière infinie dans le niveau actuel :

- t : téléportation aléatoire sur une position (i,j) du plateau.

Attention : dans certaines situations, vous remercierez votre ami le geuchar 🌟 de vous avoir sauvé des streumons 👾. Dans certains cas, il peut vous mettre dans des situations délicates et vous téléporter juste à coté d'un streumon.

Un système de vies a été mis en place. Dès le début de la partie, vous avez trois vies. A chaque passage de niveau, vous obtenez une vie supplémentaire.

## Extensions utiles

- possibilité de sauvegarde en cours de partie et reprendre plus tard.

Les streumons 👾

Au cours de votre partie, vous aurez l'occasion de rencontrer différents types de streumons doués de plus ou moins d'intelligence (cf représentation plateau ci-dessus):

- Type n°0 : ce sont des streumons qui ne sont pas allé à l'école des streumons quand ils étaient petit ... leurs déplacements sont aléatoires et ne tiennent pas en compte de la position du oueurj.

- Type n°1 : diplômés de l'école des streumons, ils appliquent l'algorithme A\* à la perfection afin de rechercher le chemin le plus court afin de dévorer le oueurj !.

- Type n°2 : ce sont des streumons qui choisissent aléatoirement entre déplacement "aléatoire" et "A\*", la probabilité de A\* augmente au fil des niveaux.

Lorsque les streumons se croisent, différentes interactions sont possibles :

- L'élimination : si deux streumons se croisent alors ils disparaissent.

- La reproduction : si deux streumons se croisent alors ils fusinnent.

- La création d'artefact : si deux streumons se croisent alors ils disparaissent et engendrent un trésor (un diams 💠 ou un geuchar 🌟 ).

## Lancement du jeu 🎮

Le temps est venu de vous expliquez comment configurer et lancer une partie afin que votre aventure EEG puisse débuter !.

### Configuration

Avant de pouvoir enfiler vos baskets et courir dans les plateaux pour éviter les streumons, il faut compiler le projet avec simplement:

```bash
make
```

ensuite il faut générer les plateaux, vous avez deux possibilités :

```bash
 ./gc fichier.board
```

![Sauvegarde](./images/menu1.png)

Cette commande permet de créer des plateaux (fichiers d'extensions .board). Elle enclenchera directement un menu qui vous demandera de spécifier quelques paramètres afin de configurer vos plateaux :

- le nombre de niveaux
- la taille des plateaux (hauteur, largeur)
- le nombre de teupors
- le nombre de diams
- le nombre de streumons
- le nombre de geuchars

![Sauvegarde](./images/menu2.png)

Une autre manière est de tapper simplement la commande suivante :

```bash
 ./gc
```

Cela vous permettra d'enclencher directement le menu afin de spécifier les paramètres comme précédemment puis de donner un nom à votre fichier .board :

![Sauvegarde](./images/gc.png)

Après avoir configuré les plateaux à votre guise, vous devez créer un "jeu" à partir de votre fichier .board précédent en créant un fichier d'extension .game :

```bash
./gc fichier1.game fichier2.board
```

![Sauvegarde](./images/compil1.png)

Lancer le jeu

Félicitations, vous avez réussi à faire la part la plus difficile du travail !

Afin de pouvoir commencer à jouer et débuter l'aventure EEG, veuillez tappez (au choix) l'une des commandes suivantes :

```bash
./gp
```

Cette première commande vous permettra de choisir de reprendre une partie parmi les fichiers .game existants :

![Sauvegarde](./images/listing3.png)

```bash
./gp fichier.game
```

Cette seconde commande vous permettra de spécifier le nom exacte de la partie que vous souhaitez reprendre :

![Sauvegarde](./images/compil2.png)

Have fun ! C'est parti pour l'aventure ! 🚪💠🌟🏃👾👾👾

## Sauvegarder une partie

Si vous devez mettre fin à cette belle aventure, vous pouvez arrêter le jeu en appuyant sur le touche 'o'.

Le menu vous proposera la possibilité de sauvegarder votre partie en cours :

![Sauvegarde](./images/savefirst.png)

Il vous suffit simplement d'écrire le nom de votre fichier (sans l'extension .game) et vous pouvez reprendre votre partie plus tard (en saisissant à nouveau ./gp nomfichier.game).

![Sauvegarde](./images/save.png)

PS : ça ne sert à rien d'appuyer sur '' puis de sauvegarder votre partie avant qu'un streumon ne vous dévore ... il sera patient et vous attendra dès votre retour ... 👾👾👾

Remarque : Dès lors que vous souhaitez mettre fin à votre partie en appuyant sur la touche 'o', vous serez redirigé vers le menu afin de choisir si vous souhaitez sauvegarder votre partie ...

![Sauvegarde](./images/listing1.png)

... puis de choisir si vous souhaitez reprendre la partie sauvegardée ...

![Sauvegarde](./images/listing2.png)

## Le format de fichier '.game'

La première ligne contient les informations sur la partie en cours : largeur du plateau, hauteur, nombre de niveaux, niveau du joueur, sa position, nombre de diams, de téléportations et vies restantes. Nous séparons ces informations par des '*' .

De plus, nous avons la liste des différents symboles sur le plateau séparés par '#".
