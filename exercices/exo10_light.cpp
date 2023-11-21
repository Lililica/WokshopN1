#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image image{"images/photo.jpg"};
    
   float puissance{0.5};
	for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
    		{
			image.pixel(x, y) = glm::vec3{pow(image.pixel(x, y).r, puissance), pow(image.pixel(x, y).g, puissance), pow(image.pixel(x, y).b, puissance)};
    		}    
	}


    

    image.save("output/light.png");
}