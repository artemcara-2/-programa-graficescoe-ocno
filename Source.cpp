#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // 1. Создаем окно 800x600
    sf::RenderWindow window(sf::VideoMode({ 800 , 600 }), "magazin");

    // 2. Загружаем шрифт из системы или папки проекта
    sf::Font font;
    if (!font.openFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        std::cerr << "Ошибка загрузки шрифта!\n";
        return -1;
    }

    // 3. Создаем плашку/карточку (прямоугольник)
    sf::RectangleShape card(sf::Vector2f(800.f, 600.f));
    card.setPosition(sf::Vector2f(100.f, 100.f));
    card.setFillColor(sf::Color(30, 30, 45)); // Темно-синий фон
    card.setOutlineColor(sf::Color(100, 100, 250)); // Голубая рамка
    card.setOutlineThickness(2.f);

    // 4. Настраиваем крупный заголовок
    sf::Text titleText(font, "magazin product ", 48);
    titleText.setFillColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(sf::Vector2f(220.f, 200.f));



    // 5. Настраиваем подзаголовок
    sf::Text subText(font, "magazin productov ", 20);
    subText.setFillColor(sf::Color(10 , 30 , 40 ));
    subText.setPosition(sf::Vector2f(210.f, 100.f));

    // Главный цикл отрисовки
    while (window.isOpen()) {
        // Обработка событий (SFML 3 style)
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // --- ОТРИСОВКА ---
        // Очищаем экран фоновым темным цветом (RGB: 15, 15, 25)
        window.clear(sf::Color(15, 15, 25));

        // Рисуем объекты слой за слоем (снизу вверх)
        window.draw(card);
        window.draw(titleText);
        window.draw(subText);

        // Выводим собранный кадр на экран
        window.display();
    }

    return 0;
}