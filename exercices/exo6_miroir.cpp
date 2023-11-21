#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image resultat{image};
    
    for (int x{0}; x < image.width(); x++)
	{
    	for (int y{0}; y < image.height(); y++)
    		{
        	resultat.pixel(x,y) = image.pixel(image.width()-1-x,y);
    		}    
	}

    

    resultat.save("output/miroir.png");
}