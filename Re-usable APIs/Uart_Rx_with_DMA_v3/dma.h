#ifndef DMA_H
#define DMA_H

#define DMA_STREAM5		5

#define DMA_STREAM5_MEMORY_INC_MODE				DMA_SxCR_MINC
#define DMA_STREAM5_TC_INT_ENABLE					DMA_SxCR_TCIE
#define DMA_STREAM5_CHANNEL4_SELECT				DMA_SxCR_CHSEL_2
#define DMA_STREAM5_CIRCULAR_BUFFER				DMA_SxCR_CIRC




extern void DMA_Start(void);

//Initializes the DMA channel for a desired USART
extern void DMA_USART_Rx_Init(DMA_Stream_TypeDef* dmaChannel, 
															USART_TypeDef* uartPort, 
															char* uartRxBuffer, 
															uint32_t bufferSize, 
															uint32_t dmaConfig);
															


extern bool DMA_Rx_InterruptReady(DMA_TypeDef* dmaPort, uint8_t streamNumber);
extern void DMA_Rx_Clear_Interrupt(DMA_TypeDef* dmaPort, uint8_t streamNumber);

#endif /* DMA_H */
