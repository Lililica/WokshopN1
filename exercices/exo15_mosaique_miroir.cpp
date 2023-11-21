#include <sil/sil.hpp>
#include <iostream>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image resultat{image.width() * 5, image.height() * 5};
    
	
	
	for (int x{0}; x < resultat.width(); x++)
	{
    	for (int y{0}; y < resultat.height(); y++)
    		{
			int x0{x / image.width()};
			int y0{y / image.height()};
			if (x0 % 2 == 0 && y0 % 2 == 0) {
				resultat.pixel(x,y) = image.pixel(x % image.width(),y % image.height());
			} 
		else	if (x0 % 2 != 0 && y0 % 2 == 0) {
				resultat.pixel(x,y) = image.pixel(image.width() - 1 - x % image.width(),y % image.height());
			}
		else	if (x0 % 2 == 0 && y0 % 2 != 0) {
				resultat.pixel(x,y) = image.pixel(x % image.width(),image.height() - 1 - y % image.height());
			} 
		else	if (x0 % 2 != 0 && y0 % 2 != 0) {
				resultat.pixel(x,y) = image.pixel(image.width() - 1 - x % image.width(),image.height() - 1 - y % image.height());
			}
			else
			{
				std::cout << "HELLO";
			}
    		}   

		
	}

    

    resultat.save("output/mosaique_miroir.png");
}

