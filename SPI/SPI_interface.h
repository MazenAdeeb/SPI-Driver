/******************************************************************/
// Auther  : Mazen Adeeb                                          //
// Date    : 25/05/2022                                           //
// version : 0.0.1                                                //
// Driver  : SPI_driver                                           //
/******************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidInit(void);

u8 SPI_u8TransRecieve(u8 copy_u8Data, u8 *copy_pu8DataRecived);

void SPI_voidSlaveSendByte(u8 copy_u8DataByte);

u8 SPI_u8ReciveByte(u8 *copy_pu8RecivedByte);


#endif