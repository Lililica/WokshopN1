#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    
    
    for (int x{0}; x < image.width(); x++)
	{
    	for (int y{0}; y < image.height(); y++)
    		{
        	float niv_gris = (image.pixel(x, y).r + image.pixel(x, y).g + image.pixel(x, y).b)/3;
        	image.pixel(x, y) = glm::vec3{niv_gris};
    		}    
	}

    image.save("output/noir_et_blanc.png");
}