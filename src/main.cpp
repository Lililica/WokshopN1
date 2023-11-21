#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image image{"images/logo.png"};
	sil::Image resultat{image};
    
    for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
    		{
			int largeur_aleatoire{random_int(0, image.width()/10)};
			int hauteur_aleatoire{random_int(0, image.height()/30)};
			int x1_aleatoire{random_int(0, image.width())};
			int y1_aleatoire{random_int(0, image.height())};
			int x2_aleatoire{random_int(0, image.width() - largeur_aleatoire)};
			int y2_aleatoire{random_int(0, image.height() - hauteur_aleatoire)};

			
			
    		}    
	}

    

    image.save("output/noise.png");
}