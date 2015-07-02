#ifndef GRAPHICTAB_HPP
#define GRAPHICTAB_HPP

#include <TGUI/TGUI.hpp>
#include "../include/GraphicListItem.hpp"

namespace prattle
{
    class GraphicTab : public tgui::Widget
    {
        public:
            // Member functions
            typedef std::shared_ptr<GraphicTab> Ptr;
            typedef std::shared_ptr<const GraphicTab> ConstPtr;

        public:
            void initialize(tgui::Container *const parent);
            GraphicTab();
            ~GraphicTab();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            virtual Widget::Ptr clone() override;
            bool mouseOnWidget(float x, float y);
            virtual void mouseMoved(float x, float y) override;
            virtual void leftMousePressed(float x, float y) override;
            void addTab(const std::string& tabLabel);
            void focusTab(const unsigned int& tabIndex);
            void removeTab(unsigned int index);
            void setPosition(const sf::Vector2f& position);
            const sf::Vector2f getPosition();
            void setSize(const sf::Vector2f& size);
            const sf::Vector2f getSize();
            void select(const std::string& tabLabel);
            const unsigned int getSelectedTabIndex();
            void deselect();
            virtual void update() override;
            bool isTabVisible(const unsigned int& tabIndex);
            const unsigned int getTabCount();

        private:

            // test member
            int tc = 1;

            // Members
            sf::FloatRect                     m_absoluteBounds;
            //sf::FloatRect                     m_visibleBounds;
            sf::Texture                       m_arrowTexture;
            sf::Sprite                        m_leftArrow;
            sf::Sprite                        m_rightArrow;
            bool                              m_leftArrowVisibile;
            bool                              m_rightArrowVisibile;
            sf::Texture*                      m_tabTexture;
            sf::Texture*                      m_tabActiveTexture;
            std::vector<sf::RectangleShape>   m_tabs;
            unsigned short                    m_visibleTabs;
            unsigned short                    m_firstTabVisible;
            unsigned short                    m_lastTabVisible;
            std::vector<bool>                 m_tabVisibility;
            std::vector<GraphicListItem::Ptr> m_items;
            std::shared_ptr<sf::Texture>      m_GLItemTexPtr;
            std::string                       m_selected;
            sf::Texture                       m_iconTexture;
            std::vector<sf::Sprite>           m_iconSprites;
            std::shared_ptr<sf::Font>         m_font;
            sf::Vector2f                      m_maxDefaultTabSize;
    };
}

#endif // GRAPHICTAB_HPP