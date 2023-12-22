#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image resultat{image.height(), image.width()};
    
    for (int x{0}; x < image.width(); x++)
	{
    	for (int y{0}; y < image.height(); y++)
    		{
                // On peut aussi faire la rotation avec une seule formule:
                resultat.pixel(y, x) = image.pixel(x, image.height() - 1 - y);
    		}    
	}

    result.save("output/rotation.png");
}