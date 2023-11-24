# Wokshop - Synthese de l'image 

*Ce repository contient deux branches représentant nos deux avancées. Les programmes sont à peu près similaire.*

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

### Concolutions

Une fois la méthode compris, il suffit de réfléchir quoi faire lorque l'on dépasse de l'image. Pour cela si notre pixel `x+i` dépasse, on le remplace par `x` (de même pour `y`).
On peut régler l'intensité de flou avec `intensiteFlou` !

Cela nous donne : 

| Intensité de flou    | Image        |
| ------------- |:-------------:| 
| 1    | ![image](images/photoFlou.jpg) |
| 3     | ![image](images/photoFlou3.jpg)    | 
| 10     | ![image](images/photoFlou10.jpg)    |