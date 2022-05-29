#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace std;
int main()
{
    string path;
    cout << "Input Image Path:";
    cin >> path;
    int limit;
    cout << "\nInput Limit:";
    cin >> limit;
    sf::Image _image;
    _image.loadFromFile(path);
    vector<bool> list;
    for (int y = 0; y < _image.getSize().y; y++)
    {
        for (int x = 0; x < _image.getSize().x; x++)
        {
            int grey = _image.getPixel(x, y).r * 0.299 + _image.getPixel(x, y).g * 0.587 + _image.getPixel(x, y).b * 0.114;
            if (grey > limit)
            {
                _image.setPixel(x, y, sf::Color::White);
                list.insert(list.end(), true);
            }
            else
            {
                _image.setPixel(x, y, sf::Color::Black);
                list.insert(list.end(), false);
            }
        }
    }
    _image.saveToFile("New.png");
    int _x = 0;
    ofstream file;
    string str;
    file.open("image.txt", ios::out);
    cout << _image.getSize().x << endl;
    for (bool x : list)
    {
        if (_x == _image.getSize().x)    
        {
            cout << "\n";
            file << "\n";
            str += "\n";
            _x = 0;
        }
        if (x)
        {
            cout << " ";
            file << " ";
            str += " ";
        }
        else
        {
            cout << "嗨";
            file << "嗨";
            str += "嗨";
        }
        _x++;
    }
    file.close();
    cin.get();
}