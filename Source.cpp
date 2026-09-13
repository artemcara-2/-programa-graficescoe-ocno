#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // 1. Создаем окно 800x600
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "magazin");

    // 2. Загружаем шрифт из системы
    sf::Font font;
    if (!font.openFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        std::cerr << "Ошибка загрузки шрифта!\n";
        return -1;
    }

    // 3. Загружаем фоновую картинку
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("pervi-ecran.png")) {
        std::cerr << "Не удалось загрузить фон!\n";
        return -1;
    } // Лишняя точка с запятой убрана

    sf::Sprite background(bgTexture);

    // 4. Настраиваем текст кнопки
    sf::Text subText(font, "producti", 48);
    subText.setFillColor(sf::Color(255, 255, 255));
    subText.setPosition(sf::Vector2f(320.f, 300.f));

    // Переменные для мигания кнопки
    sf::Clock blinkClock;
    bool isVisible = true;

    // Главный цикл отрисовки
    while (window.isOpen()) {
        // Обработка событий (SFML 3 style)
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }


        // --- ОТРИСОВКА ---
        window.clear(sf::Color(15, 15, 25));

        // 1. Рисуем картинку из Illustrator
        window.draw(background);

        // Выводим кадр
        window.display();
    }

    return 0;
};