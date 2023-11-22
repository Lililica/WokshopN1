#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image image{"images/logo.png"};
	sil::Image resultat{image};
    
    
		for (int y{0}; y < 50; y++)
    		{
			int largeur_aleatoire{random_int(0, image.width()/5)};
			int hauteur_aleatoire{random_int(0, image.height()/30)};
			int x1_aleatoire{random_int(0, image.width() - (largeur_aleatoire + 1))};
			int y1_aleatoire{random_int(0, image.height() - (hauteur_aleatoire+1))};
			int x2_aleatoire{random_int(0, image.width() - (largeur_aleatoire+1))};
			int y2_aleatoire{random_int(0, image.height() - (hauteur_aleatoire+1))};
			for (int i{0}; i < largeur_aleatoire; i++) {
				for (int j{0}; j < hauteur_aleatoire; j++) {
					image.pixel(x2_aleatoire + i, y2_aleatoire + j) = resultat.pixel(x1_aleatoire + i, y1_aleatoire + j);
					image.pixel(x1_aleatoire + i, y1_aleatoire + j) = glm::vec3{0};
				}
				
			}


			
    		}    
	

    

    image.save("output/glitch.png");
}