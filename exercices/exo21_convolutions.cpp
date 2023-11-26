#include <sil/sil.hpp>


int main()
{
	const sil::Image image{"images/logo.png"};
	sil::Image resultat{image};
	


	
	for (int x{0}; x < image.width(); x++)
	{
		for (int y{0}; y < image.height(); y++)
		{
			float somme_rouges{};
			float somme_verts{};
			float somme_bleus{};
			int compteur{};
			for (int i{-10}; i <= 10; i++) {
				for (int j{-10}; j <= 10; j++) {
					if (x + i >= 0 && y + j >= 0 && x + i < image.width() && y + j < image.height()) {
						somme_rouges += image.pixel(x + i, y+j).r;
						somme_bleus += image.pixel(x + i, y+j).b;
						somme_verts += image.pixel(x + i, y+j).g;
						

					} 
					compteur++;
					


				}
			}
			float moyenne_rouges{somme_rouges/static_cast<float>(compteur)};
			float moyenne_verts{somme_verts/static_cast<float>(compteur)};
			float moyenne_bleus{somme_bleus/static_cast<float>(compteur)};
			resultat.pixel(x,y) = glm::vec3{moyenne_rouges, moyenne_verts, moyenne_bleus};
			
		}
	}

	

	resultat.save("output/convolutions.png");
}