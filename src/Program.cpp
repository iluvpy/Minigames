#include "Program.hpp"

Program::Program() 
{}

void Program::InitSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "error while initializing\n" <<  "error: " <<  SDL_GetError() << std::endl;
        this->~Program();
    }
}

void Program::Init(const std::string& name) {
    InitSDL();
    m_window.Init(name);
    m_renderer.Init(m_window.getWindowPtr());

}

void Program::Start() {
    SnakeGrid snake_grid(&m_renderer, &m_window, 0, 0, 40);

    while (m_window.isOpen()) {
        m_renderer.Start();
        
        // render here
        m_renderer.Fill(Color(100, 100, 100), &m_window);

        snake_grid.Draw();

        m_renderer.End();
        
        HandleEvents();
    }
}

void Program::HandleEvents() {

    while (m_window.Update()){
        switch (m_window.getEvent()) {
            case SDL_QUIT:
                m_window.Close();
                break;
            
            default:
                break;
        }
    }
}
 
Program::~Program() {
    m_window.Quit();
    m_renderer.Quit();

    std::cout << "exiting..\n";
    SDL_Quit();
}