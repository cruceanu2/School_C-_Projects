#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
#include<SFML/Graphics/Color.hpp>
using namespace std;
class oscilator
{
private:
    float g = 9.8;
    float e = 0.71828182;
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
        x = A0*pow(e, (C * t.asSeconds())/ (m / 2)) * sin(w * t.asSeconds() + fi);
        return x;
    }
    int getposA(sf::Time t)
    {
        x = A0*pow(e, (C * t.asSeconds())/ (m / 2)) * sin(w * t.asSeconds() + fi);
        return (A0*pow(e, (C * t.asSeconds()) / (m / 2) ));
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
        osc.m = 3;
        osc.C = 1;
    }
    else{
        if(amortizare == "f")
        {
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
    osc.getvariables();
    sf::Time t;
    sf::RenderWindow window (sf::VideoMode(1080, 501), "Oscilator");
    sf::RectangleShape line(sf::Vector2f(1, 1));
    sf::RectangleShape pointx(sf::Vector2f(1, 1));
    sf::RectangleShape pointA(sf::Vector2f(1, 1));
    line.setPosition(0, 251);
    line.setFillColor(sf::Color::Red);
    pointA.setFillColor(sf::Color::Blue);
    sf::Clock clock;
    while (window.isOpen())
    {
        t = clock.getElapsedTime();
        pointx.setPosition(t.asMilliseconds() / 75, 251 - osc.getposx(t));
        pointA.setPosition(t.asMilliseconds() / 75, 251 - osc.getposA(t));
        line.setPosition(t.asMilliseconds() / 75, 251);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(line);
        window.draw(pointA);
        window.draw(pointx);
        window.display();
    }
}
