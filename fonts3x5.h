const static unsigned char font[] PROGMEM =
{
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x1F,0x11,0x1F,0x00,
  0x12,0x1F,0x10,0x00,
  0x1D,0x15,0x17,0x00,
  0x15,0x15,0x1F,0x00,
  0x07,0x04,0x1F,0x00,
  0x17,0x15,0x1D,0x00,
  0x1F,0x14,0x1C,0x00,
  0x01,0x01,0x1F,0x00,
  0x1F,0x15,0x1F,0x00,
  0x07,0x05,0x1F,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,
  0x1E,0x05,0x1E,0x00,
  0x1F,0x15,0x0A,0x00,
  0x0E,0x11,0x0A,0x00,
  0x1F,0x11,0x0E,0x00,
  0x1F,0x15,0x11,0x00,
  0x1F,0x05,0x01,0x00,
  0x1F,0x11,0x1D,0x00,
  0x1F,0x04,0x1F,0x00,
  0x11,0x1F,0x11,0x00,
  0x18,0x10,0x1F,0x00,
  0x1F,0x04,0x1B,0x00,
  0x1F,0x10,0x10,0x00,
  0x1F,0x06,0x1F,0x00,
  0x1F,0x0E,0x1F,0x00,
  0x0E,0x11,0x0E,0x00,
  0x1F,0x05,0x02,0x00,
  0x0E,0x11,0x1E,0x00,
  0x1F,0x05,0x1A,0x00,
  0x12,0x15,0x09,0x00,
  0x01,0x1F,0x01,0x00,
  0x1F,0x10,0x1F,0x00,
  0x07,0x18,0x07,0x00,
  0x1F,0x0C,0x1F,0x00,
  0x1B,0x04,0x1B,0x00,
  0x03,0x1C,0x03,0x00,
  0x19,0x15,0x13,0x00 
};

void drawString(int8_t X, int8_t Y, char const string[] = NULL, int8_t min_len = 0, char const prog_string[] = NULL);
void drawString(int8_t X, int8_t Y, char const string[], int8_t min_len, char const prog_string[]){
  int8_t letters = 0;
  char len=0;
  if(string != NULL){
    len = strlen(string);
  }else{
    len = strlen_P(prog_string);
  }
  if(min_len>0){
    char pad = min_len-len;
    letters+=pad;
    for(int8_t t=0; t< pad; t++){
    char d = 48;
    if(d<=32){d=0;}
    else{d-=32;}  
      for (int8_t i=0; i<4; i++ ){
        uint8_t line;
        line = pgm_read_byte(font+(d*4)+i);
    
        for (int8_t j = 0; j<6; j++)
        {
          uint8_t draw_color = (line & 0x1) ? 1 : 0; 
          if(draw_color!=0){
            arduboy.drawPixel(X + i +(t*4), Y + j, draw_color);
          }
          line >>= 1;
        }
      }  
    }
  }
  for(int8_t t=0; t<len; t++){
    char d;
    if(string != NULL){
      d = string[t];
    }else{
      d = pgm_read_byte(prog_string+t);
    }
    if(d<=32){d=0;}
    else{d-=32;}    
    for (int8_t i=0; i<4; i++ ){
      uint8_t line;
      line = pgm_read_byte(font+(d*4)+i);  
      for (int8_t j = 0; j<6; j++) {
        uint8_t draw_color = (line & 0x1) ? 1 : 0; 
        if(draw_color!=0){
          arduboy.drawPixel(X + i +((t+letters)*4), Y + j, draw_color);
        }
        line >>= 1;
      }
    }  
  }
}