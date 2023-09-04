#include "Manager.h"
#include <ctime>
#include <cstdlib>

void Manager::Init_Menu()
{
	//Especificaciones de la ventana
	this->ventana = nullptr;

	this->video_mode.height = 854;
	this->video_mode.width = 480;

	this->ventana = new sf::RenderWindow(this->video_mode, "Capitán Kloosman", sf::Style::Default);

	//Carga la fuente utilizada en la ventana
	this->font.loadFromFile("Fonts\\BrunoAceSC-Regular.ttf");

	//Vector con las opciones del MENU PRINCIPAL
	sf::Color caqui = sf::Color(62, 74, 60);

	this->main_menu[0].setFont(font);
	this->main_menu[0].setFillColor(sf::Color::Cyan);
	this->main_menu[0].setString("Jugar");
	this->main_menu[0].setCharacterSize(30);
	this->main_menu[0].setPosition(182, 520);

	this->main_menu[1].setFont(font);
	this->main_menu[1].setFillColor(caqui);
	this->main_menu[1].setString("Maximos Puntajes");
	this->main_menu[1].setCharacterSize(20);
	this->main_menu[1].setPosition(125, 580);

	this->main_menu[3].setFont(font);
	this->main_menu[3].setFillColor(caqui);
	this->main_menu[3].setString("Salir");
	this->main_menu[3].setCharacterSize(15);
	this->main_menu[3].setPosition(215, 685);

	this->main_menu[4].setFont(font);
	this->main_menu[4].setFillColor(caqui);
	this->main_menu[4].setString("By");
	this->main_menu[4].setCharacterSize(10);
	this->main_menu[4].setPosition(231, 795);

	this->main_menu[5].setFont(font);
	this->main_menu[5].setFillColor(caqui);
	this->main_menu[5].setString("Nicolas rodriguez - Sanchez Facundo");
	this->main_menu[5].setCharacterSize(10);
	this->main_menu[5].setPosition(110, 810);

	this->main_menu[6].setFont(font);
	this->main_menu[6].setFillColor(caqui);
	this->main_menu[6].setString("Moscatelli Tobias - Alvarez Leandro");
	this->main_menu[6].setCharacterSize(10);
	this->main_menu[6].setPosition(112, 825);


	//Vector con los distintos niveles
	this->menu_niveles[0].setFont(font);
	this->menu_niveles[0].setFillColor(sf::Color::Cyan);
	this->menu_niveles[0].setString("Primer nivel");
	this->menu_niveles[0].setCharacterSize(30);
	this->menu_niveles[0].setPosition(128, 302);

	this->menu_niveles[1].setFont(font);
	this->menu_niveles[1].setFillColor(caqui);
	this->menu_niveles[1].setString("Segundo nivel");
	this->menu_niveles[1].setCharacterSize(27);
	this->menu_niveles[1].setPosition(122, 392);

	this->menu_niveles[2].setFont(font);
	this->menu_niveles[2].setFillColor(caqui);
	this->menu_niveles[2].setString("Tercer nivel");
	this->menu_niveles[2].setCharacterSize(27);
	this->menu_niveles[2].setPosition(133, 478);

	this->menu_niveles[3].setFont(font);
	this->menu_niveles[3].setFillColor(caqui);
	this->menu_niveles[3].setString("regresar");
	this->menu_niveles[3].setCharacterSize(18);
	this->menu_niveles[3].setPosition(186, 742);

	this->menu_niveles[4].setFont(font);
	this->menu_niveles[4].setFillColor(caqui);
	this->menu_niveles[4].setString("Enter para Regresar");
	this->menu_niveles[4].setCharacterSize(18);
	this->menu_niveles[4].setPosition(38, 807);

	//Variable que recorre el menu para elegir la opción
	this->main_menu_selected = 0;

	if (!this->textura[0].loadFromFile("resources/main_menu.png"))
	{
		std::cout << "No se cargo el fondo" << std::endl;
	}
	this->sprite[0].setTexture(this->textura[0]);
	if (!this->textura[1].loadFromFile("resources/Kloosman.png"))
	{
		std::cout << "No se cargo el fondo" << std::endl;
	}
	this->sprite[1].setTexture(this->textura[1]);
	this->sprite[1].scale(0.5f, 0.5f);
	this->sprite[1].setPosition(800.f, -200.f);
	if (!this->textura[2].loadFromFile("resources/nombre_menu.png"))
	{
		std::cout << "No se cargo el fondo" << std::endl;
	}
	this->sprite[2].setTexture(this->textura[2]);
	if (!this->textura[3].loadFromFile("resources/nivel_menu.png"))
	{
		std::cout << "No se cargo el fondo" << std::endl;
	}
	this->sprite[3].setTexture(this->textura[3]);
	
	///Reproducir Musica
	sonido.ReproducirMusicaFondo();
	BandMusica = true;
	///Reproducir Sonido
	sonido.ReproducirGentes();
}

Manager::Manager()
{
	this->Init_Menu();
}

Manager::~Manager()
{
	delete this->ventana;
}

const bool Manager::Ventana_Esta_Abierta() const
{
	return this->ventana->isOpen();
}

void Manager::Actualizar()
{
	menu_niveles[3].setPosition(186, 742);

	MoverKlooster();
	
	//Siempre que haya un evento se mantiene el While
	while (this->ventana->pollEvent(this->evento))
	{
		//Checkea el tipo de evento
		switch (this->evento.type)
		{
			//La "X" de la ventana es para cerrar
		case sf::Event::Closed:
			this->ventana->close();
			break;

		case sf::Event::KeyPressed:
			//"Escape" es para cerrar
			if (this->evento.key.code == sf::Keyboard::Escape)
			{
				this->ventana->close();
				break;
			}
			//Con la fechita para arriba subimos
			else if (this->evento.key.code == sf::Keyboard::Up)
			{
				sonido.ReproducirSeleccion(1);
				this->Up(1);
				break;
			}
			//Con la fechita para abajo, bajamos
			else if (this->evento.key.code == sf::Keyboard::Down)
			{
				sonido.ReproducirSeleccion(1);
				this->Down(1);
				break;
			}
			else if (this->evento.key.code == sf::Keyboard::Return)
			{
				int x = this->MainMenuPressed();

				//JUGAR
				if (x == 0)
				{	
					this->IniciarJuego();
					break;
				}
				//MAYORES PUNTAJES
				if (x == 1)
				{
					sonido.ReproducirSeleccion(4);
					RankingDePuntajes();
					break;
				}
				//SALIR
				if (x == 3) 
				{
					this->ventana->close();
					break;
				}
			}
		}
	}

	this->ventana->clear();

	this->ventana->draw(this->sprite[0]);

	this->DibujarMenu(ventana, 1);

	this->ventana->draw(this->sprite[1]);

	this->ventana->display();
}

int Manager::MainMenuPressed()
{
	return main_menu_selected;
}

void Manager::Up(int tipo_de_menu)
{
	sf::Color caqui = sf::Color(62, 74, 60);

	if (tipo_de_menu == 1)
	{
		if (main_menu_selected >= 0)
		{
			main_menu[main_menu_selected].setFillColor(caqui);

			main_menu_selected--;

			if (main_menu_selected == 2)
			{
				main_menu_selected = 1;
			}
			if (main_menu_selected == -1)
			{
				main_menu_selected = 3;
			}

			main_menu[main_menu_selected].setFillColor(sf::Color::Cyan);
		}
	}
	if (tipo_de_menu == 2)
	{
		if (main_menu_selected >= 0)
		{
			menu_niveles[main_menu_selected].setFillColor(caqui);

			main_menu_selected--;

			if (main_menu_selected == -1)
			{
				main_menu_selected = 3;
			}

			this->menu_niveles[main_menu_selected].setFillColor(sf::Color::Cyan);
		}
	}

}

void Manager::Down(int tipo_de_menu)
{
	sf::Color caqui = sf::Color(62, 74, 60);
	if (tipo_de_menu == 1)
	{
		if (main_menu_selected + 1 <= max_main_menu)
		{
			main_menu[main_menu_selected].setFillColor(caqui);
			main_menu_selected++;
			if (main_menu_selected == 2)
			{
				main_menu_selected = 3;
			}

			if (main_menu_selected == 4)
			{
				main_menu_selected = 0;
			}
			main_menu[main_menu_selected].setFillColor(sf::Color::Cyan);
		}
	}
	if (tipo_de_menu == 2)
	{
		if (main_menu_selected + 1 <= max_main_menu)
		{
			menu_niveles[main_menu_selected].setFillColor(caqui);

			main_menu_selected++;

			if (main_menu_selected == 4)
			{
				main_menu_selected = 0;
			}

			menu_niveles[main_menu_selected].setFillColor(sf::Color::Cyan);
		}
	}
}

void Manager::DibujarMenu(sf::RenderWindow*& ventana, int tipo_de_menu)
{
	if (tipo_de_menu == 1)
	{
		for (int i = 0; i < max_main_menu; i++)
		{
			ventana->draw(main_menu[i]);
		}
	}
	if (tipo_de_menu == 2)
	{
		for (int i = 0; i < max_main_menu; i++)
		{
			if (i != 4)
			{
				this->ventana->draw(menu_niveles[i]);	
			}
		}
	}
}

void Manager::IniciarJuego()
{
	main_menu_selected = 0;

	Jugadores Jugador;

	while (Ventana_Esta_Abierta())
	{
		while (this->ventana->pollEvent(this->evento))
		{
			if (!BandMusica) 
			{
				sonido.Reanudar();
				BandMusica = true;
			}

			switch (this->evento.type)
			{
				case sf::Event::Closed:
					this->ventana->close();
					break;

				case sf::Event::KeyPressed:
					if (this->evento.key.code == sf::Keyboard::Escape)
					{
						this->ventana->close();
						break;
					}

					else if (this->evento.key.code == sf::Keyboard::Up)
					{
						sonido.ReproducirSeleccion(1);
						this->Up(2);
						break;
					}
					else if (this->evento.key.code == sf::Keyboard::Down)
					{
						sonido.ReproducirSeleccion(1);
						this->Down(2);
						break;
					}
					else if (this->evento.key.code == sf::Keyboard::Return)
					{
						if (main_menu_selected == 0)
						{
							if (!IngresarNombre(Jugador))
							{
								std::cout << "No se cargo nombre... " << std::endl;
								return;
							}

							sonido.ReproducirSeleccion(4);
							sonido.PausarMusica();
							BandMusica = false;

							this->ventana->setVisible(false);
							Juego instancia_juego;
							instancia_juego.primer_nivel(Jugador);
							this->ventana->setVisible(true);
						}
						if (main_menu_selected == 1)
						{
							if (!IngresarNombre(Jugador))
							{
								std::cout << "No se cargo nombre... " << std::endl;
								return;
							}

							sonido.ReproducirSeleccion(4);
							sonido.PausarMusica();
							BandMusica = false;

							this->ventana->setVisible(false);
							Juego instancia_juego;
							instancia_juego.segundo_nivel(Jugador);
							this->ventana->setVisible(true);
						}
						if (main_menu_selected == 2)
						{
							if (!IngresarNombre(Jugador))
							{
								std::cout << "No se cargo nombre... " << std::endl;
								return;
							}

							sonido.ReproducirSeleccion(4);
							sonido.PausarMusica();
							BandMusica = false;

							this->ventana->setVisible(false);
							Juego instancia_juego;
							instancia_juego.tercer_nivel(Jugador);
							this->ventana->setVisible(true);
						}
						if (main_menu_selected == 3)
						{
							sonido.ReproducirSeleccion(4);
							main_menu_selected = 0; 
							return;
						}
					}
			}
			this->ventana->clear();

			this->ventana->draw(this->sprite[3]);

			this->DibujarMenu(ventana, 2);

			this->ventana->display();
		}
	}
}

bool Manager::IngresarNombre(Jugadores& _jugador)
{
	sf::Text texto;
	texto.setFont(font);
	texto.setFillColor(sf::Color(62, 74, 60));
	texto.setString("Ingrese su nombre");
	texto.setCharacterSize(35);
	texto.setPosition(40, 338);

	sf::Text texto1;
	texto1.setFont(font);
	texto1.setFillColor(sf::Color(62, 74, 60));
	texto1.setString("Enter para continuar");
	texto1.setCharacterSize(18);
	texto1.setPosition(117, 372);

	sf::Text textBox;
	textBox.setFont(font);
	textBox.setFillColor(sf::Color(62, 74, 60));
	textBox.setCharacterSize(20);
	textBox.setPosition(80, 467);

	sf::String _nombreDeJugador;

	while (Ventana_Esta_Abierta())
	{
		this->ventana->clear();

		while (this->ventana->pollEvent(this->evento))
		{
			switch (this->evento.type)
			{
				case sf::Event::Closed:

					this->ventana->close();
					break;

				case sf::Event::KeyPressed:

					if (this->evento.key.code == sf::Keyboard::Escape)
					{
						return false;
					}
					if (this->evento.key.code == sf::Keyboard::Enter)
					{
						if (_nombreDeJugador.getSize() > 1) 
						{
							_jugador.set_nombre(_nombreDeJugador);
							return true;
						}
						else 
						{
							return false;
						}
							
					}
					
				case sf::Event::TextEntered:

					if (this->evento.type == sf::Event::TextEntered)
					{
						if (this->evento.text.unicode < 256)
						{
							if (this->evento.text.unicode == 8 && _nombreDeJugador.getSize() > 0)
							{
								sonido.ReproducirSeleccion(2);
								_nombreDeJugador.erase(_nombreDeJugador.getSize() - 1, 1);
							}
							else if (_nombreDeJugador.getSize() < 15)
							{
								sonido.ReproducirSeleccion(4);
								_nombreDeJugador += static_cast<char>(this->evento.text.unicode);
							}
							
							else
							{
								sonido.ReproducirSeleccion(3);
							}
							textBox.setString(_nombreDeJugador);
						}
					}
			}
		}
		this->ventana->draw(this->sprite[2]);

		this->ventana->draw(texto);

		this->ventana->draw(texto1);

		this->ventana->draw(textBox);

		this->ventana->display();
	}
	return false;
}

void Manager::RankingDePuntajes()
{
	sf::Vector2f nombre(70.f, 180.f);
	sf::Vector2f puntaje(370.f, nombre.y);
	float separacion = 63.f;

	sf::Color caqui = sf::Color(62, 74, 60);

	//Creo los textos y les paso los nombres de los TRES primeros jugadores y sus respectivos puntajes
	sf::Text *PodioNombres;
	sf::Text *PodioPuntajes;

	sf::Texture textura;
	if (!textura.loadFromFile("resources/max_points.png"))
	{
		std::cout << "RaningDePuntajes No se cargo el fondo" << std::endl;
	}
	sf::Sprite background(textura);

	//CREA UN VECTOR DINAMICO CON TODOS LOS REGISTROS DE JUGADORES
	ArchivoJugadores archivo;
	int cantidad_de_registros = archivo.getCantidadRegistros();

	PodioNombres = new sf::Text[cantidad_de_registros];
	PodioPuntajes = new sf::Text[cantidad_de_registros];

	if (cantidad_de_registros != 0)
	{
		Jugadores *vJugadores;

		vJugadores = new Jugadores[cantidad_de_registros];

		for (int i = 0; i < cantidad_de_registros; i++)
		{
			vJugadores[i] = archivo.leer(i);
		}

		//ORDENA EL VECTOR DE MAYOR A MENOR PUNTAJE
		OrdenarJugadoresxPuntos(vJugadores, cantidad_de_registros);

		//MENSAJES DE NOMBRES Y PUNTOS
		for (int i = 0; i < cantidad_de_registros && i < 10; i++)
		{
			if (i == 0)
			{
				PodioNombres[i].setFont(font);
				PodioNombres[i].setFillColor(caqui);
				PodioNombres[i].setString(vJugadores[i].get_str_nombre());
				PodioNombres[i].setCharacterSize(25);
				PodioNombres[i].setPosition(nombre.x, nombre.y);

				PodioPuntajes[i].setFont(font);
				PodioPuntajes[i].setFillColor(caqui);
				PodioPuntajes[i].setString(std::to_string(vJugadores[i].get_puntaje()));
				PodioPuntajes[i].setCharacterSize(25);
				PodioPuntajes[i].setPosition(puntaje.x, puntaje.y);
			}
			else if (i < 3)
			{
				PodioNombres[i].setFont(font);
				PodioNombres[i].setFillColor(caqui);
				PodioNombres[i].setString(vJugadores[i].get_str_nombre());
				PodioNombres[i].setCharacterSize(25);
				PodioNombres[i].setPosition(nombre.x, nombre.y + separacion);

				PodioPuntajes[i].setFont(font);
				PodioPuntajes[i].setFillColor(caqui);
				PodioPuntajes[i].setString(std::to_string(vJugadores[i].get_puntaje()));
				PodioPuntajes[i].setCharacterSize(25);
				PodioPuntajes[i].setPosition(puntaje.x, puntaje.y + separacion);

				separacion += 63.f;
			}
			else
			{
				PodioNombres[i].setFont(font);
				PodioNombres[i].setFillColor(caqui);
				PodioNombres[i].setString(vJugadores[i].get_str_nombre());
				PodioNombres[i].setCharacterSize(25);
				PodioNombres[i].setPosition(nombre.x - 35, nombre.y + separacion);

				PodioPuntajes[i].setFont(font);
				PodioPuntajes[i].setFillColor(caqui);
				PodioPuntajes[i].setString(std::to_string(vJugadores[i].get_puntaje()));
				PodioPuntajes[i].setCharacterSize(25);
				PodioPuntajes[i].setPosition(puntaje.x, puntaje.y + separacion);

				separacion += 63.f;
			}
		}

		delete[] vJugadores;
	}
		while (Ventana_Esta_Abierta())
		{
			this->ventana->clear();

			while (this->ventana->pollEvent(this->evento))
			{
				switch (this->evento.type)
				{
					case sf::Event::Closed:
						this->ventana->close();
						break;

					case sf::Event::KeyPressed:
						if (this->evento.key.code == sf::Keyboard::Escape)
						{
							return;
						}
						if (this->evento.key.code == sf::Keyboard::Enter)
						{
							sonido.ReproducirSeleccion(4);
							return;
						}
				}
			}

			this->ventana->draw(background);

			this->ventana->draw(menu_niveles[4]);

			for (int i = 0; i < cantidad_de_registros; i++)
			{
				this->ventana->draw(PodioNombres[i]);

				this->ventana->draw(PodioPuntajes[i]);
			}

			this->ventana->display();
	}
}

void Manager::OrdenarJugadoresxPuntos(Jugadores*& _vector, int _tamanio)
{
	int actual, mayor;

	Jugadores aux;
	 
	for (actual = 0; actual < _tamanio - 1; actual++)
	{
		mayor = actual;

		for (int j = actual + 1; j < _tamanio; j++)
		{
			if (_vector[j].get_puntaje() > _vector[mayor].get_puntaje())
			{
				mayor = j;
			}
		}

		aux = _vector[actual];

		_vector[actual] = _vector[mayor];

		_vector[mayor] = aux;
	}
}

void Manager::MoverKlooster()
{
	this->sprite[1].move((-klooster * 0.02f), (-klooster * -0.02f));
	if (this->sprite[1].getPosition().x < -800)
	{
		float random1 = rand() % (800 - 150 + 1) + 150;
		float random2 = rand() % (-200 - -400 - 1) - 400;

		this->sprite[1].setPosition(random1, random2);
	}
}
