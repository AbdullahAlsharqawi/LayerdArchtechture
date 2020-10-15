

/*  -ref voltage
    -prescalar
	-mode of operation
	-resolution-> 8 bit or 10 bit
	*/
void ADC_voidInitialize(void);

u8 ADC_Start_conversion(u8 Channel_Number);

#if  8bit resolution
u8 Get_Result(void);

#elif 16bit resolution
u16 Get_Result(void);


void set_callback(void (ptr*) (void));