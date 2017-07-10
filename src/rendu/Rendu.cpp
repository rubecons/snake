/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Rendu.h"
//#include "etats/Terrain.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include "etats/Partie.h"
#include "moteur/Moteur.h"
#include "moteur/CommandeTourner.h"
#include "etats/Serpent.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <thread>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Thread.hpp>


namespace rendu
{
    
Rendu::Rendu()
{}

Rendu::~Rendu()
{}

Rendu & Rendu::instance()
{
    static Rendu rendu;
    return rendu;
}

void Rendu::init()
{
    moteur::Moteur *moteu=&moteur::Moteur::instance();
    
    accueil =true;
    winX= 800;
    winY= 800;
    bool scoreSauvegarde=false;
    etats::FinPartie isFinduJeu;
    
    
    
    wind = new sf::RenderWindow(sf::VideoMode(winX, winY), "SnAkE", sf::Style::Titlebar | sf::Style::Close);
    vue.setSize(wind->getSize().x, wind->getSize().y);
    vue.setCenter(wind->getSize().x/2, wind->getSize().y/2);
    vue.zoom(1);
//    vue.setViewport(sf::FloatRect(0,0,1,1));
//    if (wind->getSize().y/wind->getSize().x < (uint) etats::Partie::instance().hauteur/etats::Partie::instance().largeur)
//    {
//        vue.zoom(etats::Partie::instance().hauteur/wind->getSize().y);
//        vue.setViewport({(int)(1-etats::Partie::instance().largeur*wind->getSize().y/etats::Partie::instance().hauteur/wind->getSize().x)/2, 0,(int) etats::Partie::instance().largeur*wind->getSize().y/etats::Partie::instance().hauteur/wind->getSize().x, 1});
//    }
//    else
//    {
//        vue.zoom(etats::Partie::instance().largeur/wind->getSize().x);
//        vue.setViewport({0, (int)(1-etats::Partie::instance().hauteur*wind->getSize().x/etats::Partie::instance().largeur/wind->getSize().y)/2, 1, (int)etats::Partie::instance().hauteur*wind->getSize().x/etats::Partie::instance().largeur/wind->getSize().y});
//    }

    vue.reset(sf::FloatRect(0,0,winX, winY));
    wind->setView(vue);
     sf::Font font;
    if (!font.loadFromFile("ressources/Barrio-Regular.ttf"))
    {
        std::cout<<"impossible de charger la police désirée"<<std::endl;
    }     
    
    sf::Text pause;
    pause.setFont(font);pause.setString("Pause !");pause.setCharacterSize(100);pause.setFillColor(sf::Color::Red);pause.setPosition(wind->getSize().x/3, wind->getSize().y/3);
    
    
    sf::Text instructionPause;
    instructionPause.setFont(font);instructionPause.setString("appuyer sur ECHAP pour revenir au jeu");instructionPause.setCharacterSize(20);instructionPause.setFillColor(sf::Color::Black);instructionPause.setPosition(pause.getPosition().x-20,pause.getPosition().y+110);
    
    
    sf::Text gameOver;
    gameOver.setFont(font);gameOver.setString("GAME OVER !");gameOver.setCharacterSize(100);gameOver.setFillColor(sf::Color::Red);gameOver.setPosition(wind->getSize().x/5, wind->getSize().y/4);
    
    
    sf::Text victoire;
    victoire.setFont(font);victoire.setString("VICTOIRE !");victoire.setCharacterSize(150);victoire.setFillColor(sf::Color::Red);victoire.setPosition(wind->getSize().x/5, wind->getSize().y/4);
    
    
    sf::Text instructionFinJeu;
    instructionFinJeu.setFont(font);instructionFinJeu.setString(L"appuyer sur entrée pour recommencer une partie\ntapez votre nom, puis entrée pour enregistrer votre score\nappuyer sur ECHAP pour revenir à l'écran d'accueil");instructionFinJeu.setCharacterSize(17);instructionFinJeu.setFillColor(sf::Color::Black);instructionFinJeu.setPosition(gameOver.getPosition().x-40,gameOver.getPosition().y+110);
            
            
    std::string score2, nom1="nom : ", score1="score : ";
    sf::Text score;
    score.setFont(font);score.setCharacterSize(50);score.setFillColor(sf::Color::White);score.setPosition(10, 10);
    
    
    sf::Text nom;
    nom.setFont(font);nom.setCharacterSize(50);nom.setFillColor(sf::Color::Black);nom.setPosition(wind->getSize().x*3/8, wind->getSize().y*2/3);
    
    
    meilleursScores.setFont(font);meilleursScores.setCharacterSize(18);meilleursScores.setFillColor(sf::Color::Black);meilleursScores.setPosition(wind->getSize().x*1/10, wind->getSize().y/2);
    
    actualiserScores();
    pageAccueil.init();
    afficherPageAccueil();
    threadCallerHorloge();
    
    
    while (wind->isOpen())
    {
     wind->clear();   
     score2 = std::to_string(etats::Partie::instance().points);
     score.setString(score1+score2);
     nom.setString(nom1+nom2);
     isFinduJeu = etats::Partie::instance().isFin();
        sf::Event event;
        while (wind->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed :
                    wind->close();
                    break;
                case sf::Event::LostFocus :
                    etats::Partie::instance().pause();
                    break;
                case sf::Event::KeyPressed :
                {    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape :
                            {//
                                if(accueil==false)
                                {
                                    switch(etats::Partie::instance().play)
                                    {
                                        case true  : 
                                            etats::Partie::instance().pause();
                                            break;
                                        case false : 
                                            {
                                                if(etats::Partie::instance().isFin()==etats::FinPartie::NOP)
                                                {
                                                    etats::Partie::instance().reprendre();
                                                }
                                                else
                                                {
                                                    accueil=true;
                                                    scoreSauvegarde=false;
                                                    etats::Partie::instance().quitterPartie();
                                                    afficherPageAccueil();
                                                    
                                                }
                                            } 
                                            break;
                                    }
                                }   
                            }
                            break;
                        case sf::Keyboard::Up :
                            
                            {
                                if(!accueil)
                                {
                                    moteu->ajouterCommande(new moteur::CommandeTourner(etats::Direction::NORD));
                                }
                            }
                            break;
                        case sf::Keyboard::Down : moteu->ajouterCommande(new moteur::CommandeTourner(etats::Direction::SUD));
                            break;
                        case sf::Keyboard::Right : moteu->ajouterCommande(new moteur::CommandeTourner(etats::Direction::EST));
                            break;
                        case sf::Keyboard::Left : moteu->ajouterCommande(new moteur::CommandeTourner(etats::Direction::OUEST));
                            break;
                        case sf::Keyboard::Return : 
                            {
                                if(!accueil)
                                {
                                    if(nom2.empty() || scoreSauvegarde==true)
                                    {
                                        scoreSauvegarde=false;
                                        nom2.clear();
                                        moteur::Moteur::instance().clearCommandes();
                                        etats::Partie::instance().recommencer();
                                    }
                                    else if(scoreSauvegarde==false)
                                    {
                                        etats::Partie::instance().sauvegarderScore(nom2);
                                        nom2.clear();
                                        scoreSauvegarde=true;
                                        actualiserScores();
                                    }
                                }
                            }
                            break;
                        case sf::Keyboard::A : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='a';}} break;
                        case sf::Keyboard::B : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='b';}} break;
                        case sf::Keyboard::C : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='c';}} break;
                        case sf::Keyboard::D : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='d';}} break;
                        case sf::Keyboard::E : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='e';}} break;
                        case sf::Keyboard::F : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='f';}} break;
                        case sf::Keyboard::G : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='g';}} break;
                        case sf::Keyboard::H : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='h';}} break;
                        case sf::Keyboard::I : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='i';}} break;
                        case sf::Keyboard::J : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='j';}} break;
                        case sf::Keyboard::K : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='k';}} break;
                        case sf::Keyboard::L : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='l';}} break;
                        case sf::Keyboard::M : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='m';}} break;
                        case sf::Keyboard::N : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='n';}} break;
                        case sf::Keyboard::O : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='o';}} break;
                        case sf::Keyboard::Q : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='q';}} break;
                        case sf::Keyboard::R : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='r';}} break;
                        case sf::Keyboard::S : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='s';}} break;
                        case sf::Keyboard::T : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='t';}} break;
                        case sf::Keyboard::U : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='u';}} break;
                        case sf::Keyboard::V : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='v';}} break;
                        case sf::Keyboard::W : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='w';}} break;
                        case sf::Keyboard::X : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='x';}} break;
                        case sf::Keyboard::P : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='p';}} break;
                        case sf::Keyboard::Y : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='y';}} break;
                        case sf::Keyboard::Z : {if(isFinduJeu!=etats::FinPartie::NOP){nom2+='z';}} break;
                        case sf::Keyboard::BackSpace : {if(isFinduJeu!=etats::FinPartie::NOP && nom2.empty()==false){nom2.pop_back();}} break;
                        default : 
                            break;
                    }
                }
                break;
                default : break;
            }
        }

        if(!accueil)
        {
            wind->draw(map);
            if(etats::Partie::instance().play==false && isFinduJeu==etats::FinPartie::NOP){wind->draw(pause);wind->draw(instructionPause);}
            if(isFinduJeu==etats::FinPartie::GAMEOVER){wind->draw(gameOver);wind->draw(instructionFinJeu);}
            if(isFinduJeu==etats::FinPartie::VICTOIRE){wind->draw(victoire);wind->draw(instructionFinJeu);}
            if(isFinduJeu!=etats::FinPartie::NOP){if(scoreSauvegarde==false){wind->draw(nom);}wind->draw(meilleursScores);}
            wind->draw(score);
        }
        wind->display();
    }
}

void Rendu::afficherPageAccueil()
{
    sf::Font font;
    if (!font.loadFromFile("ressources/Barrio-Regular.ttf"))
    {
        std::cout<<"impossible de charger la police désirée"<<std::endl;
    } 
//    pageAccueil.init();
    sf::Text jouer;
    sf::Text facile;
    sf::Text moyen;
    sf::Text difficile, instructionAccueil;
    jouer.setFont(font);jouer.setString("jouer !");jouer.setFillColor(sf::Color::White);jouer.setPosition(30, 500);
    facile.setFont(font);facile.setString("facile");facile.setFillColor(sf::Color::White);facile.setPosition(30, 650);
    moyen.setFont(font);moyen.setString("moyen");moyen.setFillColor(sf::Color::White);moyen.setPosition(100,690 );
    difficile.setFont(font);difficile.setString("difficile");difficile.setFillColor(sf::Color::White);difficile.setPosition(200,730);
    instructionAccueil.setFont(font);instructionAccueil.setString(L"appuyer sur entrée pour sélectionner un choix\ndéplacez vous dans le menu à l'aide des flèches directionnelles\ndéplacez le serpent à l'aide des flèches directionnelles\nappuyer sur ECHAP pour mettre le jeu en pause");instructionAccueil.setCharacterSize(17);instructionAccueil.setFillColor(sf::Color::White);instructionAccueil.setPosition(30,350);
    
    std::array<sf::Text*, 3> textesNiveaux;
    textesNiveaux[0]=&facile;
    textesNiveaux[1]=&moyen;
    textesNiveaux[2]=&difficile;
    
    while (wind->isOpen())
    {
        wind->clear();
        sf::Event event;
        while (wind->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed :
                    wind->close();
                    break;
                case sf::Event::Resized :
                    {    //pageAccueil.fond.resizeFond();//event.size);
                        uint cote = std::fmin(wind->getSize().x, wind->getSize().y);
//                        vue.setSize(cote, cote);
//                        vue.setCenter(wind->getSize().x/2, wind->getSize().y/2);
                        //vue.zoom(1);
                        //vue.setViewport(sf::FloatRect(0,0,1,1));
                        
                        
//                        if (wind->getSize().y/wind->getSize().x < 1)
//                        {
//                            vue.zoom(1);
//                            vue.setViewport(sf::FloatRect(0,0,cote, cote));
////                            vue.zoom(etats::Partie::instance().hauteur/wind->getSize().y);
////                            vue.setViewport({(int)(1-etats::Partie::instance().largeur*wind->getSize().y/etats::Partie::instance().hauteur/wind->getSize().x)/2, 0,(int) etats::Partie::instance().largeur*wind->getSize().y/etats::Partie::instance().hauteur/wind->getSize().x, 1});
//                        }
//                        else
//                        {
//                            vue.zoom(1);
//                            vue.setViewport(sf::FloatRect(0,0,cote, cote));
////                            vue.zoom(etats::Partie::instance().largeur/wind->getSize().x);
////                            vue.setViewport({0, (int)(1-etats::Partie::instance().hauteur*wind->getSize().x/etats::Partie::instance().largeur/wind->getSize().y)/2, 1, (int)etats::Partie::instance().hauteur*wind->getSize().x/etats::Partie::instance().largeur/wind->getSize().y});
//                        }

                        
                        
//                        vue.reset(sf::FloatRect(0,0,cote, cote));
                        wind->setView(vue);
                        //int cote = std::fmin(wind->getSize().x/, wind->getSize().y)
//                        vue.setViewport(sf::FloatRect(0,0,std::fmin(wind->getSize().x, wind->getSize().y),std::fmin(wind->getSize().x, wind->getSize().y)));
                        vue.setViewport(sf::FloatRect(0,0,std::fmin(event.size.height, event.size.width),std::fmin(event.size.height, event.size.width)));
                    }
                    break;
                case sf::Event::KeyPressed :
                {    switch(event.key.code)
                    {
                    case sf::Keyboard::Return : 
                    {
                        if(pageAccueil.curseur[0]==0)
                        {
                            rendu::Rendu::instance().accueil=false;
                            etats::Partie::instance().nouvellePartie(pageAccueil.niveau+1);
                            map.init(wind, L, H);
                            update();
                            return;
                        }
                        else
                        {
                            pageAccueil.enregisrerNiveauViaCurseur();
                            pageAccueil.curseur[0]=0;
                        }
                    }
                        break;
                    case sf::Keyboard::Up :
                    {
                        pageAccueil.curseur[0]=0;
                    }
                        break;
                    case sf::Keyboard::Down :
                    {
                        pageAccueil.curseur[0]=1;
                    }
                        break;
                    case sf::Keyboard::Left :
                    {
                        if(pageAccueil.curseur[0]==1 && pageAccueil.curseur[1]>0){pageAccueil.curseur[1]--;}
                    }
                        break;
                    case sf::Keyboard::Right :
                    {
                        if(pageAccueil.curseur[0]==1 && pageAccueil.curseur[1]<2){pageAccueil.curseur[1]++;}
                    }
                        break;
                    default :
                        break;
                    }
                    
                }
                    break;
                default :
                    break;
            }
        }
        
        jouer.setCharacterSize(pageAccueil.tailleJouer);
        facile.setCharacterSize(pageAccueil.tailleTexteNiv);
        moyen.setCharacterSize(pageAccueil.tailleTexteNiv);
        difficile.setCharacterSize(pageAccueil.tailleTexteNiv);
        
        
        for(sf::Text*& txt : textesNiveaux){txt->setStyle(sf::Text::Regular);}
        
        
        textesNiveaux[pageAccueil.niveau]->setStyle(sf::Text::Underlined);
        
        
        if(pageAccueil.curseur[0]==0){jouer.setCharacterSize(pageAccueil.tailleJouer+15);}
        else if(pageAccueil.curseur[0]==1){textesNiveaux[pageAccueil.curseur[1]]->setCharacterSize(pageAccueil.tailleTexteNiv+9);}
        
        wind->draw(pageAccueil.fond);
        wind->draw(instructionAccueil);
        wind->draw(jouer);
        wind->draw(facile);
        wind->draw(moyen);
        wind->draw(difficile);
        
        wind->display();
    }
}

void Rendu::lancerHorloge()
{
    sf::Time duree, delai;
    
    switch(etats::Partie::instance().niveau)
    {
        case 1 : delai=sf::milliseconds(200); break;
        case 2 : delai=sf::milliseconds(175); break;
        case 3 : delai=sf::milliseconds(150); break;
    }
    
    duree=delai;
    sf::Clock dt;
    while(wind->isOpen())
    {
        duree-=dt.restart();
        switch(etats::Partie::instance().niveau)
        {
            case 1 : delai=sf::milliseconds(200); break;
            case 2 : delai=sf::milliseconds(175); break;
            case 3 : delai=sf::milliseconds(150); break;
        }
        if(duree<=sf::Time::Zero)
        {
            if(etats::Partie::instance().play==true)
            {
                moteur::Moteur::instance().execCommande();
                etats::Partie::instance().serpent->avancer();
                update();
            }

            duree=delai;
        }
    }
}


void Rendu::update()
{
    unsigned int x = wind->getSize().x; //largeur
    unsigned int y = wind->getSize().y; //hauteur
    
    tailleCote = (int)std::fmin((float)(x/H),(float)(y/L));
    
    if(!map.load(sf::Vector2u((unsigned int)tailleCote, (unsigned int)tailleCote), L, H))
    {exit(-1);}
    if(y<x)
    {
    map.setPosition((x-(L*tailleCote))/2,0);
    }
    else
    {
        map.setPosition(0,(y-(H*tailleCote))/2);
    }
}

void Rendu::threadCallerHorloge()
{
    std::thread threadHorloge(&Rendu::lancerHorloge,this);
    threadHorloge.detach();
}

void Rendu::actualiserScores()
{
    std::string line, str = "Meilleurs scores :\n";
    std::ifstream lecture;
    lecture.open("ressources/score.txt");

    if(lecture.is_open()==false)
    {
        std::cout<<"impossible to open the score file"<<std::endl;return;
    }
    else
    {
        while(std::getline(lecture, line))
        {
            int i=0;
            while (line[i]!='\0')
            {	if(line[i]!=' ' && line[i]!='\n')
                {
                    line[i]+=5;
                }
                i++;
            }
            int nivo=std::atoi(line.substr(0, 1).c_str());
            if(etats::Partie::instance().niveau==nivo)
            {str+=line.substr(1, line.size()-1)+'\n';
            
            }
            
        }
        meilleursScores.setString(str);
    }
    lecture.close();
    return;
}




//void Rendu::gererRendu()
//{
//     sf::Font font;
//    if (!font.loadFromFile("ressources/Barrio-Regular.ttf"))
//    {
//        std::cout<<"impossible de charger la police désirée"<<std::endl;
//    }     
//    
//    sf::Text pause;
//    pause.setFont(font);pause.setString("Pause !");pause.setCharacterSize(100);pause.setFillColor(sf::Color::Red);pause.setPosition(wind->getSize().x/3, wind->getSize().y/3);
//    
//    sf::Text gameOver;
//    gameOver.setFont(font);gameOver.setString("GAME OVER !");gameOver.setCharacterSize(100);gameOver.setFillColor(sf::Color::Red);gameOver.setPosition(wind->getSize().x/4, wind->getSize().y/3);
//    
//    sf::Text victoire;
//    victoire.setFont(font);victoire.setString("VICTOIRE !");victoire.setCharacterSize(150);victoire.setFillColor(sf::Color::Red);victoire.setPosition(wind->getSize().x/4, wind->getSize().y/4);
//    //tailleCote = (int)std::fmin((float)(winX/L),(float)(winY/H));
//    
//    
//    while(wind->isOpen() && accueil==false)
//    {
//        wind->clear();
//        wind->draw(map);
//        if(partie->play==false && partie->isFin()==etats::FinPartie::NOP)wind->draw(pause);
//        if(partie->isFin()==etats::FinPartie::GAMEOVER)wind->draw(gameOver);
//        if(partie->isFin()==etats::FinPartie::VICTOIRE)wind->draw(victoire);
//        wind->display();
//    }
//}
//
//void Rendu::threadCallerRendu()
//{
//    std::thread threadRendu(&Rendu::gererRendu, this);
//    //threadRendu.detach();
//    //sf::Thread threadRendu(&Rendu::gererRendu, this);
//    //threadRendu.launch();
//}
};