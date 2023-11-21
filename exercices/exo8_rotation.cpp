#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image resultat{image.height(), image.width()};
	sil::Image result{resultat};
    
    for (int x{0}; x < image.width(); x++)
	{
    	for (int y{0}; y < image.height(); y++)
    		{
        	resultat.pixel(y,x) = image.pixel(x,y);
    		}    
	}

	for (int x{0}; x < resultat.width(); x++)
	{
    	for (int y{0}; y < resultat.height(); y++)
    		{
        	result.pixel(x,y) = resultat.pixel(resultat.width()-1-x,y);
    		}    
	}

    

    result.save("output/rotation.png");
}