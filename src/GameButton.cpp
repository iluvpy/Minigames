#include "GameButton.hpp"

void GameButton::Init(Renderer *renderer, int x, int y, const std::string& img_path, int outlineWidth, const Color& backgroundColor, const Color& outlineColor) {
	m_renderer = renderer;
	m_image.Init(m_renderer, x, y, img_path);
	int image_w, image_h;
	image_w = m_image.GetWidth();
	image_h = m_image.GetHeight();
	m_button.Init(x, y, image_w, image_h, backgroundColor, backgroundColor);
	m_outlineRect.Init(x-outlineWidth, y-outlineWidth, image_w+outlineWidth*2, image_h+outlineWidth*2, backgroundColor);

	m_backgroundColor = backgroundColor;
	m_outlineColor = outlineColor;
}

const GUIButton& GameButton::GetButton() {
	return m_button;
}

void GameButton::Update(InputHandler *input) {
	m_button.Update(input);

	if (m_outlineRect.IsOntop(input->GetMousePos())) 
		m_outlineRect.SetColor(m_outlineColor);
	else 
		m_outlineRect.SetColor(m_backgroundColor);

}

void GameButton::Draw() {
	m_outlineRect.Draw(m_renderer);
	m_button.Draw(m_renderer);
	m_image.Draw();
}
