/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "derivative.h" /* include peripheral declarations */

unsigned char* mens_recieve[10] ={
		"",
		"ready\r\n",				//1
		"WIFI GOT IP\r\n",			//2
		"OK\r\n",					//3
		"ERROR\r\n",				//4
		"busy\r\n",					//5
		"SEND OK\r\n",				//6
		">"							//7
};
unsigned char* mens_control[10] ={
		"AT\r\n",					//0
		"AT+CWMODE=3\r\n",			//1
		"AT+CWJAP=\"LJ\",\"12345678\"",//2
		"AT+CIPSTA_DEF=\"192.168.43.70\",\"192.168.43.1\",\"255.255.255.0\"",//3
		"AT+CIPMUX=1\r\n",			//4
		"AT+CIPSERVER=1,80\r\n",	//5
		"AT+CIFSR\r\n",				//6
		"AT+CIPSEND=",				//7
		"AT+CIPCLOSE="
		
};
unsigned char* mens_parser[10] = {
		":GET /",					//0
		"+IPD,",					//1
		",",						//2
		":",						//3
		".",						//4
		" "							//5
};

unsigned char* mens_console[15] = {
		"MENSAJE RECIBIDO: ",		//0
		"CANAL RECIBIDO: ",			//1
		"\r\n",						//2
		"BYTES RECIBIDOS: ",		//3
		"LED ROJO ON\r\n",				//4
		"LED AZUL ON\r\n",
		"LED VERDE ON\r\n",
		"LED BLANCO ON\r\n",
		"LED AMARILLO ON\r\n",
		"LED OFF\r\n",
		"FOCO ON\r\n",
		"FOCO OFF\r\n",
		"COMANDO NO RECONOCIDO\r\n"
};
unsigned char* mens_html[15] = {
		"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: Close\r\n\r\n<html><body><h3>",
		"</h3></body></html>",
		"<html><head><title>ESP8266 LED Control</title></head><body><script src=\"https://code.jquery.com/jquery-2.1.4.min.js\"></script><header size=32>ESP8266 - K64F Equipo 1 connexión</header><button id=\"1\" class=\"led\">Light On</button><button id=\"0\" class=\"led\">Light Off</button><button id=\"R\" class=\"led\">LED Red</button><button id=\"G\" class=\"led\">LED Green</button><button id=\"B\" class=\"led\">LED Blue</button><button id=\"O\" class=\"led\">LED Off</button><p id=\"LightStatus\">",
		"</p><p id=\"LEDStatus\">",
		"</p><script type=\"text/javascript\">$(document).ready(function(){$(\".led\").click(function(){var status = $(this).attr('id');switch (status) {case '1':$.get(\"http://172.16.101.131/1!\");break;case '0':$.get(\"http://172.16.101.131/0!\");break;case 'R':$.get(\"http://172.16.101.131/R!\");break;case 'G':$.get(\"http://172.16.101.131/G!\");break;case 'B':$.get(\"http://172.16.101.131/B!\");break;case 'O':$.get(\"http://172.16.101.131/O!\");break;default:break;}});});</script></body></html>"
};

unsigned char buffer[40];			//Arreglo donde se guardará información temporal
unsigned char mensaje[40];				//Mensaje
unsigned char canal;				//Canal de comunicación
unsigned char bytes[5];				//Bytes recibidos
unsigned char x = 0;				//Contador SM
unsigned char s = 0;


void vUART_init(void);
void delay(void);
void setLEDColor(unsigned char a);
void setLamp(unsigned char a);
void vUART_send_Console(unsigned char dato);
void vUART_send_msg_Console (unsigned char *a);
void vUART_send_ESP8266(unsigned char dato);
void vUART_send_msg_ESP8266 (unsigned char *a);
void vUART_send_msg_INTERNET (unsigned char c,unsigned char *a);
unsigned char u8parser1(unsigned char *a);
void vUART_recieve_buffer2(unsigned char *byte);
void vUART_recieve_buffer (unsigned char *a);
void vUART_clear_array(unsigned char *a);
unsigned int u16Contador_buffer(unsigned char *a);
unsigned char* itoa(unsigned int dato,unsigned char *buff);
void copy_buffer(unsigned char *a);
unsigned char* respuesta(unsigned char a);
/*
typedef enum 
{
	WAIT_READY,
	BLUE,
	YELLOW
}States;
//STATES X
states current_state;
current_state = WAIT_READY;
*/
/*
switch() 
*/
int main(void)
{
    vUART_init();
    GPIOC_PDOR = 0x00000000; //Estado inicial, Módulo y Relevador apagado
    setLEDColor('R');
    delay();
    setLEDColor('W');
    delay();
    setLEDColor('B');
    delay();
    setLEDColor('W');
    delay();
    setLEDColor('R');
    delay();
    GPIOC_PDOR |= 1 << 5; //Enceder solamente el pin 5 del puerto C (Activar Módulo)
    while (1)
    {
       
    	switch(x){
    	case 0://WAIT READY
    		if(u8parser1(mens_recieve[1])==1){			//Buscar un ready
    		    setLEDColor('B');
    		    x++;
    		}else setLEDColor('R');
    		break;
    	case 1:
    		if(u8parser1(mens_recieve[2])==1){			//Esperar a que reciba una IP
    			setLEDColor('B');
    			x++;
    		}else setLEDColor('R');
    		break;
    	case 2:
    		vUART_send_msg_ESP8266(mens_control[0]);		//Mandar un AT y esperar un OK
    		if(u8parser1(mens_recieve[3])==1){
    			setLEDColor('B');
    			x++;
    		}else setLEDColor('B');
    		break;
    	case 3:
     	   vUART_send_msg_ESP8266(mens_control[4]);		//Configurar MUX=1 y esperar un OK
     	   if(u8parser1(mens_recieve[3])==1){
     		   setLEDColor('B');
     		   x++;
     	   }else setLEDColor('R');
     	   break;
    	case 4:
     	   vUART_send_msg_ESP8266(mens_control[5]);		//Configurar como servidor en el puerto 80 y esperar un OK
     	   if(u8parser1(mens_recieve[3])==1){
     		   setLEDColor('B');
     		   x++;
     	   }else setLEDColor('R');
     	   break;
    	case 5:									//Mostrar IP actual y esperar un OK
     	   vUART_send_msg_ESP8266(mens_control[6]);
     	   if(u8parser1(mens_recieve[3])==1){
     		   setLEDColor('B');
     		   x++;
     		   setLEDColor('l');
     	   }else setLEDColor('R');
     	   break;
    	case 6:											//	+IPD,0,5:HELLO			
    		if(u8parser1(mens_parser[1])==1){			//Esperar a inicio del mensaje "+IPD,"
    			vUART_recieve_buffer(mens_parser[2]);	//Parsear el mensaje hasta encontrar una ","
    		    canal=buffer[0];						//Poner el valor (0-4) en canal
    		    vUART_recieve_buffer(mens_parser[3]);	//Parsear hasta encontrar un ":"
    		    copy_buffer(bytes);						//Convertir array a integer
    		    //vUART_recieve_buffer(mens_parser[4]);	//Parsear el mensaje hasta encontrar un "."    
    		    vUART_recieve_buffer2(bytes);
    		    copy_buffer(mensaje);
    		    
    		    vUART_send_msg_Console(mens_console[2]);//Espacio
    		    vUART_send_msg_Console(mens_console[2]);//Espacio
    		    vUART_send_msg_Console(mens_console[1]);//"Canal recibido"
    		    vUART_send_Console(canal);
    		    vUART_send_msg_Console(mens_console[2]);//Espacio
		        vUART_send_msg_Console(mens_console[3]);//"Bytes recibidos"
		        vUART_send_msg_Console(bytes);
		        vUART_send_msg_Console(mens_console[2]);//Espacio
		        vUART_send_msg_Console(mens_console[0]);//"Mensaje recibido"
		        vUART_send_msg_Console(mensaje);
		        vUART_send_msg_Console(mens_console[2]);//Espacio
    		    
    		    setLEDColor(buffer[0]);
    		    setLamp(buffer[0]);
		        
    		   


		        

    		    vUART_send_msg_INTERNET(canal, mens_html[0]);//MANDAR HEADER HTTP
		        vUART_send_msg_INTERNET(canal, respuesta(mensaje[0]));//MANDAR MENSAJE STATUS
		        vUART_send_msg_INTERNET(canal, mens_html[1]);//MANDAR HTML
    		    //vUART_send_msg_INTERNET(canal, respuesta(mensaje[0]));//MANDAR MENSAJE STATUS
    		    
    		    //vUART_send_msg_INTERNET(canal, respuesta(mensaje[0]));//MANDAR MENSAJE STATUS
    		    //vUART_send_msg_INTERNET(canal, mens_html[3]);//MANDAR FINAL HTML
    		    //delay();

    		    vUART_send_msg_ESP8266(mens_control[8]);
    		    vUART_send_ESP8266(canal);
    		    vUART_send_msg_ESP8266(mens_console[2]);
		        
    		    vUART_clear_array(buffer);
    		    vUART_clear_array(mensaje);
    		    vUART_clear_array(bytes);
    		    
    		    //x++;
    		}
    		break;
    	case 7:
    		break;
    	default:
    		setLEDColor('Y');
    		break;
    	}	
     }//while (1)
    return 0;

} //main

void vUART_init(void)

{
//UART init   
    SIM_SCGC4=0x00000C00; //Hab clk UART0 y UART1
    UART0_BDH=0;
    UART0_BDL=11;
    UART1_BDH=0;
    UART1_BDL=11;
    //UART0_C1=0;
    UART0_C2=12; // bit 3: Hab Tx, bit 2: Hab Rx
    UART1_C2=12;
   
//Pin/terminal init
    SIM_SCGC5=0x00002C00; //Hab clk PORTB (PB16 y 17 son Rx y Tx) y PORTC
    PORTB_PCR16=0x00000300; //Hab clk PB16 Rx
    PORTB_PCR17=0x00000300; //Hab clk PB17 Tx
    PORTC_PCR3=0x00000300; //Hab clk PC3 Rx
    PORTC_PCR4=0x00000300; //Hab clk PC4 Tx
    
    PORTB_PCR21 = 0x00000100;	//Seleccionar pin como GPIO 
    PORTB_PCR22 = 0x00000100;
    PORTC_PCR2 =  0x00000100;
    PORTC_PCR5 = 0x00000100;
    PORTE_PCR26 = 0x00000100;
    GPIOB_PDDR = 0x00600000;//Dirección del pin (ouput)
    GPIOE_PDDR = 0x04000000;
    GPIOC_PDDR = 0x00000024;
}
void delay(void){
	unsigned long i;
	for(i=0;i<=1000000;i++);	
}
void setLEDColor(unsigned char a){
	switch(a){
	case 'R':
		GPIOB_PDOR = 0x00200000;
		GPIOE_PDOR = 0x04000000;
		break;
	case 'B':
		GPIOB_PDOR = 0x00400000;
		GPIOE_PDOR = 0x04000000;
		break;
	case 'G':
		GPIOB_PDOR = 0x00600000;
		GPIOE_PDOR = 0x00000000;
		break;
	case 'W':
		GPIOB_PDOR = 0x00000000;
		GPIOE_PDOR = 0x00000000;
		break;
	case 'Y':
		GPIOB_PDOR = 0x00200000;
		GPIOE_PDOR = 0x00000000;
			break;
	case 'O':
		GPIOB_PDOR = 0x00600000;
		GPIOE_PDOR = 0x04000000;
		break;
	}
	// 31 30 29 28 || 27 26 25 24 || 23 22 21 20 || 19 18 17 16 || 15 14 13 12 || 11 10 09 08 || 07 06 05 04 || 03 02 01 00
	//Led Red --- PTB22
	//Led Blue -- PTB21
	//Led Green - PTE26
}
void setLamp(unsigned char a){
	if(a == '1' || a == 1){
		GPIOC_PDOR |= 1 << 2;	//Apagar relay (Encender bit 2)
	}
	if(a == '0' || a == 0){
		GPIOC_PDOR &= ~(1 << 2); //Encender relay (Apagar bit 2)
	}
}

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
void vUART_send_ESP8266(unsigned char dato){
	do{}while(!(UART1_S1& 0x80));
	UART1_D=dato; //mandar 'A'
	do{}while(!(UART0_S1& 0x80));
	UART0_D=dato; //mandar 'A'
}
void vUART_send_msg_ESP8266 (unsigned char *a){
	unsigned char i = 0;
	do{
		vUART_send_ESP8266(a[i++]); 
		//i++;
	}while(a[i] != 0);
}
unsigned char u8parser1(unsigned char *a)	//

{
	unsigned char i = 0;
	unsigned long cont=0;
	do{
		if (UART1_S1&0x20)
		   {
		     do{}while (!(UART0_S1&0x80));
		     UART0_D=UART1_D;
		     if(UART1_D == a[i])i++;
		     else i = 0;
		   }
		
	}while((a[i]!=0) && (++cont<=100000));
	if((++cont<=100000))return 1;
	else return 0;
}
void vUART_recieve_buffer2(unsigned char *byte){//Recibe los datos del UART y los guarda en el buffer, contemplando los bytes del mensaje
	unsigned char i= 0;
	unsigned int val = 0;
	unsigned long cont = 0;
	//i = u16array_to_char(byte);
	do{											//Convierte el arreglo de caracteres a decimal
			val *= 10;
		    val += byte[i] - '0';
		}while(byte[++i] != 0);

	unsigned char n=0;
	if(val > 100){								//Checa el tamaño de la trama, si es mayor de 100 significa que se mandó por HTTP
		unsigned char trash;					//Variable donde se pondrán los caracteres de GET /
		do{
			if (UART1_S1&0x20){
				trash = UART1_D;				//Coloca el dato recibido en trash para poder borrar la bandera
				do{}while(!(UART1_S1&0x20)); 	//Espera a que mande un nuevo dato
			}
		}while(trash != '/');					//"/" Significa que inició el mensaje
		do{			
				buffer[n] = UART1_D;			//Coloca el dato recibido en el buffer
				do{}while(!(UART1_S1&0x20));	//Espera a que mande un nuevo dato	
		}while(buffer[n++] != '!'  && buffer[n] != '/');				//"!" Significa que terminó el mensaje
		if(buffer[n] == '/'){
			vUART_clear_array(buffer);
			buffer[0] = 'X';
		}
		n--;
	}
	else{										//Si la trama es menor a 100 significa que lo mandó por Putty
		val +=1;
		do{
			if (UART1_S1&0x20)
			{
				buffer[n] = UART1_D;
				n++;
			}
		do{}while(!(UART1_S1&0x20));			//Espera a que mande un nuevo dato
	}while(--val != 0);							//Disminuye la variable de bytes hasta llegar a 0
		
	}
	buffer[n] = 0;
}
void vUART_recieve_buffer (unsigned char *a)
{
	unsigned char i=0;
	unsigned char n=0;
	unsigned long cont=0;
	do{
		if (UART1_S1&0x20)
			{
			if(UART1_D == a[n])n++;
			else {
				n=0;
				buffer[i++] = UART1_D;
			}
			
			}
	}while(a[n]!=0 && (++cont<=100000));
	buffer[i] = 0;
	}
void vUART_clear_array(unsigned char *a){							//Limpia el arreglo recibido
	unsigned char i=0;
	do{
		a[i] = 0;
	}while(a[++i] != 0);
}
unsigned int u16Contador_buffer(unsigned char *a){					//Recibe un Arreglo de caracteres y cuenta la cantidad de datos
	
	unsigned int i = 0;
	do{}while(a[++i] != 0);
	return i;
	
}
void vUART_send_msg_INTERNET (unsigned char c,unsigned char *a){
	vUART_send_msg_ESP8266(mens_control[7]); 						//"AT+CIPSEND="
	vUART_send_ESP8266(c);											//Canal
	vUART_send_msg_ESP8266(mens_parser[2]);							//,
	vUART_send_msg_ESP8266(itoa(u16Contador_buffer(a), buffer));	//Contar los caracteres que tiene el array, luego convertir de entero a array para poder mandar
	vUART_send_msg_ESP8266(mens_console[2]);						//Espacio
	if(u8parser1(mens_recieve[7])==1){								//Esperar a >
	    vUART_send_msg_ESP8266(a);									//mandar el menjake
	    }
	   	do{
	    }while(u8parser1(mens_recieve[6])!=1);						//Esperar a "SEND OK"
}
unsigned char u16array_to_char(unsigned char *a){
	
	unsigned char val = 0;
	unsigned char i = 0;
	
	do{
		val *= 10;
	    val += a[i] - '0';
	}while(a[++i] != 0);
	return val;
}
unsigned char* itoa(unsigned int dato,unsigned char *buff){ //Convierte de decimal a un arreglo
	unsigned char  digit;
        unsigned char i = 0;
        if (dato == 0)			//Si el dato es 0, pone automaticamente 0
        {
            buff[i++] = '0';
            buff[i] = 0;
            return buff;
        }
        if(dato / 10 == 0){		//Si el dato es menos a 9, pone automaticamente el dígito
            buff[i++] = dato + '0';
            buff[i] = 0;
            return buff;
        }
        do{
            digit = dato % 10; //Multiplica el valor anterior por 10
            dato /= 10;			//Divide el dato entre 10 
            buff[i++] = digit + '0';	//Suma el valor actual más el valor anterior
            }while(dato != 0);
        buff[i] = 0;
        unsigned char inicio, fin, c;
        fin = i-1;
        inicio = 0;
        do{
            c = buff[inicio];
            buff[inicio] = buff[fin];
            buff[fin] = c;
        }while(++inicio < --fin);
        return buff;
        
    }
void copy_buffer(unsigned char *a){
	int i = 0;
	do{
		a[i]=buffer[i];
	}while(buffer[++i] != 0);
}
unsigned char* respuesta(unsigned char a){
	switch(a){
	case 'R':
		s = 4;
		return mens_console[4];
		break;
	case 'B':
		s = 5;
		return mens_console[5];
		break;
	case 'G':
		s = 6;
		return mens_console[6];
		break;
	case 'W':
		s = 7;
		return mens_console[7];
		break;
	case 'Y':
		s = 8;
		return mens_console[8];
			break;
	case 'O':
		s = 9;
		return mens_console[9];
		break;
	case '1':
		s = 10;
		return mens_console[10];
			break;
	case '0':
		s = 11;
			return mens_console[11];
			break;
	case 'S':
			return mens_console[s];
			break;
	default:
		return mens_console[12];
		break;
	}
}
