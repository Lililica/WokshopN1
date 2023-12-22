#include <sil/sil.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.3f}} + center_of_rotation;
}


int main()
{
    sil::Image const image{"images/logo.png"};
	sil::Image resultat{image.width(), image.height()};
	
    
    // float angle{90.0}; // Variable inutilisée
	int x0{image.width()/2};
	int y0{image.height()/2};
	glm::vec2 origine{x0, y0};
		 
	for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
    		{
			int const rayon = pow(pow(x - x0,2)+pow(y -y0,2),0.5f); // On préfère déclarer les variables le plus tard possible, seulement quand on en a réellement besoin
			glm::vec2 vecteur{x, y};
			glm::vec2 resultant {rotated(vecteur, origine, 0.1f*rayon)};
			int xi{static_cast<int>(resultant[0])};
			int yi{static_cast<int>(resultant[1])};
			if (xi < image.width() && yi < image.height() && xi >= 0 && yi >= 0
			) {
				// image.pixel(x, y) =
				resultat.pixel(x, y) = image.pixel(xi,yi);
			}
			
			

			
			
			
    		}    
	}


    

    resultat.save("output/vortex.png");
}