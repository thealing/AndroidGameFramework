#pragma once

#include "geometry.h"

#include "image.h"

#define GRAPHICS_HISTORY_SIZE 10

#define GRAPHICS_CIRCLE_RESOLUTION 32

typedef enum Alignment Alignment;

typedef struct Texture Texture;

typedef struct Color Color;

enum Alignment
{
	ALIGNMENT_LEFT,

	ALIGNMENT_RIGHT,

	ALIGNMENT_BOTTOM,

	ALIGNMENT_TOP,

	ALIGNMENT_CENTER,

	ALIGNMENT_COUNT
};

struct Texture
{
	Vector size;

	Vector center;

	int id;
};

struct Color
{
	double red;

	double green;

	double blue;

	double alpha;
};

Texture* texture_create_from_image(const Image* image);

Texture* texture_create_from_file(const char* path);

void texture_destroy(Texture* texture);

void texture_scale(Texture* texture, Vector scale);

void texture_resize(Texture* texture, Vector size);

void graphics_init(void* window);

void graphics_uninit(void* window);

void graphics_display();

void graphics_clear(const Color* color);

void graphics_set_camera(const Rect* rect);

void graphics_set_color(const Color* color);

void graphics_set_texture(const Texture* texture);

void graphics_set_font(const Texture* font);

void graphics_save_state();

void graphics_load_state();

void graphics_save_transform();

void graphics_load_transform();

void graphics_translate(Vector translation);

void graphics_rotate(double angle);

void graphics_scale(Vector factor);

void graphics_scale_uniformly(double factor);

void graphics_draw_segment(const Segment* segment, bool fill);

void graphics_draw_circle(const Circle* circle, bool fill);

void graphics_draw_polygon(const Polygon* polygon, bool fill);

void graphics_draw_shape(const Shape* shape, bool fill);

void graphics_draw_rect(const Rect* rect, bool fill);

void graphics_draw_texture();

void graphics_draw_texture_at(Vector position, double angle);

void graphics_draw_texture_in_rect(const Rect* rect);

void graphics_draw_texture_in_quad(const Vector quad[4]);

void graphics_draw_texture_rect_in_rect(const Rect* texture_rect, const Rect* rect);

void graphics_draw_texture_rect_in_quad(const Rect* texture_rect, const Vector quad[4]);

void graphics_draw_texture_quad_in_quad(const Vector texture_quad[4], const Vector quad[4]);

void graphics_draw_character_in_rect(const Rect* rect, char character);

void graphics_draw_string_in_rect(const Rect* rect, Alignment alignment, const char* string);

void graphics_draw_format_in_rect(const Rect* rect, Alignment alignment, const char* format, ...);

void graphics_draw_string(Alignment horizontal_alignment, Alignment vertical_alignment, const char* string);

void graphics_draw_format(Alignment horizontal_alignment, Alignment vertical_alignment, const char* format, ...);
