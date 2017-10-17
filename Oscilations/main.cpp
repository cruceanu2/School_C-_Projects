#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
#include<SFML/Graphics/Color.hpp>
#include<SFML/System/Vector2.hpp>
using namespace std;
class oscilator
{
private:
    float g = 9.8;
    float e = 2.71828182;
public:
    float x, A0, m, C, fi, w, k, l, Acurrent;
    bool uscat = 0;
    int fluid ()
    {
        k = g;
    }
    int getvariables_uscate()
    {
        fi = asin(x/A0);
        w = sqrt(k/m);
    }
    int getvariables_fluide()
    {
        fi = asin(x/A0);
        w = sqrt(k/l);
    }
    int set_uscat()
    {
        uscat = 1;
    }
    int is_dead()
    {
        if(x == Acurrent)
        {
            if(C * m * g >= x * k)
            {
                return 1;
            }
        }
        return 0;
    }
    int getposx(sf::Time t)
    {
        if(uscat)
        {
            if(is_dead())
            {
                return x;
            }
        }
        x = Acurrent * sin(w * t.asSeconds() + fi);
        return x;
    }
    int getposA(sf::Time t)
    {
        if(uscat)
        {
            if(is_dead())
            {
                return x;
            }
        }
        Acurrent = A0*pow(e, -(C * t.asSeconds()) / (m / 2) );
        return Acurrent;
    }
}osc;
int main()
{
    string amortizare;
    cout<<"Amortizare fluida sau uscata? (f/u) ";cin>>amortizare;
    if(amortizare == "demo")
    {
        osc.x = 0;
        osc.A0 = 500;
        osc.m = 1;
        osc.C = 0.09;
        osc.l = .5;
        osc.fluid();
        osc.getvariables_fluide();
    }
    else{
        cout<<"Elongatia initiala: ";cin>>osc.x;
        cout<<"Amplitudinea initiala: ";cin>>osc.A0;
        cout<<"Masa corpului: ";cin>>osc.m;
        cout<<"Coeficientul de frecare vascoasa: ";cin>>osc.C;
        if(amortizare == "f-g")
        {
            cout<<"Acceleratia gravitationala: ";cin>>osc.k;
            cout<<"Lungimea firului: ";cin>>osc.l;
            osc.getvariables_fluide();
        }
        if(amortizare == "f"){
            cout<<"Lungimea firului: ";cin>>osc.l;
            osc.fluid();
            osc.getvariables_fluide();
        }
        else if(amortizare =="u")
        {
            cout<<"Constanta de elasticitate a resortului: ";cin>>osc.k;
            osc.getvariables_uscate();
            osc.set_uscat();
        }
    }
    int a = 1921, b = 1080;
sf::Time t;
sf::RenderWindow window (sf::VideoMode(a, b), "Oscilator");
window.setFramerateLimit(60);
sf::RectangleShape line(sf::Vector2f(10000, 3));
sf::RectangleShape pointx(sf::Vector2f(2, 2));
sf::RectangleShape pointA(sf::Vector2f(2, 2));
sf::RenderTexture rendertexture;
sf::Texture texture;
sf::Sprite sprite;
sf::Vector2f previousx;
sf::Vector2f previousA;
    rendertexture.create(a, b);   //setting the stuff for render stuff...
    line.setPosition(0, b/2 -3);
    pointx.setFillColor(sf::Color::Red);
    pointA.setFillColor(sf::Color::Blue);
    rendertexture.draw(line);
    texture = rendertexture.getTexture();
    sprite.setTexture(texture);
    sf::VertexArray oscilatie(sf::LinesStrip, 2);
    sf::VertexArray amplitudine(sf::LinesStrip, 2);
    sf::Clock clock; //set clock
    while (window.isOpen())
    {
        previousx = pointx.getPosition();
        previousA = pointA.getPosition();
        oscilatie[0].position = previousx;
        amplitudine[0].position = previousA;
        oscilatie[0].color = sf::Color::Red;
        amplitudine[0].color = sf::Color::Blue;
        t = clock.getElapsedTime();
        pointx.setPosition(t.asMilliseconds() / 75, b/2 + 1 - osc.getposx(t));
        pointA.setPosition(t.asMilliseconds() / 75, b/2 + 1 - osc.getposA(t));
        oscilatie[1] = pointx.getPosition();
        amplitudine[1] = pointA.getPosition();
        oscilatie[1].color = sf::Color::Red;
        amplitudine[1].color = sf::Color::Blue;
        //line.setPosition(t.asMilliseconds() / 75, 251);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        rendertexture.clear();
        rendertexture.draw(sprite); // using the previously drawn sprite
        rendertexture.draw(amplitudine); //
        rendertexture.draw(oscilatie); //
        rendertexture.display();    //rendering the texture
        texture = rendertexture.getTexture();   //setting the texture
        sprite.setTexture(texture);     //attributing to the sprite the texture
        window.draw(sprite);
        window.display();
    }
}
