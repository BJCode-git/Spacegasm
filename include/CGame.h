#ifndef CGAME_H
#define CGAME_H

#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>
#include <CPacketHandler.h>
#include <SFGUI/SFGUI.hpp>
#define NET_PORT 17001
#include <Windows/MainMenu.h>
#include <Windows/ServerConnection.h>
class StartGame;
class ServerConnection;
class CNetworkManager;

class CGame
{
    public:
        enum State {
            GUI
        };
        CGame();
        virtual ~CGame();
        /**
            @brief This initializes the client.
        **/
        void onInit();
        /**
            @brief Connects to the specified IP-Adress
            @param IP The IPv4 to connect to (format: 127.0.0.1)
        **/
        void connectToIp(unsigned int IP, std::string username, std::string password);
        CNetworkManager* getNetworkManager();

        void quit();

        void lockDrawMutex();
        void unlockDrawMutex();
        void onConnectionEstablished(sf::Packet  packet, ENetPeer* peer);
        void onConsoleOutput(sf::Packet packet, ENetPeer* peer);

        CPacketHandler* getPacketHandler() {return m_packetHandler;}
    protected:
        void onEvent();
        void onUpdate();
        void onRender();
        void onExit();
    private:
        sigc::connection m_onConnectionEstablishedEventConnection;
        int m_loginWindowID, m_serverLobbyID;
        sf::RenderWindow *window;
        sf::Clock *m_FrameClock;
        sf::Time *m_FrameTime;
        Window::MainMenu *w_mainWindow;
        Window::ServerConnection *w_serverConnection;
        sfg::Desktop *m_desktop;
        sfg::SFGUI *m_sfgui;
        CNetworkManager *m_networkManager;
        CPacketHandler *m_packetHandler;
        std::thread *m_networkThread;
        int m_state;
        bool m_running;
        bool m_createLobbyWindow;
        std::mutex m_drawMutex;
};

#endif // CGAME_H
