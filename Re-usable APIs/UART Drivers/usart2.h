#ifndef USART2_H
#define USART2_H

extern void USART2_Init(void);
extern void USART2_Transmit_Byte(char buffer);
extern void USART2_Transmit_String(char* pString);
extern void USART2_Transmit_String_With_Null(char* pString);


#endif /* USART2_H */

