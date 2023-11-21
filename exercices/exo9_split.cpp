#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image image{"images/logo.png"};
	sil::Image resultat{image};
    
   for (int x{0}; x < 20; x++)
	{
		for (int y{0}; y < image.height(); y++)
    		{
			resultat.pixel(x, y) = glm::vec3{image.pixel(x+20, y).r, image.pixel(x, y).g, 0};
    		}    
	}
 
	
	for (int x{20}; x < image.width() - 20; x++)
	{
		for (int y{0}; y < image.height(); y++)
    		{
			resultat.pixel(x, y) = glm::vec3{image.pixel(x+20, y).r, image.pixel(x, y).g, image.pixel(x-20, y).b};
    		}    
	}

	for (int x{image.width() - 20}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
    		{
			resultat.pixel(x, y) = glm::vec3{0, image.pixel(x, y).g, image.pixel(x-20, y).b};
    		}    
	}


    

    resultat.save("output/split.png");
}