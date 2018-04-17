#include "derivative.h" /* include peripheral declarations */
//-----------------------------------------------------------------------------------------------------------------
//--------------------------------------------------CONSTANTES-----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------	
					//Crea constantes numeradas, empezando desde 0
enum{				//Numeración para la máquina de estados	
	WAIT_WIFI,	    
	WAIT_OK,
	CONF_MUX,
	CONF_SERVER,
	SHOW_IP,
	WAIT_IP,
	SHOW_MAC,
	WAIT_MAC,
	WAIT_HEADER,
	WAIT_CHANNEL,
	WAIT_BYTES,
	WAIT_SEND,
	WAIT_SEND_OK,
	WAIT_CONNECTION,
	WAIT_REF,
	SET_REF,
	WAIT_TIME,
	SET_TIME,
	WAIT_ACT,
	SET_ACT,
	WAIT_END
};
enum{
	RED,
	GREEN,
	BLUE,
	WHITE,
	YELLOW,
	PINK,
	CYAN,
	ON,
	OFF,
	RESET,
	TOOGLE,
	TX_BUSY,
	TX_READY,
	AUTO,
	MANUAL
};
enum{				//Numeración para los mensajes
	READY,		
	WIFI_GOT_IP,
	WIFI_DISCONNECT,
	OK,
	ERROR,
	BUSY,
	SEND_OK,
	ARROW,			//>
	AT,
	AT_CWMODE,
	AT_CWJAP,
	AT_CIPSTA_DEF,
	AT_CIPMUX,
	AT_CIPSERVER,
	AT_CIFSR,
	AT_CIPSEND,
	AT_CIPCLOSE,
	AT_CIPSTART,
	STAIP,
	STAMAC,
	GET,
	IPD,
	COMA,
	DOS_PUNTOS,			//":"
	PUNTO,
	ESPACIO,
	COMILLA,
	SLASH,
	EXCLAMATION,
	INICIO_TRAMA,
	MENSAJE_RECIBIDO,
	CANAL_RECIBIDO,
	ENTER,
	BYTES_RECIBIDOS,
	LED_ROJO_ON,
	LED_AZUL_ON,
	LED_VERDE_ON,
	LED_BLANCO_ON,
	LED_AMARILLO_ON,
	LED_OFF,
	FOCO_ON,
	FOCO_OFF,
	COMANDO_NO_RECONOCIDO,
	PAGINA_WEB1,
	PAGINA_WEB2,
	PAGINA_WEB3,
	PAGINA_WEB4,
	QUERY1,
	QUERY2,
	QUERY3,
	QUERY4,
	QUERY5
};
//-----------------------------------------------------------------------------------------------------------------
//--------------------------------------------------MENSAJES-----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
unsigned char mensaje[60][120] ={
		"ready\r\n",				
		"WIFI GOT IP\r\n",
		"WIFI DISCONNECT\r\n",
		"OK\r\n",					
		"ERROR",				
		"busy\r\n",					
		"SEND OK\r\n",				
		">",					
		"AT\r\n",					
		"AT+CWMODE=3\r\n",			
		"AT+CWJAP=\"LJ\",\"12345678\"",
		"AT+CIPSTA_DEF=\"192.168.43.70\",\"192.168.43.1\",\"255.255.255.0\"",
		"AT+CIPMUX=1\r\n",			
		"AT+CIPSERVER=1,80\r\n",	
		"AT+CIFSR\r\n",				
		"AT+CIPSEND=",				
		"AT+CIPCLOSE=0\r\n",
		"AT+CIPSTART=4,\"TCP\",\"192.168.43.45\",80\r\n",
		"+CIFSR:STAIP,\"",
		"+CIFSR:STAMAC,\"",
		":GET /",					
		"+IPD,",					
		",",						
		":",						
		".",						
		" ",
		"\"",
		"/!",
		"!",
		"?",
		"MENSAJE RECIBIDO: ",		
		"CANAL RECIBIDO: ",			
		"\r\n",						
		"BYTES RECIBIDOS: ",		
		"LED ROJO ON\r\n",				
		"LED AZUL ON\r\n",
		"LED VERDE ON\r\n",
		"LED BLANCO ON\r\n",
		"LED AMARILLO ON\r\n",
		"LED OFF\r\n",
		"ON",
		"OFF",
		"COMANDO NO RECONOCIDO\r\n",
		"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: Close\r\n\r\n<html><head><title>ESP8266</title><body><p>",
		"</p><p>",
		"</p><p>",
		"</p></body></html>",
		"GET /SemestreI/psrLamp.php?idStatus=default&IP=",
		"&MAC=",
		"&stDate=now()&Estado=",
		"&Voltaje=",
		" HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"
};
//-----------------------------------------------------------------------------------------------------------------
//--------------------------------------------------VARIABLES GLOBALES-----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

unsigned char temp;							//Variable donde se guardará temporalmente el dato recibido por la UART
unsigned char mensaje_enviado[800];			//Arreglo donde se pondrá la información que será enviada
unsigned char buffer[200];					//Arreglo donde se guardará información temporal
unsigned char canal_recibido[2];			//Arreglo para el canal 
unsigned char bytes_recibidos[4];			//Arreglo para los bytes
unsigned char informacion_recibida[40];	    //Arreglo donde se guardará
unsigned char* pointer_UART0;
unsigned char* pointer_UART1;
unsigned char count_parser, count_parser2;	//Variable para llevar la cuenta de la comparación del parser
unsigned int count_msg;						//Variable para llevar la cuenta para almacenar los datos recibidos
unsigned int byte_size;						//Variable 
unsigned char tx_status;					//Variable que indica si se está mandando datos 
unsigned char actualState;					//Variable para aumentar la máquina de estados
unsigned int medicion, medicion2;			//Variables donde se guarda la medición de los sensores
unsigned char voltaje[6];					//Arreglo auxiliar para convertir la medición de entero a String
unsigned char lamp_status;					//Estado de la lámpara, ON, OFF o ERROR
unsigned char last_status = OFF;
unsigned char ip[20];
unsigned char mac[20];
unsigned char enable_transmit;
unsigned int time_count = 0;
unsigned char enable_time_out = 0;
unsigned int error_count = 0;
unsigned int time_out_count = 0;
unsigned int activation_method = AUTO;


unsigned int sensor1_ref = 40000;			//Referencia a la que se activará la lámpara 
unsigned int sensor2_ref = 20000;			//Referencia para saber si la lámpara está encendida 
unsigned int act_time = 10000;				//Variable de tiempo que indica cada cuánto se mandará un dato a la BD (ms)
unsigned int sense_time = 500;				//Variable de tiempo que indica cada cuánto se tomará una medición del sensor (ms)		
unsigned int error_time = 5000;				//Variable de tiempo que indica cada cuánto se mandará un reporte de error a la BS (ms)
unsigned int time_out = 1000;

//-----------------------------------------------------------------------------------------------------------------
//--------------------------------------------------DECLARACIÓN DE FUNCIONES-----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

void vUART_init(void);
void copy_AtoB(unsigned char *arrayA, unsigned char *arrayB);
unsigned char* integer_to_array(unsigned int dato,unsigned char *array);
unsigned int array_to_integer(unsigned char *array);
void clear_array(unsigned char *array);
unsigned int count_array(unsigned char *array);
void setLamp(unsigned char estado);
void setLEDColor(unsigned char color);
void setESP8266(unsigned char estado);
void UART1_send(unsigned char* msg);
void UART1_send_msg(unsigned char msg_ID);
void UART1_send_msg_address(unsigned char* msg_address);
unsigned char UART1_parser(unsigned char msg_ID);
unsigned char UART1_parser2(unsigned char msg_ID);
void join_String(unsigned char * String1, unsigned char * String2);
unsigned char* format(unsigned char msg_ID, unsigned char* buff );
unsigned int convertVoltage(unsigned int med);
void vUART_send_Console(unsigned char dato);
void vUART_send_msg_Console (unsigned char *a);

//-----------------------------------------------------------------------------------------------------------------
//--------------------------------------------------MAIN-----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

int main(void)
{
	vUART_init();				//Inicializar entradas y salidas
	setESP8266(OFF);	
	setLamp(OFF);
	setLEDColor(RED);			//Iniciar con todas las salidas apagadas
	setESP8266(ON);			//Resetear el módulo Wifi
	tx_status = TX_READY;
	actualState = WAIT_WIFI;		//Inicio de la máquina de estados
	enable_transmit = 0;
	count_parser = 0;
	count_parser2 = 0;
	count_msg = 0;

	while(1){
								
		//Loop infinito
		
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------
//--------------------------------------------------ISR´s-----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

void UART0_Status_IRQHandler(){
	if(UART0_S1&(1<<7)){				//Revisar si se puede escribir en la UART0
		UART0_D=*(pointer_UART0++);
		if(*pointer_UART0==0){
				tx_status = TX_READY; //Indica que ya terminó de mandar el mensaje
				UART0_C2&=~(1<<7);	  //Deshabilitar interrupción
			}
	}
}
void UART1_Status_IRQHandler(){
	if(tx_status == TX_BUSY){			//Solamente puede entrar a esta función si se mandó algo 
	if(UART1_S1&(1<<7)){				//Revisar si se puede escribir en la UART1
		UART1_D=*(pointer_UART1++);
		//UART0_D=*(pointer_UART1++);
		if(*pointer_UART1==0){
				tx_status = TX_READY;	//Indica que ya terminó de mandar el mensaje
				UART1_C2&=~(1<<7);		//Deshabilitar interrupción
			}
	}
	}
	if(UART1_S1&(1<<5)){
		do{}while(tx_status == TX_BUSY);		//Esperar por si todavía se está mandando algo
		
		temp = UART1_D;					//Guardar medoralmente el dato
		
		switch(actualState){
		
		case WAIT_WIFI:
			if(UART1_parser(WIFI_GOT_IP) == 1){		//Esperar a "ready" y mandar un "AT"
				actualState = WAIT_OK;
				UART1_send_msg(AT);
			}
			break;
		case WAIT_OK:
			if(UART1_parser(OK) == 1){			//Esperar un "OK" y mandar "AT+CIPMUX=..."
				actualState = CONF_MUX;
				UART1_send_msg(AT_CIPMUX);
			}
			break;
		case CONF_MUX:		
			if(UART1_parser(OK) == 1){			//Esperar un "OK" y mandar un "AT+CIPSERVER=..."
				actualState = CONF_SERVER;
				UART1_send_msg(AT_CIPSERVER);
			}
			break;
		case CONF_SERVER:						//Esperar un "OK"
			if(UART1_parser(OK) == 1){
				actualState = SHOW_IP; //SHOW_IP;
				UART1_send_msg(AT_CIFSR);
			}
			break;
		case SHOW_IP:						//Esperar un "STAIP"
			if(UART1_parser(STAIP) == 1){
				actualState = WAIT_IP;	
			}
			break;
		case WAIT_IP:						//Almacena el canal recibido (máximo 2 caracteres) hasta que encuentra una coma
			if(UART1_parser(COMILLA) == 1){
				canal_recibido[count_msg] = 0;
				count_msg = 0;
				actualState = SHOW_MAC;
			}
			else ip[count_msg++] = temp;
			break;
		case SHOW_MAC:						//Esperar un "STAIP"
			if(UART1_parser(STAMAC) == 1){
				actualState = WAIT_MAC;	
			}
			break;
		case WAIT_MAC:						//Almacena el canal recibido (máximo 2 caracteres) hasta que encuentra una coma
			if(UART1_parser(COMILLA) == 1){
				canal_recibido[count_msg] = 0;
				count_msg = 0;
				enable_transmit=1;
				setLEDColor(OFF);
				actualState = WAIT_HEADER;
			}
			else mac[count_msg++] = temp;
			break;
			
		case WAIT_HEADER:						//Esperar un "+IPD,"
					if(UART1_parser(IPD) == 1){
						actualState = WAIT_CHANNEL;
						count_msg = 0;
					}
					break;
		case WAIT_CHANNEL:						//Almacena el canal recibido (máximo 2 caracteres) hasta que encuentra una coma
					if(UART1_parser(COMA) == 1){
						canal_recibido[count_msg] = 0;
						count_msg = 0;
						actualState = WAIT_BYTES;
					}
					else canal_recibido[count_msg++] = temp;
					break;
		case WAIT_BYTES:											//Almacena los bytes recibidos (máximo 4 caracteres) hasta que encuentra dos puntos
					if(UART1_parser(DOS_PUNTOS) == 1){
						canal_recibido[count_msg] = 0;
						byte_size = array_to_integer(&bytes_recibidos[0]); //Convierte el arreglo de bytes_recibidos a entero
						count_msg = 0;
						if(enable_transmit) actualState = WAIT_ACT;
						else actualState = WAIT_REF;
					}
					else bytes_recibidos[count_msg++] = temp;
					break;
		case WAIT_ACT:						//Esperar un "+IPD,"
			byte_size--;
			enable_time_out = 2;
			if(UART1_parser(SLASH) == 1){
											//Desactiva la transmisión de datos mientras está recibiendo algo
				actualState = SET_ACT;
				clear_array(buffer);
			}
			break;
		case SET_ACT:						//Almacena el canal recibido (máximo 2 caracteres) hasta que encuentra una coma
			byte_size--;
			if(UART1_parser(EXCLAMATION) == 1){
				count_msg = 0;
				
				if(buffer[0] != '2'){
					activation_method = MANUAL;
					if(buffer[0] == '0') {
						setLamp(OFF);
						lamp_status = FOCO_OFF;
					}
					if(buffer[0] == '1'){
						setLamp(ON);
						lamp_status = FOCO_ON;
					}
				}
				else activation_method = AUTO;
				
				actualState = WAIT_END;
			}
			else buffer[count_msg++] = temp;
			break;
		case WAIT_END:						//Esperar un "+IPD,"
			byte_size--;
			if(byte_size == 0){
				copy_AtoB(format(PAGINA_WEB1,buffer), mensaje_enviado);
				vUART_send_msg_Console(mensaje_enviado);
				UART1_send_msg_address(format(AT_CIPSEND, buffer));
				actualState = WAIT_SEND;
			}
			break;
		case WAIT_REF:						//Esperar un "+IPD,"
			if(UART1_parser(INICIO_TRAMA) == 1){
				//enable_transmit=0;			//Desactiva la transmisión de datos mientras está recibiendo algo
				actualState = SET_REF;
				clear_array(buffer);
			}
			break;
		case SET_REF:						//Almacena el canal recibido (máximo 2 caracteres) hasta que encuentra una coma
			if(UART1_parser(PUNTO) == 1){
				count_msg = 0;
				sensor1_ref = array_to_integer(buffer);
				actualState = WAIT_TIME;
			}
			else buffer[count_msg++] = temp;
			break;
		case WAIT_TIME:						//Esperar a poder recibir el tiempo de activación
			if(UART1_parser(INICIO_TRAMA) == 1){
				actualState = SET_TIME;
				clear_array(buffer);
			}
			break;
		case SET_TIME:						//Almacena el tiempo de activación y actualiza su valor
			if(UART1_parser(PUNTO) == 1){
				count_msg = 0;
				
				act_time = array_to_integer(buffer);
				vUART_send_msg_Console(mensaje[ENTER]);	//Muestra un OK en la consola
				vUART_send_msg_Console(mensaje[OK]);
				actualState = WAIT_HEADER;
				
			}
			else buffer[count_msg++] = temp;
			break;
		
		case WAIT_CONNECTION:
			
			if(UART1_parser(OK) == 1){
				count_msg = 0;
				actualState = WAIT_SEND;
				clear_array(canal_recibido);
				canal_recibido[0]='4';
				copy_AtoB(format(QUERY1,buffer), mensaje_enviado);
				vUART_send_msg_Console(mensaje_enviado);
				UART1_send_msg_address(format(AT_CIPSEND, buffer));
				
			}

			break;
		case WAIT_SEND:						//Esperar un ">" para mandar un mensaje
			if(UART1_parser(ARROW) == 1){
				UART1_send(mensaje_enviado);	//Mandar el mensaje
				actualState = WAIT_SEND_OK;
			}
			break;
		case WAIT_SEND_OK:						//Esperar un "SEND OK" para terminar la comunicacion
			if(UART1_parser(SEND_OK) == 1){
				enable_time_out = 0; 
				setLEDColor(OFF);				//Resetea todas las variables usadas
				actualState = WAIT_HEADER;
				clear_array(canal_recibido);
				clear_array(bytes_recibidos);
				clear_array(informacion_recibida);
				if(enable_transmit){
					//UART1_send_msg(AT_CIPCLOSE);
					//UART1_send_msg_address(format(AT_CIPCLOSE, buffer));
					vUART_send_msg_Console(mensaje[ENTER]);	//Muestra un OK en la consola
					vUART_send_msg_Console(mensaje[LED_OFF]);
				}
				enable_transmit = 1;
			}
			break;
		default:
			break;		
		}
		if(UART1_parser2(WIFI_DISCONNECT) == 1){		//Si se desconecta el WIFI deja de transmitir datos y espera una nueva conexión
			count_msg = 0;
			enable_transmit = 0;
			setLEDColor(RED);
			actualState = WAIT_WIFI;
		}
		UART0_D = temp;					//Enviar el dato a la consola		
	}
}
void LPTimer_IRQHandler(void){
	LPTMR0_CSR|=(1<<7);					//Apagar bandera del TIMER
	ADC1_SC1A=(1<<6)+18;				//Activar conversión del canal 18 y activar interrupción
			
}

void ADC1_IRQHandler(void){
	ADC1_SC1A=(1<<7)+0x1F;	//Turn off COCO	and stop conversion
	medicion = ADC1_RA;			//RA is the data output
	
	if(activation_method == AUTO){
		if(medicion > sensor1_ref) {
			setLamp(OFF);
			lamp_status = FOCO_OFF;
		}
		else{
			setLamp(ON);
			lamp_status = FOCO_ON;
		}
	}
		
	ADC0_SC1A=(1<<6)+19; //pag 121 el pin está conectado a ADC0_DM0
}


void ADC0_IRQHandler(void){
	ADC0_SC1A=(1<<7)+0x1F;			//Turn off COCO	and stop conversion
	medicion2 = ADC0_RA;			//RA is the data output
	time_count += sense_time;		//
	
	if(enable_time_out != 0) time_out_count += sense_time;
	else time_out_count = 0;
	
	if(time_out_count >= time_out){
		/*if(enable_time_out == 2){
			copy_AtoB(format(PAGINA_WEB1,buffer), mensaje_enviado);
			vUART_send_msg_Console(mensaje_enviado);
			UART1_send_msg_address(format(AT_CIPSEND, buffer));
			actualState = WAIT_SEND;
		}
		else{*/
			enable_time_out = 0;
			actualState = WAIT_HEADER;
			setLEDColor(OFF);
		//}
	}
	
	if(medicion2 > sensor2_ref && lamp_status == FOCO_OFF) lamp_status = ERROR;
	if(medicion2 < sensor2_ref && lamp_status == FOCO_ON) lamp_status = ERROR;
	
	if(lamp_status == ERROR) error_count += sense_time;
	else error_count = 0;
	
	if(enable_transmit){ 
		if (time_count >= act_time || error_count >= error_time){
			enable_time_out = 1;
			setLEDColor(GREEN);
			time_count = 0;
			UART1_send_msg(AT_CIPSTART);
			actualState = WAIT_CONNECTION;
			enable_transmit = 0;
			
			if(error_count >= error_time)error_count = 0;
		}
	}	
}

//-----------------------------------------------------------------------------------------------------------------
//--------------------------------------------------FUNCIONES PRINCIPALES-----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

void vUART_send_Console(unsigned char dato){
	do{}while(!(UART0_S1& 0x80));
	UART0_D=dato; //mandar 'A'
}
void vUART_send_msg_Console (unsigned char *a){
	unsigned char i = 0;
	do{
		vUART_send_Console(a[i++]); 
		//i++;
	}while(a[i] != 0);
}
void UART1_send_msg(unsigned char msg_ID){			//Manda solamente mensajes previamente guardados en el arreglo de Mensajes
	//pointer_UART0=&mensaje[msg_ID][0];
	do{}while(tx_status == TX_BUSY);
	tx_status = TX_BUSY;
	pointer_UART1=&mensaje[msg_ID][0];				//Copia la dirección del arreglo al puntero global
	UART1_C2|=1<<7;
	//UART0_C2|=1<<7; 								//Enable interruption for UART1_Tx
}
void UART1_send_msg_address(unsigned char* msg_address){
	//pointer_UART0=&mensaje[msg_ID][0];
	do{}while(tx_status == TX_BUSY);
	tx_status = TX_BUSY;
	pointer_UART1=msg_address;				//Copia la dirección del arreglo al puntero global
	UART1_C2|=1<<7;
	//UART0_C2|=1<<7; 								//Enable interruption for UART1_Tx
}

void UART1_send(unsigned char* msg){							//
	unsigned char i = 0;
	do{
		do{}while(!(UART1_S1& 0x80));
		UART1_D=msg[i]; //mandar 'A'
		i++;
	}while(msg[i] != 0);
}

unsigned char UART1_parser(unsigned char msg_ID){
	if(temp == mensaje[msg_ID][count_parser]) count_parser++; //Si el nuevo dato es igual a la letra siguiente, aumenta la variable global
	else count_parser = 0;											//Si no, vuelve a iniciar

	if(mensaje[msg_ID][count_parser] == 0){
		count_parser = 0;
		return 1;													//Regresa un 1 si encontró la palabra
	}
	else return 0;													//Si no, regresa un 0
}

unsigned char UART1_parser2(unsigned char msg_ID){
	if(temp == mensaje[msg_ID][count_parser2]) count_parser2++; //Si el nuevo dato es igual a la letra siguiente, aumenta la variable global
	else count_parser2 = 0;											//Si no, vuelve a iniciar

	if(mensaje[msg_ID][count_parser2] == 0){
		count_parser2 = 0;
		return 1;													//Regresa un 1 si encontró la palabra
	}
	else return 0;													//Si no, regresa un 0
}


//-----------------------------------------------------------------------------------------------------------------
//--------------------------------------------------FUNCIONES SECUNDARIAS-----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

void vUART_init(void)
{
	//Configurar UART  
    SIM_SCGC4=0x00000C00; //Hab clk UART0 y UART1
    UART0_BDH=0;
    UART0_BDL=11;
    UART1_BDH=0;
    UART1_BDL=11;
    //UART0_C1=0;
    UART0_C2=12;           // bit 3: Hab Tx, bit 2: Hab Rx, Habilitar interrupción del Reciever
    UART1_C2=12 + (1<<5); // bit 3: Hab Tx, bit 2: Hab Rx, Habilitar interrupción del Reciever
    
    NVICICER0=(1<<(31%32));		//Configurar NVIC para UART0
    NVICISER0|=(1<<(31%32));
    
    NVICICER1=(1<<(33%32));		//Configurar NVIC para UART1
    NVICISER1|=(1<<(33%32));
    
    //Configurar pines
    SIM_SCGC5=0x00002C00 + 1; //Hab clk PORTB (PB16 y 17 son Rx y Tx) y PORTC
    PORTB_PCR16=0x00000300; //Hab clk PB16 Rx
    PORTB_PCR17=0x00000300; //Hab clk PB17 Tx
    PORTC_PCR3=0x00000300; //Hab clk PC3 Rx
    PORTC_PCR4=0x00000300; //Hab clk PC4 Tx
 
    								//Seleccionar pin como GPIO 
    PORTB_PCR21 = 0x00000100;		//Led Rojo	
    PORTB_PCR22 = 0x00000100;		//Led Azul
    PORTE_PCR26 = 0x00000100;		//Led Verde
    
    PORTC_PCR2 =  0x00000100;		//Relay
    PORTC_PCR5 = 0x00000100;		//Enable ESP8266
    PORTC_PCR7 = 0x00000100;		//Led
    
    
    GPIOB_PDDR = 0x00600000;//Dirección del pin (ouput)
    GPIOE_PDDR = 0x04000000;
    GPIOC_PDDR = 0x000000A4;
    
    //Configurar LPTMR
    LPTMR0_PSR = 0x05; //Configurar LPTMR
    LPTMR0_CMR = sense_time;
    LPTMR0_CSR = (1<<6) + 1;; //Habilitar LPTMR e Interrupción
	NVICICER1=(1<<(58%32));		//Configure NVIC for LPTMR0
	NVICISER1|=(1<<(58%32));	//Enable NVIC
	
	
	//Configurar ADC1
	SIM_SCGC3|= 1<<27;			//clock ADC1
	ADC1_CFG1=0x0C;				//Conversión de 16 bits
	NVICICER2=(1<<(73%32));		//Configure NVIC for ADC1
	NVICISER2|=(1<<(73%32));	//Enable NVIC
	
	//Configurar ADC0
	SIM_SCGC6|= 1<<27;			//clock ADC1
	ADC0_CFG1=0x0C;				//Conversión de 16 bits
	NVICICER1=(1<<(39%32));		//Configure NVIC for ADC1
	NVICISER1|=(1<<(39%32));	//Enable NVIC
	
	
}
void copy_AtoB(unsigned char *arrayA, unsigned char *arrayB){		//Copia la información del arreglo A al arreglo B
	clear_array(arrayB);
	int i = 0;
	do{
		arrayB[i]=arrayA[i];
	}while(arrayA[++i] != 0);
}
unsigned char* integer_to_array(unsigned int dato,unsigned char *array){ //Convierte de decimal a un arreglo
	clear_array(array);
	unsigned char  digit;
    unsigned char i = 0;
        if (dato == 0)					//Si el dato es 0, pone automaticamente 0
        {
            array[i++] = '0';
            array[i] = 0;
            return array;
        }
        if(dato / 10 == 0){				//Si el dato es menor a 9, pone automaticamente el dígito
            array[i++] = dato + '0';
            array[i] = 0;
            return array;
        }
        do{
            digit = dato % 10; 			//Multiplica el valor anterior por 10
            dato /= 10;			
            //Divide el dato entre 10 
            array[i++] = digit + '0';	//Suma el valor actual más el valor anterior
            }while(dato != 0);
        array[i] = 0;
        unsigned char inicio, fin, c;
        fin = i-1;
        inicio = 0;
        do{								//Invierte el orden del arreglo
            c = array[inicio];
            array[inicio] = array[fin];
            array[fin] = c;
        }while(++inicio < --fin);
        return array;
    }
unsigned int convertVoltage(unsigned int med){
	unsigned int dato = (med * 3300)/65500;
	return dato;	
}
unsigned int array_to_integer(unsigned char *array){
	
	unsigned int val = 0;
	unsigned char i = 0;
	
	do{
		val *= 10;
	    val += array[i] - '0';
	}while(array[++i] != 0);
	return val;
}
void clear_array(unsigned char *array){							//Limpia el arreglo recibido
	unsigned char i=0;
	do{
		array[i] = 0;
	}while(array[++i] != 0);
}
unsigned int count_array(unsigned char *array){					//Recibe un Arreglo de caracteres y cuenta la cantidad de datos
	
	unsigned int i = 0;
	do{}while(array[++i] != 0);
	return i;
	
}
void setLamp(unsigned char estado){
	if(estado ==  OFF) {
		GPIOC_PDOR &= ~(1 << 2);	//Apagar relay (Encender bit 2)
		GPIOC_PDOR |= 1 << 7;
	}
	if(estado ==  ON){
		GPIOC_PDOR |= 1 << 2;
		GPIOC_PDOR &= ~(1 << 7);
	}
	if(estado == TOOGLE){
		GPIOC_PTOR |= (1 << 2); //TOOGLE
		GPIOC_PTOR |= (1 << 7);
	}
	
}
void setESP8266(unsigned char estado){
	if(estado ==  OFF) GPIOC_PDOR &= ~(1 << 5); 	//Apagar relay (Encender bit 2)
	if(estado ==  ON) GPIOC_PDOR |= 1 << 5;
	if(estado == RESET){
		GPIOC_PDOR &= ~(1 << 5); 
		GPIOC_PDOR |= 1 << 5;		//Resetear el ESP8266
	}
}
void setLEDColor(unsigned char color){
	switch(color){
	case RED:
		GPIOB_PDOR = 0x00200000;
		GPIOE_PDOR = 0x04000000;
		break;
	case BLUE:
		GPIOB_PDOR = 0x00400000;
		GPIOE_PDOR = 0x04000000;
		break;
	case GREEN:
		GPIOB_PDOR = 0x00600000;
		GPIOE_PDOR = 0x00000000;
		break;
	case WHITE:
		GPIOB_PDOR = 0x00000000;
		GPIOE_PDOR = 0x00000000;
		break;
	case YELLOW:
		GPIOB_PDOR = 0x00200000;
		GPIOE_PDOR = 0x00000000;
		break;
	case OFF:
		GPIOB_PDOR = 0x00600000;
		GPIOE_PDOR = 0x04000000;
		break;
	case PINK:
		GPIOB_PDOR = 0x00000000;
		GPIOE_PDOR = 0x04000000;
		break;
	case CYAN:
		GPIOB_PDOR = 0x00400000;
		GPIOE_PDOR = 0x00000000;
		break;
	case TOOGLE:
		GPIOB_PTOR |= 1<<21;
		break;
	default: //OFF
		GPIOB_PDOR = 0x00600000;
		GPIOE_PDOR = 0x04000000;
		break;
	}
	// 31 30 29 28 || 27 26 25 24 || 23 22 21 20 || 19 18 17 16 || 15 14 13 12 || 11 10 09 08 || 07 06 05 04 || 03 02 01 00
	//Led Red --- PTB22
	//Led Blue -- PTB21
	//Led Green - PTE26
}
void join_String(unsigned char * String1, unsigned char * String2){	//Junta dos Strings en uno sólo
	unsigned char i = 0;
	unsigned char j = 0;
	do{}while(String1[++i] != 0);
	do{String1[i++] = String2[j];}while(String2[++j] != 0);
	String1[i] = 0;
	}

unsigned char* format(unsigned char msg_ID, unsigned char* buff ){	//Le da formato los mensajes que se quieren enviar en un sólo String
	clear_array(buff);
	if(msg_ID == AT_CIPSEND){
		copy_AtoB(mensaje[AT_CIPSEND], buff);
		join_String(buff, canal_recibido);
		join_String(buff, mensaje[COMA]);
		join_String(buff,integer_to_array(count_array(mensaje_enviado), bytes_recibidos));
		join_String(buff, mensaje[ENTER]);
	}
	if(msg_ID == AT_CIPCLOSE){
		copy_AtoB(mensaje[AT_CIPCLOSE], buff);
		join_String(buff, canal_recibido);
		join_String(buff, mensaje[ENTER]);
	}
	if(msg_ID == PAGINA_WEB1){
		copy_AtoB(mensaje[PAGINA_WEB1], buff);
		join_String(buff, integer_to_array(medicion, voltaje));
		join_String(buff, mensaje[PAGINA_WEB2]);
		join_String(buff, integer_to_array(medicion2, voltaje));
		join_String(buff, mensaje[PAGINA_WEB3]);
		join_String(buff, mensaje[lamp_status]);
		join_String(buff, mensaje[PAGINA_WEB4]);
	}
	if(msg_ID == QUERY1){
		copy_AtoB(mensaje[QUERY1], buff);
		join_String(buff,ip);
		join_String(buff, mensaje[QUERY2]);
		join_String(buff, mac);
		join_String(buff, mensaje[QUERY3]);
		join_String(buff, mensaje[lamp_status]);
		join_String(buff, mensaje[QUERY4]);
		join_String(buff, integer_to_array(medicion, voltaje));
		join_String(buff, mensaje[QUERY5]);
	}
	return buff;
}

