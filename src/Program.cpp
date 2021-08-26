#include "Program.hpp"
#include "Utils.hpp"

Program::Program() 
{}

void Program::InitSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "error while initializing\n" <<  "error: " <<  SDL_GetError() << std::endl;
        m_window.Close();
    }
    if (TTF_Init() != 0) {
        std::cerr <<  "error while initializing sdl ttf\n";
        m_window.Close();
    }
	
	int flags=IMG_INIT_JPG|IMG_INIT_PNG;
	if ((IMG_Init(flags) & flags) != flags) {
		std::cerr << "error while initializing sdl image\n" << "error: " <<  IMG_GetError();
		m_window.Close();
	}
}

void Program::Init(const std::string& name) {
    srand(time(NULL)); // init random library with seed
    InitSDL();
    m_window.Init(name);
    m_renderer.Init(m_window.GetWindowPtr());

    m_gameMenu.Init(&m_window, &m_renderer, &m_input);

}

void Program::Start() {
    // main loop
    while (m_window.isOpen()) {
        Util::Sleep(10);
        m_renderer.Start();
        
        // render here
        m_renderer.Fill(Color(100, 100, 100), &m_window); // draw background
    
        m_gameMenu.Draw();
        
        m_renderer.End();

        HandleEvents();
        Update();
    }
}

void Program::HandleEvents() {

    while (m_window.Update()){
        SDL_Event event = m_window.GetEvent();
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

            case SDL_MOUSEMOTION:
                m_input.SetMousePos(Point{event.motion.x, event.motion.y});

            default:
                break;
        }
    }
}

void Program::Update() {
    m_gameMenu.Update();
}

Program::~Program() {
    std::cout << "exiting..\n";
    SDL_Quit();
}