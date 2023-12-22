#include <sil/sil.hpp>
#include <complex>


int main()
{
    sil::Image image{400/*width*/, 400/*height*/};
	
    
    
		 
	for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
    		{
			float x0{static_cast<float>(x)/100 -2};
			float y0{static_cast<float>(y)/100 -2};

			std::complex<float> c{x0, y0};
			std::complex<float> z{0, 0};
			int compteur{0};

			while (compteur < 30) {
				z = z * z + c;
				if (std::abs(z) > 2) {
					break;
				}
				compteur ++;
			}
            float const color = static_cast<float>(compteur)/30; // Plutôt que de faire le calcul à chaque itération de la boucle, on peut ne le faire qu'une seule fois à la fin, ça évite de faire compteur-1 calculs inutiles qui seront écrasés à l'itération suivante

			image.pixel(x, y) = glm::vec3{color};

			
			
			
    		}    
	}


    

    image.save("output/fractale_Mandelbrot.png");
}