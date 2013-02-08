#include <CGame.h>

void CGame::onEvent()
{
    sf::Event event;
    while(this->window->pollEvent(event))
    {
        m_desktop->HandleEvent(event);
        if(event.type == sf::Event::Closed)
        {
            this->m_running = false;
        }
    }
}
