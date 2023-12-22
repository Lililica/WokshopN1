#include <sil/sil.hpp>


int main()
{
	const sil::Image image{"images/logo.png"};
	sil::Image resultat{image};
	


	
	for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
		{
			glm::vec3 somme{};
			int compteur{};
			for (int i{-10}; i <= 10; i++) {
				for (int j{-10}; j <= 10; j++) {
					if (x + i >= 0 && y + j >= 0 && x + i < image.width() && y + j < image.height()) {
						somme += image.pixel(x + i, y+j);
						

					} 
					compteur++;
					


				}
			}
			glm::vec3 moyenne{somme/static_cast<float>(compteur)};
			resultat.pixel(x,y) = moyenne;
			
		}
	}

	

	resultat.save("output/convolutions.png");
}