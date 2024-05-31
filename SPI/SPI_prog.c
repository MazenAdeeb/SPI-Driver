/******************************************************************/
// Auther  : Mazen Adeeb                                          //
// Date    : 25/05/2022                                           //
// version : 0.0.1                                                //
// Driver  : SPI_driver                                           //
/******************************************************************/

#include "std_types.h"
#include "bit_math.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"

#include "DIO_interface.h" 

void SPI_voidInit(void)
{
    /*Data Order = MSB First*/
    CLEAR_BIT(SPI_u8_SPCR_REG, 5);
    /*Select Master Mode*/
    SET_BIT(SPI_u8_SPCR_REG, 4);
    /*Clk Polarity and phase*/
    SET_BIT(SPI_u8_SPCR_REG, 3);
    SET_BIT(SPI_u8_SPCR_REG, 2);
    /*Select clk => F/64*/
    CLEAR_BIT(SPI_u8_SPCR_REG, 0);
    SET_BIT(SPI_u8_SPCR_REG, 1);
    /*Enable SPI*/
    SET_BIT(SPI_u8_SPCR_REG, 6);
}
u8 SPI_u8TransRecieve(u8 copy_u8Data, u8 *copy_pu8DataRecived)
{

    u8 Local_StdError = STD_Sucesses;
    if (copy_pu8DataRecived != NULL)
    {
        /*Send Byte*/
        SPI_u8_SPDR_REG = copy_pu8DataRecived;
        /*Check if the transmission is completed*/
        while ((GET_BIT(SPI_u8_SPSR_REG, 7)) == 0)
            ;
        /*Read Byte*/
        *copy_pu8DataRecived = SPI_u8_SPDR_REG;
    }
    else
    {
        Local_StdError = STD_Error;
    }

    return Local_StdError;
}

void SPI_voidSlaveSendByte(u8 copy_u8DataByte)
{

    SPI_u8_SPDR_REG = copy_u8DataByte;
    // /*Check if the transmission is completed*/
    // while ((GET_BIT(SPI_u8_SPSR_REG,7)) == 0);
}

u8 SPI_u8ReciveByte(u8 *copy_pu8RecivedByte)
{

    u8 Local_StdError = STD_Sucesses;
    if (copy_pu8RecivedByte != NULL)
    {
        /*Check if the transmission is completed*/
        while ((GET_BIT(SPI_u8_SPSR_REG, 7)) == 0)
            ;
        /*Read Byte*/
        *copy_pu8RecivedByte = SPI_u8_SPDR_REG;
    }
    else
    {
        Local_StdError = STD_Error;
    }

    return Local_StdError;
}