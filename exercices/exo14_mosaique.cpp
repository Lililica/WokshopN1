#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image resultat{image.width() * 5, image.height() * 5};
    
    for (int x{0}; x < resultat.width(); x++)
	{
    	for (int y{0}; y < resultat.height(); y++)
    		{
        	resultat.pixel(x,y) = image.pixel(x % image.width(),y % image.height());
    		}    
	}

    

    resultat.save("output/mosaique.png");
}