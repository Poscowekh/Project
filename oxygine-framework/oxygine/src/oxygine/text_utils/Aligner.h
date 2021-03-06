#pragma once
#include "../oxygine-include.h"
#include "../Font.h"
#include "../Material.h"
#include "../TextStyle.h"
#include "../core/NativeTexture.h"
#include "../math/Color.h"
#include "../math/Rect.h"
#include <vector>

namespace oxygine
{
    struct glyph;
    class Font;


    namespace text
    {
        struct Symbol
        {
            Symbol(): x(0), y(0), code(0) {}

            short x, y;
            int code;
            glyph gl;
            RectF destRect;
            spSTDMaterial mat;
        };

        class Aligner
        {
        public:
            Aligner(const TextStyle& style, spSTDMaterial mat, const Font* font, float gscale, const Vector2& size);
            ~Aligner();


            const TextStyle& getStyle() const {return style;}
            float getScale() const;

            void begin();
            void end();

            int putSymbol(Symbol& s);
            void nextLine();


            TextStyle style;
            Rect bounds;
            int width;
            int height;
            size_t options;

            spSTDMaterial mat;

            const Font* _font;

        private:
            int getLineWidth()const;
            int getLineSkip()const;


            typedef std::vector<Symbol*> line;

            void _alignLine(line& ln);
            int _alignX(int rx);
            int _alignY(int ry);
            void _nextLine(line& ln);

            float _scale;
            int _x, _y;
            line _line;
            int _lineWidth;
            int _lineSkip;
        };
    }
}