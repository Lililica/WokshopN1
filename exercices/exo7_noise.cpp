#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image image{"images/logo.png"};
    
    for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
    		{
			int x_aleatoire{random_int(0, image.width())};
			int y_aleatoire{random_int(0, image.height())};
			float r_aleatoire{random_float(0.0, 1.0)};
			float g_aleatoire{random_float(0.0, 1.0)};
			float b_aleatoire{random_float(0.0, 1.0)};
        	image.pixel(x_aleatoire,y_aleatoire) = glm::vec3{r_aleatoire, g_aleatoire, b_aleatoire};
    		}    
	}

    

    image.save("output/noise.png");
}