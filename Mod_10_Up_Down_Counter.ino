void setup() {
  asm volatile (
    
    ".equ DDRB, 0x04 \n"
    ".equ PORTB, 0x05 \n"
    ".equ PINB, 0x03 \n"
    
    ".equ DDRD, 0x0A \n"
    ".equ PORTD, 0x0B \n"
    ".equ PIND, 0x09 \n"
    
	// Configurations of port B and D are being made.
    
    
    "ldi r17, 0b00001111 	\n" // Register 17 is assigned the value 0b00001111. 
    "out PORTB, r17 		\n" // Update the value assigned in r17 to PORTB
    "out DDRB, r17 			\n" // We set the relevant pins of PORTB as output.
    

    "mainprog: \n"
      
    
      " upcounter:   		\n"
      " sbis PIND,5 		\n"
      " jmp downcounter 	\n"
      " jmp increase 		\n"
     // We check whether the button connected to pin 5 on port D is pressed. If pressed, the increase function is called.
    
      " stopcont:  			\n"
      " sbis PIND,7 		\n"
      " jmp mainprog 		\n"
      " jmp stop 			\n"
     // We check whether the button connected to pin 7 on port D is pressed. If pressed, the stop function is called.


      " downcounter:   		\n"
      " sbis PIND,6			\n"
      " jmp stopcont 		\n"
      " jmp decrease 		\n"
     // We check whether the button connected to pin 6 on port D is pressed. If pressed, the decrease function is called.

    
      " increase : 			\n" // We define the increase function.
      " inc r17 			\n" // We increase the r17 register by 1 with the "inc" command
      " out PORTB, r17 		\n" // We update the new value of the register.
      " call delay 			\n" // We call the delay function.
      " sbic PIND,6 		\n" // We check whether the button on pin 6 of port D is pressed.
      " jmp decrease 		\n" // If the above condition is met, we switch to the decrease function.
      " sbic PIND,7 		\n" // We check whether the button on pin 7 of port D is pressed.
      " jmp stop 			\n" // If the above condition is met, we jump to the stop function.
      " cpi r17, 0b00001001 \n" // We compare the value of register r17 with the port value required to display 9 on 7 segments.
      " breq mainprog 		\n" // If the upper row is realized, that is, if the value becomes 9, the increase stops and the system returns to the main function.
    							// The reason for this is to prevent the screen from counting from the beginning again after 9 and to stop at 9.
      " jmp increase 		\n" // We ensure that the function loops within itself.

      " decrease : 			\n" // decrease fonksiyonunnu tanımlıyoruz.
      " dec r17 			\n" // r17 registerini "dec" komutu ile 1 azaltıyoruz
      " out PORTB, r17 		\n" // registerin yeni değerini güncelliyoruz. 
      " call delay 			\n" // We call the delay function.
      " sbic PIND,5 		\n" // We check whether the button on pin 5 of port D is pressed.
      " jmp increase		\n" // If the above condition is met, we jump to the increase function.
      " sbic PIND,7 		\n" // We check whether the button on pin 7 of port D is pressed.
      " jmp stop 			\n" // If the above condition is met, we jump to the stop function.
      " cpi r17, 0b00000000 \n" // We compare the value of register r17 with the port value required to display 0 on 7 segments.
      " breq mainprog 		\n" // If the top row is realized, that is, if the value becomes 0, the countdown stops and the system returns to the main function.
    							// The reason for this is to prevent the screen from starting from 9 again and counting down after 0, so that it remains 0 on the screen.
      " jmp decrease 		\n" // We ensure that the function loops within itself.
    
      " stop: 				\n" // We define the stop function.
      " out PORTB, r17 		\n" // We show the last value of the register on 7 segments 
      " jmp mainprog 		\n" // We return to the main function.


    //---------- alt program -----------
    "delay: \n"
    "ldi r18, 0xFF \n" // 1 döngü
    "ldi r19, 0x30 \n" // 1 döngü
    "ldi r20, 0x0F \n" // 1 döngü
    "repeat: \n"
    "subi r18, 1 \n" // 1 döngü
    "sbci r19, 0 \n" // 1 döngü
    "sbci r20, 0 \n" // 1 döngü
    "brcc repeat \n" // doğru ise 2 döngü, yanlış ise 1 döngü
    "ret \n" // alt programın sonu (ret alt programın sonu)
    //-----------------------------------
  );
}

void loop() {
  
  
}