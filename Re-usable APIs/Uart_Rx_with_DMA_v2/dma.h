#ifndef DMA_H
#define DMA_H

#define No_Of_DMA1_Streams			8

extern void DMA1_Rx_Init(char* uartRxBuffer, uint32_t bufferSize);
extern void DMA1_Transmit(const char* data);
extern void DMA_Start(void);
extern void DMA1_Restart(void);
extern bool DMA1_Is_Sending(void);
extern bool DMA1_Rx_Interrupt_Ready(void);
extern void DMA1_Rx_Clear_Interrupt(void);


#endif /* DMA_H */
