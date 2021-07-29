#ifndef DMA_H
#define DMA_H

extern void DMA1_Init(void);
extern void DMA1_Transmit(const char* data);
extern void DMA1_Restart(void);
extern bool DMA1_Is_Sending(void);


#endif /* DMA_H */
