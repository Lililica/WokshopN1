#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image image{500/*width*/, 500/*height*/};

	int x0 {image.width()/2};
	int y0 {image.height()/2};
	int rayon{80};
    
	for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
    		{
				if (pow(y - y0, 2) + pow(x - x0, 2) <= pow(rayon, 2) && pow(y - y0, 2) + pow(x - x0, 2) >= pow(rayon-10, 2)) {
					image.pixel(x, y) = glm::vec3{1,1,1};
				}
			
    		}    
	}


    

    image.save("output/cercle.png");
}