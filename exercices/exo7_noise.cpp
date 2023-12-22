#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image image{"images/logo.png"};
    
    // Il n'y a pas de raison particulière de faire une boucle sur tous les x et y de l'image.
    // Puisque on n'utilise ni x ni y dans la suite du code, c'est équivalent à faire une seule boucle avec image.width() * image.height() itérations.
    // Et ce nombre image.width() * image.height() est en fait totalement arbitraire. On pourrait faire 100 itérations comme 1000, ça produirait une image plus ou moins bruitée.
    // Le nombre d'itérations est en fait un paramètre artistique qu'on peut mettre à la valeur qu'on veut
    for (int i{0}; i < 1000; i++)
	{
        int x_aleatoire{random_int(0, image.width())};
        int y_aleatoire{random_int(0, image.height())};
        float r_aleatoire{random_float(0.0, 1.0)};
        float g_aleatoire{random_float(0.0, 1.0)};
        float b_aleatoire{random_float(0.0, 1.0)};
        image.pixel(x_aleatoire,y_aleatoire) = glm::vec3{r_aleatoire, g_aleatoire, b_aleatoire};
	}

    

    image.save("output/noise.png");
}