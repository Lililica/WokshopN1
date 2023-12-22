#include <sil/sil.hpp>

int main()
{
    int nbrMosaique{5};
    sil::Image imageRef{"images/logo.png"};
    sil::Image imageOutPut{imageRef.width()*nbrMosaique,imageRef.height()*nbrMosaique};


    for(int i{0}; i<nbrMosaique; i++){ 
        for(int j{0}; j<nbrMosaique; j++){
            // Puisque les boucles sur x et y ne dépendent pas de i et j, on peut les mettre en dehors des if, une seule fois.
            for (int x{0}; x < imageRef.width(); ++x)
            {
                for (int y{0}; y < imageRef.height(); ++y)
                {
                    // Et ensuite, on peut faire seulement deux if au lieu de 4: un pour calculer le x à utiliser, et l'autre pour le y. Et je vais même utiliser l'opérateur ternaire pour que ce soit encore plus simple
                    int const actual_x = i%2==0 ? x : imageRef.width()-x-1;
                    int const actual_y = j%2==0 ? y : imageRef.height()-y-1;
                    imageOutPut.pixel(x + i*(imageRef.width()-1),y + j*(imageRef.height()-1)) = imageRef.pixel(actual_x,actual_y);
                }
            }
        }
    }
    
    imageOutPut.save("output/exo15.png");

}