#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
#include<SFML/Graphics/Color.hpp>
using namespace std;
class oscilator
{
private:
    float g = 9.8;
    float e = 2.71828182;
public:
    float x, A0, m, C, fi, w, k;
    int fluid ()
    {
        k = g;
    }
    int getvariables()
    {
        fi = asin(x/A0);
        w = sqrt(k/m);
    }
    int getposx(sf::Time t)
    {
        x = A0*pow(e, -(C * t.asSeconds())/ (m / 2)) * sin(w * t.asSeconds() + fi);
        return x;
    }
    int getposA(sf::Time t)
    {
        return (A0*pow(e, -(C * t.asSeconds()) / (m / 2) ));
    }
}osc;
int main()
{
    string amortizare;
    cout<<"Amortizare fluida sau uscata? (f/u) ";cin>>amortizare;
    if(amortizare == "demo")
    {
        osc.x = 0;
        osc.A0 = 250;
        osc.m = 0.3;
        osc.C = 0.05;
        osc.fluid();
    }
    else{
        if(amortizare == "f-g")
        {
            cout<<"Acceleratia gravitationala: ";cin>>osc.k;
        }
        else if(amortizare == "f"){
        osc.fluid();
        }
        cout<<"Elongatia initiala: ";cin>>osc.x;
        cout<<"Amplitudinea initiala: ";cin>>osc.A0;
        cout<<"Masa corpului: ";cin>>osc.m;
        cout<<"Forta de rezistenta: ";cin>>osc.C;
        if(amortizare =="u")
        {
            cout<<"Constanta de elasticitate a resortului: ";cin>>osc.k;
        }
    }
    int a, b;
    a = 1921;
    b = 1080;
    osc.getvariables();
    sf::Time t;
    sf::RenderWindow window (sf::VideoMode(a, b), "Oscilator");
    window.setFramerateLimit(60);
    sf::RectangleShape line(sf::Vector2f(10000, 4));
    sf::RectangleShape pointx(sf::Vector2f(1, 1));
    sf::RectangleShape pointA(sf::Vector2f(1, 1));
    sf::RenderTexture rendertexture;
    rendertexture.create(1920, 1080);
    sf::Texture texture;
    sf::Sprite sprite;
    line.setPosition(0, b/2 -3);
    pointx.setFillColor(sf::Color::Red);
    pointA.setFillColor(sf::Color::Blue);
    rendertexture.draw(line);
    texture = rendertexture.getTexture();
    sprite.setTexture(texture);
    sf::Clock clock;
    while (window.isOpen())
    {
        t = clock.getElapsedTime();
        pointx.setPosition(t.asMilliseconds() / 75, b/2 + 1 - osc.getposx(t));
        pointA.setPosition(t.asMilliseconds() / 75, b/2 + 1 - osc.getposA(t));
        //line.setPosition(t.asMilliseconds() / 75, 251);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        rendertexture.clear();
        rendertexture.draw(sprite);
        rendertexture.draw(pointA);
        rendertexture.draw(pointx);
        rendertexture.display();
        texture = rendertexture.getTexture();
        sprite.setTexture(texture);
        window.draw(sprite);
        window.display();

    }
}
