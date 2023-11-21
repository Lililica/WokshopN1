#include <sil/sil.hpp>
#include "random.hpp"
#include <cmath>

int main()
{
    sil::Image image{500/*width*/, 500/*height*/};

	int x0 {image.width()/2};
	int y0 {image.height()/2};
	int rayon{80};
	float xi{};
	float yi{};
    
	for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
    		{
				
				if (pow(y - y0, 2) + pow(x - x0, 2) <= pow(rayon, 2) && pow(y - y0, 2) + pow(x - x0, 2) >= pow(rayon-5, 2)) {
					image.pixel(x, y) = glm::vec3{1,1,1};
				}

				for (int i{0}; i < 6; i++) {
					double angle {static_cast<float>(i) * (3.14/3)};
					yi = rayon * sin(angle);
					xi = rayon * cos(angle);

					if (pow(y - y0 + yi, 2) + pow(x - x0 + xi, 2) <= pow(rayon, 2) && pow(y - y0 + yi, 2) + pow(x - x0 + xi, 2) >= pow(rayon-5, 2)) {
					image.pixel(x, y) = glm::vec3{1,1,1};
					}
				}
				
				
				
			
    		}    
	}


    

    image.save("output/mosaique.png");
}