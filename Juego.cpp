#include "Juego.h"

void Juego::InitJuego()
{
    //Determina si la bola esta en juego
    this->bool_En_Juego = false;
    //Determina si el juego sigue o no
    this->bool_Fin_Juego = false;
    //Puntos
    this->puntaje_total = 0;
    this->puntaje_mas_alto = 0;
    //Bolas
    this->bolas_restantes = 3;

    ///FUENTE DE TEXTO
    this->fuente_de_texto.loadFromFile("Fonts\\Roboto-Black.ttf");
   
    ///VENTANA
    this->video_mode.width = 720;
    this->video_mode.height = 980;
    this->ventana.create(this->video_mode, "Capitan Kloosman", sf::Style::Default);

    if (!this->textura.loadFromFile("resources/Kloosman.png"))
    {
        std::cout << "No se cargo el fondo" << std::endl;
    }
    this->sprite.setTexture(this->textura);
    this->sprite.scale(0.2f, 0.2f);
    this->sprite.setPosition(800.f, -200.f);

    BandSonido = true;

    
}

Juego::Juego()
{
    InitJuego();
}

std::list<Bola> bolas;
std::list<Bola>::iterator bolasIterador;

//--------------------------------------------------//

void Juego::primer_nivel(Jugadores& _jugador)
{
        ///FONDO DEL NIVEL
        sf::Texture textura;
        sf::Texture textura1;
        sf::Texture textura2;
        if (!textura.loadFromFile("resources/background.png"))
        {
            std::cout << "No se cargo el fondo" << std::endl;
        }
        sf::Sprite background(textura);
        if (!textura1.loadFromFile("resources/game_over.png"))
        {
            std::cout << "No se cargo el fondo" << std::endl;
        }
        sf::Sprite gameOver(textura1);
        if (!textura2.loadFromFile("resources/texture_map.png"))
        {
            std::cout << "No se cargo el fondo" << std::endl;
        }

        sf::Sprite textureMap(textura2);
       
        sonido.ReproducirArranque();
        sonido.ReproducirMusicaNivel1();

        ///DECLARACION DE COLORES DEL NIVEL
        sf::Color Azul = sf::Color(8, 68, 112);
        sf::Color blanco = sf::Color(235, 235, 235);
        sf::Color rosa = sf::Color(200, 90, 129);
        sf::Color gris = sf::Color(39, 36, 36);

        ///MENSAJES EN PANTALLA
        sf::Text str_maximo_puntaje = sf::Text("~ Mejor puntaje: " + std::to_string(puntaje_mas_alto) + "...", fuente_de_texto, 18);
        str_maximo_puntaje.setFillColor(blanco);
        str_maximo_puntaje.setPosition(200, 30);

        sf::Text puntos = sf::Text("Puntos", fuente_de_texto, 35);
        puntos.setFillColor(blanco);
        puntos.setPosition(448, 28);

        sf::Text str_puntaje = sf::Text(std::to_string(puntaje_total), fuente_de_texto, 30);
        str_puntaje.setFillColor(blanco);
        str_puntaje.setPosition(445, 72);

        sf::Text bola = sf::Text("Bola", fuente_de_texto, 25);
        bola.setFillColor(rosa);
        bola.setPosition(616, 22);

        sf::Text str_bolas_restantes = sf::Text(std::to_string(bolas_restantes), fuente_de_texto, 30);
        str_bolas_restantes.setFillColor(blanco);
        str_bolas_restantes.setPosition(634,64);

        ///LISTAS E ITERADORES DE OBJETOS (Almacenan los Objetos)
        std::list<Rectangulo> lRectangulos;
        std::list<Rectangulo>::iterator lRectangulosIt;
        std::list<HitBox> lHitbox;
        std::list<HitBox>::iterator lHitboxIt;
        std::list<EnemigoRedondo> lEnemigosRedondos;
        std::list<EnemigoRedondo>::iterator lEnemigosRedondosIt;
        std::list<EnemigoRectangular> lEnemigosRectangulares;
        std::list<EnemigoRectangular>::iterator lEnemigosRectangularesIt; 

        //MUROS DEL JUEGO
        Rectangulo muro_superior = Rectangulo(sf::Vector2f(18.f, 7.8f) /*ORIGEN*/, sf::Vector2f(17.f, 0.4f)/*EXTENSION*/, gris/*COLOR*/);

        Rectangulo muro_izquierdo = Rectangulo(sf::Vector2f(0.5f, 27.5f)/*ORIGEN*/, sf::Vector2f(0.7f, 30.f)/*EXTENSION*/, gris/*COLOR*/);

        Rectangulo muro_derecho = Rectangulo(sf::Vector2f(35.5f, 27.5f), sf::Vector2f(0.7f, 30.f), gris);

        Rectangulo esquina_superior_derecha = Rectangulo(sf::Vector2f(34.8f, 8.2f)/*POSICION*/, sf::Vector2f(0.5f, 0.5f)/*EXTENSION MEDIA*/, gris/*COLOR*/);

        Rectangulo tunel = Rectangulo(sf::Vector2f(32.9f, 40.f), sf::Vector2f(0.4f, 23.f), gris);

        //ENEMIGOS REDONDOS - BUMPERS DEL JUEGO
        EnemigoRedondo eRedondo1 = EnemigoRedondo(sf::Vector2f(17.f, 12.f)/*Posicion*/, 1.2f/*Radio*/, 50/*Puntos*/, gris/*Color*/);

        EnemigoRedondo eRedondo2 = EnemigoRedondo(sf::Vector2f(17.f, 24.f), 1.2f, 50, gris);

        EnemigoRedondo eRedondo3 = EnemigoRedondo(sf::Vector2f(10.2f, 18.f), 1.2f, 100, gris);

        EnemigoRedondo eRedondo4 = EnemigoRedondo(sf::Vector2f(23.8f, 18.f), 1.2f, 100, gris);

        EnemigoRedondo eRedondoGrande1 = EnemigoRedondo(sf::Vector2f(17.f, 18.f), 2.f, 10, gris);

        EnemigoRedondo eRedondoGrande2 = EnemigoRedondo(sf::Vector2f(6.f, 25.f), 2.f, 25, gris);

        EnemigoRedondo eRedondoGrande3 = EnemigoRedondo(sf::Vector2f(28.f, 25.f), 2.f, 25, gris);


        //FLIPPERS
        Flippers FlipperIzquierdo(sf::Vector2f(11.5f, 44.1f)/*Posicion*/, 0.6f/*Angulo*/, sf::Vector2f(4.75f, 0.5f)/*Extension media*/, Azul/*Color*/, true/*EnladoIzquierdo*/);

        Flippers FlipperDerecho(sf::Vector2f(21.9f, 44.1f)/*Posicion*/, 0.6f/*Angulo*/, sf::Vector2f(4.75f, 0.5f)/*Extension media*/, Azul/*Color*/, false/*EnladoIzquierdo*/);

        //RAMPAS AL COSTADO DE LOS FLIPPERS
        HitBox rampaIzquierda = HitBox(sf::Vector2f(5.5f, 40.f), sf::Vector2f(6.f, 0.5f), 0.6f, gris);

        HitBox rampaDerecha = HitBox(sf::Vector2f(27.9f, 40.f), sf::Vector2f(6.f, 0.5f), -0.6f, gris);

        //ENEMIGOS RECTANGULARES (Los dos finitos de la pantalla)
        EnemigoRectangular eRectangular1 = EnemigoRectangular(sf::Vector2f(10.4f, 36.3f), sf::Vector2f(0.5f, 2.9f), -0.7f, 0, gris);

        EnemigoRectangular eRectangular2 = EnemigoRectangular(sf::Vector2f(23.f, 36.3f), sf::Vector2f(0.5f, 2.9f), 0.7f, 0, gris);

        EnemigoRectangular eRectangular3 = EnemigoRectangular(sf::Vector2f(5.f, 11.5f), sf::Vector2f(0.5f, 2.f), 0.65f, 0, gris);

        ///A�ADE LOS OBJETOS CREADOS A LAS LISTAS
        lEnemigosRectangulares.push_back(eRectangular1);    
        lEnemigosRectangulares.push_back(eRectangular2);
        lEnemigosRectangulares.push_back(eRectangular3);

        lEnemigosRedondos.push_back(eRedondo1);
        lEnemigosRedondos.push_back(eRedondo2);
        lEnemigosRedondos.push_back(eRedondo3);
        lEnemigosRedondos.push_back(eRedondo4);
        lEnemigosRedondos.push_back(eRedondoGrande1);
        lEnemigosRedondos.push_back(eRedondoGrande2);
        lEnemigosRedondos.push_back(eRedondoGrande3);

        lRectangulos.push_back(muro_superior);
        lRectangulos.push_back(muro_izquierdo);
        lRectangulos.push_back(muro_derecho);
        lRectangulos.push_back(esquina_superior_derecha);
        lRectangulos.push_back(tunel);

        lHitbox.push_back(rampaIzquierda);
        lHitbox.push_back(rampaDerecha);

        ///RELOJ PARA USAR FUNCIONES DE TIEMPO PARA EL FRAMERATE
        sf::Clock clock;

        ///WHILE PARA CONTROLAR QUE LA VENTANA EST� ABIERTA
        while (this->ventana.isOpen())
        {
            ///WHILE PARA CONTROLAR QUE HAYAN EVENTOS Y RECIBIR LA ACCION DEL JUGADOR
            while (this->ventana.pollEvent(this->evento))
            {
                if (this->evento.type == sf::Event::Closed) //Cierra la ventana
                {
                    sonido.DetenerMusica();

                    this->ventana.close();
                }
                else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape) //Cierra la ventana
                {

                    sonido.DetenerMusica();

                    this->ventana.close();
                }
                else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Space) //Crea y lanza la bola
                {

                    if (!bool_En_Juego && !bool_Fin_Juego)
                    {
                        //Parametros de la bola
                        sf::Vector2f posicion = sf::Vector2f(34.f, 50.f);
                        sf::Vector2f velocidad = sf::Vector2f(0.f, -60.f);
                        sf::Vector2f aceleracion = sf::Vector2f(0.f, 30.f);

                        //Crea la bola
                        Bola bola = Bola(posicion, velocidad, aceleracion, 0.9f);

                        bola.set_color(sf::Color::White);

                        //Agrega la bola a la lista
                        bolas.push_back(bola);

                        //Indica que hay una bola en juego
                        bool_En_Juego = true;

                        sonido.ReproducirLanzamiento();
                    }
                }
                else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Z)
                {
                    sonido.ReproducirFlipper();
                    FlipperIzquierdo.Mover("arriba");
                }
                else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::X)
                {
                    sonido.ReproducirFlipper();
                    FlipperDerecho.Mover("arriba");
                }
                else if (this->evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::Z)
                {
                    FlipperIzquierdo.Mover("abajo");
                }
                else if (this->evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::X)
                {
                    FlipperDerecho.Mover("abajo");
                }
            }

            this->ventana.clear(sf::Color::Black);

            ///SE UTILIZAN FUNCIONES DE TIEMPO PARA EL FLUJO DEL JUEGO
            sf::Time intervalo_tiempo = clock.getElapsedTime();

            const unsigned int tiempo_transcurrido = intervalo_tiempo.asMilliseconds();

            if (tiempo_transcurrido >= 10 && !bool_Fin_Juego)
            {
                const float fSegundos = intervalo_tiempo.asSeconds();

                ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA OBJETO
                for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
                {
                    for (auto p = bolas.begin(); p != bolas.end(); p++)
                    {
                        if (bolasIterador != p)
                        {
                            //inicializa el objeto colision con el constructor 
                            Colisiones colision = Colisiones(&bolasIterador->cuerpo, &p->cuerpo);

                            if (colision.CirculoVsCirculo())
                            {
                                colision.correctPosition();

                                colision.aplicarImpulso();
                            }
                        }
                    }

                    ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA ENEMIGO REDONDO
                    for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt)
                    {
                        Colisiones colision = Colisiones(&lEnemigosRedondosIt->cuerpo, &bolasIterador->cuerpo);

                        if (colision.CirculoVsCirculo())
                        {
                            sonido.ReproducirChoque();

                            puntaje_total += lEnemigosRedondosIt->get_puntos();

                            colision.correctPosition();

                            colision.aplicarImpulso();
                        }
                    }

                    ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA ENEMIGO RECTANGULAR
                    for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
                    {
                        Colisiones colision = Colisiones(&lEnemigosRectangularesIt->cuerpo, &bolasIterador->cuerpo);

                        if (colision.CirculoVsHitbox())
                        {
                            puntaje_total += lEnemigosRectangularesIt->get_puntos();

                            colision.correctPosition();

                            colision.aplicarImpulso();
                        }
                    }

                    ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA OBJETO RECTANGULAR
                    for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
                    {
                        Colisiones colision = Colisiones(&lRectangulosIt->cuerpo, &bolasIterador->cuerpo);

                        if (colision.CirculoVsRectangulo())
                        {
                            colision.correctPosition();

                            colision.aplicarImpulso();
                        }
                    }

                    //FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA RAMPA
                    for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
                    {
                        Colisiones colision = Colisiones(&lHitboxIt->cuerpo, &bolasIterador->cuerpo);

                        if (colision.CirculoVsHitbox())
                        {
                            colision.correctPosition();

                            colision.aplicarImpulso();

                            colision.aplicarCaida();
                        }
                    }

                    /*
                        TOMA A UN FLIPPER COMO CUERPO A Y A UNA BOLA COMO CUERPO B.
                        CHECKEA SI SE ESTAN TOCANDO, CORRIGE LA POSICION Y LE APLICA EL IMPULSO A LA BOLA.
                    */

                    Colisiones FlipperIzquierdo_colision = Colisiones(&FlipperDerecho.cuerpo, &bolasIterador->cuerpo);

                    if (FlipperIzquierdo_colision.CirculoVsHitbox())
                    {
                        FlipperIzquierdo_colision.correctPosition();

                        FlipperIzquierdo_colision.aplicarImpulso();

                        FlipperIzquierdo_colision.aplicarCaida();
                    }

                    Colisiones FlipperDerecho_colision = Colisiones(&FlipperIzquierdo.cuerpo, &bolasIterador->cuerpo);

                    if (FlipperDerecho_colision.CirculoVsHitbox())
                    {
                        FlipperDerecho_colision.correctPosition();

                        FlipperDerecho_colision.aplicarImpulso();

                        FlipperDerecho_colision.aplicarCaida();
                    }

                    //ACTUALIZA LAS PROPIEDADES DE LA BOLA (POSICION, VELOCIDAD Y ACELERACION)
                    bolasIterador->cuerpo.updateBola(fSegundos);
                }

                //MUEVE A LOS FLIPPERS
                FlipperDerecho.cuerpo.update(fSegundos);
                FlipperDerecho.rotarFlipper();

                FlipperIzquierdo.cuerpo.update(fSegundos);
                FlipperIzquierdo.rotarFlipper();

                clock.restart();
            }

            this->ventana.draw(background);

            //ACTUALIZA MENSAJES EN PANTALLA
            str_puntaje.setString(std::to_string(puntaje_total));

            str_bolas_restantes.setString(std::to_string(bolas_restantes));

            str_maximo_puntaje.setString("~ Mejor puntaje: " + std::to_string(puntaje_mas_alto) + "...");
        
            restar_bola();

            if (bolas_restantes <= 0)
            {
                bool_Fin_Juego = true;
            }
            if (puntaje_total > puntaje_mas_alto)
            {
                puntaje_mas_alto = puntaje_total;
            }

            /*
                A PARTIR DE ACA SE DIBUJAN LOS OBJETOS HASTA
                    "if (bool_Fin_Juego)"
            */
            this->ventana.draw(FlipperDerecho);
            this->ventana.draw(FlipperIzquierdo);

            for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
            {
                this->ventana.draw(*lRectangulosIt);
            }

            for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
            {
                this->ventana.draw(*lHitboxIt);
            }

            for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
            {
                this->ventana.draw(*bolasIterador);
            }

            for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt)
            {
                this->ventana.draw(*lEnemigosRedondosIt);
            }

            for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
            {
                this->ventana.draw(*lEnemigosRectangularesIt);
            }

            this->ventana.draw(str_maximo_puntaje);
            this->ventana.draw(puntos);
            this->ventana.draw(str_puntaje);
            this->ventana.draw(bola);
            this->ventana.draw(str_bolas_restantes);
            this->ventana.draw(textureMap);

            if (bool_Fin_Juego)
            {
               
                bool_En_Juego = false;

                this->ventana.draw(gameOver);

                if (BandSonido) {
                    sonido.ReproducirGameOver();
                    BandSonido = false;
                }
                float  fDelay = sf::seconds(6.0).asSeconds();

                sf::Time now = clock.getElapsedTime();

                
                if (puntaje_total > 0)
                {
                    _jugador.set_puntaje(puntaje_total);
                }

                if (now.asSeconds() >= fDelay)
                {
                    BandSonido = true;
                    puntaje_total = 0;
                    bolas_restantes = 3;
                    bool_Fin_Juego = false;
                    clock.restart();
                }
            }

            this->ventana.display();
        }
        ///Guarda el puntaje una vez el jugador pierde
        ArchivoJugadores archivo;
        if (_jugador.get_puntaje() > 0)
        {
            if (archivo.guardar(_jugador))
            {
                std::cout << _jugador.get_nombre() << " PUNTOS " << _jugador.get_puntaje() << std::endl;
                std::cout << "Jugador guardado correctamente!" << std::endl;
            }
        }
}

void Juego::segundo_nivel(Jugadores& _jugador)
{
    ///FONDO DEL NIVEL
    sf::Texture textura;
    sf::Texture textura1;
    sf::Texture textura2;
    if (!textura.loadFromFile("resources/background2.png"))
    {
        std::cout << "No se cargo el fondo" << std::endl;
    }
    sf::Sprite background(textura);
    if (!textura1.loadFromFile("resources/game_over.png"))
    {
        std::cout << "No se cargo el fondo" << std::endl;
    }
    sf::Sprite gameOver(textura1);
    if (!textura2.loadFromFile("resources/texture_map2.png"))
    {
        std::cout << "No se cargo el fondo" << std::endl;
    }
    sf::Sprite textureMap(textura2);

    sonido.ReproducirArranque();
    sonido.ReproducirMusicaNivel2();
    
    ///DECLARACION DE COLORES DEL NIVEL
    sf::Color Azul = sf::Color(8, 68, 112);
    sf::Color blanco = sf::Color(235, 235, 235);
    sf::Color rosa = sf::Color(200, 90, 129);
    sf::Color gris = sf::Color(39, 36, 36);

    ///MENSAJES EN PANTALLA
    sf::Text str_maximo_puntaje = sf::Text("~ Mejor puntaje: " + std::to_string(puntaje_mas_alto) + "...", fuente_de_texto, 18);
    str_maximo_puntaje.setFillColor(blanco);
    str_maximo_puntaje.setPosition(200, 30);

    sf::Text puntos = sf::Text("Puntos", fuente_de_texto, 35);
    puntos.setFillColor(blanco);
    puntos.setPosition(448, 28);

    sf::Text str_puntaje = sf::Text(std::to_string(puntaje_total), fuente_de_texto, 30);
    str_puntaje.setFillColor(blanco);
    str_puntaje.setPosition(445, 72);

    sf::Text bola = sf::Text("Bola", fuente_de_texto, 25);
    bola.setFillColor(rosa);
    bola.setPosition(616, 22);

    sf::Text str_bolas_restantes = sf::Text(std::to_string(bolas_restantes), fuente_de_texto, 30);
    str_bolas_restantes.setFillColor(blanco);
    str_bolas_restantes.setPosition(634, 64);

    ///LISTAS E ITERADORES DE OBJETOS (Almacenan los Objetos)
    std::list<Rectangulo> lRectangulos;
    std::list<Rectangulo>::iterator lRectangulosIt;
    std::list<HitBox> lHitbox;
    std::list<HitBox>::iterator lHitboxIt;
    std::list<EnemigoRedondo> lEnemigosRedondos;
    std::list<EnemigoRedondo>::iterator lEnemigosRedondosIt;
    std::list<EnemigoRectangular> lEnemigosRectangulares;
    std::list<EnemigoRectangular>::iterator lEnemigosRectangularesIt;

    //MUROS DEL JUEGO
    Rectangulo muro_superior = Rectangulo(sf::Vector2f(18.f, 7.8f) /*ORIGEN*/, sf::Vector2f(17.f, 0.4f)/*EXTENSION*/, gris/*COLOR*/);

    Rectangulo muro_izquierdo = Rectangulo(sf::Vector2f(0.5f, 27.5f)/*ORIGEN*/, sf::Vector2f(0.7f, 30.f)/*EXTENSION*/, gris/*COLOR*/);

    Rectangulo muro_derecho = Rectangulo(sf::Vector2f(35.5f, 27.5f), sf::Vector2f(0.7f, 30.f), gris);

    Rectangulo esquina_superior_derecha = Rectangulo(sf::Vector2f(34.8f, 8.2f)/*POSICION*/, sf::Vector2f(0.5f, 0.5f)/*EXTENSION MEDIA*/, gris/*COLOR*/);

    Rectangulo esquina_superior_izquierda = Rectangulo(sf::Vector2f(1.f, 8.2f)/*POSICION*/, sf::Vector2f(0.5f, 0.5f)/*EXTENSION MEDIA*/, gris/*COLOR*/);

    Rectangulo tunel = Rectangulo(sf::Vector2f(32.9f, 40.f), sf::Vector2f(0.4f, 15.f), gris);

    //ENEMIGOS REDONDOS - BUMPERS DEL JUEGO
    EnemigoRedondo eRedondo1 = EnemigoRedondo(sf::Vector2f(22.5f, 25.f), 1.f, 100, gris);

    EnemigoRedondo eRedondo2 = EnemigoRedondo(sf::Vector2f(28.f, 18.f), 1.2f, 10, gris);

    EnemigoRedondo eRedondo3 = EnemigoRedondo(sf::Vector2f(12.5f, 39.f), 1.3f, 25, gris);

    EnemigoRedondo eRedondo4 = EnemigoRedondo(sf::Vector2f(6.f, 35.f), 1.4f, 50, gris);

    EnemigoRedondo eRedondo5 = EnemigoRedondo(sf::Vector2f(20.9f, 39.f), 1.5f, 25, gris);

    EnemigoRedondo eRedondo6 = EnemigoRedondo(sf::Vector2f(17.f, 18.f), 1.5f, 10, gris);

    EnemigoRedondo eRedondo7 = EnemigoRedondo(sf::Vector2f(13.f, 26.f), 1.6f, 50, gris);

    EnemigoRedondo eRedondo8 = EnemigoRedondo(sf::Vector2f(21.f, 12.f), 1.6f, 20, gris);

    EnemigoRedondo eRedondo9 = EnemigoRedondo(sf::Vector2f(27.4f, 35.f), 1.8f, 50, gris);

    EnemigoRedondo eRedondo10 = EnemigoRedondo(sf::Vector2f(7.f, 12.f), 2.f, 100, gris);

    //FLIPPERS
    Flippers FlipperIzquierdoInf(sf::Vector2f(11.5f, 46.1f)/*Posicion*/, 0.6f/*Angulo*/, sf::Vector2f(4.5f, 0.5f)/*Extension media*/, Azul/*Color*/, true/*EnladoIzquierdo*/);

    Flippers FlipperDerechoInf(sf::Vector2f(21.9f, 46.1f)/*Posicion*/, 0.6f/*Angulo*/, sf::Vector2f(4.5f, 0.5f)/*Extension media*/, Azul/*Color*/, false/*EnladoIzquierdo*/);

    Flippers FlipperIzquierdoSup(sf::Vector2f(4.5f, 30.f)/*Posicion*/, 0.6f/*Angulo*/, sf::Vector2f(4.4f, 0.5f)/*Extension media*/, Azul/*Color*/, true/*EnladoIzquierdo*/);

    Flippers FlipperDerechoSup(sf::Vector2f(28.9f, 30.f)/*Posicion*/, 0.6f/*Angulo*/, sf::Vector2f(4.4f, 0.5f)/*Extension media*/, Azul/*Color*/, false/*EnladoIzquierdo*/);

    //RAMPAS AL COSTADO DE LOS FLIPPERS
    HitBox rampaIzquierdaInf = HitBox(sf::Vector2f(5.5f, 42.f), sf::Vector2f(6.f, 0.5f), 0.6f, gris);

    HitBox rampaDerechaInf = HitBox(sf::Vector2f(27.9f, 42.f), sf::Vector2f(6.f, 0.5f), -0.6f, gris);

    //ENEMIGOS RECTANGULARES (Los dos finitos de la pantalla)
    EnemigoRectangular eRectangular1 = EnemigoRectangular(sf::Vector2f(4.5f, 23.5f), sf::Vector2f(0.5f, 2.5f), -0.f, 0, gris);

    EnemigoRectangular eRectangular2 = EnemigoRectangular(sf::Vector2f(28.9f, 23.5f), sf::Vector2f(0.5f, 2.5f), 0.f, 0, gris);

    EnemigoRectangular eRectangular3 = EnemigoRectangular(sf::Vector2f(8.5f, 18.9f), sf::Vector2f(0.5f, 2.5f), -6.f, 0, gris);

    EnemigoRectangular eRectangular4 = EnemigoRectangular(sf::Vector2f(24.9f, 18.9f), sf::Vector2f(0.5f, 2.5f), 6.f, 0, gris);

    ///AnADE LOS OBJETOS CREADOS A LAS LISTAS
    lEnemigosRectangulares.push_back(eRectangular1);
    lEnemigosRectangulares.push_back(eRectangular2);
    lEnemigosRectangulares.push_back(eRectangular3);
    lEnemigosRectangulares.push_back(eRectangular4);

    lEnemigosRedondos.push_back(eRedondo1);
    lEnemigosRedondos.push_back(eRedondo2);
    lEnemigosRedondos.push_back(eRedondo3);
    lEnemigosRedondos.push_back(eRedondo4);
    lEnemigosRedondos.push_back(eRedondo5);
    lEnemigosRedondos.push_back(eRedondo6);
    lEnemigosRedondos.push_back(eRedondo7);
    lEnemigosRedondos.push_back(eRedondo8);
    lEnemigosRedondos.push_back(eRedondo9);
    lEnemigosRedondos.push_back(eRedondo10);

    lRectangulos.push_back(muro_superior);
    lRectangulos.push_back(muro_izquierdo);
    lRectangulos.push_back(muro_derecho);
    lRectangulos.push_back(esquina_superior_derecha); 
    lRectangulos.push_back(esquina_superior_izquierda);
    lRectangulos.push_back(tunel);

    lHitbox.push_back(rampaIzquierdaInf);
    lHitbox.push_back(rampaDerechaInf);

    ///RELOJ PARA USAR FUNCIONES DE TIEMPO
    sf::Clock clock;

    ///WHILE PARA CONTROLAR QUE LA VENTANA EST� ABIERTA
    while (this->ventana.isOpen())
    {
        ///WHILE PARA CONTROLAR QUE HAYAN EVENTOS Y RECIBIR LA ACCION DEL JUGADOR
        while (this->ventana.pollEvent(this->evento))
        {
            if (this->evento.type == sf::Event::Closed) //Cierra la ventana
            {
                sonido.DetenerMusica();
                this->ventana.close();
            }
            else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape) //Cierra la ventana
            {
                sonido.DetenerMusica();
                this->ventana.close();
            }
            else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Space) //Crea y lanza la bola
            {

                if (!bool_En_Juego && !bool_Fin_Juego)
                {
                    //Parametros de la bola
                    sf::Vector2f posicion = sf::Vector2f(34.f, 50.f);
                    sf::Vector2f velocidad = sf::Vector2f(0.f, -60.f);
                    sf::Vector2f aceleracion = sf::Vector2f(0.f, 30.f);

                    //Crea la bola
                    Bola bola = Bola(posicion, velocidad, aceleracion, 0.9f);
                    bola.set_color(sf::Color::White);

                    //Agrega la bola a la lista
                    bolas.push_back(bola);

                    //Indica que hay una bola en juego
                    bool_En_Juego = true;

                    sonido.ReproducirLanzamiento();
                }
            }
            else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Z)
            {
                sonido.ReproducirFlipper();
                
                FlipperIzquierdoInf.Mover("arriba");
                FlipperIzquierdoSup.Mover("arriba");

            }
            else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::X)
            {
                sonido.ReproducirFlipper();
                
                FlipperDerechoInf.Mover("arriba");
                FlipperDerechoSup.Mover("arriba");

            }
            else if (this->evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::Z)
            {

                FlipperIzquierdoInf.Mover("abajo");
                FlipperIzquierdoSup.Mover("abajo");
            }
            else if (this->evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::X)
            {

                FlipperDerechoInf.Mover("abajo");
                FlipperDerechoSup.Mover("abajo");
            }
        }

        this->ventana.clear(sf::Color::Black);

        //Controla el framerate y los tiempos del juego
        sf::Time intervalo_tiempo = clock.getElapsedTime();

        const unsigned int tiempo_transcurrido = intervalo_tiempo.asMilliseconds();

        if (tiempo_transcurrido >= 10 && !bool_Fin_Juego)
        {
            const float fSegundos = intervalo_tiempo.asSeconds();

            /*
                A partir de aca se crean varios For para recorrer las distintas listas de objetos
                y comprobar si la bola colisiona contra ellos.
            */

            for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
            {
                for (auto p = bolas.begin(); p != bolas.end(); p++)
                {
                    if (bolasIterador != p)
                    {
                        Colisiones colision = Colisiones(&bolasIterador->cuerpo, &p->cuerpo);

                        if (colision.CirculoVsCirculo())
                        {
                            
                            colision.correctPosition();

                            colision.aplicarImpulso();
                        }
                    }
                }

                for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt)
                {
                    Colisiones colision = Colisiones(&lEnemigosRedondosIt->cuerpo, &bolasIterador->cuerpo);

                    if (colision.CirculoVsCirculo())
                    {
                        sonido.ReproducirChoque();
                        
                        puntaje_total += lEnemigosRedondosIt->get_puntos();

                        colision.correctPosition();

                        colision.aplicarImpulso();
                    }
                }

                for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
                {
                    Colisiones colision = Colisiones(&lEnemigosRectangularesIt->cuerpo, &bolasIterador->cuerpo);

                    if (colision.CirculoVsHitbox())
                    {
                        puntaje_total += lEnemigosRectangularesIt->get_puntos();

                        colision.correctPosition();

                        colision.aplicarImpulso();
                    }
                }

                for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
                {
                    Colisiones colision = Colisiones(&lRectangulosIt->cuerpo, &bolasIterador->cuerpo);

                    if (colision.CirculoVsRectangulo())
                    {
                        colision.correctPosition();

                        colision.aplicarImpulso();
                    }
                }

                for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
                {
                    Colisiones colision = Colisiones(&lHitboxIt->cuerpo, &bolasIterador->cuerpo);

                    if (colision.CirculoVsHitbox())
                    {
                        colision.correctPosition();

                        colision.aplicarImpulso();

                        colision.aplicarCaida();
                    }
                }

                Colisiones FlipperIzquierdoInf_colision = Colisiones(&FlipperDerechoInf.cuerpo, &bolasIterador->cuerpo);
                if (FlipperIzquierdoInf_colision.CirculoVsHitbox())
                {
                    FlipperIzquierdoInf_colision.correctPosition();

                    FlipperIzquierdoInf_colision.aplicarImpulso();

                    FlipperIzquierdoInf_colision.aplicarCaida();
                }

                Colisiones FlipperDerechoInf_colision = Colisiones(&FlipperIzquierdoInf.cuerpo, &bolasIterador->cuerpo);
                if (FlipperDerechoInf_colision.CirculoVsHitbox())
                {
                    FlipperDerechoInf_colision.correctPosition();

                    FlipperDerechoInf_colision.aplicarImpulso();

                    FlipperDerechoInf_colision.aplicarCaida();
                }

                Colisiones FlipperIzquierdoSup_colision = Colisiones(&FlipperDerechoSup.cuerpo, &bolasIterador->cuerpo);
                if (FlipperIzquierdoSup_colision.CirculoVsHitbox())
                {
                    FlipperIzquierdoSup_colision.correctPosition();

                    FlipperIzquierdoSup_colision.aplicarImpulso();

                }

                Colisiones FlipperDerechoSup_colision = Colisiones(&FlipperIzquierdoSup.cuerpo, &bolasIterador->cuerpo);
                if (FlipperDerechoSup_colision.CirculoVsHitbox())
                {
                    FlipperDerechoSup_colision.correctPosition();

                    FlipperDerechoSup_colision.aplicarImpulso();

                }

                bolasIterador->cuerpo.updateBola(fSegundos);
            }

            ///Mueve los flippers
            FlipperDerechoInf.cuerpo.update(fSegundos);
            FlipperDerechoInf.rotarFlipper();

            FlipperIzquierdoInf.cuerpo.update(fSegundos);
            FlipperIzquierdoInf.rotarFlipper();

            FlipperDerechoSup.cuerpo.update(fSegundos);
            FlipperDerechoSup.rotarFlipper();

            FlipperIzquierdoSup.cuerpo.update(fSegundos);
            FlipperIzquierdoSup.rotarFlipper();

            clock.restart();
        }

        this->ventana.draw(background);

        str_puntaje.setString(std::to_string(puntaje_total));
        str_bolas_restantes.setString(std::to_string(bolas_restantes));
        str_maximo_puntaje.setString("~ Mejor puntaje: " + std::to_string(puntaje_mas_alto) + "...");

        restar_bola();

        if (bolas_restantes <= 0)
        {
            bool_Fin_Juego = true;
        }
        if (puntaje_total > puntaje_mas_alto)
        {
            puntaje_mas_alto = puntaje_total;
        }

        /*
            A patir de aca se dibujan todos los objetos del nivel
        */

        this->ventana.draw(FlipperDerechoInf);
        this->ventana.draw(FlipperIzquierdoInf);
        this->ventana.draw(FlipperDerechoSup);
        this->ventana.draw(FlipperIzquierdoSup);

        for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
        {
            this->ventana.draw(*lRectangulosIt);
        }

        for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
        {
            this->ventana.draw(*lHitboxIt);
        }

        for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
        {
            this->ventana.draw(*bolasIterador);
        }

        for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt)
        {
            this->ventana.draw(*lEnemigosRedondosIt);
        }

        for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
        {
            this->ventana.draw(*lEnemigosRectangularesIt);
        }

        this->ventana.draw(str_maximo_puntaje);
        this->ventana.draw(puntos);
        this->ventana.draw(str_puntaje);
        this->ventana.draw(bola);
        this->ventana.draw(str_bolas_restantes);
        this->ventana.draw(textureMap);

        ///Termina el juego
        if (bool_Fin_Juego)
        {
            bool_En_Juego = false;

            this->ventana.draw(gameOver);

            if (BandSonido) {
                sonido.ReproducirGameOver();
                BandSonido = false;
            }

            float  fDelay = sf::seconds(6.0).asSeconds();

            sf::Time now = clock.getElapsedTime();

            if (puntaje_total > 0)
            {
                _jugador.set_puntaje(puntaje_total);
            }

            if (now.asSeconds() >= fDelay)
            {
                BandSonido = true;
                puntaje_total = 0;
                bolas_restantes = 3;
                bool_Fin_Juego = false;
                clock.restart();
            }
        }
        this->ventana.display();
    }

    ///Guarda el puntaje una vez el jugador pierde
    ArchivoJugadores archivo;
    if (_jugador.get_puntaje() > 0)
    {
        if (archivo.guardar(_jugador))
        {
            std::cout << _jugador.get_nombre() << " PUNTOS " << _jugador.get_puntaje() << std::endl;
            std::cout << "Jugador guardado correctamente!" << std::endl;
        }
    }
}

void Juego::tercer_nivel(Jugadores& _jugador) 
{
    ///FONDO DEL NIVEL
    sf::Texture textura;
    sf::Texture textura1;
    sf::Texture textura2;
    if (!textura.loadFromFile("resources/background3.png"))
    {
        std::cout << "No se cargo el fondo" << std::endl;
    }
    sf::Sprite background(textura);
    if (!textura1.loadFromFile("resources/game_over.png"))
    {
        std::cout << "No se cargo el fondo" << std::endl;
    }
    sf::Sprite gameOver(textura1);
    if (!textura2.loadFromFile("resources/texture_map3.png"))
    {
        std::cout << "No se cargo el fondo" << std::endl;
    }
    sf::Sprite textureMap(textura2);

    sonido.ReproducirArranque();
    sonido.ReproducirMusicaNivel3();

    ///DECLARACION DE COLORES DEL NIVEL
    sf::Color Azul = sf::Color(8, 68, 112);
    sf::Color blanco = sf::Color(235, 235, 235);
    sf::Color rosa = sf::Color(200, 90, 129);
    sf::Color gris = sf::Color(39, 36, 36);

    ///MENSAJES EN PANTALLA
    sf::Text str_maximo_puntaje = sf::Text("~ Mejor puntaje: " + std::to_string(puntaje_mas_alto) + "...", fuente_de_texto, 18);
    str_maximo_puntaje.setFillColor(blanco);
    str_maximo_puntaje.setPosition(200, 30);

    sf::Text puntos = sf::Text("Puntos", fuente_de_texto, 35);
    puntos.setFillColor(blanco);
    puntos.setPosition(448, 28);

    sf::Text str_puntaje = sf::Text(std::to_string(puntaje_total), fuente_de_texto, 30);
    str_puntaje.setFillColor(blanco);
    str_puntaje.setPosition(445, 72);

    sf::Text bola = sf::Text("Bola", fuente_de_texto, 25);
    bola.setFillColor(rosa);
    bola.setPosition(616, 22);

    sf::Text str_bolas_restantes = sf::Text(std::to_string(bolas_restantes), fuente_de_texto, 30);
    str_bolas_restantes.setFillColor(blanco);
    str_bolas_restantes.setPosition(634, 64);

    ///LISTAS E ITERADORES DE OBJETOS (Almacenan los Objetos)
    std::list<Rectangulo> lRectangulos;
    std::list<Rectangulo>::iterator lRectangulosIt;
    std::list<HitBox> lHitbox;
    std::list<HitBox>::iterator lHitboxIt;
    std::list<EnemigoRedondo> lEnemigosRedondos;
    std::list<EnemigoRedondo>::iterator lEnemigosRedondosIt;
    std::list<EnemigoRectangular> lEnemigosRectangulares;
    std::list<EnemigoRectangular>::iterator lEnemigosRectangularesIt;

    //MUROS DEL JUEGO----------------
    Rectangulo muro_superior = Rectangulo(sf::Vector2f(18.f, 7.8f) /*ORIGEN*/, sf::Vector2f(17.f, 0.4f)/*EXTENSION*/, gris/*COLOR*/);

    Rectangulo muro_izquierdo = Rectangulo(sf::Vector2f(0.5f, 27.5f)/*ORIGEN*/, sf::Vector2f(0.7f, 30.f)/*EXTENSION*/, gris/*COLOR*/);

    Rectangulo muro_derecho = Rectangulo(sf::Vector2f(35.5f, 27.5f), sf::Vector2f(0.7f, 30.f), gris);

    Rectangulo esquina_superior_derecha = Rectangulo(sf::Vector2f(34.8f, 8.2f)/*POSICION*/, sf::Vector2f(0.5f, 0.5f)/*EXTENSION MEDIA*/, gris/*COLOR*/);

    Rectangulo tunel = Rectangulo(sf::Vector2f(32.9f, 40.f), sf::Vector2f(0.4f, 15.f), gris);

    //ENEMIGOS REDONDOS - BUMPERS DEL JUEGO-----------------
    EnemigoRedondo eRedondo2 = EnemigoRedondo(sf::Vector2f(9.f, 18.f), 1.f, 100, gris);

    EnemigoRedondo eRedondo3 = EnemigoRedondo(sf::Vector2f(25.f, 18.f), 1.f, 100, gris);

    EnemigoRedondo eRedondoGrande1 = EnemigoRedondo(sf::Vector2f(25.f, 35.f), 2.f, 10, gris);

    EnemigoRedondo eRedondoGrande2 = EnemigoRedondo(sf::Vector2f(9.f, 35.f), 2.f, 10, gris);

    EnemigoRedondo eRedondoGrande3 = EnemigoRedondo(sf::Vector2f(9.f, 25.f), 2.f, 25, gris);

    EnemigoRedondo eRedondoGrande4 = EnemigoRedondo(sf::Vector2f(25.f, 25.f), 2.f, 25, gris);

    //FLIPPERS---------------------------
    Flippers FlipperIzquierdo(sf::Vector2f(11.5f, 44.1f)/*Posicion*/, 0.6f/*Angulo*/, sf::Vector2f(4.75f, 0.5f)/*Extension media*/, Azul/*Color*/, true/*EnladoIzquierdo*/);

    Flippers FlipperDerecho(sf::Vector2f(21.9f, 44.1f)/*Posicion*/, 0.6f/*Angulo*/, sf::Vector2f(4.75f, 0.5f)/*Extension media*/, Azul/*Color*/, false/*EnladoIzquierdo*/);

    //RAMPAS AL COSTADO DE LOS FLIPPERS
    HitBox rampaIzquierda = HitBox(sf::Vector2f(5.5f, 40.f), sf::Vector2f(6.f, 0.5f), 0.6f, gris);

    HitBox rampaDerecha = HitBox(sf::Vector2f(27.9f, 40.f), sf::Vector2f(6.f, 0.5f), -0.6f, gris);

    //ENEMIGOS RECTANGULARES (Los dos finitos de la pantalla)-----------------
    EnemigoRectangular eRectangular1 = EnemigoRectangular(sf::Vector2f(5.f, 15.f), sf::Vector2f(0.5f, 2.f), -0.7f, 0, gris);

    EnemigoRectangular eRectangular2 = EnemigoRectangular(sf::Vector2f(13.f, 15.3f), sf::Vector2f(0.5f, 2.f), 0.7f, 0, gris);

    EnemigoRectangular eRectangular3 = EnemigoRectangular(sf::Vector2f(21.f, 15.5f), sf::Vector2f(0.5f, 2.f), -0.7f, 0, gris);

    EnemigoRectangular eRectangular4 = EnemigoRectangular(sf::Vector2f(29.f, 15.5f), sf::Vector2f(0.5f, 2.f), 0.7f, 0, gris);

    EnemigoRectangular eRectangular5 = EnemigoRectangular(sf::Vector2f(5.f, 20.5f), sf::Vector2f(0.5f, 2.f), -0.7f, 0, gris);

    EnemigoRectangular eRectangular6 = EnemigoRectangular(sf::Vector2f(30.f, 20.5f), sf::Vector2f(0.5f, 2.f), 0.7f, 0, gris);

    ///AÑADE LOS OBJETOS CREADOS A LAS LISTAS
    lEnemigosRectangulares.push_back(eRectangular1);
    lEnemigosRectangulares.push_back(eRectangular2);
    lEnemigosRectangulares.push_back(eRectangular3);
    lEnemigosRectangulares.push_back(eRectangular4);
    lEnemigosRectangulares.push_back(eRectangular5);
    lEnemigosRectangulares.push_back(eRectangular6);

    lEnemigosRedondos.push_back(eRedondo2);
    lEnemigosRedondos.push_back(eRedondo3);
    lEnemigosRedondos.push_back(eRedondoGrande1);
    lEnemigosRedondos.push_back(eRedondoGrande2);
    lEnemigosRedondos.push_back(eRedondoGrande3);
    lEnemigosRedondos.push_back(eRedondoGrande4);

    lRectangulos.push_back(muro_superior);
    lRectangulos.push_back(muro_izquierdo);
    lRectangulos.push_back(muro_derecho);
    lRectangulos.push_back(esquina_superior_derecha);
    lRectangulos.push_back(tunel);

    lHitbox.push_back(rampaIzquierda);
    lHitbox.push_back(rampaDerecha);

    ///RELOJ PARA USAR FUNCIONES DE TIEMPO
    sf::Clock clock;

    ///WHILE PARA CONTROLAR QUE LA VENTANA EST� ABIERTA
    while (this->ventana.isOpen())
    {
        ///WHILE PARA CONTROLAR QUE HAYAN EVENTOS Y RECIBIR LA ACCION DEL JUGADOR
        while (this->ventana.pollEvent(this->evento))
        {
            if (this->evento.type == sf::Event::Closed) //Cierra la ventana
            {
                sonido.DetenerMusica();
                this->ventana.close();
            }
            else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape) //Cierra la ventana
            {
                sonido.DetenerMusica();
                this->ventana.close();
            }
            else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Space) //Crea y lanza la bola
            {

                if (!bool_En_Juego && !bool_Fin_Juego)
                {
                    //Parametros de la bola
                    sf::Vector2f posicion = sf::Vector2f(34.f, 50.f);
                    sf::Vector2f velocidad = sf::Vector2f(0.f, -60.f);
                    sf::Vector2f aceleracion = sf::Vector2f(0.f, 30.f);

                    //Crea la bola
                    Bola bola = Bola(posicion, velocidad, aceleracion, 0.9f);

                    bola.set_color(sf::Color::White);

                    //Agrega la bola a la lista
                    bolas.push_back(bola);

                    //Indica que hay una bola en juego
                    bool_En_Juego = true;

                    sonido.ReproducirLanzamiento();
                }
            }
            else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Z)
            {
                sonido.ReproducirFlipper();

                FlipperIzquierdo.Mover("arriba");
            }
            else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::X)
            {
                sonido.ReproducirFlipper();

                FlipperDerecho.Mover("arriba");
            }
            else if (this->evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::Z)
            {
                FlipperIzquierdo.Mover("abajo");
            }
            else if (this->evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::X)
            {
                FlipperDerecho.Mover("abajo");
            }

        }

        this->ventana.clear(sf::Color::Black);

        ///SE UTILIZAN FUNCIONES DE TIEMPO PARA EL FLUJO DEL JUEGO
        sf::Time intervalo_tiempo = clock.getElapsedTime();

        MoverKlooster();

        const unsigned int tiempo_transcurrido = intervalo_tiempo.asMilliseconds();

        if (tiempo_transcurrido >= 10 && !bool_Fin_Juego)
        {
            const float fSegundos = intervalo_tiempo.asSeconds();

            ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA OBJETO
            for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
            {
                for (auto p = bolas.begin(); p != bolas.end(); p++)
                {
                    if (bolasIterador != p)
                    {
                        Colisiones colision = Colisiones(&bolasIterador->cuerpo, &p->cuerpo);

                        if (colision.CirculoVsCirculo())
                        {
                            colision.correctPosition();

                            colision.aplicarImpulso();
                        }
                    }
                }
                ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA ENEMIGO REDONDO
                for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt)
                {
                    Colisiones colision = Colisiones(&lEnemigosRedondosIt->cuerpo, &bolasIterador->cuerpo);

                    if (colision.CirculoVsCirculo())
                    {
                        sonido.ReproducirChoque();


                        puntaje_total += lEnemigosRedondosIt->get_puntos();

                        colision.correctPosition();

                        colision.aplicarImpulso();

                    }
                }

                ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA ENEMIGO RECTANGULAR
                for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
                {
                    Colisiones colision = Colisiones(&lEnemigosRectangularesIt->cuerpo, &bolasIterador->cuerpo);

                    if (colision.CirculoVsHitbox())
                    {
                        puntaje_total += lEnemigosRectangularesIt->get_puntos();

                        colision.correctPosition();

                        colision.aplicarImpulso();
                    }
                }

                ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA OBJETO RECTANGULAR
                for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
                {
                    Colisiones colision = Colisiones(&lRectangulosIt->cuerpo, &bolasIterador->cuerpo);

                    if (colision.CirculoVsRectangulo())
                    {
                        colision.correctPosition();

                        colision.aplicarImpulso();
                    }
                }

                //FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA RAMPA
                for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
                {
                    Colisiones colision = Colisiones(&lHitboxIt->cuerpo, &bolasIterador->cuerpo);

                    if (colision.CirculoVsHitbox())
                    {
                        colision.correctPosition();

                        colision.aplicarImpulso();

                        colision.aplicarCaida();
                    }
                }

                /*
                    TOMA A UN FLIPPER COMO CUERPO A Y A UNA BOLA COMO CUERPO B.
                    CHECKEA SI SE ESTAN TOCANDO, CORRIGE LA POSICION Y LE APLICA EL IMPULSO A LA BOLA.
                */
                Colisiones FlipperIzquierdo_colision = Colisiones(&FlipperDerecho.cuerpo, &bolasIterador->cuerpo);

                if (FlipperIzquierdo_colision.CirculoVsHitbox())
                {
                    FlipperIzquierdo_colision.correctPosition();

                    FlipperIzquierdo_colision.aplicarImpulso();

                    FlipperIzquierdo_colision.aplicarCaida();
                }

                Colisiones FlipperDerecho_colision = Colisiones(&FlipperIzquierdo.cuerpo, &bolasIterador->cuerpo);

                if (FlipperDerecho_colision.CirculoVsHitbox())
                {
                    FlipperDerecho_colision.correctPosition();

                    FlipperDerecho_colision.aplicarImpulso();

                    FlipperDerecho_colision.aplicarCaida();
                }

                //ACTUALIZA LAS PROPIEDADES DE LA BOLA (POSICION, VELOCIDAD Y ACELERACION)
                bolasIterador->cuerpo.updateBola(fSegundos);
            }

            ///MUEVE LOS FLIPPERS
            FlipperDerecho.cuerpo.update(fSegundos);
            FlipperDerecho.rotarFlipper();

            FlipperIzquierdo.cuerpo.update(fSegundos);
            FlipperIzquierdo.rotarFlipper();

            clock.restart();
        }

        this->ventana.draw(background);

        //Actualiza los mensajes de la pantalla
        str_puntaje.setString(std::to_string(puntaje_total));

        str_bolas_restantes.setString(std::to_string(bolas_restantes));

        str_maximo_puntaje.setString("~ Mejor puntaje: " + std::to_string(puntaje_mas_alto) + "...");

        restar_bola();

        //Si no quedan bolas, termina el juego
        if (bolas_restantes <= 0)
        {
            bool_Fin_Juego = true;
        }
        //Si nuestro puntaje es mayor al puntaje mas alto, se actualiza
        if (puntaje_total > puntaje_mas_alto)
        {
            puntaje_mas_alto = puntaje_total;
        }

        /*
            A PARTIR DE ACA SE DIBUJAN LOS OBJETOS HASTA
                "if (bool_Fin_Juego)"
        */

        this->ventana.draw(FlipperDerecho);
        this->ventana.draw(FlipperIzquierdo);

        this->ventana.draw(str_maximo_puntaje);
        this->ventana.draw(puntos);
        this->ventana.draw(str_puntaje);
        this->ventana.draw(bola);
        this->ventana.draw(str_bolas_restantes);
        this->ventana.draw(this->sprite);

        for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
        {
            this->ventana.draw(*lRectangulosIt);
        }

        for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
        {
            this->ventana.draw(*lHitboxIt);
        }

        for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
        {
            this->ventana.draw(*bolasIterador);
        }

        for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt)
        {
            this->ventana.draw(*lEnemigosRedondosIt);
        }

        for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
        {
            this->ventana.draw(*lEnemigosRectangularesIt);
        }

        this->ventana.draw(textureMap);

        if (bool_Fin_Juego)
        {
            bool_En_Juego = false;

            this->ventana.draw(gameOver);

            if (BandSonido) 
            {
                sonido.ReproducirGameOver();
                BandSonido = false;
            }

            float  fDelay = sf::seconds(6.0).asSeconds();

            sf::Time now = clock.getElapsedTime();

            if (puntaje_total > 0)
            {
                _jugador.set_puntaje(puntaje_total);
            }

            if (now.asSeconds() >= fDelay)
            {
                BandSonido = true;
                intentos++;
                puntaje_total = 0;
                bolas_restantes = 3;
                bool_Fin_Juego = false;
                clock.restart();
            }
        }

        this->ventana.display();
    }

    ArchivoJugadores archivo;
    if (_jugador.get_puntaje() > 0)
    {
        if (archivo.guardar(_jugador))
        {
            std::cout << _jugador.get_nombre() << " PUNTOS " << _jugador.get_puntaje() << std::endl;
            std::cout << "Jugador guardado correctamente!" << std::endl;
        }
    }
}

//--------------------------------------------------//

void Juego::restar_bola()
{
    /*
    CONTROLA QUE LA PELOTA NO SE HAYA IDO DE LA PANTALLA,
    EN CASO DE QUE SI, RESTA UNA VIDA.
    */

    for (bolasIterador = bolas.begin(); bolasIterador != bolas.end();)
    {
        if (bolasIterador->cuerpo.getPosicion().y > 60)
        {
                sonido.ReproducirRestarBola();
                bolasIterador = bolas.erase(bolasIterador);
                bolas_restantes--;
                bool_En_Juego = false;
        }
        else 
        {
            bolasIterador++;
        }
    }
}

void Juego::MoverKlooster()
{
    this->sprite.move((-klooster * 0.01f), (-klooster * -0.01f));
    if (this->sprite.getPosition().x < -800)
    {
        float random1 = rand() % (800 - 150 + 1) + 150;
        float random2 = rand() % (-200 - -400 - 1) - 400;

        this->sprite.setPosition(random1, random2);
    }
}