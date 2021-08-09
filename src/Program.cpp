#include "Program.hpp"
#include "Utils.hpp"

Program::Program() 
{}

void Program::InitSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "error while initializing\n" <<  "error: " <<  SDL_GetError() << std::endl;
        this->~Program();
    }
}

void Program::Init(const std::string& name) {
    srand(time(NULL)); // init random library with seed
    InitSDL();
    m_window.Init(name);
    m_renderer.Init(m_window.getWindowPtr());

    // init games
    m_snake.Init(&m_renderer, &m_window, &m_input, 0, 0, 40);
}

void Program::Start() {
    // main loop
    while (m_window.isOpen()) {
        m_renderer.Start();
        
        // render here
        m_renderer.Fill(Color(100, 100, 100), &m_window); // draw background

        m_snake.Draw(); 

        m_renderer.End();
        
        HandleEvents();
        Update();
    }
}

void Program::HandleEvents() {

    while (m_window.Update()){
        SDL_Event event = m_window.getEvent();
        switch (event.type) {
            case SDL_QUIT:
                m_window.Close();
                break;
            
            case SDL_KEYDOWN:
                m_input.PressKey(event);
                break;
            case SDL_KEYUP:
                m_input.ReleaseKey(event);
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                m_input.PressMouseButton(event);
                break;

            case SDL_MOUSEBUTTONUP:
                m_input.ReleaseMouseButton(event);
                break;

            default:
                break;
        }
    }
}

void Program::Update() {
    m_snake.Update();
}

Program::~Program() {

    std::cout << "exiting..\n";
    SDL_Quit();
}