#ifndef HC06_H
#define HC06_H

extern void HC06_Rx_Init(char* hc06RxBuffer);
extern bool HC06_Rx_Done_Receiving(void);
extern void HC06_Restart(char* hc06Rxbuffer);
extern void HC06_Begin(void);

#endif /* HC06_H */
