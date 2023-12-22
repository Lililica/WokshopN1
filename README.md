# Wokshop - Synthese de l'image 

*Ce repository contient deux branches représentant nos deux avancées. 
JeanBranche : Jean LE CHAUDELEC
LucasBranch : Lucas TERRASSON*

### Diamond Square

Le programme est juste une adaptation du pseudo-code de la vidéo de présentation en C++. Mon code est très mal écrit ce qui le rend un peu difficile à lire. Néanmoins voici des exemples de rendu. 


| Duretée     | Image        |
| ------------- |:-------------:| 
| 0.1      | ![image](output/DiamondSquare/Rough(0,1).png) |
| 0.5     | ![image](output/DiamondSquare/Rough(0,5).png)    | 
| 1 | ![image](output/DiamondSquare/Rough(1).png)     | 
| 2 | ![image](output/DiamondSquare/Rough(2).png)     |


### K-Means

On peut justement voir avec la photo donnée la limite de ce filtre. Il ne prendra pas forcement les K-couleurs les plus représenté. Surtout dans une image où beaucoup de couleurs sont représenté à la même intensité. On peut changer la variable `facteurK` dans le programme pour choisir le nombre de couleur.

Voici des exemples pour plusieurs K :

| K - couleur(s)     | Image        |
| ------------- |:-------------:| 
| 3  (plusieurs essais)    | ![image](output/KMeans/3colors.png) ![image](output/KMeans/3colors1.png)|
| 5     | ![image](output/KMeans/5colors.png)    | 
| 10 | ![image](output/KMeans/10colors.png)    | 
| 30 | ![image](output/KMeans/30colors.png)    |

### Filtre de Kuwahara

Mon code prend un peu de temps selon moi, peut-être un soucis d'optimisation. Le rendu est néanmoins très satisfaisant et on peut régler l'intensité via la variable `intensiteFlou`. Il faut bien faire attention que l'image d'entrée du programme est flou, sinon cela va juste retourner une image flou.

Voici plusieurs exemples avec différentes intensitées :

| Intensité de flou de l'entrée | Intensité de la sortie    | Image        |
| --------- | ------------- |:-------------:| 
|1| 2    | ![image](output/Kuwahara/intensite2.png) |
|1| 3     | ![image](output/Kuwahara/intensite3.png)    | 
|1| 6     | ![image](output/Kuwahara/intensite6.png)    |

<details><summary>Pourquoi pas une intensité plus haute ?</summary>
*Plus on fait une intensité élevée, plus la compleité augmente vite donc moins facile à générer...*
</details>


On peut aussi faire varier l'image flou d'entrée. Plus l'image d'entrée est flou, plus notre "peinture" va sembler imprécise :

| Intensité de flou de l'entrée | Intensité de la sortie    | Image        |
| --------- | ------------- |:-------------:| 
|1| 2    | ![image](output/Kuwahara/intensite2.png) |
|3| 2     | ![image](output/Kuwahara/intensiteentree3.png)    | 
|10| 2     | ![image](output/Kuwahara/intensiteentree10.png)    |

### Tri de pixels

Pour créer notre rendu final, nous sommes passées par 3 étapes :

#### 1) Trier toute l'image par luminosité :

Le code est particuliérement simple mais au début il mettait du temps à nous sortir un resultat. Cela venait du fait que l'on fesait le tri des pixels un nombre fois égal au nombre de pixels dans l'image... Alors qu'il suffisait de le faire une fois ! :/

Voici donc ce que cela donne : ![image](output/exo25_allSorted.png)
*Magnifque !*

#### 2) Trier chaque ligne par luminosité :

Une fois que l'on sait trier l'image, il nous suffit de déterminer les bornes et le nombre d'itération de tris pour trier par ligne.

Voici ce que cela donne : ![image](output/exo25AllLignesSorted.png)

#### 3) Trier des parties aléaroires par luminosité :

Il faut maintenant ajouter de l'aléatoire sur les parties à trier.

Voila ce que l'on obtient : ![image](output/exo25.png)

### Différences de Gaussiennes

Une fois que l'on sait faire un flou, il suffit de soustraire les couleurs d'une image bien flou aux couleurs de l'image moins flou. Les résultats différent beaucoup en fonction des flous choisies mais aussi en fonction du facteur `facteurBlancNoir` qui va déterminer après soustraction des images si un pixel doit être noir ou blanc.

Voici ce que l'on obtient avec :
```cpp
int intensiteFlou{1};
int intensiteFlouSub{5};
float const facteurBlancNoir{0.2};
```
![image](output/exo24.png)


### Filtre séparable

Il suffit de modifier son code de Convolution, ce qui donne :
![image](output/exo23.png)

### Netteté, contours, etc.

Ici, on peut tester plein de matrices différentes :

|![image](output/NetteteContour/Sharpen.png)|![image](output/NetteteContour/Outline.png)|![image](output/NetteteContour/Emboss.png)|
| --------- | ------------- |-------------| 
|Sharpen|Outline|Emboss|

|![image](output/NetteteContour/TopSobel.png)|![image](output/NetteteContour/BotSobel.png)|![image](output/NetteteContour/Perso.png)|
| --------- | ------------- |-------------| 
|Top Sobel|Bot Sobel|Personnalisé|

### Convolutions

Une fois la méthode compris, il suffit de réfléchir quoi faire lorque l'on dépasse de l'image. Pour cela si notre pixel `x+i` dépasse, on le remplace par `x` (de même pour `y`).
On peut régler l'intensité de flou avec `intensiteFlou` !

Cela nous donne : 

| Intensité de flou    | Image        |
| ------------- |:-------------:| 
| 1    | ![image](images/photoFlou.jpg) |
| 3     | ![image](images/photoFlou3.jpg)    | 
| 10     | ![image](images/photoFlou10.jpg)    |

### Normalisation de l'histogramme

Le but ici est de redéfinir l'échelle de définition des couleurs par la luminosité maximale et minimale de l'image.
Pour cela on utilise cette formule :
`image.pixel(x,y) = (image.pixel(x,y)-minBrightness)/(maxBrightness-minBrightness)`

Voici donc le résultat : 
|![image](images/photo_faible_contraste.jpg)|![image](output/NomalisationDeLhisto/Normalisation.png)|
|------|------|
|Avant|Après|

### Tramage

La spécificité de mon programme repose sur le fait que l'on peut choisir le niveau de sa matrice de Bayer pour créer son image. Pour ça, j'ai créer une fonction `generateBayerLevel(int level)` qui fonctionne par itération.
J'ai suivi les explications de [ce site](https://surma.dev/things/ditherpunk/).

Voici donc mes différents rendus :
| Niveau de la matrice de Bayer    | Image        |
| ------------- |:-------------:| 
| 2    | ![image](output/Tramage/MatriceLevel2.png) |
| 5     | ![image](output/Tramage/MatriceLevel5.png)    | 
| 10     | ![image](output/Tramage/MatriceLevel10.png)    |


*Attention à ne pas mettre un nieau trop grand car si la taille de la matrice dépasse celle de l'image, il y aura une erreur !*

### Vortex

Mon programme fait donc l'effet de Vortex mais l'on peut choisir l'intensité de rotation selon un niveau arbitraire nommé `levelOfRotating`.

Voici les images obtenues :
| Niveau de rotation    | Image        |
| ------------- |:-------------:| 
| 1    | ![image](output/Vortex/Level1.png) |
| 3     | ![image](output/Vortex/Level3.png)    | 
| 5     | ![image](output/Vortex/Level5.png)    |

Mais si l'on peut régler l'intensité, on peut se demander ce vue nous donne le programme avec des facteurs de plus en plus grands. C'est donc ce que j'ai testé :

|Image|![image](output/Vortex/Level3.png)|![image](output/Vortex/Level30.png)|![image](output/Vortex/Level300.png)|![image](output/Vortex/Level3000.png)|![image](output/Vortex/Level30000.png)|![image](output/Vortex/Level300000.png)|![image](output/Vortex/Level3000000.png)|![image](output/Vortex/Level30000000.png)
|---|---|---|---|---|---|---|---|---|
|Niveau de rotation|3|30|300|3000|30000|300000|3000000|30000000|

Notre image semble tendre vers une repartion des couleurs assez déstructuré et impossible à prévoir. Mais bon, c'est marrant :) !

### Fractale de Mandelbrot

L'exercice reste assez simple mais il est intéressant ici de recadrer le rendu de l'image pour avoir la partie intéressant. Pour cela, il suffit de définir la valeur initial de notre `std::complex<float> c` en fonction de ce que l'on désire.

Voici le rendu : ![image](output/Fractale/Mandelbrot.png)

On peut tester avec une opération différente sur notre z :

|![image](output/Fractale/Test1.png)|![image](output/Fractale/Test2.png)|![image](output/Fractale/Test3.png)|
|------|------|------|
|`z = z*z*z + c`|`z = z + c`|`z = z + c + c`|

### Glitch

On peut choisir le nombre de glitch généré à l'aide de la variable `nbr_glitch`.
Mais on peut vite se rendre compte que mon code n'est pas parfait lorque l'on met un `nbr_glitch` assez grand, les glitchs ne sont pas bien repartis sur les deux côtés car j'esquive tous les problèmes de sortir de l'image dans mon code.

On peut le voir ici :
| Nombre de glitch   | Image        |
| ------------- |:-------------:| 
| 50    | ![image](output/Glitch/Glitch50.png) |
| 100     | ![image](output/Glitch/Glitch100.png)    | 
| 500     | ![image](output/Glitch/Glitch500.png)    |

*Donc à optimiser...*

### Mosaïque Miroir

Contrairement à ma mosaïque, je ne passe pas par des modulos mais par des `if` qui sont plus complexe MAIS SURTOUT qui rendent mon code plus difficile à lire. Ce serait donc à revoir...

Voici le rendu : ![image](output/exo15.png)

### Mosaïque

Ici, on créer simplement une image plus grande que l'original pour y placer le nombre de mosaïque souhaité. Lors du parcours des pixels sur notre image de sortie, on utilise des `%imageRef.width()` et des `%imageRef.height()` pour parcourir le logo d'origine afin de le répeter sur l'image.

Cela donne : ![image](output/exo14.png)

### Rosace

J'ai réglé mon programme de tel sorte à ce que l'on puisse choisir le nombre de pétales de notre rosace à l'aide de `nbrRosace`.

Voici un rendu en modifiant ce nombre :
| Nombre de pétales   | Image        |
| ------------- |:-------------:| 
| 4    | ![image](output/Rosace/4Petal.png) |
| 10     | ![image](output/Rosace/10Petal.png)    | 
| 100     | ![image](output/Rosace/100Petal.png)    |

### Cercle

On peut modier le rayon du cercle avec la variable `Rayon` et l'épaisseur du trait avec `thickness`.

Voici le plusieurs rendus :
| Rayon| Epaisseur   | Image        |
| ------------- |-------------|-------------|
| 100   |10| ![image](output/Cercle/R100T10.png) |
| 200     |2| ![image](output/Cercle/R200T2.png)    | 
| 150     |80| ![image](output/Cercle/R150T80.png)    |

### Disque

On peut simplement changer le rayon avec `Rayon`.

Voici l'image : ![image](output/exo11.png)

### Luminosité

Pour modifier la luminosité, il suffit d'appliquer la fonction :
$$
f(x) = x^α
$$
où $α∈R^+$.
On distinguera donc deux cas :
    - Si $α∈[0,1]$ :
*<p style="text-align: center;">La luminosité va être augmentée</p>*
    - Si $α∈[1,+\infty{}]$ :

*<p style="text-align: center;">La luminosité va être diminuée</p>*

Dans mon programme on utilisera la variable `intensiteModify` supérieur à 1 qui générera 2 image. Une utilisant la fonction $f$ avec :
$α=intensiteModify$ 
et une autre utilisant :
$α=1/(intensiteModify)$

Voici donc le résultat donné en fonction de `intensiteModify` :

|intensiteModify| Image assombrie   | Image éclaircie      |
| ------------- |-------------|-------------|
| 2   |![image](output/Luminosite/LumiDownModif2.png)| ![image](output/Luminosite/LumiUpModif2.png) |
| 3     |![image](output/Luminosite/LumiDownModif3.png)| ![image](output/Luminosite/LumiUpModif3.png)    | 
| 10    |![image](output/Luminosite/LumiDownModif10.png)| ![image](output/Luminosite/LumiUpModif10.png)    |

<details><summary>Et si α<0 ?</summary>
Si α est plus petit que 0 alors l'application de notre fonction va faire passer la valeur de chaque couleur au dessus de 1, ce qui va donc donner une image blanche. 
</details>

### RGB Split

Ici mon code n'est pas le plus optimisé. Je passe par 3 conditions pour gérer les problèmes de bords ce qui n'est clairement pas optimal mais fonctionnel.

Voici le résultat : ![image](output/exo9.png)

### Rotation de 90°

Il suffit juste d'appliquer la bonne formule.

On a donc : 
![image](output/exo8.png)

### Image bruitée

Le programme nous donne : 
![image](output/exo7.png)

### Mirroir

Le programme nous donne : 
![image](output/exo6.png)

### Dégradé

On a : 
![image](output/exo5.png)

### Négatif

On a :
![image](output/exo4.png)

### Noir & Blanc

On a :
![image](output/exo3.png)

### Echanger les canaux

On a :
![image](output/exo2.png)

### Ne gardez que le vert

On a :
![image](output/exo1.png)