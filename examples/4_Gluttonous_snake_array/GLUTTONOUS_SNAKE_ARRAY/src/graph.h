#ifndef __GRAPH_H__
#define __GRAPH_H__

#ifdef __cplusplus

extern "C" {

#endif 

extern void init_graph();
extern void draw_square(uint16_t x,uint16_t y,uint8_t length);
extern void clear_square(uint16_t x,uint16_t y,uint8_t length);
extern void draw_line(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);

#ifdef __cplusplus

  }

#endif /* end of __cplusplus */ 

#endif